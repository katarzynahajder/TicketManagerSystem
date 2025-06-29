#include "Database.h"
#include "sqlite3.h"
#include <vector>
#include <string>

// ==============================================
// Implementacja operacji na bazie danych SQLite:
// - Tworzenie tabel
// - Wstawianie rekordów (użytkownicy, wydarzenia, rezerwacje)
// - Pobieranie danych dla UI
// ==============================================

// rejestracja użytkownika
bool registerUser(const std::string& username, const std::string& email, const std::string& password) {
	// otwarcie bazy danych
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) {
        return false;
    }

	// tworzenie tabeli użytkowników, jeśli nie istnieje
    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT NOT NULL,"
        "email TEXT NOT NULL,"
        "password TEXT NOT NULL);";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }

	// przygotowanie zapytania SQL do wstawienia użytkownika
    const char* insertSQL =
        "INSERT INTO users (username, email, password) VALUES (?, ?, ?);";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

	// bindowanie parametrów zapytania
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_STATIC);

	// wykonanie zapytania
    bool success = sqlite3_step(stmt) == SQLITE_DONE;

	// zwolnienie zasobów
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

// sprawdzenie, czy użytkownik istnieje
bool userExists(const std::string& username) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK)
        return false;

    const char* sql = "SELECT COUNT(*) FROM users WHERE username = ?;";
    sqlite3_stmt* stmt;

    bool exists = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int count = sqlite3_column_int(stmt, 0);
            exists = (count > 0);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return exists;
}

// logowanie użytkownika
bool loginUser(const std::string& username, const std::string& password) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK)
        return false;

    const char* sql = "SELECT password FROM users WHERE username = ?;";
    sqlite3_stmt* stmt;

    bool authenticated = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* storedPassword = sqlite3_column_text(stmt, 0);
            if (storedPassword && password == reinterpret_cast<const char*>(storedPassword)) {
                authenticated = true;
            }
        }

        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return authenticated;
}

// tworzenie wydarzenia
bool createEvent(const std::string& title, const std::string& desc, const std::string& date, int count, const std::string& category) {
    sqlite3* db;
    sqlite3_open("tms.db", &db);

    const char* createEventsSQL =
        "CREATE TABLE IF NOT EXISTS events ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT NOT NULL,"
        "description TEXT,"
        "date TEXT NOT NULL,"
        "count INTEGER NOT NULL,"
        "category TEXT"
        ");";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, createEventsSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }

    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO events (title, description, date, count, category) VALUES (?, ?, ?, ?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, desc.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, date.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, count);
    sqlite3_bind_text(stmt, 5, category.c_str(), -1, SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

// ładowanie wydarzeń
std::vector<Event> loadEvents() {
    std::vector<Event> events;
    sqlite3* db;
    sqlite3_open("tms.db", &db);

	// pobranie wszystkich wydarzeń z bazy danych
    const char* sql = "SELECT id, title, description, date, count, category FROM events";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

	// iteracja po wynikach zapytania
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Event e;
        e.id = sqlite3_column_int(stmt, 0);
        e.title = (const char*)sqlite3_column_text(stmt, 1);
        e.description = (const char*)sqlite3_column_text(stmt, 2);
        e.date = (const char*)sqlite3_column_text(stmt, 3);
        e.count = sqlite3_column_int(stmt, 4);
        e.category = (const char*)sqlite3_column_text(stmt, 5);
        events.push_back(e);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return events;
}

// tworzenie rezerwacji
bool createReservation(const std::string& username, int ticketId) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK)
        return false;

    const char* createReservationsTableSQL =
        "CREATE TABLE IF NOT EXISTS reservations ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT NOT NULL, "
        "ticket_id INTEGER NOT NULL);";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, createReservationsTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }

    const char* sql = "INSERT INTO reservations (username, ticket_id) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ticketId);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

// zmniejszenie liczby biletów dla wydarzenia
bool decrementTicketCount(int ticketId) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) return false;

	// aktualizacja liczby biletów w tabeli wydarzeń
    const char* sql = "UPDATE events SET count = count - 1 WHERE id = ? AND count > 0;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_int(stmt, 1, ticketId);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

// sprawdzenie, czy użytkownik zarezerwował bilet na dane wydarzenie
bool hasUserReserved(const std::string& username, int ticketId) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) return false;

    const char* sql = "SELECT COUNT(*) FROM reservations WHERE username = ? AND ticket_id = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ticketId);

    bool reserved = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        reserved = sqlite3_column_int(stmt, 0) > 0;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return reserved;
}

// ładowanie rezerwacji użytkownika lub wszystkich rezerwacji dla administratora
std::vector<Reservation> loadReservations(const std::string& username) {
    std::vector<Reservation> result;
    sqlite3* db;
    sqlite3_open("tms.db", &db);

    const char* sql;

    if (username == "admin") {
        sql = R"(
			SELECT r.ticket_id, r.username, t.title, t.description, t.date, t.category
			FROM reservations r
			JOIN events t ON r.ticket_id = t.id
		)";
    }
    else {
        sql = R"(
			SELECT r.ticket_id, r.username, t.title, t.description, t.date, t.category
			FROM reservations r
			JOIN events t ON r.ticket_id = t.id
			WHERE r.username = ?
		)";
    }

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return result;
    }

    if (username != "admin") {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Reservation r;
        r.ticketId = sqlite3_column_int(stmt, 0);
        r.username = (const char*)sqlite3_column_text(stmt, 1);
        r.title = (const char*)sqlite3_column_text(stmt, 2);
        r.description = (const char*)sqlite3_column_text(stmt, 3);
        r.date = (const char*)sqlite3_column_text(stmt, 4);
        r.category = (const char*)sqlite3_column_text(stmt, 5);
        result.push_back(r);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}

// pobranie liczby biletów użytkownika
int getUserTicketCount(const std::string& username) {
    int ticketCount = -1;
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) return ticketCount;

    const char* sql = "SELECT count() FROM reservations WHERE username = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return ticketCount;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        ticketCount = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return ticketCount;
}

// pobranie informacji o użytkowniku
std::vector<UserInfo> getUserInfo(const std::string& username) {
    std::vector<UserInfo> result;
    sqlite3* db;
    sqlite3_open("tms.db", &db);

    const char* sql = "SELECT username, email, password FROM users WHERE username = ?";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return result;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        UserInfo u;
        u.username = (const char*)sqlite3_column_text(stmt, 0);
        u.email = (const char*)sqlite3_column_text(stmt, 1);
        u.password = (const char*)sqlite3_column_text(stmt, 2);
        result.push_back(u);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}

// aktualizacja informacji o użytkowniku
bool updateUserInfo(const std::string& oldUsername, const std::string& newUsername, const std::string& email, const std::string& password) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) {
        return false;
    }

    const char* sql = "UPDATE users SET username = ?, email = ?, password = ? WHERE username = ?";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, newUsername.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, oldUsername.c_str(), -1, SQLITE_STATIC);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

// anulowanie rezerwacji użytkownika
bool cancelUserTicket(const std::string& username, int ticketId) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) {
        return false;
    }

	// usunięcie rezerwacji użytkownika
    const char* sqlRemoveTicket = "DELETE FROM reservations WHERE username = ? AND ticket_id = ?";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sqlRemoveTicket, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, ticketId);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return false;
        }
    }
    sqlite3_finalize(stmt);

	// zwiększenie liczby biletów dla wydarzenia
    const char* sqlEventIncreaseCount = "UPDATE events SET count = count + 1 WHERE id = ?";

    if (sqlite3_prepare_v2(db, sqlEventIncreaseCount, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, ticketId);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return false;
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}

// aktualizacja wydarzenia
bool updateEvent(int eventId, const std::string& newTitle, const std::string& newDesc, const std::string& newDate, int newCount, const std::string& newCategory) {
    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) {
        return false;
    }

    const char* sql = "UPDATE events SET title = ?, description = ?, date = ?, count = ?, category = ? WHERE id = ?";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, newTitle.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, newDesc.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, newDate.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, newCount);
    sqlite3_bind_text(stmt, 5, newCategory.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, eventId);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

// usunięcie wydarzenia i wszystkich jego rezerwacji
bool removeEvent(int eventId) {

    sqlite3* db;
    if (sqlite3_open("tms.db", &db) != SQLITE_OK) {
        return false;
    }
    const char* sqlRemoveEvent = "DELETE FROM events WHERE id = ?";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sqlRemoveEvent, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, eventId);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return false;
        }
    }
    sqlite3_finalize(stmt);

    const char* sqlRemoveAllTickets = "DELETE FROM reservations WHERE ticket_id = ?";

    if (sqlite3_prepare_v2(db, sqlRemoveAllTickets, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, eventId);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return false;
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}

// pobranie informacji o wydarzeniu na podstawie ID
std::vector<Event> getEventInfo(int eventId) {
    std::vector<Event> result;
    sqlite3* db;
    sqlite3_open("tms.db", &db);

    const char* sql = "SELECT * FROM events WHERE id = ?";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return result;
    }

    sqlite3_bind_int(stmt, 1, eventId);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Event e;
        e.id = sqlite3_column_int(stmt, 0);
        e.title = (const char*)sqlite3_column_text(stmt, 1);
        e.description = (const char*)sqlite3_column_text(stmt, 2);
        e.date = (const char*)sqlite3_column_text(stmt, 3);
        e.count = sqlite3_column_int(stmt, 4);
        e.category = (const char*)sqlite3_column_text(stmt, 5);
        result.push_back(e);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}
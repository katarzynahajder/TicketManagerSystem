#include "Database.h"
#include "sqlite3.h"

bool registerUser(const std::string& username, const std::string& email, const std::string& password) {
    sqlite3* db;
    if (sqlite3_open("ticketmanager.db", &db) != SQLITE_OK) {
        return false;
    }

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

    const char* insertSQL =
        "INSERT INTO users (username, email, password) VALUES (?, ?, ?);";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_STATIC);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

bool userExists(const std::string& username) {
    sqlite3* db;
    if (sqlite3_open("ticketmanager.db", &db) != SQLITE_OK)
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

bool loginUser(const std::string& username, const std::string& password) {
    sqlite3* db;
    if (sqlite3_open("ticketmanager.db", &db) != SQLITE_OK)
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
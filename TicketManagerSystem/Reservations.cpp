#include <msclr/marshal_cppstd.h>
#include "Reservations.h"
#include "MainForm.h"
#include "UserProfile.h"
#include "Session.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

// ==============================================
// Implementacja klasy Reservations.
// Obs³uguje wyœwietlanie listy rezerwacji oraz akcje przycisku powrotu.
// ==============================================

using namespace TicketManagerSystem;

// za³adowanie rezerwacji dla danego u¿ytkownika
Void Reservations::LoadReservations() {
	this->reservationListPanel->Controls->Clear();

	// pobranie nazwy u¿ytkownika z sesji i konwersja
	msclr::interop::marshal_context context;
	std::string nativeUsername = context.marshal_as<std::string>(Session::Username);
	auto reservations = loadReservations(nativeUsername);

	// iteracja po rezerwacjach i dodawanie ich do panelu
	for (auto& r : reservations) {
		int ticketId = r.ticketId;
		String^ username = gcnew String(r.username.c_str());
		String^ title = gcnew String(r.title.c_str());
		String^ description = gcnew String(r.description.c_str());
		DateTime date = DateTime::Parse(gcnew String(r.date.c_str()));
		String^ category = gcnew String(r.category.c_str());

		ReservationItem^ item = gcnew ReservationItem(ticketId, username, title, description, date, category);
		reservationListPanel->Controls->Add(item);
	}
}

// akcja przycisku powrotu
Void Reservations::backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// zamkniêcie aktualnej formy i powrót do profilu u¿ytkownika
	MainForm::Instance->loadControl(gcnew UserProfile());
}
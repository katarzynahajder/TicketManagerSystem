#include <msclr/marshal_cppstd.h>
#include "Reservations.h"
#include "MainForm.h"
#include "UserProfile.h"
#include "Session.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

Void Reservations::LoadReservations() {
	this->reservationListPanel->Controls->Clear();

	msclr::interop::marshal_context context;
	std::string nativeUsername = context.marshal_as<std::string>(Session::Username);
	auto reservations = loadReservations(nativeUsername);

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

Void Reservations::backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	MainForm^ main = safe_cast<MainForm^>(this->FindForm());
	if (main != nullptr) {
		main->loadControl(gcnew UserProfile());
	}
}
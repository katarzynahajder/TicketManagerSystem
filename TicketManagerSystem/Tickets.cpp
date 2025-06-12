#include "Tickets.h"
#include "MainForm.h"
#include "UserProfile.h"
#include "MainMenuControl.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

Void Tickets::userBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew UserProfile());
    }
}

void Tickets::LoadTickets() {
    this->ticketListPanel->Controls->Clear();

	auto nativeTickets = loadTickets();

	for (auto& t : nativeTickets) {
		String^ title = gcnew String(t.title.c_str());
		String^ description = gcnew String(t.description.c_str());
		DateTime date = DateTime::Parse(gcnew String(t.date.c_str()));
		String^ category = gcnew String(t.category.c_str());

		TicketItem^ item = gcnew TicketItem(t.id, title, description, date, t.count, category);
		ticketListPanel->Controls->Add(item);
	}
}

Void Tickets::logoutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	MainForm^ main = safe_cast<MainForm^>(this->FindForm());
	if (main != nullptr) {
		main->loadControl(gcnew MainMenuControl());
	}
}
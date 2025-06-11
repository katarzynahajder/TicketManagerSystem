#include "Tickets.h"
#include "MainForm.h"
#include "UserProfile.h"

using namespace TicketManagerSystem;

Void Tickets::userBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew UserProfile());
    }
}

void Tickets::LoadTickets() {
    this->ticketListPanel->Controls->Clear();

    for (int i = 0; i < 5; i++) {
        String^ title = "Wydarzenie #" + i.ToString();
        String^ description = "Opis wydarzenia testowego numer " + i.ToString();
        DateTime date = DateTime::Now.AddDays(i);
        int count = 100 - i * 10;
        String^ category = (i % 2 == 0) ? "film" : "koncert";

        TicketItem^ item = gcnew TicketItem(title, description, date, count, category);
        this->ticketListPanel->Controls->Add(item);
    }
}
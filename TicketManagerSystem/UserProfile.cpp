#include "UserProfile.h"
#include "MainForm.h"
#include "TicketForm.h"
#include "Tickets.h"
#include "Reservations.h"
#include "Session.h"

using namespace TicketManagerSystem;

Void UserProfile::addTicketBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew TicketForm());
    }
}

Void UserProfile::showReservationsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew Reservations());
    }
}

Void UserProfile::backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew Tickets());
    }
}
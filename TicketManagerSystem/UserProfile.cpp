#include "UserProfile.h"
#include "MainForm.h"
#include "TicketForm.h"

using namespace TicketManagerSystem;

Void UserProfile::addTicketBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew TicketForm());
    }
}
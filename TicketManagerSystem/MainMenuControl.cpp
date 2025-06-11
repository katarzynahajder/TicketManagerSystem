#include "MainForm.h"
#include "MainMenuControl.h"
#include "LoginControl.h"
#include "RegisterControl.h"

using namespace TicketManagerSystem;

void MainMenuControl::loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew LoginControl());
    }
}

void MainMenuControl::registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew RegisterControl());
    }
}
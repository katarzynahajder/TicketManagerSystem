#include "MainForm.h"
#include "MainMenuControl.h"
#include "LoginControl.h"
#include "RegisterControl.h"

using namespace TicketManagerSystem;

void MainMenuControl::loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew LoginControl());
}

void MainMenuControl::registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew RegisterControl());
}
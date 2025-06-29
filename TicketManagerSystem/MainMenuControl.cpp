#include "MainForm.h"
#include "MainMenuControl.h"
#include "LoginControl.h"
#include "RegisterControl.h"

// ==============================================
// Implementacja klasy MainMenuControl.
// Wyœwietla g³ówne menu aplikacji i obs³uguje przyciski logowania i rejestracji.
// ==============================================

using namespace TicketManagerSystem;

// klikniêcie przycisku "Zaloguj siê"
void MainMenuControl::loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew LoginControl());
}

// klikniêcie przycisku "Zarejestruj siê"
void MainMenuControl::registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew RegisterControl());
}
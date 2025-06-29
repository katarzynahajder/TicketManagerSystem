#include "MainForm.h"
#include "MainMenuControl.h"
#include "LoginControl.h"
#include "RegisterControl.h"

// ==============================================
// Implementacja klasy MainMenuControl.
// Wy�wietla g��wne menu aplikacji i obs�uguje przyciski logowania i rejestracji.
// ==============================================

using namespace TicketManagerSystem;

// klikni�cie przycisku "Zaloguj si�"
void MainMenuControl::loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew LoginControl());
}

// klikni�cie przycisku "Zarejestruj si�"
void MainMenuControl::registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew RegisterControl());
}
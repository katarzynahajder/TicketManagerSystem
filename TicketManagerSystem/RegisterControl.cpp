#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "LoginControl.h"
#include "RegisterControl.h"
#include "EventList.h"
#include "Session.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

// ==============================================
// Implementacja klasy RegisterControl.
// Obs³uguje rejestracjê nowego u¿ytkownika.
// ==============================================

using namespace TicketManagerSystem;

// klikniêcie linku do logowania
void RegisterControl::loginLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    MainForm::Instance->loadControl(gcnew LoginControl());
}

// klikniêcie przycisku rejestracji
void RegisterControl::registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// pobranie danych z pól formularza
    String^ username = usernameBox->Text->Trim();
    String^ email = emailBox->Text->Trim();
    String^ password = passwordBox->Text;
    String^ confirm = passwordConfirmBox->Text;

	// sprawdzenie, czy pola nie s¹ puste
    if (username->Length == 0 || email->Length == 0 || password->Length == 0 || confirm->Length == 0) {
        MessageBox::Show("Wszystkie pola s¹ wymagane.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

	// sprawdzenie zgodnoœci hase³
    if (password != confirm) {
        MessageBox::Show("Has³a nie s¹ zgodne.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

	// konwersja danych
    msclr::interop::marshal_context context;
    std::string nativeUsername = context.marshal_as<std::string>(username);
    std::string nativeEmail = context.marshal_as<std::string>(email);
    std::string nativePassword = context.marshal_as<std::string>(password);

	// sprawdzenie, czy u¿ytkownik o takiej nazwie ju¿ istnieje
    if (userExists(nativeUsername)) {
        MessageBox::Show("U¿ytkownik o takiej nazwie ju¿ istnieje.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

	// rejestracja u¿ytkownika w bazie danych
    bool success = registerUser(nativeUsername, nativeEmail, nativePassword);

    if (success) {
        MessageBox::Show("Konto zosta³o utworzone! Mo¿esz siê zalogowaæ.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
        MainForm::Instance->loadControl(gcnew LoginControl());
    }
    else {
        MessageBox::Show("Rejestracja nie powiod³a siê. Spróbuj ponownie.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
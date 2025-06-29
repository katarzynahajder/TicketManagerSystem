#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "LoginControl.h"
#include "RegisterControl.h"
#include "EventList.h"
#include "Session.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

void RegisterControl::loginLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    MainForm::Instance->loadControl(gcnew LoginControl());
}
void RegisterControl::registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = usernameBox->Text->Trim();
    String^ email = emailBox->Text->Trim();
    String^ password = passwordBox->Text;
    String^ confirm = passwordConfirmBox->Text;

    if (username->Length == 0 || email->Length == 0 || password->Length == 0 || confirm->Length == 0) {
        MessageBox::Show("Wszystkie pola s� wymagane.", "B��d", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    if (password != confirm) {
        MessageBox::Show("Has�a nie s� zgodne.", "B��d", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    msclr::interop::marshal_context context;
    std::string nativeUsername = context.marshal_as<std::string>(username);
    std::string nativeEmail = context.marshal_as<std::string>(email);
    std::string nativePassword = context.marshal_as<std::string>(password);

    if (userExists(nativeUsername)) {
        MessageBox::Show("U�ytkownik o takiej nazwie ju� istnieje.", "B��d", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    bool success = registerUser(nativeUsername, nativeEmail, nativePassword);

    if (success) {
        MessageBox::Show("Konto zosta�o utworzone! Mo�esz si� zalogowa�.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
        MainForm::Instance->loadControl(gcnew LoginControl());
    }
    else {
        MessageBox::Show("Rejestracja nie powiod�a si�. Spr�buj ponownie.", "B��d", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
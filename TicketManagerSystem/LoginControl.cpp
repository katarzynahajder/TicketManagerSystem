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

// akcja klikniÍcia linku do rejestracji
void LoginControl::registerLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    MainForm::Instance->loadControl(gcnew RegisterControl());
}

// akcja klikniÍcia przycisku "Zaloguj"
void LoginControl::loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = usernameBox->Text->Trim();
    String^ password = passwordBox->Text;

	// sprawdza, czy pola login i has≥o nie sπ puste
    if (username->Length == 0 || password->Length == 0) {
        MessageBox::Show("Wprowadü login i has≥o.", "B≥πd", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

	// konwersja danych
    msclr::interop::marshal_context context;
    std::string nativeUsername = context.marshal_as<std::string>(username);
    std::string nativePassword = context.marshal_as<std::string>(password);

	// wywo≥anie funkcji logowania z biblioteki natywnej
    bool success = loginUser(nativeUsername, nativePassword);

    if (success) {
        MessageBox::Show("Zalogowano pomyúlnie!", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
        Session::Username = username;
        MainForm::Instance->loadControl(gcnew EventList());
    }
    else {
        MessageBox::Show("Nieprawid≥owy login lub has≥o.", "B≥πd", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
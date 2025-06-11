#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "LoginControl.h"
#include "RegisterControl.h"
#include "Tickets.h"
#include "Session.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

void LoginControl::registerLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew RegisterControl());
    }
}

void LoginControl::loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = usernameBox->Text->Trim();
    String^ password = passwordBox->Text;

    if (username->Length == 0 || password->Length == 0) {
        MessageBox::Show("Wprowadü login i has≥o.", "B≥πd", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    msclr::interop::marshal_context context;
    std::string nativeUsername = context.marshal_as<std::string>(username);
    std::string nativePassword = context.marshal_as<std::string>(password);

    bool success = loginUser(nativeUsername, nativePassword);

    if (success) {
        MessageBox::Show("Zalogowano pomyúlnie!", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
        Session::Username = username;
        MainForm^ main = safe_cast<MainForm^>(this->FindForm());
        if (main != nullptr) {
            main->loadControl(gcnew Tickets());
        }
    }
    else {
        MessageBox::Show("Nieprawid≥owy login lub has≥o.", "B≥πd", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
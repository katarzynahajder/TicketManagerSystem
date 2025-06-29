#include <msclr/marshal_cppstd.h>
#include "EditProfileControl.h"
#include "MainForm.h"
#include "UserProfile.h"
#include "Session.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

// ==============================================
// Implementacja klasy EditProfileControl.
// Ta klasa s³u¿y do edycji danych u¿ytkownika.
// ==============================================

using namespace TicketManagerSystem;

// akcja przycisku anulowania
Void EditProfileControl::cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// przejœcie do profilu u¿ytkownika bez zmian
    MainForm::Instance->loadControl(gcnew UserProfile());
}

Void EditProfileControl::EditProfileControl_Load(System::Object^ sender, System::EventArgs^ e) {
	// pobranie nazwy u¿ytkownika z sesji
    String^ username = Session::Username;
    std::string uname = msclr::interop::marshal_as<std::string>(username);
	// pobranie informacji o u¿ytkowniku z bazy danych
    std::vector<UserInfo> info = getUserInfo(uname);

    if (!info.empty()) {
        UserInfo user = info[0];

        usernameBox->Text = gcnew String(user.username.c_str());
        emailBox->Text = gcnew String(user.email.c_str());
        passwordBox->Text = gcnew String(user.password.c_str());
        passwordConfirmBox->Text = gcnew String(user.password.c_str());
    }
    else {
        usernameBox->Text = "Nie wczytano";
        emailBox->Text = "Nie wczytano";
        passwordBox->Text = "Nie wczytano";
        passwordConfirmBox->Text = "Nie wczytano";
    }
}

// akcja przycisku edycji profilu
Void EditProfileControl::editBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// pobranie danych z pól tekstowych i sesji
    String^ oldUsername = Session::Username;
    String^ newUsername = usernameBox->Text;
    String^ newEmail = emailBox->Text;
    String^ newPassword = passwordBox->Text;

	// konwersja danych
    std::string oldU = msclr::interop::marshal_as<std::string>(oldUsername);
    std::string newU = msclr::interop::marshal_as<std::string>(newUsername);
    std::string email = msclr::interop::marshal_as<std::string>(newEmail);
    std::string pass = msclr::interop::marshal_as<std::string>(newPassword);

	// wywo³anie funkcji aktualizuj¹cej dane u¿ytkownika
    if (updateUserInfo(oldU, newU, email, pass)) {
        MessageBox::Show("Dane konta zosta³y zakutalizowane.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
        Session::Username = newUsername;
        MainForm::Instance->loadControl(gcnew UserProfile());
    }
    else {
        MessageBox::Show("Wyst¹pi³ b³¹d podczas zmiany danych konta.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
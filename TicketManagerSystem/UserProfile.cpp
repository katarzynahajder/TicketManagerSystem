#include <msclr/marshal_cppstd.h>
#include "UserProfile.h"
#include "MainForm.h"
#include "CreateEventForm.h"
#include "EventList.h"
#include "Reservations.h"
#include "Session.h"
#include "EditProfileControl.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

// ==============================================
// Implementacja klasy UserProfile.
// Klasa wyświetla profil użytkownika; umożliwia tworzenie wydarzeń (dla admina), wyświetlanie rezerwacji oraz edycję profilu.
// ==============================================

using namespace TicketManagerSystem;

// akcja przycisku tworzenia wydarzenia, wyświetlania rezerwacji i powrotu do listy wydarzeń
Void UserProfile::createEventBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew CreateEventForm());
}

Void UserProfile::showReservationsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew Reservations());
}

Void UserProfile::backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew EventList());
}

// załadowanie profilu użytkownika
Void UserProfile::UserProfile_Load(System::Object^ sender, System::EventArgs^ e) {
    String^ username = Session::Username;

    std::string uname = msclr::interop::marshal_as<std::string>(username);
    std::vector<UserInfo> info = getUserInfo(uname);

    if (!info.empty()) {
        UserInfo user = info[0];

        usernameLabel->Text = "Nazwa: " + gcnew String(user.username.c_str());
        emailLabel->Text = "E-Mail: " + gcnew String(user.email.c_str());
    }
    else {
        usernameLabel->Text = "Nazwa: [Nie wczytano]";
        emailLabel->Text = "E-Mail: [Nie wczytano]";
    }

	// pobranie ilości biletów użytkownika
    int amountOfTickets = getUserTicketCount(uname);

    if (username == "admin") {
        ticketCountLabel->Text = "";
    }
    else if (amountOfTickets >= 0) {
       ticketCountLabel->Text = "Posiadane bilety: " + amountOfTickets.ToString();
    }
    else {
        ticketCountLabel->Text = "Posiadane bilety: [Nie wczytano]";
    }
}

// akcja przycisku edycji profilu
Void UserProfile::editProfileBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// przejście do kontrolki edycji profilu
    MainForm::Instance->loadControl(gcnew EditProfileControl());
}
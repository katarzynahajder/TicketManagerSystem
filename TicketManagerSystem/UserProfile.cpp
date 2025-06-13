#include <msclr/marshal_cppstd.h>
#include "UserProfile.h"
#include "MainForm.h"
#include "TicketForm.h"
#include "Tickets.h"
#include "Reservations.h"
#include "Session.h"
#include "EditProfileControl.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

Void UserProfile::addTicketBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew TicketForm());
    }
}

Void UserProfile::showReservationsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew Reservations());
    }
}

Void UserProfile::backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew Tickets());
    }
}

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

Void UserProfile::editProfileBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew EditProfileControl());
    }
}
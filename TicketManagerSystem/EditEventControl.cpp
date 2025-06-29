#include <msclr/marshal_cppstd.h>
#include "EditEventControl.h"
#include "MainForm.h"
#include "UserProfile.h"
#include "Session.h"
#include "EventList.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

Void EditEventControl::EditEventControl_Load(System::Object^ sender, System::EventArgs^ e) {
    std::vector<Event> info = getEventInfo(this->eventId);

    if (!info.empty()) {
        Event event = info[0];

        titleBox->Text = gcnew String(event.title.c_str());
        dateTimeBox->Text = gcnew String(event.date.c_str());
        descriptionBox->Text = gcnew String(event.description.c_str());
        categoryBox->Text = gcnew String(event.category.c_str());
        ticketCountBox->Value = event.count;
    }
    else {
        titleBox->Text = "Nie wczytano";
        dateTimeBox->Text = "Nie wczytano";
        descriptionBox->Text = "Nie wczytano";
        categoryBox->Text = "Nie wczytano";
        ticketCountBox->Value = 0;
    }
}

Void EditEventControl::cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm::Instance->loadControl(gcnew EventList());
}

Void EditEventControl::addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ newTitle = titleBox->Text;
    String^ newDateTime = dateTimeBox->Text;
    String^ newDescription = descriptionBox->Text;
    String^ newCategory = categoryBox->Text;
    int newTicketCount = (int)ticketCountBox->Value;
    int eventId = this->eventId;
    
    std::string newT = msclr::interop::marshal_as<std::string>(newTitle);
    std::string newDT= msclr::interop::marshal_as<std::string>(newDateTime);
    std::string newDesc = msclr::interop::marshal_as<std::string>(newDescription);
    std::string newCat = msclr::interop::marshal_as<std::string>(newCategory);

    if (updateEvent(eventId, newT, newDesc, newDT, newTicketCount, newCat)) {
        MessageBox::Show("Dane wydarzenia zosta�y zaktualizowane.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
        MainForm::Instance->loadControl(gcnew EventList());
    }
    else {
        MessageBox::Show("Wyst�pi� b��d podczas zmiany danych wydarzenia.", "B��d", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


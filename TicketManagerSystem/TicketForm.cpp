#include <msclr/marshal_cppstd.h>
#include "TicketForm.h"
#include "UserProfile.h"
#include "MainForm.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

Void TicketForm::addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ title = usernameBox->Text->Trim();
    String^ description = descriptionBox->Text->Trim();
    DateTime date = dateTimePicker->Value;
    int count = Decimal::ToInt32(numericUpDown->Value);
    String^ category = comboBox->SelectedItem != nullptr ? comboBox->SelectedItem->ToString() : "";

    if (title->Length == 0 || category->Length == 0) {
        MessageBox::Show("Wype�nij wszystkie wymagane pola.");
        return;
    }

    msclr::interop::marshal_context context;
    std::string nativeTitle = context.marshal_as<std::string>(title);
    std::string nativeDesc = context.marshal_as<std::string>(description);
    std::string nativeCategory = context.marshal_as<std::string>(category);
    std::string nativeDate = context.marshal_as<std::string>(date.ToString("yyyy-MM-dd"));

    insertTicket(nativeTitle, nativeDesc, nativeDate, count, nativeCategory);

    MessageBox::Show("Wydarzenie dodane.");

    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew UserProfile());
    }

}

Void TicketForm::cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ main = safe_cast<MainForm^>(this->FindForm());
    if (main != nullptr) {
        main->loadControl(gcnew UserProfile());
    }

}
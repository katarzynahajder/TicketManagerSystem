#include <msclr/marshal_cppstd.h>
#include "CreateEventForm.h"
#include "UserProfile.h"
#include "MainForm.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

// ==============================================
// Implementacja klasy CreateEventForm.
// Odpowiedzialna za tworzenie nowych wydarze� w systemie zarz�dzania biletami.
// ==============================================

using namespace TicketManagerSystem;

// akcja przycisku dodawania wydarzenia
Void CreateEventForm::addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// pobierania danych z p�l formularza
    String^ title = usernameBox->Text->Trim();
    String^ description = descriptionBox->Text->Trim();
    DateTime date = dateTimePicker->Value;
    int count = Decimal::ToInt32(numericUpDown->Value);
    String^ category = comboBox->SelectedItem != nullptr ? comboBox->SelectedItem->ToString() : "";

	// sprawdzenie, czy wszystkie wymagane pola s� wype�nione
    if (title->Length == 0 || category->Length == 0) {
        MessageBox::Show("Wype�nij wszystkie wymagane pola.");
        return;
    }

	// konwersja danych z managed do unmanaged
    msclr::interop::marshal_context context;
    std::string nativeTitle = context.marshal_as<std::string>(title);
    std::string nativeDesc = context.marshal_as<std::string>(description);
    std::string nativeCategory = context.marshal_as<std::string>(category);
    std::string nativeDate = context.marshal_as<std::string>(date.ToString("yyyy-MM-dd"));

	// wywo�anie funkcji z biblioteki natywnej do tworzenia wydarzenia
    createEvent(nativeTitle, nativeDesc, nativeDate, count, nativeCategory);

    MessageBox::Show("Wydarzenie dodane.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// po dodaniu wydarzenia, przej�cie do profilu u�ytkownika
    MainForm::Instance->loadControl(gcnew UserProfile());
}

// akcja przycisku anulowania dodawania wydarzenia
Void CreateEventForm::cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// zamkni�cie formularza tworzenia wydarzenia i powr�t do profilu u�ytkownika
    MainForm::Instance->loadControl(gcnew UserProfile());
}
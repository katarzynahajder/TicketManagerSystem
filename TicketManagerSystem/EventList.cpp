#include "EventList.h"
#include "MainForm.h"
#include "UserProfile.h"
#include "MainMenuControl.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

// ==============================================
// Implementacja klasy EventList.
// Obs�uguje wy�wietlanie listy wydarze� oraz obs�ug� przycisk�w, takich jak "Moje konto" czy "Wyloguj si�".
// ==============================================

using namespace TicketManagerSystem;

Void EventList::userBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	MainForm::Instance->loadControl(gcnew UserProfile());
}

// metoda �adowania danych z bazy do interfejsu u�ytkownika
void EventList::loadEventList() {
	// usuwa stare kontrolki z panelu, a nast�pnie dodaje aktualne dane z bazy danych
    this->ticketListPanel->Controls->Clear();

	// zak�ada, �e loadEvents() zwraca wektor struktur Event z bazy danych
	auto nativeEvents = loadEvents();

	// iteruje przez ka�dy element w wektorze i tworzy kontrolk� EventItem dla ka�dego wydarzenia
	for (auto& e : nativeEvents) {
		String^ title = gcnew String(e.title.c_str());
		String^ description = gcnew String(e.description.c_str());
		DateTime date = DateTime::Parse(gcnew String(e.date.c_str()));
		String^ category = gcnew String(e.category.c_str());

		EventItem^ item = gcnew EventItem(e.id, title, description, date, e.count, category);
		ticketListPanel->Controls->Add(item);
	}
}

// akcja przycisku wylogowania u�ytkownika
Void EventList::logoutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Czy na pewno chcesz si� wylogowa�?",
		"Potwierdzenie wylogowania",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question
	);

	if (result == System::Windows::Forms::DialogResult::Yes) {
		MainForm::Instance->loadControl(gcnew MainMenuControl());
	}
}
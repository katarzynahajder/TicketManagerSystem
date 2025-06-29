#include "EventList.h"
#include "MainForm.h"
#include "UserProfile.h"
#include "MainMenuControl.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace TicketManagerSystem;

Void EventList::userBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	MainForm::Instance->loadControl(gcnew UserProfile());
}

void EventList::loadEventList() {
    this->ticketListPanel->Controls->Clear();

	auto nativeEvents = loadEvents();

	for (auto& e : nativeEvents) {
		String^ title = gcnew String(e.title.c_str());
		String^ description = gcnew String(e.description.c_str());
		DateTime date = DateTime::Parse(gcnew String(e.date.c_str()));
		String^ category = gcnew String(e.category.c_str());

		EventItem^ item = gcnew EventItem(e.id, title, description, date, e.count, category);
		ticketListPanel->Controls->Add(item);
	}
}

Void EventList::logoutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Czy na pewno chcesz siê wylogowaæ?",
		"Potwierdzenie wylogowania",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question
	);

	if (result == System::Windows::Forms::DialogResult::Yes) {
		MainForm::Instance->loadControl(gcnew MainMenuControl());
	}
}
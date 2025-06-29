#include <msclr/marshal_cppstd.h>
#include "EventItem.h"
#include "Session.h"
#include "MainForm.h"
#include "EventList.h"
#include "EditEventControl.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

// ==============================================
// Implementacja klasy EventItem.
// Klasa ta reprezentuje pojedynczy element wydarzenia.
// ==============================================

namespace TicketManagerSystem {

	// konstruktor klasy EventItem
	EventItem::EventItem(int id, String^ title, String^ description, DateTime date, int count, String^ category) {
		this->ticketId = id;
		this->Size = Drawing::Size(1115, 175);
		this->BackColor = System::Drawing::Color::WhiteSmoke;
		this->Margin = System::Windows::Forms::Padding(10, 10, 0, 10);
		this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

		titleLabel = gcnew Label();
		titleLabel->Text = title;
		titleLabel->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
		titleLabel->Location = Point(10, 10);
		titleLabel->Size = Drawing::Size(600, 25);

		dateLabel = gcnew Label();
		dateLabel->Text = "Data: " + date.ToShortDateString();
		dateLabel->Location = Point(10, 40);
		dateLabel->Size = Drawing::Size(250, 20);

		descriptionLabel = gcnew Label();
		descriptionLabel->Text = "Opis: " + description;
		descriptionLabel->Location = Point(10, 65);
		descriptionLabel->Size = Drawing::Size(750, 20);

		countLabel = gcnew Label();
		countLabel->Text = "Liczba miejsc: " + count.ToString();
		countLabel->Location = Point(700, 10);
		countLabel->Size = Drawing::Size(200, 20);

		categoryLabel = gcnew Label();
		categoryLabel->Text = "Kategoria: " + category;
		categoryLabel->Location = Point(700, 40);
		categoryLabel->Size = Drawing::Size(300, 20);

		adminLabel = gcnew Label();
		adminLabel->Text = "Akcje administratora";
		adminLabel->Location = Point(1000, 10);
		adminLabel->Size = Drawing::Size(300, 15);
		adminLabel->Visible = false;
		
		reserveBtn = gcnew Button();
		reserveBtn->Text = "Rezerwuj";
		reserveBtn->Location = Point(1000, 10);
		reserveBtn->Size = Drawing::Size(100, 30);
		reserveBtn->Click += gcnew System::EventHandler(this, &EventItem::reserveBtn_Click);

		editEventBtn = gcnew Button();
		editEventBtn->Text = "Edytuj wydarzenie";
		editEventBtn->Location = Point(1000, 25);
		editEventBtn->Size = Drawing::Size(100, 30);
		editEventBtn->Click += gcnew System::EventHandler(this, &EventItem::editEventBtn_Click);
		editEventBtn->Enabled = false;
		editEventBtn->Visible = false;

		removeEventBtn = gcnew Button();
		removeEventBtn->Text = "Usuń wydarzenie";
		removeEventBtn->Location = Point(1000, 60);
		removeEventBtn->Size = Drawing::Size(100, 30);
		removeEventBtn->Click += gcnew System::EventHandler(this, &EventItem::removeEventBtn_Click);
		removeEventBtn->Enabled = false;
		removeEventBtn->Visible = false;
		
		// sprawdza, czy użytkownik jest administratorem i czy ma już rezerwację na ten bilet
		msclr::interop::marshal_context context;
		std::string nativeUsername = context.marshal_as<std::string>(Session::Username);
		if (nativeUsername == "admin") {
			reserveBtn->Enabled = false;
			reserveBtn->Visible = false;

			editEventBtn->Enabled = true;
			editEventBtn->Visible = true;

			removeEventBtn->Enabled = true;
			removeEventBtn->Visible = true;

			adminLabel->Visible = true;
		}
		else if (hasUserReserved(nativeUsername, ticketId)) {
			reserveBtn->Enabled = false;
			reserveBtn->Text = "Zarezerwowano";
			reserveBtn->BackColor = System::Drawing::Color::LightGray;
		}
		else if (count <= 0) {
			reserveBtn->Enabled = false;
			reserveBtn->Text = "Brak miejsc";
			reserveBtn->BackColor = System::Drawing::Color::LightGray;
		}

		this->Controls->Add(reserveBtn);
		this->Controls->Add(titleLabel);
		this->Controls->Add(dateLabel);
		this->Controls->Add(descriptionLabel);
		this->Controls->Add(countLabel);
		this->Controls->Add(categoryLabel);
		this->Controls->Add(adminLabel);
		this->Controls->Add(editEventBtn);
		this->Controls->Add(removeEventBtn);
	}

	// obsługuje kliknięcie przycisku "Rezerwuj"
	// - zapisuje rezerwację do bazy
	// - odświeża widok
	// - dezaktywuje przycisk po rezerwacji
	void EventItem::reserveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		std::string nativeUsername = context.marshal_as<std::string>(Session::Username); 
		
		// sprawdza, czy użytkownik już zarezerwował dany bilet
		// jeśli tak – przycisk rezerwacji jest nieaktywny
		if (hasUserReserved(nativeUsername, this->ticketId)) {
			MessageBox::Show("Już zarezerwowałeś ten bilet.", "Informacja", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		
		bool success = createReservation(nativeUsername, this->ticketId);
		decrementTicketCount(this->ticketId);

		MainForm::Instance->loadControl(gcnew EventList());

		// jeśli rezerwacja się powiodła, wyświetla komunikat i usuwa przycisk rezerwacji
		if (success) {
			String^ msg = "Zarezerwowano bilet na: " + titleLabel->Text;
			MessageBox::Show(msg, "Rezerwacja", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Controls->Remove(reserveBtn);
		}
	}

	// obsługuje kliknięcie przycisku "Edytuj wydarzenie"
	void EventItem::editEventBtn_Click(Object^ sender, EventArgs^ e) {
		MainForm::Instance->loadControl(gcnew EditEventControl(this->ticketId));
	}

	// obsługuje kliknięcie przycisku "Usuń wydarzenie"
	void EventItem::removeEventBtn_Click(Object^ sender, EventArgs^ e) {

		if (removeEvent(this->ticketId)) {

			String^ msg = "Usunięto wydarzenie: " + titleLabel->Text;

			MessageBox::Show(msg, "Usuwanie wydarzenia", MessageBoxButtons::OK, MessageBoxIcon::Information);

			MainForm::Instance->loadControl(gcnew EventList());
		}
		else {
			MessageBox::Show("Błąd poczas usuwania wydarzenia", "Usuwanie wydarzenia", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
#include <msclr/marshal_cppstd.h>
#include "ReservationItem.h"
#include "Session.h"
#include "MainForm.h"
#include "Reservations.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

// ==============================================
// Implementacja klasy ReservationItem.
// Klasa ta reprezentuje pojedynczy element rezerwacji.
// ==============================================

namespace TicketManagerSystem {

	// konstruktor klasy ReservationItem
	ReservationItem::ReservationItem(int ticketId, String^ username, String^ title, String^ description, DateTime date, String^ category) {
		this->ticketId = ticketId;
		this->username = username;
		this->Size = Drawing::Size(1115, 120);
		this->BackColor = System::Drawing::Color::WhiteSmoke;
		this->Margin = System::Windows::Forms::Padding(10, 10, 0, 10);
		this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

		int top = 10;

		// je¿eli u¿ytkownik jest adminem, dodatkowo wyœwietla nazwê u¿ytkownika w kontrolce
		if (username != nullptr && Session::Username=="admin") {
			usernameLabel = gcnew Label();
			usernameLabel->Text = "U¿ytkownik: " + username;
			usernameLabel->Location = System::Drawing::Point(10, top);
			usernameLabel->Size = System::Drawing::Size(300, 20);
			this->Controls->Add(usernameLabel);
			top += 25;
		}

		titleLabel = gcnew Label();
		titleLabel->Text = "Tytu³: " + title;
		titleLabel->Location = System::Drawing::Point(10, top);
		titleLabel->Size = Drawing::Size(300, 20);
		this->Controls->Add(titleLabel);

		descriptionLabel = gcnew Label();
		descriptionLabel->Text = "Opis: " + description;
		descriptionLabel->Location = System::Drawing::Point(10, top + 25);
		descriptionLabel->Size = Drawing::Size(600, 20);
		this->Controls->Add(descriptionLabel);

		dateLabel = gcnew Label();
		dateLabel->Text = "Data: " + date.ToShortDateString();
		dateLabel->Location = System::Drawing::Point(700, top);
		dateLabel->Size = Drawing::Size(300, 20);
		this->Controls->Add(dateLabel);

		categoryLabel = gcnew Label();
		categoryLabel->Text = "Kategoria: " + category;
		categoryLabel->Location = System::Drawing::Point(700, top + 25);
		categoryLabel->Size = Drawing::Size(300, 20);
		this->Controls->Add(categoryLabel);

		cancelBtn = gcnew Button();
		cancelBtn->Text = "Anuluj rezerwacje";
		cancelBtn->Location = System::Drawing::Point(1000, 10);
		cancelBtn->Size = System::Drawing::Size(100, 30);
		cancelBtn->Click += gcnew System::EventHandler(this, &ReservationItem::cancelBtn_Click);
		this->Controls->Add(cancelBtn);
	}

	// klikniêcie przycisku anulowania rezerwacji
	Void ReservationItem::cancelBtn_Click(Object^ sender, EventArgs^ e) {
		// pobranie nazwy u¿ytkownika z rezerwacji
		String^ username = this->username;

		// konwersja nazwy u¿ytkownika
		std::string uname = msclr::interop::marshal_as<std::string>(username);

		// anulowanie biletu u¿ytkownika podaj¹c id biletu i nazwê u¿ytkownika
		if (cancelUserTicket(uname, ticketId)) {
			MainForm::Instance->loadControl(gcnew Reservations());

			// sprawdzenie czy u¿ytkownik to admin, jeœli tak to wyœwietlenie komunikatu o anulowaniu biletu
			if (Session::Username == "admin") {
				MessageBox::Show("Anulowano bilet u¿ytkownikowi.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Zrezygnowano z biletu.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		else {
			MessageBox::Show("Wyst¹pi³ b³¹d podczas anulowania biletu", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	
	};
}

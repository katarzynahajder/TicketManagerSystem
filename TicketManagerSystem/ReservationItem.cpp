#include <msclr/marshal_cppstd.h>
#include "ReservationItem.h"
#include "Session.h"
#include "MainForm.h"
#include "Reservations.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

namespace TicketManagerSystem {

	ReservationItem::ReservationItem(int ticketId, String^ username, String^ title, String^ description, DateTime date, String^ category) {
		this->ticketId = ticketId;
		this->username = username;
		this->Size = Drawing::Size(1155, 120);
		this->BackColor = System::Drawing::Color::WhiteSmoke;
		this->Margin = System::Windows::Forms::Padding(10, 10, 0, 10);
		this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

		int top = 10;


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
		cancelBtn->UseVisualStyleBackColor = true;
		cancelBtn->Click += gcnew System::EventHandler(this, &ReservationItem::cancelBtn_Click);
		this->Controls->Add(cancelBtn);
	}

	Void ReservationItem::cancelBtn_Click(Object^ sender, EventArgs^ e) {
		String^ username = this->username;

		std::string uname = msclr::interop::marshal_as<std::string>(username);

		if (cancelUserTicket(uname, ticketId)) {
			MainForm^ main = safe_cast<MainForm^>(this->FindForm());
			if (main != nullptr) {
				main->loadControl(gcnew Reservations());
			}

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

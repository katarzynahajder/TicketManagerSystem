#include "ReservationItem.h"
#include "Session.h"

namespace TicketManagerSystem {

	ReservationItem::ReservationItem(String^ username, String^ title, String^ description, DateTime date, String^ category) {
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
	}
}

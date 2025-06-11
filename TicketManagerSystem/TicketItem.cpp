#include "TicketItem.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace TicketManagerSystem {

	TicketItem::TicketItem(String^ title, String^ description, DateTime date, int count, String^ category) {
		this->Size = Drawing::Size(1138, 120);
		this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->Margin = System::Windows::Forms::Padding(10);

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
		descriptionLabel->Size = Drawing::Size(1000, 20);

		countLabel = gcnew Label();
		countLabel->Text = "Liczba miejsc: " + count.ToString();
		countLabel->Location = Point(900, 10);
		countLabel->Size = Drawing::Size(200, 20);

		categoryLabel = gcnew Label();
		categoryLabel->Text = "Kategoria: " + category;
		categoryLabel->Location = Point(900, 40);
		categoryLabel->Size = Drawing::Size(300, 20);

		this->Controls->Add(titleLabel);
		this->Controls->Add(dateLabel);
		this->Controls->Add(descriptionLabel);
		this->Controls->Add(countLabel);
		this->Controls->Add(categoryLabel);
	}
}
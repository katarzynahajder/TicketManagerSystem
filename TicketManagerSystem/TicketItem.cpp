﻿#include <msclr/marshal_cppstd.h>
#include "TicketItem.h"
#include "Session.h"
#include "MainForm.h"
#include "Tickets.h"

#pragma unmanaged
#include "../NativeDatabase/Database.h"
#pragma managed

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace TicketManagerSystem {

	TicketItem::TicketItem(int id, String^ title, String^ description, DateTime date, int count, String^ category) {
		this->ticketId = id;
		this->Size = Drawing::Size(1155, 120);
		this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->Margin = System::Windows::Forms::Padding(10, 10, 0, 10);

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
		countLabel->Location = Point(700, 10);
		countLabel->Size = Drawing::Size(200, 20);

		categoryLabel = gcnew Label();
		categoryLabel->Text = "Kategoria: " + category;
		categoryLabel->Location = Point(700, 40);
		categoryLabel->Size = Drawing::Size(300, 20);

		reserveBtn = gcnew Button();
		reserveBtn->Text = "Rezerwuj";
		reserveBtn->Location = Point(850, 10);
		reserveBtn->Size = Drawing::Size(100, 30);
		reserveBtn->Click += gcnew System::EventHandler(this, &TicketItem::reserveBtn_Click);

		msclr::interop::marshal_context context;
		std::string nativeUsername = context.marshal_as<std::string>(Session::Username);

		if (nativeUsername == "admin") {
			reserveBtn->Enabled = false;
			reserveBtn->Text = "Brak dostępu";
			reserveBtn->BackColor = System::Drawing::Color::LightGray;
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
	}
	void TicketItem::reserveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		std::string nativeUsername = context.marshal_as<std::string>(Session::Username); 
		
		if (hasUserReserved(nativeUsername, this->ticketId)) {
			MessageBox::Show("Już zarezerwowałeś ten bilet.", "Informacja", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		
		bool success = insertReservation(nativeUsername, this->ticketId);
		decrementTicketCount(this->ticketId);

		MainForm^ main = safe_cast<MainForm^>(this->FindForm());
		if (main != nullptr) {
			main->loadControl(gcnew Tickets());
		}

		if (success) {
			String^ msg = "Zarezerwowano bilet na: " + titleLabel->Text;
			MessageBox::Show(msg, "Rezerwacja", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Controls->Remove(reserveBtn);
		}
	}
}
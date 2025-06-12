#pragma once

#include "Session.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace TicketManagerSystem {

	public ref class UserProfile : public System::Windows::Forms::UserControl
	{
	public:
		UserProfile(void)
		{
			InitializeComponent();
			if (Session::Username != "admin") {
				addTicketBtn->Enabled = false;
				addTicketBtn->BackColor = System::Drawing::Color::LightGray;
			}
		}

	protected:
		~UserProfile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ addTicketBtn;
	private: System::Windows::Forms::Button^ showReservationsBtn;

	private: System::Windows::Forms::Button^ backBtn;

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->addTicketBtn = (gcnew System::Windows::Forms::Button());
			this->showReservationsBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// addTicketBtn
			// 
			this->addTicketBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addTicketBtn->Location = System::Drawing::Point(20, 20);
			this->addTicketBtn->Name = L"addTicketBtn";
			this->addTicketBtn->Size = System::Drawing::Size(278, 107);
			this->addTicketBtn->TabIndex = 1;
			this->addTicketBtn->Text = L"Dodaj wydarzenie";
			this->addTicketBtn->UseVisualStyleBackColor = true;
			this->addTicketBtn->Click += gcnew System::EventHandler(this, &UserProfile::addTicketBtn_Click);
			// 
			// showReservationsBtn
			// 
			this->showReservationsBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->showReservationsBtn->Location = System::Drawing::Point(322, 20);
			this->showReservationsBtn->Name = L"showReservationsBtn";
			this->showReservationsBtn->Size = System::Drawing::Size(316, 107);
			this->showReservationsBtn->TabIndex = 2;
			this->showReservationsBtn->Text = L"Wyœwietl rezerwacje";
			this->showReservationsBtn->UseVisualStyleBackColor = true;
			this->showReservationsBtn->Click += gcnew System::EventHandler(this, &UserProfile::showReservationsBtn_Click);
			// 
			// backBtn
			// 
			this->backBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->backBtn->Location = System::Drawing::Point(1292, 20);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(244, 107);
			this->backBtn->TabIndex = 3;
			this->backBtn->Text = L"Powrót";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &UserProfile::backBtn_Click);
			// 
			// UserProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->showReservationsBtn);
			this->Controls->Add(this->addTicketBtn);
			this->Name = L"UserProfile";
			this->Size = System::Drawing::Size(1560, 910);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void addTicketBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void showReservationsBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
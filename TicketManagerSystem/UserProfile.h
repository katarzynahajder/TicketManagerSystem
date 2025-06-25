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
	private: System::Windows::Forms::Button^ editProfileBtn;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ emailLabel;
	private: System::Windows::Forms::Label^ ticketCountLabel;
	private: System::Windows::Forms::Label^ label;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->addTicketBtn = (gcnew System::Windows::Forms::Button());
			this->showReservationsBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->editProfileBtn = (gcnew System::Windows::Forms::Button());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->ticketCountLabel = (gcnew System::Windows::Forms::Label());
			this->label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// addTicketBtn
			// 
			this->addTicketBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addTicketBtn->Location = System::Drawing::Point(20, 20);
			this->addTicketBtn->Margin = System::Windows::Forms::Padding(4);
			this->addTicketBtn->Name = L"addTicketBtn";
			this->addTicketBtn->Size = System::Drawing::Size(279, 107);
			this->addTicketBtn->TabIndex = 1;
			this->addTicketBtn->Text = L"Dodaj wydarzenie";
			this->addTicketBtn->UseVisualStyleBackColor = true;
			this->addTicketBtn->Click += gcnew System::EventHandler(this, &UserProfile::addTicketBtn_Click);
			// 
			// showReservationsBtn
			// 
			this->showReservationsBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->showReservationsBtn->Location = System::Drawing::Point(323, 20);
			this->showReservationsBtn->Margin = System::Windows::Forms::Padding(4);
			this->showReservationsBtn->Name = L"showReservationsBtn";
			this->showReservationsBtn->Size = System::Drawing::Size(315, 107);
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
			this->backBtn->Margin = System::Windows::Forms::Padding(4);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(244, 107);
			this->backBtn->TabIndex = 3;
			this->backBtn->Text = L"Powrót";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &UserProfile::backBtn_Click);
			// 
			// editProfileBtn
			// 
			this->editProfileBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->editProfileBtn->Location = System::Drawing::Point(664, 20);
			this->editProfileBtn->Margin = System::Windows::Forms::Padding(4);
			this->editProfileBtn->Name = L"editProfileBtn";
			this->editProfileBtn->Size = System::Drawing::Size(315, 107);
			this->editProfileBtn->TabIndex = 4;
			this->editProfileBtn->Text = L"Edytuj konto";
			this->editProfileBtn->UseVisualStyleBackColor = true;
			this->editProfileBtn->Click += gcnew System::EventHandler(this, &UserProfile::editProfileBtn_Click);
			// 
			// usernameLabel
			// 
			this->usernameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->usernameLabel->Location = System::Drawing::Point(552, 379);
			this->usernameLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(136, 38);
			this->usernameLabel->TabIndex = 5;
			this->usernameLabel->Text = L"Nazwa: ";
			// 
			// emailLabel
			// 
			this->emailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->emailLabel->Location = System::Drawing::Point(552, 456);
			this->emailLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(127, 38);
			this->emailLabel->TabIndex = 6;
			this->emailLabel->Text = L"E-Mail: ";
			// 
			// ticketCountLabel
			// 
			this->ticketCountLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ticketCountLabel->AutoSize = true;
			this->ticketCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->ticketCountLabel->Location = System::Drawing::Point(552, 530);
			this->ticketCountLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->ticketCountLabel->Name = L"ticketCountLabel";
			this->ticketCountLabel->Size = System::Drawing::Size(265, 38);
			this->ticketCountLabel->TabIndex = 7;
			this->ticketCountLabel->Text = L"Posiadane bilety:";
			// 
			// label
			// 
			this->label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label->Location = System::Drawing::Point(621, 250);
			this->label->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(311, 64);
			this->label->TabIndex = 8;
			this->label->Text = L"Moje konto";
			// 
			// UserProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label);
			this->Controls->Add(this->ticketCountLabel);
			this->Controls->Add(this->emailLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->editProfileBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->showReservationsBtn);
			this->Controls->Add(this->addTicketBtn);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"UserProfile";
			this->Size = System::Drawing::Size(1560, 910);
			this->Load += gcnew System::EventHandler(this, &UserProfile::UserProfile_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

			if (Session::Username != "admin") {
				this->addTicketBtn->Visible = false;
				this->showReservationsBtn->Location = Point(20, 20);
				this->editProfileBtn->Location = Point(200, 20);
			}
		}

#pragma endregion
	private: System::Void addTicketBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void showReservationsBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void UserProfile_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void editProfileBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
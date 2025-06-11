#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace TicketManagerSystem {

	public ref class RegisterControl : public System::Windows::Forms::UserControl
	{
	public:
		RegisterControl(void)
		{
			InitializeComponent();
		}

	protected:
		~RegisterControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ emailLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::Label^ passwordConfirmLabel;
	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::TextBox^ emailBox;
	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::TextBox^ passwordConfirmBox;
	private: System::Windows::Forms::Label^ textLabel;
	private: System::Windows::Forms::LinkLabel^ loginLinkLabel;
	private: System::Windows::Forms::Button^ registerBtn;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->passwordConfirmLabel = (gcnew System::Windows::Forms::Label());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordConfirmBox = (gcnew System::Windows::Forms::TextBox());
			this->textLabel = (gcnew System::Windows::Forms::Label());
			this->loginLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->registerBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->titleLabel->Location = System::Drawing::Point(611, 95);
			this->titleLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(319, 64);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Rejestracja";
			// 
			// usernameLabel
			// 
			this->usernameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->usernameLabel->Location = System::Drawing::Point(560, 231);
			this->usernameLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(270, 32);
			this->usernameLabel->TabIndex = 1;
			this->usernameLabel->Text = L"Nazwa u¿ytkownika:";
			// 
			// emailLabel
			// 
			this->emailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->emailLabel->Location = System::Drawing::Point(560, 331);
			this->emailLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(181, 32);
			this->emailLabel->TabIndex = 2;
			this->emailLabel->Text = L"Adres e-mail:";
			// 
			// passwordLabel
			// 
			this->passwordLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->passwordLabel->Location = System::Drawing::Point(560, 428);
			this->passwordLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(95, 32);
			this->passwordLabel->TabIndex = 3;
			this->passwordLabel->Text = L"Has³o:";
			// 
			// passwordConfirmLabel
			// 
			this->passwordConfirmLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordConfirmLabel->AutoSize = true;
			this->passwordConfirmLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->passwordConfirmLabel->Location = System::Drawing::Point(560, 534);
			this->passwordConfirmLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->passwordConfirmLabel->Name = L"passwordConfirmLabel";
			this->passwordConfirmLabel->Size = System::Drawing::Size(223, 32);
			this->passwordConfirmLabel->TabIndex = 4;
			this->passwordConfirmLabel->Text = L"PotwierdŸ has³o:";
			// 
			// usernameBox
			// 
			this->usernameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->usernameBox->Location = System::Drawing::Point(566, 267);
			this->usernameBox->Margin = System::Windows::Forms::Padding(6);
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(400, 39);
			this->usernameBox->TabIndex = 6;
			// 
			// emailBox
			// 
			this->emailBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->emailBox->Location = System::Drawing::Point(566, 367);
			this->emailBox->Margin = System::Windows::Forms::Padding(6);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(400, 39);
			this->emailBox->TabIndex = 7;
			// 
			// passwordBox
			// 
			this->passwordBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->passwordBox->Location = System::Drawing::Point(566, 466);
			this->passwordBox->Margin = System::Windows::Forms::Padding(6);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->PasswordChar = '*';
			this->passwordBox->Size = System::Drawing::Size(400, 39);
			this->passwordBox->TabIndex = 8;
			// 
			// passwordConfirmBox
			// 
			this->passwordConfirmBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordConfirmBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->passwordConfirmBox->Location = System::Drawing::Point(566, 572);
			this->passwordConfirmBox->Margin = System::Windows::Forms::Padding(6);
			this->passwordConfirmBox->Name = L"passwordConfirmBox";
			this->passwordConfirmBox->PasswordChar = '*';
			this->passwordConfirmBox->Size = System::Drawing::Size(400, 39);
			this->passwordConfirmBox->TabIndex = 9;
			// 
			// textLabel
			// 
			this->textLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textLabel->AutoSize = true;
			this->textLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->textLabel->Location = System::Drawing::Point(1277, 809);
			this->textLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->textLabel->Name = L"textLabel";
			this->textLabel->Size = System::Drawing::Size(237, 29);
			this->textLabel->TabIndex = 10;
			this->textLabel->Text = L"Posiadasz ju¿ konto\?";
			// 
			// loginLinkLabel
			// 
			this->loginLinkLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->loginLinkLabel->AutoSize = true;
			this->loginLinkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->loginLinkLabel->Location = System::Drawing::Point(1327, 838);
			this->loginLinkLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->loginLinkLabel->Name = L"loginLinkLabel";
			this->loginLinkLabel->Size = System::Drawing::Size(187, 29);
			this->loginLinkLabel->TabIndex = 11;
			this->loginLinkLabel->TabStop = true;
			this->loginLinkLabel->Text = L"Zaloguj siê tutaj!";
			this->loginLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterControl::loginLinkLabel_LinkClicked);
			// 
			// registerBtn
			// 
			this->registerBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registerBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->registerBtn->Location = System::Drawing::Point(566, 669);
			this->registerBtn->Margin = System::Windows::Forms::Padding(6);
			this->registerBtn->Name = L"registerBtn";
			this->registerBtn->Size = System::Drawing::Size(229, 92);
			this->registerBtn->TabIndex = 12;
			this->registerBtn->Text = L"Stwórz konto";
			this->registerBtn->UseVisualStyleBackColor = true;
			this->registerBtn->Click += gcnew System::EventHandler(this, &RegisterControl::registerBtn_Click);
			// 
			// RegisterControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->passwordConfirmBox);
			this->Controls->Add(this->loginLinkLabel);
			this->Controls->Add(this->passwordConfirmLabel);
			this->Controls->Add(this->passwordBox);
			this->Controls->Add(this->registerBtn);
			this->Controls->Add(this->emailBox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->textLabel);
			this->Controls->Add(this->usernameBox);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->emailLabel);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"RegisterControl";
			this->Size = System::Drawing::Size(1560, 910);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loginLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void registerBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

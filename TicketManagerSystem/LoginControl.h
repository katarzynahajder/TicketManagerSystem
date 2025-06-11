#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace TicketManagerSystem {

	public ref class LoginControl : public System::Windows::Forms::UserControl
	{
	public:
		LoginControl(void)
		{
			InitializeComponent();
		}

	protected:
		~LoginControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::LinkLabel^ registerLinkLabel;
	private: System::Windows::Forms::Label^ textLabel;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->usernameLabel = (gcnew System::Windows::Forms::Label());
			   this->passwordLabel = (gcnew System::Windows::Forms::Label());
			   this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			   this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			   this->loginBtn = (gcnew System::Windows::Forms::Button());
			   this->titleLabel = (gcnew System::Windows::Forms::Label());
			   this->registerLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			   this->textLabel = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // usernameLabel
			   // 
			   this->usernameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->usernameLabel->AutoSize = true;
			   this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->usernameLabel->Location = System::Drawing::Point(569, 229);
			   this->usernameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->usernameLabel->Name = L"usernameLabel";
			   this->usernameLabel->Size = System::Drawing::Size(270, 32);
			   this->usernameLabel->TabIndex = 0;
			   this->usernameLabel->Text = L"Nazwa u¿ytkownika:";
			   // 
			   // passwordLabel
			   // 
			   this->passwordLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->passwordLabel->AutoSize = true;
			   this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->passwordLabel->Location = System::Drawing::Point(569, 329);
			   this->passwordLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->passwordLabel->Name = L"passwordLabel";
			   this->passwordLabel->Size = System::Drawing::Size(95, 32);
			   this->passwordLabel->TabIndex = 1;
			   this->passwordLabel->Text = L"Has³o:";
			   // 
			   // passwordBox
			   // 
			   this->passwordBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->passwordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->passwordBox->Location = System::Drawing::Point(566, 367);
			   this->passwordBox->Margin = System::Windows::Forms::Padding(4);
			   this->passwordBox->Name = L"passwordBox";
			   this->passwordBox->PasswordChar = '*';
			   this->passwordBox->Size = System::Drawing::Size(400, 39);
			   this->passwordBox->TabIndex = 2;
			   // 
			   // usernameBox
			   // 
			   this->usernameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->usernameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->usernameBox->Location = System::Drawing::Point(566, 267);
			   this->usernameBox->Margin = System::Windows::Forms::Padding(4);
			   this->usernameBox->Name = L"usernameBox";
			   this->usernameBox->Size = System::Drawing::Size(400, 39);
			   this->usernameBox->TabIndex = 3;
			   // 
			   // loginBtn
			   // 
			   this->loginBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->loginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->loginBtn->Location = System::Drawing::Point(566, 467);
			   this->loginBtn->Margin = System::Windows::Forms::Padding(4);
			   this->loginBtn->Name = L"loginBtn";
			   this->loginBtn->Size = System::Drawing::Size(229, 92);
			   this->loginBtn->TabIndex = 4;
			   this->loginBtn->Text = L"Zaloguj siê";
			   this->loginBtn->UseVisualStyleBackColor = true;
			   this->loginBtn->Click += gcnew System::EventHandler(this, &LoginControl::loginBtn_Click);
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
			   this->titleLabel->Size = System::Drawing::Size(306, 64);
			   this->titleLabel->TabIndex = 6;
			   this->titleLabel->Text = L"Logowanie";
			   // 
			   // registerLinkLabel
			   // 
			   this->registerLinkLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->registerLinkLabel->AutoSize = true;
			   this->registerLinkLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->registerLinkLabel->Location = System::Drawing::Point(1312, 838);
			   this->registerLinkLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			   this->registerLinkLabel->Name = L"registerLinkLabel";
			   this->registerLinkLabel->Size = System::Drawing::Size(207, 29);
			   this->registerLinkLabel->TabIndex = 7;
			   this->registerLinkLabel->TabStop = true;
			   this->registerLinkLabel->Text = L"Stwórz konto tutaj!";
			   this->registerLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginControl::registerLinkLabel_LinkClicked);
			   // 
			   // textLabel
			   // 
			   this->textLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->textLabel->AutoSize = true;
			   this->textLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->textLabel->Location = System::Drawing::Point(1277, 809);
			   this->textLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			   this->textLabel->Name = L"textLabel";
			   this->textLabel->Size = System::Drawing::Size(242, 29);
			   this->textLabel->TabIndex = 8;
			   this->textLabel->Text = L"Nie posiadasz konta\?";
			   // 
			   // LoginControl
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->Controls->Add(this->textLabel);
			   this->Controls->Add(this->registerLinkLabel);
			   this->Controls->Add(this->titleLabel);
			   this->Controls->Add(this->loginBtn);
			   this->Controls->Add(this->usernameBox);
			   this->Controls->Add(this->passwordBox);
			   this->Controls->Add(this->passwordLabel);
			   this->Controls->Add(this->usernameLabel);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"LoginControl";
			   this->Size = System::Drawing::Size(1560, 910);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void registerLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
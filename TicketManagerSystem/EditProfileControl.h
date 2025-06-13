#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TicketManagerSystem {

	/// <summary>
	/// Summary for EditProfileControl
	/// </summary>
	public ref class EditProfileControl : public System::Windows::Forms::UserControl
	{
	public:
		EditProfileControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditProfileControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	protected:
	private: System::Windows::Forms::TextBox^ passwordConfirmBox;
	private: System::Windows::Forms::Label^ passwordConfirmLabel;
	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::Button^ editBtn;

	private: System::Windows::Forms::TextBox^ emailBox;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ emailLabel;
	private: System::Windows::Forms::Button^ cancelBtn;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->passwordConfirmBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordConfirmLabel = (gcnew System::Windows::Forms::Label());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->titleLabel->Location = System::Drawing::Point(290, 73);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(285, 37);
			this->titleLabel->TabIndex = 13;
			this->titleLabel->Text = L"Edytowanie konta";
			// 
			// passwordConfirmBox
			// 
			this->passwordConfirmBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordConfirmBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->passwordConfirmBox->Location = System::Drawing::Point(317, 325);
			this->passwordConfirmBox->Name = L"passwordConfirmBox";
			this->passwordConfirmBox->PasswordChar = '*';
			this->passwordConfirmBox->Size = System::Drawing::Size(220, 26);
			this->passwordConfirmBox->TabIndex = 21;
			// 
			// passwordConfirmLabel
			// 
			this->passwordConfirmLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordConfirmLabel->AutoSize = true;
			this->passwordConfirmLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->passwordConfirmLabel->Location = System::Drawing::Point(313, 304);
			this->passwordConfirmLabel->Name = L"passwordConfirmLabel";
			this->passwordConfirmLabel->Size = System::Drawing::Size(125, 20);
			this->passwordConfirmLabel->TabIndex = 17;
			this->passwordConfirmLabel->Text = L"PotwierdŸ has³o:";
			// 
			// passwordBox
			// 
			this->passwordBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->passwordBox->Location = System::Drawing::Point(317, 267);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->PasswordChar = '*';
			this->passwordBox->Size = System::Drawing::Size(220, 26);
			this->passwordBox->TabIndex = 20;
			// 
			// editBtn
			// 
			this->editBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->editBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->editBtn->Location = System::Drawing::Point(450, 368);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(125, 50);
			this->editBtn->TabIndex = 22;
			this->editBtn->Text = L"Edytuj";
			this->editBtn->UseVisualStyleBackColor = true;
			this->editBtn->Click += gcnew System::EventHandler(this, &EditProfileControl::editBtn_Click);
			// 
			// emailBox
			// 
			this->emailBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->emailBox->Location = System::Drawing::Point(317, 214);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(220, 26);
			this->emailBox->TabIndex = 19;
			// 
			// passwordLabel
			// 
			this->passwordLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->passwordLabel->Location = System::Drawing::Point(313, 247);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(55, 20);
			this->passwordLabel->TabIndex = 16;
			this->passwordLabel->Text = L"Has³o:";
			// 
			// usernameBox
			// 
			this->usernameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->usernameBox->Location = System::Drawing::Point(317, 160);
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(220, 26);
			this->usernameBox->TabIndex = 18;
			// 
			// usernameLabel
			// 
			this->usernameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->usernameLabel->Location = System::Drawing::Point(313, 140);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(151, 20);
			this->usernameLabel->TabIndex = 14;
			this->usernameLabel->Text = L"Nazwa u¿ytkownika:";
			// 
			// emailLabel
			// 
			this->emailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->emailLabel->Location = System::Drawing::Point(313, 194);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(101, 20);
			this->emailLabel->TabIndex = 15;
			this->emailLabel->Text = L"Adres e-mail:";
			// 
			// cancelBtn
			// 
			this->cancelBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->cancelBtn->Location = System::Drawing::Point(289, 368);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(125, 50);
			this->cancelBtn->TabIndex = 23;
			this->cancelBtn->Text = L"Anuluj";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditProfileControl::cancelBtn_Click);
			// 
			// EditProfileControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->passwordConfirmBox);
			this->Controls->Add(this->passwordConfirmLabel);
			this->Controls->Add(this->passwordBox);
			this->Controls->Add(this->editBtn);
			this->Controls->Add(this->emailBox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameBox);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->emailLabel);
			this->Name = L"EditProfileControl";
			this->Size = System::Drawing::Size(851, 493);
			this->Load += gcnew System::EventHandler(this, &EditProfileControl::EditProfileControl_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditProfileControl_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

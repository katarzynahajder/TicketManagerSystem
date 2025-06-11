#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace TicketManagerSystem {

	public ref class MainMenuControl : public System::Windows::Forms::UserControl
	{
	public:
		MainMenuControl(void)
		{
			InitializeComponent();
		}

	protected:
		~MainMenuControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ infoLabel;
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Button^ registerBtn;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->registerBtn = (gcnew System::Windows::Forms::Button());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// infoLabel
			// 
			this->infoLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->infoLabel->AutoSize = true;
			this->infoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->infoLabel->Location = System::Drawing::Point(461, 353);
			this->infoLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(598, 32);
			this->infoLabel->TabIndex = 7;
			this->infoLabel->Text = L"Zaloguj siê lub stwórz konto by kontynuuowaæ.\r\n";
			// 
			// titleLabel
			// 
			this->titleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->titleLabel->Location = System::Drawing::Point(396, 258);
			this->titleLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(724, 64);
			this->titleLabel->TabIndex = 6;
			this->titleLabel->Text = L"System Rezerwacji Biletów";
			this->titleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// registerBtn
			// 
			this->registerBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registerBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->registerBtn->Location = System::Drawing::Point(799, 535);
			this->registerBtn->Margin = System::Windows::Forms::Padding(6);
			this->registerBtn->Name = L"registerBtn";
			this->registerBtn->Size = System::Drawing::Size(321, 92);
			this->registerBtn->TabIndex = 5;
			this->registerBtn->Text = L"Zarejestruj siê";
			this->registerBtn->UseVisualStyleBackColor = true;
			this->registerBtn->Click += gcnew System::EventHandler(this, &MainMenuControl::registerBtn_Click);
			// 
			// loginBtn
			// 
			this->loginBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->loginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->loginBtn->Location = System::Drawing::Point(407, 535);
			this->loginBtn->Margin = System::Windows::Forms::Padding(6);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(321, 92);
			this->loginBtn->TabIndex = 4;
			this->loginBtn->Text = L"Zaloguj siê";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &MainMenuControl::loginBtn_Click);
			// 
			// MainMenuControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->infoLabel);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->registerBtn);
			this->Controls->Add(this->loginBtn);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MainMenuControl";
			this->Size = System::Drawing::Size(1560, 910);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void registerBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

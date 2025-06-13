#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TicketManagerSystem {

	public ref class TicketForm : public System::Windows::Forms::UserControl
	{
	public:
		TicketForm(void)
		{
			InitializeComponent();
		}

	protected:
		~TicketForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::Label^ dateLabel;
	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::Label^ emailLabel;
	private: System::Windows::Forms::TextBox^ descriptionBox;
	private: System::Windows::Forms::Label^ numLabel;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown;
	private: System::Windows::Forms::Label^ categorylabel;
	private: System::Windows::Forms::ComboBox^ comboBox;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::Button^ cancelBtn;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->descriptionBox = (gcnew System::Windows::Forms::TextBox());
			this->numLabel = (gcnew System::Windows::Forms::Label());
			this->numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->categorylabel = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->titleLabel->Location = System::Drawing::Point(449, 95);
			this->titleLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(603, 64);
			this->titleLabel->TabIndex = 13;
			this->titleLabel->Text = L"Tworzenie wydarzenia";
			// 
			// addBtn
			// 
			this->addBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->addBtn->Location = System::Drawing::Point(246, 645);
			this->addBtn->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(280, 92);
			this->addBtn->TabIndex = 22;
			this->addBtn->Text = L"Stwórz";
			this->addBtn->UseVisualStyleBackColor = true;
			this->addBtn->Click += gcnew System::EventHandler(this, &TicketForm::addBtn_Click);
			// 
			// dateLabel
			// 
			this->dateLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateLabel->AutoSize = true;
			this->dateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->dateLabel->Location = System::Drawing::Point(798, 252);
			this->dateLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(189, 32);
			this->dateLabel->TabIndex = 16;
			this->dateLabel->Text = L"Odbêdzie siê:";
			// 
			// usernameBox
			// 
			this->usernameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->usernameBox->Location = System::Drawing::Point(246, 289);
			this->usernameBox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(501, 39);
			this->usernameBox->TabIndex = 18;
			// 
			// nameLabel
			// 
			this->nameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->nameLabel->Location = System::Drawing::Point(240, 252);
			this->nameLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(259, 32);
			this->nameLabel->TabIndex = 14;
			this->nameLabel->Text = L"Nazwa wydarzenia:";
			// 
			// emailLabel
			// 
			this->emailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->emailLabel->Location = System::Drawing::Point(240, 357);
			this->emailLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(81, 32);
			this->emailLabel->TabIndex = 15;
			this->emailLabel->Text = L"Opis:";
			// 
			// descriptionBox
			// 
			this->descriptionBox->AcceptsReturn = true;
			this->descriptionBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descriptionBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->descriptionBox->Location = System::Drawing::Point(246, 394);
			this->descriptionBox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->descriptionBox->Multiline = true;
			this->descriptionBox->Name = L"descriptionBox";
			this->descriptionBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->descriptionBox->Size = System::Drawing::Size(501, 200);
			this->descriptionBox->TabIndex = 23;
			// 
			// numLabel
			// 
			this->numLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numLabel->AutoSize = true;
			this->numLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->numLabel->Location = System::Drawing::Point(798, 457);
			this->numLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->numLabel->Name = L"numLabel";
			this->numLabel->Size = System::Drawing::Size(169, 32);
			this->numLabel->TabIndex = 25;
			this->numLabel->Text = L"Iloœæ biletów";
			// 
			// numericUpDown
			// 
			this->numericUpDown->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->numericUpDown->Location = System::Drawing::Point(803, 492);
			this->numericUpDown->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->numericUpDown->Name = L"numericUpDown";
			this->numericUpDown->Size = System::Drawing::Size(163, 34);
			this->numericUpDown->TabIndex = 26;
			this->numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// categorylabel
			// 
			this->categorylabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->categorylabel->AutoSize = true;
			this->categorylabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->categorylabel->Location = System::Drawing::Point(798, 357);
			this->categorylabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->categorylabel->Name = L"categorylabel";
			this->categorylabel->Size = System::Drawing::Size(296, 32);
			this->categorylabel->TabIndex = 27;
			this->categorylabel->Text = L"Kategoria wydarzenia:";
			// 
			// comboBox
			// 
			this->comboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"koncert", L"film", L"mecz" });
			this->comboBox->Location = System::Drawing::Point(803, 393);
			this->comboBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(340, 37);
			this->comboBox->TabIndex = 28;
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dateTimePicker->Location = System::Drawing::Point(803, 287);
			this->dateTimePicker->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(501, 34);
			this->dateTimePicker->TabIndex = 29;
			this->dateTimePicker->Value = System::DateTime(2025, 6, 28, 0, 0, 0, 0);
			// 
			// cancelBtn
			// 
			this->cancelBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->cancelBtn->Location = System::Drawing::Point(557, 645);
			this->cancelBtn->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(280, 92);
			this->cancelBtn->TabIndex = 30;
			this->cancelBtn->Text = L"Anuluj";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &TicketForm::cancelBtn_Click);
			// 
			// TicketForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->dateTimePicker);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->categorylabel);
			this->Controls->Add(this->numericUpDown);
			this->Controls->Add(this->numLabel);
			this->Controls->Add(this->descriptionBox);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->usernameBox);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->emailLabel);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"TicketForm";
			this->Size = System::Drawing::Size(1560, 910);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

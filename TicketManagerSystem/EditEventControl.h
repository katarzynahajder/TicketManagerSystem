#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TicketManagerSystem {

	public ref class EditEventControl : public System::Windows::Forms::UserControl
	{
	private: int eventId;
	public:
		EditEventControl(int eventId)
		{
			InitializeComponent();
			this->eventId = eventId;

		}

	protected:
		~EditEventControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ cancelBtn;
	private: System::Windows::Forms::DateTimePicker^ dateTimeBox;
	private: System::Windows::Forms::ComboBox^ categoryBox;




	private: System::Windows::Forms::Label^ categorylabel;
	private: System::Windows::Forms::NumericUpDown^ ticketCountBox;

	private: System::Windows::Forms::Label^ numLabel;
	private: System::Windows::Forms::TextBox^ descriptionBox;
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::Label^ dateLabel;
	private: System::Windows::Forms::TextBox^ titleBox;


	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::Label^ emailLabel;
	private:System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->dateTimeBox = (gcnew System::Windows::Forms::DateTimePicker());
			this->categoryBox = (gcnew System::Windows::Forms::ComboBox());
			this->categorylabel = (gcnew System::Windows::Forms::Label());
			this->ticketCountBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->numLabel = (gcnew System::Windows::Forms::Label());
			this->descriptionBox = (gcnew System::Windows::Forms::TextBox());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->titleBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ticketCountBox))->BeginInit();
			this->SuspendLayout();
			// 
			// cancelBtn
			// 
			this->cancelBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->cancelBtn->Location = System::Drawing::Point(289, 375);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(153, 50);
			this->cancelBtn->TabIndex = 43;
			this->cancelBtn->Text = L"Anuluj";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditEventControl::cancelBtn_Click);
			// 
			// dateTimeBox
			// 
			this->dateTimeBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateTimeBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dateTimeBox->Location = System::Drawing::Point(423, 181);
			this->dateTimeBox->Margin = System::Windows::Forms::Padding(2);
			this->dateTimeBox->Name = L"dateTimeBox";
			this->dateTimeBox->Size = System::Drawing::Size(275, 23);
			this->dateTimeBox->TabIndex = 42;
			this->dateTimeBox->Value = System::DateTime(2025, 6, 28, 0, 0, 0, 0);
			// 
			// categoryBox
			// 
			this->categoryBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->categoryBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->categoryBox->FormattingEnabled = true;
			this->categoryBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"koncert", L"film", L"mecz" });
			this->categoryBox->Location = System::Drawing::Point(423, 239);
			this->categoryBox->Margin = System::Windows::Forms::Padding(2);
			this->categoryBox->Name = L"categoryBox";
			this->categoryBox->Size = System::Drawing::Size(187, 24);
			this->categoryBox->TabIndex = 41;
			// 
			// categorylabel
			// 
			this->categorylabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->categorylabel->AutoSize = true;
			this->categorylabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->categorylabel->Location = System::Drawing::Point(420, 219);
			this->categorylabel->Name = L"categorylabel";
			this->categorylabel->Size = System::Drawing::Size(164, 20);
			this->categorylabel->TabIndex = 40;
			this->categorylabel->Text = L"Kategoria wydarzenia:";
			// 
			// ticketCountBox
			// 
			this->ticketCountBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ticketCountBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ticketCountBox->Location = System::Drawing::Point(423, 292);
			this->ticketCountBox->Margin = System::Windows::Forms::Padding(2);
			this->ticketCountBox->Name = L"ticketCountBox";
			this->ticketCountBox->Size = System::Drawing::Size(89, 23);
			this->ticketCountBox->TabIndex = 39;
			this->ticketCountBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numLabel
			// 
			this->numLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numLabel->AutoSize = true;
			this->numLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->numLabel->Location = System::Drawing::Point(420, 274);
			this->numLabel->Name = L"numLabel";
			this->numLabel->Size = System::Drawing::Size(95, 20);
			this->numLabel->TabIndex = 38;
			this->numLabel->Text = L"Iloœæ biletów";
			// 
			// descriptionBox
			// 
			this->descriptionBox->AcceptsReturn = true;
			this->descriptionBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descriptionBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->descriptionBox->Location = System::Drawing::Point(119, 239);
			this->descriptionBox->Multiline = true;
			this->descriptionBox->Name = L"descriptionBox";
			this->descriptionBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->descriptionBox->Size = System::Drawing::Size(275, 110);
			this->descriptionBox->TabIndex = 37;
			// 
			// titleLabel
			// 
			this->titleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->titleLabel->Location = System::Drawing::Point(230, 77);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(372, 37);
			this->titleLabel->TabIndex = 31;
			this->titleLabel->Text = L"Edytowanie wydarzenia";
			// 
			// addBtn
			// 
			this->addBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->addBtn->Location = System::Drawing::Point(119, 375);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(153, 50);
			this->addBtn->TabIndex = 36;
			this->addBtn->Text = L"Stwórz";
			this->addBtn->UseVisualStyleBackColor = true;
			this->addBtn->Click += gcnew System::EventHandler(this, &EditEventControl::addBtn_Click);
			// 
			// dateLabel
			// 
			this->dateLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateLabel->AutoSize = true;
			this->dateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->dateLabel->Location = System::Drawing::Point(420, 162);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(105, 20);
			this->dateLabel->TabIndex = 34;
			this->dateLabel->Text = L"Odbêdzie siê:";
			// 
			// titleBox
			// 
			this->titleBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titleBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->titleBox->Location = System::Drawing::Point(119, 183);
			this->titleBox->Name = L"titleBox";
			this->titleBox->Size = System::Drawing::Size(275, 26);
			this->titleBox->TabIndex = 35;
			// 
			// nameLabel
			// 
			this->nameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->nameLabel->Location = System::Drawing::Point(116, 162);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(144, 20);
			this->nameLabel->TabIndex = 32;
			this->nameLabel->Text = L"Nazwa wydarzenia:";
			// 
			// emailLabel
			// 
			this->emailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->emailLabel->Location = System::Drawing::Point(116, 219);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(45, 20);
			this->emailLabel->TabIndex = 33;
			this->emailLabel->Text = L"Opis:";
			// 
			// EditEventControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->dateTimeBox);
			this->Controls->Add(this->categoryBox);
			this->Controls->Add(this->categorylabel);
			this->Controls->Add(this->ticketCountBox);
			this->Controls->Add(this->numLabel);
			this->Controls->Add(this->descriptionBox);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->titleBox);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->emailLabel);
			this->Name = L"EditEventControl";
			this->Size = System::Drawing::Size(814, 503);
			this->Load += gcnew System::EventHandler(this, &EditEventControl::EditEventControl_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ticketCountBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditEventControl_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

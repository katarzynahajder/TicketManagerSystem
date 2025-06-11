#pragma once

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
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->addTicketBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// addTicketBtn
			// 
			this->addTicketBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addTicketBtn->Location = System::Drawing::Point(20, 20);
			this->addTicketBtn->Name = L"addTicketBtn";
			this->addTicketBtn->Size = System::Drawing::Size(243, 112);
			this->addTicketBtn->TabIndex = 1;
			this->addTicketBtn->Text = L"Dodaj nowy bilet";
			this->addTicketBtn->UseVisualStyleBackColor = true;
			this->addTicketBtn->Click += gcnew System::EventHandler(this, &UserProfile::addTicketBtn_Click);
			// 
			// UserProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->addTicketBtn);
			this->Name = L"UserProfile";
			this->Size = System::Drawing::Size(1560, 910);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void addTicketBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
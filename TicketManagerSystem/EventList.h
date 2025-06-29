#pragma once
#include "EventItem.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

// ==============================================
// Plik zawiera deklaracjê klasy EventList – kontrolki wyœwietlaj¹cej listê wydarzeñ.
// Umo¿liwia u¿ytkownikowi rezerwacjê oraz przegl¹d wydarzeñ.
// ==============================================

namespace TicketManagerSystem {

	public ref class EventList : public System::Windows::Forms::UserControl
	{
	public:
		EventList(void)
		{
			InitializeComponent();
			this->loadEventList();
		}

	protected:
		~EventList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ userBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ ticketListPanel;
	private: System::Windows::Forms::Button^ logoutBtn;
	private: System::Windows::Forms::Label^ label;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->userBtn = (gcnew System::Windows::Forms::Button());
			this->ticketListPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// userBtn
			// 
			this->userBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->userBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->userBtn->Location = System::Drawing::Point(705, 11);
			this->userBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->userBtn->Name = L"userBtn";
			this->userBtn->Size = System::Drawing::Size(133, 58);
			this->userBtn->TabIndex = 0;
			this->userBtn->Text = L"Moje konto";
			this->userBtn->UseVisualStyleBackColor = true;
			this->userBtn->Click += gcnew System::EventHandler(this, &EventList::userBtn_Click);
			// 
			// ticketListPanel
			// 
			this->ticketListPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ticketListPanel->AutoScroll = true;
			this->ticketListPanel->BackColor = System::Drawing::Color::White;
			this->ticketListPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->ticketListPanel->Location = System::Drawing::Point(0, 81);
			this->ticketListPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ticketListPanel->Name = L"ticketListPanel";
			this->ticketListPanel->Size = System::Drawing::Size(851, 411);
			this->ticketListPanel->TabIndex = 0;
			this->ticketListPanel->WrapContents = false;
			// 
			// logoutBtn
			// 
			this->logoutBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->logoutBtn->Location = System::Drawing::Point(11, 11);
			this->logoutBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(133, 58);
			this->logoutBtn->TabIndex = 1;
			this->logoutBtn->Text = L"Wyloguj siê";
			this->logoutBtn->UseVisualStyleBackColor = true;
			this->logoutBtn->Click += gcnew System::EventHandler(this, &EventList::logoutBtn_Click);
			// 
			// label
			// 
			this->label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label->Location = System::Drawing::Point(310, 17);
			this->label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(186, 37);
			this->label->TabIndex = 2;
			this->label->Text = L"Wydarzenia";
			// 
			// Events
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label);
			this->Controls->Add(this->logoutBtn);
			this->Controls->Add(this->ticketListPanel);
			this->Controls->Add(this->userBtn);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Tickets";
			this->Size = System::Drawing::Size(851, 493);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void userBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void loadEventList();
	private: System::Void logoutBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

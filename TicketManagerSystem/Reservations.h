#pragma once

#include "ReservationItem.h"
#include "Session.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

// ==============================================
// Klasa odpowiada za wyœwietlanie zarezerwowanych wydarzeñ.
// Dzia³a dynamicznie: dla admina wyœwietla wszystkie rezerwacje, a dla u¿ytkownika tylko jego.
// ==============================================

namespace TicketManagerSystem {

	public ref class Reservations : public System::Windows::Forms::UserControl
	{
	public:
		Reservations(void)
		{
			InitializeComponent();
			this->LoadReservations();
		}

	protected:
		~Reservations()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ reservationListPanel;
	private: System::Windows::Forms::Label^ label;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->backBtn = (gcnew System::Windows::Forms::Button());
			   this->reservationListPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->label = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // backBtn
			   // 
			   this->backBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->backBtn->Location = System::Drawing::Point(1292, 20);
			   this->backBtn->Name = L"backBtn";
			   this->backBtn->Size = System::Drawing::Size(244, 107);
			   this->backBtn->TabIndex = 0;
			   this->backBtn->Text = L"Powrót";
			   this->backBtn->UseVisualStyleBackColor = true;
			   this->backBtn->Click += gcnew System::EventHandler(this, &Reservations::backBtn_Click);
			   // 
			   // reservationListPanel
			   // 
			   this->reservationListPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->reservationListPanel->AutoScroll = true;
			   this->reservationListPanel->BackColor = System::Drawing::Color::White;
			   this->reservationListPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			   this->reservationListPanel->Location = System::Drawing::Point(0, 150);
			   this->reservationListPanel->Name = L"reservationListPanel";
			   this->reservationListPanel->Size = System::Drawing::Size(1560, 759);
			   this->reservationListPanel->TabIndex = 1;
			   this->reservationListPanel->WrapContents = false;
			   // 
			   // label
			   // 
			   this->label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->label->AutoSize = true;
			   this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24));
			   this->label->Name = L"label";
			   this->label->Size = System::Drawing::Size(332, 64);
			   this->label->TabIndex = 2;
			   if (Session::Username == "admin") {
				   this->label->Location = System::Drawing::Point(600, 31);
				   this->label->Text = L"Rezerwacje";
			   }
			   else {
				   this->label->Location = System::Drawing::Point(550, 31);
				   this->label->Text = L"Moje rezerwacje";
			   }
			   // 
			   // Reservations
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->Controls->Add(this->label);
			   this->Controls->Add(this->reservationListPanel);
			   this->Controls->Add(this->backBtn);
			   this->Name = L"Reservations";
			   this->Size = System::Drawing::Size(1560, 910);
			   this->ResumeLayout(false);
			   this->PerformLayout();
		   }
#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LoadReservations();
	};
}

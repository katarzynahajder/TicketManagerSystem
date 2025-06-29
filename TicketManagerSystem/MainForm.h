#include "MainMenuControl.h"
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

// ==============================================
// G³ówne okno systemu zarz¹dzania biletami.
// ==============================================

namespace TicketManagerSystem {

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		static MainForm^ Instance;

		MainForm(void)
		{
			InitializeComponent();
			Instance = this;
			loadControl(gcnew MainMenuControl());
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->SuspendLayout();
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->ClientSize = System::Drawing::Size(1141, 636);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1165, 700);
			this->MinimumSize = System::Drawing::Size(1165, 700);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ticket Manager System";
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void loadControl(System::Windows::Forms::UserControl^ control);
	};
}

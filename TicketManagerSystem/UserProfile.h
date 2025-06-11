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

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// UserProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Name = L"UserProfile";
			this->Size = System::Drawing::Size(1560, 910);
			this->ResumeLayout(false);

		}

#pragma endregion

	};
}
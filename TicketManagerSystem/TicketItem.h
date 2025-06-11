#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace TicketManagerSystem {

	public ref class TicketItem : public UserControl {
	public:
		TicketItem(String^ title, String^ description, DateTime date, int count, String^ category);

	private:
		Label^ titleLabel;
		Label^ dateLabel;
		Label^ descriptionLabel;
		Label^ countLabel;
		Label^ categoryLabel;
	};
}
#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace TicketManagerSystem {

	public ref class TicketItem : public UserControl {
	public:
		TicketItem(int id, String^ title, String^ description, DateTime date, int count, String^ category);

	private:
		Label^ titleLabel;
		Label^ dateLabel;
		Label^ descriptionLabel;
		Label^ countLabel;
		Label^ categoryLabel;
		Label^ adminLabel;
		Button^ reserveBtn;
		Button^ editEventBtn;
		Button^ removeEventBtn;
		int ticketId;

	private: System::Void reserveBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: Void editEventBtn_Click(Object^ sender, EventArgs^ e);
	private: Void removeEventBtn_Click(Object^ sender, EventArgs^ e);
	};
}
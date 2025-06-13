#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace TicketManagerSystem {

	public ref class ReservationItem : public UserControl {
	public:
		ReservationItem(int ticketId, String^ username, String^ title, String^ description, DateTime date, String^ category);

	private:
		Label^ titleLabel;
		Label^ dateLabel;
		Label^ descriptionLabel;
		Label^ categoryLabel;
		Label^ usernameLabel;
		Button^ cancelBtn;
		int ticketId;
		String^ username;

	private: Void cancelBtn_Click(Object^ sender, EventArgs^ e);
	};
}

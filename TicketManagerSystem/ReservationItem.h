#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace TicketManagerSystem {

	public ref class ReservationItem : public UserControl {
	public:
		ReservationItem(String^ username, String^ title, String^ description, DateTime date, String^ category);

	private:
		Label^ titleLabel;
		Label^ dateLabel;
		Label^ descriptionLabel;
		Label^ categoryLabel;
		Label^ usernameLabel;
	};
}

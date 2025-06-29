#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

// ==============================================
// Reprezentacja graficzna pojedynczego wydarzenia.
// Zawiera dane: tytu³, opis, data, kategoria, liczba miejsc.
// Umo¿liwia wykonanie rezerwacji (jeœli nie zosta³o to wczeœniej zrobione).
// ==============================================

namespace TicketManagerSystem {

	public ref class EventItem : public UserControl {
	public:
		EventItem(int id, String^ title, String^ description, DateTime date, int count, String^ category);

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
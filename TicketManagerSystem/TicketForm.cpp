#include "TicketForm.h"

using namespace TicketManagerSystem;

Void TicketForm::addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("Dodano bilet.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
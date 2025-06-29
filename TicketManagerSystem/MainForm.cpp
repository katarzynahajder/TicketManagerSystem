#include <iostream>
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace TicketManagerSystem;

[STAThreadAttribute]

// ==============================================
// G³ówna forma aplikacji odpowiedzialna za dynamiczne prze³¹czanie kontrolek (np. logowanie, wydarzenia, profil).
// ==============================================

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TicketManagerSystem::MainForm form;
	Application::Run(% form);
}

// za³adowanie kontrolki do g³ównej formy - czszczenie kontrolek i dodanie nowej kontrolki
void MainForm::loadControl(System::Windows::Forms::UserControl^ control) {
	this->Controls->Clear();
	control->Dock = System::Windows::Forms::DockStyle::Fill;
	this->Controls->Add(control);
}
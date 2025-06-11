#include <iostream>
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace TicketManagerSystem;

[STAThreadAttribute]

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TicketManagerSystem::MainForm form;
	Application::Run(% form);
}

void MainForm::loadControl(System::Windows::Forms::UserControl^ control) {
	this->Controls->Clear();
	control->Dock = System::Windows::Forms::DockStyle::Fill;
	this->Controls->Add(control);
}
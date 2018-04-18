#include "PantallaDeJuego.h"
using namespace System;
using namespace System ::Windows::Forms;
[STAThread]
void main(array<String^>^ arg) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   //TestForma es el nombre del proyecto
   Tetris::PantallaDeJuego form;
   Application::Run(%form);
}


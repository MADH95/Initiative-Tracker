/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "InitiativeWindow.h"

using namespace System;
using namespace System::Windows::Forms;

//Attribute designating a single threed application
[STAThreadAttribute]

/// <summary>
/// Entry point for application
/// </summary>
/// <param name="args"></param>
void main(array<String^>^ args)
{
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    InitiativeTracker::InitiativeWindow initiativeWindow;
    Application::Run(% initiativeWindow);
}
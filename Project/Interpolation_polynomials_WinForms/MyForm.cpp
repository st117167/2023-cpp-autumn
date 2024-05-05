#include "MyForm.h"
#include "Header.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <msclr/marshal_cppstd.h>


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project::MyForm form;
	Application::Run(% form);
}

//lagrange
System::Void Project::MyForm::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string str1 = msclr::interop::marshal_as<std::string>(arguments->Text);
	std::string str2 = msclr::interop::marshal_as<std::string>(values->Text);

	std::vector<float> x, y;

	convert(str1, x);
	convert(str2, y);

	std::string result = lagrangePolynomial(x, y);

	this->function->Text = gcnew String(result.c_str());

	return System::Void();
}

//newton
System::Void Project::MyForm::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string str1 = msclr::interop::marshal_as<std::string>(arguments->Text);
	std::string str2 = msclr::interop::marshal_as<std::string>(values->Text);

	std::vector<float> x, y;

	convert(str1, x);
	convert(str2, y);

	std::string result = newtonPolynomial(x, y);

	this->function->Text = gcnew String(result.c_str());

	return System::Void();
}


System::Void Project::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}


System::Void Project::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}


System::Void Project::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}


System::Void Project::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}


System::Void Project::MyForm::create_chart_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string str1 = msclr::interop::marshal_as<std::string>(arguments->Text);
	std::string str2 = msclr::interop::marshal_as<std::string>(values->Text);

	std::vector<float> x, y;

	convert(str1, x);
	convert(str2, y);

	this->chart1->Series[0]->Points->Clear();
	for (int argumentX = -10; argumentX <= 10; argumentX++)
	{
		this->chart1->Series[0]->Points->AddXY(argumentX, search(x, y, argumentX));
	}

	return System::Void();
}


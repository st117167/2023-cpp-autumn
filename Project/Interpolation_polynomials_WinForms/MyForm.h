#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		
		MyForm(void) { InitializeComponent(); }
	
	protected:
	
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
	
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Label^ function;
		System::Windows::Forms::GroupBox^ groupBox3;
		System::Windows::Forms::TextBox^ values;
		System::Windows::Forms::TextBox^ arguments;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::RadioButton^ radioButton_lagrange;
		System::Windows::Forms::RadioButton^ radioButton_newton;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Button^ create_chart;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->create_chart = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->function = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->radioButton_newton = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_lagrange = (gcnew System::Windows::Forms::RadioButton());
			this->values = (gcnew System::Windows::Forms::TextBox());
			this->arguments = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->create_chart);
			this->groupBox1->Controls->Add(this->chart1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(24, 155);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(669, 485);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Chart";
			// 
			// create_chart
			// 
			this->create_chart->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->create_chart->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->create_chart->Location = System::Drawing::Point(529, 319);
			this->create_chart->Name = L"create_chart";
			this->create_chart->Size = System::Drawing::Size(94, 99);
			this->create_chart->TabIndex = 1;
			this->create_chart->Text = L"Create chart";
			this->create_chart->UseVisualStyleBackColor = false;
			this->create_chart->Click += gcnew System::EventHandler(this, &MyForm::create_chart_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(3, 26);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->EmptyPointStyle->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDotDot;
			series1->EmptyPointStyle->BorderWidth = 7;
			series1->EmptyPointStyle->Color = System::Drawing::Color::Khaki;
			series1->Legend = L"Legend1";
			series1->MarkerSize = 7;
			series1->Name = L"Series1";
			series1->XValueMember = L"x";
			series1->YValueMembers = L"y";
			series1->YValuesPerPoint = 6;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Single;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(646, 448);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// function
			// 
			this->function->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->function->Location = System::Drawing::Point(21, 9);
			this->function->Name = L"function";
			this->function->Size = System::Drawing::Size(1242, 143);
			this->function->TabIndex = 2;
			this->function->Text = L"F(x) = ";
			this->function->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->radioButton_newton);
			this->groupBox3->Controls->Add(this->radioButton_lagrange);
			this->groupBox3->Controls->Add(this->values);
			this->groupBox3->Controls->Add(this->arguments);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(699, 155);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(436, 485);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Parameters";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(57, 298);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(327, 25);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Which polynomials do you want\?";
			// 
			// radioButton_newton
			// 
			this->radioButton_newton->AutoSize = true;
			this->radioButton_newton->Location = System::Drawing::Point(11, 354);
			this->radioButton_newton->Name = L"radioButton_newton";
			this->radioButton_newton->Size = System::Drawing::Size(105, 29);
			this->radioButton_newton->TabIndex = 7;
			this->radioButton_newton->TabStop = true;
			this->radioButton_newton->Text = L"Newton";
			this->radioButton_newton->UseVisualStyleBackColor = true;
			this->radioButton_newton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton_lagrange
			// 
			this->radioButton_lagrange->AutoSize = true;
			this->radioButton_lagrange->Location = System::Drawing::Point(231, 354);
			this->radioButton_lagrange->Name = L"radioButton_lagrange";
			this->radioButton_lagrange->Size = System::Drawing::Size(124, 29);
			this->radioButton_lagrange->TabIndex = 4;
			this->radioButton_lagrange->TabStop = true;
			this->radioButton_lagrange->Text = L"Lagrange";
			this->radioButton_lagrange->UseVisualStyleBackColor = true;
			this->radioButton_lagrange->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// values
			// 
			this->values->Location = System::Drawing::Point(6, 232);
			this->values->Name = L"values";
			this->values->Size = System::Drawing::Size(384, 30);
			this->values->TabIndex = 5;
			this->values->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// arguments
			// 
			this->arguments->Location = System::Drawing::Point(6, 130);
			this->arguments->Name = L"arguments";
			this->arguments->Size = System::Drawing::Size(384, 30);
			this->arguments->TabIndex = 4;
			this->arguments->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 204);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(236, 25);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Function Values( F(x) )";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 102);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 25);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Arguments( x )";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(81, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(232, 35);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Enter their coordinates";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1275, 666);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->function);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Calculate";
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void create_chart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

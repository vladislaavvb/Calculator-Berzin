#pragma once
#include <cmath>
#include <string>
#include <algorithm>

namespace КалькуляторБерзін {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->updateMemoryIndicator();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Label^ result_label;
	private: System::Windows::Forms::Button^ button_ac;
	private: System::Windows::Forms::Button^ button_minusplus;
	private: System::Windows::Forms::Button^ button_percent;
	private: System::Windows::Forms::Button^ button_divide;
	private: System::Windows::Forms::Button^ button_multi;
	private: System::Windows::Forms::Button^ button_9;
	private: System::Windows::Forms::Button^ button_8;
	private: System::Windows::Forms::Button^ button_7;
	private: System::Windows::Forms::Button^ button_subtr;
	private: System::Windows::Forms::Button^ button_6;
	private: System::Windows::Forms::Button^ button_5;
	private: System::Windows::Forms::Button^ button_4;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_3;
	private: System::Windows::Forms::Button^ button_2;
	private: System::Windows::Forms::Button^ button_1;
	private: System::Windows::Forms::Button^ button_equal;
	private: System::Windows::Forms::Button^ button_dot;
	private: System::Windows::Forms::Button^ button_0;
	private: double first_num;
	private: char user_action = ' ';
	private: bool is_equal = false;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ sqrt_button;
	private: System::Windows::Forms::Button^ button_factorial;
	private: System::Windows::Forms::Button^ button_sin;
	private: System::Windows::Forms::Button^ button_cos;
	private: System::Windows::Forms::Button^ button_int;
	private: System::Windows::Forms::Button^ button_mem_plus;
	private: System::Windows::Forms::Button^ button_mem_minus;
	private: System::Windows::Forms::Button^ button_mem_recall;
	private: System::Windows::Forms::Button^ button_mem_clear;
	private: System::Windows::Forms::Label^ memory_label;
	private: double memory = 0.0;

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->result_label = (gcnew System::Windows::Forms::Label());
			this->button_ac = (gcnew System::Windows::Forms::Button());
			this->button_minusplus = (gcnew System::Windows::Forms::Button());
			this->button_percent = (gcnew System::Windows::Forms::Button());
			this->button_divide = (gcnew System::Windows::Forms::Button());
			this->button_multi = (gcnew System::Windows::Forms::Button());
			this->button_9 = (gcnew System::Windows::Forms::Button());
			this->button_8 = (gcnew System::Windows::Forms::Button());
			this->button_7 = (gcnew System::Windows::Forms::Button());
			this->button_subtr = (gcnew System::Windows::Forms::Button());
			this->button_6 = (gcnew System::Windows::Forms::Button());
			this->button_5 = (gcnew System::Windows::Forms::Button());
			this->button_4 = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_3 = (gcnew System::Windows::Forms::Button());
			this->button_2 = (gcnew System::Windows::Forms::Button());
			this->button_1 = (gcnew System::Windows::Forms::Button());
			this->button_equal = (gcnew System::Windows::Forms::Button());
			this->button_dot = (gcnew System::Windows::Forms::Button());
			this->button_0 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sqrt_button = (gcnew System::Windows::Forms::Button());
			this->button_factorial = (gcnew System::Windows::Forms::Button());
			this->button_sin = (gcnew System::Windows::Forms::Button());
			this->button_cos = (gcnew System::Windows::Forms::Button());
			this->button_int = (gcnew System::Windows::Forms::Button());
			this->button_mem_plus = (gcnew System::Windows::Forms::Button());
			this->button_mem_minus = (gcnew System::Windows::Forms::Button());
			this->button_mem_recall = (gcnew System::Windows::Forms::Button());
			this->button_mem_clear = (gcnew System::Windows::Forms::Button());
			this->memory_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 18, System::Drawing::FontStyle::Bold));
			this->button_exit->ForeColor = System::Drawing::Color::White;
			this->button_exit->Location = System::Drawing::Point(12, 12);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(36, 35);
			this->button_exit->TabIndex = 0;
			this->button_exit->Text = L"X";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::button_exit_Click);
			// 
			// result_label
			// 
			this->result_label->Font = (gcnew System::Drawing::Font(L"Gadugi", 36, System::Drawing::FontStyle::Bold));
			this->result_label->Location = System::Drawing::Point(87, 84);
			this->result_label->Name = L"result_label";
			this->result_label->Size = System::Drawing::Size(330, 66);
			this->result_label->TabIndex = 1;
			this->result_label->Text = L"0";
			this->result_label->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->result_label->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_ac
			// 
			this->button_ac->BackColor = System::Drawing::Color::Silver;
			this->button_ac->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_ac->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_ac->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->button_ac->Location = System::Drawing::Point(24, 172);
			this->button_ac->Name = L"button_ac";
			this->button_ac->Size = System::Drawing::Size(72, 65);
			this->button_ac->TabIndex = 2;
			this->button_ac->Text = L"AC";
			this->button_ac->UseVisualStyleBackColor = false;
			this->button_ac->Click += gcnew System::EventHandler(this, &MyForm::button_ac_Click);
			// 
			// button_minusplus
			// 
			this->button_minusplus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_minusplus->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_minusplus->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_minusplus->Location = System::Drawing::Point(102, 172);
			this->button_minusplus->Name = L"button_minusplus";
			this->button_minusplus->Size = System::Drawing::Size(72, 65);
			this->button_minusplus->TabIndex = 3;
			this->button_minusplus->Text = L"+/-";
			this->button_minusplus->UseVisualStyleBackColor = false;
			this->button_minusplus->Click += gcnew System::EventHandler(this, &MyForm::button_minusplus_Click);
			// 
			// button_percent
			// 
			this->button_percent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_percent->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_percent->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_percent->Location = System::Drawing::Point(180, 172);
			this->button_percent->Name = L"button_percent";
			this->button_percent->Size = System::Drawing::Size(72, 65);
			this->button_percent->TabIndex = 4;
			this->button_percent->Text = L"%";
			this->button_percent->UseVisualStyleBackColor = false;
			this->button_percent->Click += gcnew System::EventHandler(this, &MyForm::button_percent_Click);
			// 
			// button_divide
			// 
			this->button_divide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_divide->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_divide->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_divide->Location = System::Drawing::Point(258, 172);
			this->button_divide->Name = L"button_divide";
			this->button_divide->Size = System::Drawing::Size(72, 65);
			this->button_divide->TabIndex = 5;
			this->button_divide->Text = L"/";
			this->button_divide->UseVisualStyleBackColor = false;
			this->button_divide->Click += gcnew System::EventHandler(this, &MyForm::button_divide_Click);
			// 
			// button_multi
			// 
			this->button_multi->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_multi->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_multi->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_multi->Location = System::Drawing::Point(258, 243);
			this->button_multi->Name = L"button_multi";
			this->button_multi->Size = System::Drawing::Size(72, 65);
			this->button_multi->TabIndex = 9;
			this->button_multi->Text = L"*";
			this->button_multi->UseVisualStyleBackColor = false;
			this->button_multi->Click += gcnew System::EventHandler(this, &MyForm::button_multi_Click);
			// 
			// button_9
			// 
			this->button_9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_9->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_9->Location = System::Drawing::Point(180, 243);
			this->button_9->Name = L"button_9";
			this->button_9->Size = System::Drawing::Size(72, 65);
			this->button_9->TabIndex = 8;
			this->button_9->Text = L"9";
			this->button_9->UseVisualStyleBackColor = false;
			this->button_9->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_8
			// 
			this->button_8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_8->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_8->Location = System::Drawing::Point(102, 243);
			this->button_8->Name = L"button_8";
			this->button_8->Size = System::Drawing::Size(72, 65);
			this->button_8->TabIndex = 7;
			this->button_8->Text = L"8";
			this->button_8->UseVisualStyleBackColor = false;
			this->button_8->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_7
			// 
			this->button_7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_7->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_7->Location = System::Drawing::Point(24, 243);
			this->button_7->Name = L"button_7";
			this->button_7->Size = System::Drawing::Size(72, 65);
			this->button_7->TabIndex = 6;
			this->button_7->Text = L"7";
			this->button_7->UseVisualStyleBackColor = false;
			this->button_7->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_subtr
			// 
			this->button_subtr->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_subtr->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_subtr->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_subtr->Location = System::Drawing::Point(258, 314);
			this->button_subtr->Name = L"button_subtr";
			this->button_subtr->Size = System::Drawing::Size(72, 65);
			this->button_subtr->TabIndex = 13;
			this->button_subtr->Text = L"-";
			this->button_subtr->UseVisualStyleBackColor = false;
			this->button_subtr->Click += gcnew System::EventHandler(this, &MyForm::button_subtr_Click);
			// 
			// button_6
			// 
			this->button_6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_6->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_6->Location = System::Drawing::Point(180, 314);
			this->button_6->Name = L"button_6";
			this->button_6->Size = System::Drawing::Size(72, 65);
			this->button_6->TabIndex = 12;
			this->button_6->Text = L"6";
			this->button_6->UseVisualStyleBackColor = false;
			this->button_6->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_5
			// 
			this->button_5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_5->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_5->Location = System::Drawing::Point(102, 314);
			this->button_5->Name = L"button_5";
			this->button_5->Size = System::Drawing::Size(72, 65);
			this->button_5->TabIndex = 11;
			this->button_5->Text = L"5";
			this->button_5->UseVisualStyleBackColor = false;
			this->button_5->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_4
			// 
			this->button_4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_4->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_4->Location = System::Drawing::Point(24, 314);
			this->button_4->Name = L"button_4";
			this->button_4->Size = System::Drawing::Size(72, 65);
			this->button_4->TabIndex = 10;
			this->button_4->Text = L"4";
			this->button_4->UseVisualStyleBackColor = false;
			this->button_4->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_add
			// 
			this->button_add->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_add->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_add->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_add->Location = System::Drawing::Point(258, 385);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(72, 65);
			this->button_add->TabIndex = 17;
			this->button_add->Text = L"+";
			this->button_add->UseVisualStyleBackColor = false;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_3
			// 
			this->button_3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_3->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_3->Location = System::Drawing::Point(180, 385);
			this->button_3->Name = L"button_3";
			this->button_3->Size = System::Drawing::Size(72, 65);
			this->button_3->TabIndex = 16;
			this->button_3->Text = L"3";
			this->button_3->UseVisualStyleBackColor = false;
			this->button_3->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_2
			// 
			this->button_2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_2->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_2->Location = System::Drawing::Point(102, 385);
			this->button_2->Name = L"button_2";
			this->button_2->Size = System::Drawing::Size(72, 65);
			this->button_2->TabIndex = 15;
			this->button_2->Text = L"2";
			this->button_2->UseVisualStyleBackColor = false;
			this->button_2->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_1
			// 
			this->button_1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_1->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_1->Location = System::Drawing::Point(24, 385);
			this->button_1->Name = L"button_1";
			this->button_1->Size = System::Drawing::Size(72, 65);
			this->button_1->TabIndex = 14;
			this->button_1->Text = L"1";
			this->button_1->UseVisualStyleBackColor = false;
			this->button_1->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// button_equal
			// 
			this->button_equal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_equal->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_equal->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_equal->Location = System::Drawing::Point(258, 456);
			this->button_equal->Name = L"button_equal";
			this->button_equal->Size = System::Drawing::Size(72, 65);
			this->button_equal->TabIndex = 21;
			this->button_equal->Text = L"=";
			this->button_equal->UseVisualStyleBackColor = false;
			this->button_equal->Click += gcnew System::EventHandler(this, &MyForm::button_equal_Click);
			// 
			// button_dot
			// 
			this->button_dot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_dot->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_dot->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_dot->Location = System::Drawing::Point(180, 456);
			this->button_dot->Name = L"button_dot";
			this->button_dot->Size = System::Drawing::Size(72, 65);
			this->button_dot->TabIndex = 20;
			this->button_dot->Text = L".";
			this->button_dot->UseVisualStyleBackColor = false;
			this->button_dot->Click += gcnew System::EventHandler(this, &MyForm::button_dot_Click);
			// 
			// button_0
			// 
			this->button_0->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_0->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_0->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_0->Location = System::Drawing::Point(24, 456);
			this->button_0->Name = L"button_0";
			this->button_0->Size = System::Drawing::Size(150, 65);
			this->button_0->TabIndex = 18;
			this->button_0->Text = L"0";
			this->button_0->UseVisualStyleBackColor = false;
			this->button_0->Click += gcnew System::EventHandler(this, &MyForm::button_number_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(19, 126);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(589, 43);
			this->label1->TabIndex = 22;
			this->label1->Text = L"______________________________________";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// sqrt_button
			// 
			this->sqrt_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->sqrt_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sqrt_button->Font = (gcnew System::Drawing::Font(L"Gadugi", 16, System::Drawing::FontStyle::Bold));
			this->sqrt_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->sqrt_button->Location = System::Drawing::Point(336, 172);
			this->sqrt_button->Name = L"sqrt_button";
			this->sqrt_button->Size = System::Drawing::Size(72, 65);
			this->sqrt_button->TabIndex = 23;
			this->sqrt_button->Text = L"sqrt";
			this->sqrt_button->UseVisualStyleBackColor = false;
			this->sqrt_button->Click += gcnew System::EventHandler(this, &MyForm::sqrt_button_Click);
			// 
			// button_factorial
			// 
			this->button_factorial->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_factorial->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_factorial->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_factorial->Location = System::Drawing::Point(336, 243);
			this->button_factorial->Name = L"button_factorial";
			this->button_factorial->Size = System::Drawing::Size(72, 65);
			this->button_factorial->TabIndex = 24;
			this->button_factorial->Text = L"x!";
			this->button_factorial->UseVisualStyleBackColor = false;
			this->button_factorial->Click += gcnew System::EventHandler(this, &MyForm::button_factorial_Click);
			// 
			// button_sin
			// 
			this->button_sin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_sin->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_sin->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_sin->Location = System::Drawing::Point(336, 314);
			this->button_sin->Name = L"button_sin";
			this->button_sin->Size = System::Drawing::Size(72, 65);
			this->button_sin->TabIndex = 25;
			this->button_sin->Text = L"sin";
			this->button_sin->UseVisualStyleBackColor = false;
			this->button_sin->Click += gcnew System::EventHandler(this, &MyForm::button_sin_Click);
			// 
			// button_cos
			// 
			this->button_cos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_cos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_cos->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_cos->Location = System::Drawing::Point(336, 385);
			this->button_cos->Name = L"button_cos";
			this->button_cos->Size = System::Drawing::Size(72, 65);
			this->button_cos->TabIndex = 26;
			this->button_cos->Text = L"cos";
			this->button_cos->UseVisualStyleBackColor = false;
			this->button_cos->Click += gcnew System::EventHandler(this, &MyForm::button_cos_Click);
			// 
			// button_int
			// 
			this->button_int->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_int->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_int->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->button_int->Location = System::Drawing::Point(336, 456);
			this->button_int->Name = L"button_int";
			this->button_int->Size = System::Drawing::Size(72, 65);
			this->button_int->TabIndex = 27;
			this->button_int->Text = L"INT";
			this->button_int->UseVisualStyleBackColor = false;
			this->button_int->Click += gcnew System::EventHandler(this, &MyForm::button_int_Click);
			// 
			// button_mem_plus
			// 
			this->button_mem_plus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_mem_plus->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_mem_plus->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_mem_plus->Location = System::Drawing::Point(414, 172);
			this->button_mem_plus->Name = L"button_mem_plus";
			this->button_mem_plus->Size = System::Drawing::Size(72, 65);
			this->button_mem_plus->TabIndex = 29;
			this->button_mem_plus->Text = L"M+";
			this->button_mem_plus->UseVisualStyleBackColor = false;
			this->button_mem_plus->Click += gcnew System::EventHandler(this, &MyForm::button_mem_plus_Click);
			// 
			// button_mem_minus
			// 
			this->button_mem_minus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_mem_minus->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_mem_minus->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_mem_minus->Location = System::Drawing::Point(414, 243);
			this->button_mem_minus->Name = L"button_mem_minus";
			this->button_mem_minus->Size = System::Drawing::Size(72, 65);
			this->button_mem_minus->TabIndex = 30;
			this->button_mem_minus->Text = L"M-";
			this->button_mem_minus->UseVisualStyleBackColor = false;
			this->button_mem_minus->Click += gcnew System::EventHandler(this, &MyForm::button_mem_minus_Click);
			// 
			// button_mem_recall
			// 
			this->button_mem_recall->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_mem_recall->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_mem_recall->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_mem_recall->Location = System::Drawing::Point(414, 385);
			this->button_mem_recall->Name = L"button_mem_recall";
			this->button_mem_recall->Size = System::Drawing::Size(72, 65);
			this->button_mem_recall->TabIndex = 31;
			this->button_mem_recall->Text = L"MR";
			this->button_mem_recall->UseVisualStyleBackColor = false;
			this->button_mem_recall->Click += gcnew System::EventHandler(this, &MyForm::button_mem_recall_Click);
			// 
			// button_mem_clear
			// 
			this->button_mem_clear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button_mem_clear->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_mem_clear->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_mem_clear->Location = System::Drawing::Point(414, 315);
			this->button_mem_clear->Name = L"button_mem_clear";
			this->button_mem_clear->Size = System::Drawing::Size(72, 64);
			this->button_mem_clear->TabIndex = 32;
			this->button_mem_clear->Text = L"MC";
			this->button_mem_clear->UseVisualStyleBackColor = false;
			this->button_mem_clear->Click += gcnew System::EventHandler(this, &MyForm::button_mem_clear_Click);
			// 
			// memory_label
			// 
			this->memory_label->AutoSize = true;
			this->memory_label->Font = (gcnew System::Drawing::Font(L"Gadugi", 18, System::Drawing::FontStyle::Bold));
			this->memory_label->Location = System::Drawing::Point(348, 56);
			this->memory_label->Name = L"memory_label";
			this->memory_label->Size = System::Drawing::Size(0, 43);
			this->memory_label->TabIndex = 28;
			this->memory_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->ClientSize = System::Drawing::Size(508, 544);
			this->Controls->Add(this->button_mem_clear);
			this->Controls->Add(this->button_mem_recall);
			this->Controls->Add(this->button_mem_minus);
			this->Controls->Add(this->button_mem_plus);
			this->Controls->Add(this->memory_label);
			this->Controls->Add(this->button_int);
			this->Controls->Add(this->button_cos);
			this->Controls->Add(this->button_sin);
			this->Controls->Add(this->button_factorial);
			this->Controls->Add(this->sqrt_button);
			this->Controls->Add(this->result_label);
			this->Controls->Add(this->button_equal);
			this->Controls->Add(this->button_dot);
			this->Controls->Add(this->button_0);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->button_3);
			this->Controls->Add(this->button_2);
			this->Controls->Add(this->button_1);
			this->Controls->Add(this->button_subtr);
			this->Controls->Add(this->button_6);
			this->Controls->Add(this->button_5);
			this->Controls->Add(this->button_4);
			this->Controls->Add(this->button_multi);
			this->Controls->Add(this->button_9);
			this->Controls->Add(this->button_8);
			this->Controls->Add(this->button_7);
			this->Controls->Add(this->button_divide);
			this->Controls->Add(this->button_percent);
			this->Controls->Add(this->button_minusplus);
			this->Controls->Add(this->button_ac);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Gadugi", 11, System::Drawing::FontStyle::Bold));
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Калькулятор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button_number_Click(System::Object^ sender, System::EventArgs^ e) {
		this->result_label->ForeColor = Color::White;
		Button^ button = safe_cast<Button^>(sender);
		if (this->result_label->Text == "0" || is_equal) {
			this->result_label->Text = button->Text;
			is_equal = false;
		}
		else
			this->result_label->Text = this->result_label->Text + button->Text;;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->updateMemoryIndicator();
	}
	private: System::Void button_divide_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('/');
	}
	private: System::Void button_multi_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('*');
	}
	private: System::Void button_subtr_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('-');
	}
	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('+');
	}
	private: System::Void button_percent_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('%');
	}
	private: System::Void math_action(char action) {
		this->first_num = System::Convert::ToDouble(this->result_label->Text);
		this->user_action = action;
		this->result_label->Text = "0";
	}
	private: System::Void button_equal_Click(System::Object^ sender, System::EventArgs^ e) {
		if (user_action == ' ')
			return;
		double second_num = System::Convert::ToDouble(this->result_label->Text);
		double res = 0;
		switch (this->user_action) {
		case '+': res = this->first_num + second_num; break;
		case '-': res = this->first_num - second_num; break;
		case '*': res = this->first_num * second_num; break;
		case '%': res = this->first_num * second_num / 100; break;
		case '/':
			if (second_num == 0) {
				res = 0;
				this->result_label->ForeColor = Color::Red;
				MessageBox::Show(this, "Division by 0 is prohibited", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
				res = this->first_num / second_num;
			break;
		}
		this->is_equal = true;
		this->result_label->Text = System::Convert::ToString(res);
	}
	private: System::Void button_ac_Click(System::Object^ sender, System::EventArgs^ e) {
		this->result_label->Text = "0";
		this->result_label->ForeColor = Color::White;
		this->first_num = 0;
		this->user_action = ' ';
		this->is_equal = false;
	}
	private: System::Void button_minusplus_Click(System::Object^ sender, System::EventArgs^ e) {
		double num = System::Convert::ToDouble(this->result_label->Text);
		num *= -1;
		this->result_label->Text = System::Convert::ToString(num);
	}
	private: System::Void button_dot_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = this->result_label->Text;
		if (!text->Contains(","))
			this->result_label->Text = text + ",";
	}
	private: System::Void sqrt_button_Click(System::Object^ sender, System::EventArgs^ e) {
		double num = System::Convert::ToDouble(this->result_label->Text);
		if (num < 0) {
			this->result_label->ForeColor = Color::Red;
			MessageBox::Show(this, "Square root of negative number is prohibited", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			num = std::sqrt(num);
			this->result_label->Text = System::Convert::ToString(num);
		}
	}
	private: System::Void button_factorial_Click(System::Object^ sender, System::EventArgs^ e) {
		double num = System::Convert::ToDouble(this->result_label->Text);
		double num_check = std::round(num);
		double res = 1;
		if (num < 0 || num != num_check) {
			this->result_label->ForeColor = Color::Red;
			MessageBox::Show(this, "Data for factorial is incorrect", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			if (num_check >= 18)
			{
				this->result_label->ForeColor = Color::Red;
				MessageBox::Show(this, "Type overflow. Use numbers below 18", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (num == 0) {
				this->result_label->Text = "1";
			}
			else
			{
				for (int i = 1; i <= num_check; i++)
				{
					res *= i;
				}
				this->result_label->Text = System::Convert::ToString(res);
			}
		}
	}
	private: System::Void button_int_Click(System::Object^ sender, System::EventArgs^ e) {
		double num = System::Convert::ToDouble(this->result_label->Text);
		num = std::round(num);
		this->result_label->Text = System::Convert::ToString(num);
	}
	private: System::Void button_sin_Click(System::Object^ sender, System::EventArgs^ e) {
		double num = System::Convert::ToDouble(this->result_label->Text);
		num = std::sin(num);
		this->result_label->Text = System::Convert::ToString(num);
	}
	private: System::Void button_cos_Click(System::Object^ sender, System::EventArgs^ e) {
		double num = System::Convert::ToDouble(this->result_label->Text);
		num = std::cos(num);
		this->result_label->Text = System::Convert::ToString(num);
	}
	private: System::Void button_mem_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		double val = System::Convert::ToDouble(this->result_label->Text);
		this->memory += val;
		this->updateMemoryIndicator();
	}
	private: System::Void button_mem_minus_Click(System::Object^ sender, System::EventArgs^ e) {
		double val = System::Convert::ToDouble(this->result_label->Text);
		this->memory -= val;
		this->updateMemoryIndicator();
	}
	private: System::Void button_mem_recall_Click(System::Object^ sender, System::EventArgs^ e) {
		this->result_label->Text = System::Convert::ToString(this->memory);
		this->result_label->ForeColor = Color::White;
		this->is_equal = true;
	}
	private: System::Void button_mem_clear_Click(System::Object^ sender, System::EventArgs^ e) {
		this->memory = 0.0;
		this->updateMemoryIndicator();
	}
	private: System::Void updateMemoryIndicator() {
		if (this->memory_label != nullptr) {
			if (this->memory != 0.0) {
				this->memory_label->Text = L"M";
			}
			else {
				this->memory_label->Text = L"";
			}
		}
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
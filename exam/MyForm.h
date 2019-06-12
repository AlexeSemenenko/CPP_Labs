#pragma once

#include "MED.h"
#include <vcclr.h>

MB1 items;
MB2 price;
MB3 med;

namespace examkr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  open_price;
	protected:
	private: System::Windows::Forms::OpenFileDialog^  open_items;
	private: System::Windows::Forms::SaveFileDialog^  save_med;
	private: System::Windows::Forms::Button^  items_button;
	private: System::Windows::Forms::DataGridView^  items_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  items_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  items_date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  items_section;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  items_amount;
	private: System::Windows::Forms::Button^  price_button;
	private: System::Windows::Forms::DataGridView^  price_table;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  price_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  price_date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  price_pr;
	private: System::Windows::Forms::Button^  combo_butotn;
	private: System::Windows::Forms::DataGridView^  med_table;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  med_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  med_date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  med_section;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  med_pr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  med_amount;
	private: System::Windows::Forms::Button^  sort_button;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::SaveFileDialog^  save_bin;


	private: System::Windows::Forms::Button^  save1_button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->open_price = (gcnew System::Windows::Forms::OpenFileDialog());
			this->open_items = (gcnew System::Windows::Forms::OpenFileDialog());
			this->save_med = (gcnew System::Windows::Forms::SaveFileDialog());
			this->items_button = (gcnew System::Windows::Forms::Button());
			this->items_table = (gcnew System::Windows::Forms::DataGridView());
			this->items_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->items_date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->items_section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->items_amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price_button = (gcnew System::Windows::Forms::Button());
			this->price_table = (gcnew System::Windows::Forms::DataGridView());
			this->price_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price_date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price_pr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->combo_butotn = (gcnew System::Windows::Forms::Button());
			this->med_table = (gcnew System::Windows::Forms::DataGridView());
			this->med_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->med_date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->med_section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->med_pr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->med_amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sort_button = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->save_bin = (gcnew System::Windows::Forms::SaveFileDialog());
			this->save1_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->items_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->med_table))->BeginInit();
			this->SuspendLayout();
			// 
			// open_price
			// 
			this->open_price->FileName = L"openFileDialog1";
			// 
			// open_items
			// 
			this->open_items->FileName = L"openFileDialog1";
			// 
			// items_button
			// 
			this->items_button->Location = System::Drawing::Point(195, 12);
			this->items_button->Name = L"items_button";
			this->items_button->Size = System::Drawing::Size(78, 34);
			this->items_button->TabIndex = 0;
			this->items_button->Text = L"Browse Items";
			this->items_button->UseVisualStyleBackColor = true;
			this->items_button->Click += gcnew System::EventHandler(this, &MyForm::items_button_Click);
			// 
			// items_table
			// 
			this->items_table->AllowUserToAddRows = false;
			this->items_table->AllowUserToDeleteRows = false;
			this->items_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->items_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->items_name,
					this->items_date, this->items_section, this->items_amount
			});
			this->items_table->Location = System::Drawing::Point(12, 52);
			this->items_table->Name = L"items_table";
			this->items_table->ReadOnly = true;
			this->items_table->Size = System::Drawing::Size(444, 141);
			this->items_table->TabIndex = 1;
			// 
			// items_name
			// 
			this->items_name->HeaderText = L"Name";
			this->items_name->Name = L"items_name";
			this->items_name->ReadOnly = true;
			// 
			// items_date
			// 
			this->items_date->HeaderText = L"Date";
			this->items_date->Name = L"items_date";
			this->items_date->ReadOnly = true;
			// 
			// items_section
			// 
			this->items_section->HeaderText = L"Section";
			this->items_section->Name = L"items_section";
			this->items_section->ReadOnly = true;
			// 
			// items_amount
			// 
			this->items_amount->HeaderText = L"Amount";
			this->items_amount->Name = L"items_amount";
			this->items_amount->ReadOnly = true;
			// 
			// price_button
			// 
			this->price_button->Location = System::Drawing::Point(634, 12);
			this->price_button->Name = L"price_button";
			this->price_button->Size = System::Drawing::Size(78, 34);
			this->price_button->TabIndex = 2;
			this->price_button->Text = L"Browse Price";
			this->price_button->UseVisualStyleBackColor = true;
			this->price_button->Click += gcnew System::EventHandler(this, &MyForm::price_button_Click);
			// 
			// price_table
			// 
			this->price_table->AllowUserToAddRows = false;
			this->price_table->AllowUserToDeleteRows = false;
			this->price_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->price_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->price_name,
					this->price_date, this->price_pr
			});
			this->price_table->Location = System::Drawing::Point(482, 52);
			this->price_table->Name = L"price_table";
			this->price_table->ReadOnly = true;
			this->price_table->Size = System::Drawing::Size(344, 141);
			this->price_table->TabIndex = 3;
			// 
			// price_name
			// 
			this->price_name->HeaderText = L"Name";
			this->price_name->Name = L"price_name";
			this->price_name->ReadOnly = true;
			// 
			// price_date
			// 
			this->price_date->HeaderText = L"Date";
			this->price_date->Name = L"price_date";
			this->price_date->ReadOnly = true;
			// 
			// price_pr
			// 
			this->price_pr->HeaderText = L"Price";
			this->price_pr->Name = L"price_pr";
			this->price_pr->ReadOnly = true;
			// 
			// combo_butotn
			// 
			this->combo_butotn->Location = System::Drawing::Point(375, 215);
			this->combo_butotn->Name = L"combo_butotn";
			this->combo_butotn->Size = System::Drawing::Size(81, 34);
			this->combo_butotn->TabIndex = 4;
			this->combo_butotn->Text = L"Combo";
			this->combo_butotn->UseVisualStyleBackColor = true;
			this->combo_butotn->Click += gcnew System::EventHandler(this, &MyForm::combo_butotn_Click);
			// 
			// med_table
			// 
			this->med_table->AllowUserToAddRows = false;
			this->med_table->AllowUserToDeleteRows = false;
			this->med_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->med_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->med_name, this->med_date,
					this->med_section, this->med_pr, this->med_amount
			});
			this->med_table->Location = System::Drawing::Point(155, 255);
			this->med_table->Name = L"med_table";
			this->med_table->ReadOnly = true;
			this->med_table->Size = System::Drawing::Size(543, 150);
			this->med_table->TabIndex = 5;
			// 
			// med_name
			// 
			this->med_name->HeaderText = L"Name";
			this->med_name->Name = L"med_name";
			this->med_name->ReadOnly = true;
			// 
			// med_date
			// 
			this->med_date->HeaderText = L"Date";
			this->med_date->Name = L"med_date";
			this->med_date->ReadOnly = true;
			// 
			// med_section
			// 
			this->med_section->HeaderText = L"Section";
			this->med_section->Name = L"med_section";
			this->med_section->ReadOnly = true;
			// 
			// med_pr
			// 
			this->med_pr->HeaderText = L"Price";
			this->med_pr->Name = L"med_pr";
			this->med_pr->ReadOnly = true;
			// 
			// med_amount
			// 
			this->med_amount->HeaderText = L"Amount";
			this->med_amount->Name = L"med_amount";
			this->med_amount->ReadOnly = true;
			// 
			// sort_button
			// 
			this->sort_button->Location = System::Drawing::Point(67, 255);
			this->sort_button->Name = L"sort_button";
			this->sort_button->Size = System::Drawing::Size(82, 33);
			this->sort_button->TabIndex = 6;
			this->sort_button->Text = L"Sort";
			this->sort_button->UseVisualStyleBackColor = true;
			this->sort_button->Click += gcnew System::EventHandler(this, &MyForm::sort_button_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(704, 255);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(82, 33);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Save as .txt";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// save1_button
			// 
			this->save1_button->Location = System::Drawing::Point(704, 294);
			this->save1_button->Name = L"save1_button";
			this->save1_button->Size = System::Drawing::Size(82, 33);
			this->save1_button->TabIndex = 8;
			this->save1_button->Text = L"Save as .bin";
			this->save1_button->UseVisualStyleBackColor = true;
			this->save1_button->Click += gcnew System::EventHandler(this, &MyForm::save1_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(390, 425);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Input date";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(363, 441);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(111, 20);
			this->textBox1->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(375, 467);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(81, 29);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Find";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 509);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->save1_button);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->sort_button);
			this->Controls->Add(this->med_table);
			this->Controls->Add(this->combo_butotn);
			this->Controls->Add(this->price_table);
			this->Controls->Add(this->price_button);
			this->Controls->Add(this->items_table);
			this->Controls->Add(this->items_button);
			this->Name = L"MyForm";
			this->Text = L"Drug Store";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->items_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->med_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void items_button_Click(System::Object^  sender, System::EventArgs^  e) {
		open_price->ShowDialog();

		char* file_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_price->FileName);

		std::ifstream fin(file_name, std::ios::binary);

		if (!fin.is_open() && file_name != "")
		{
			MessageBox::Show("No file selected", "File selecting warning");
		}
		else if (file_name != "")
		{
			items.GetMeds(fin);
		}
		
		items_table->Rows->Clear();

		for (int i = 0; i < items.get_count(); i++)
		{
			Items temp = items[i];

			System::String^ name = gcnew System::String(temp.Name);
			System::String^ date = gcnew System::String(temp.myDate);
			System::String^ section = gcnew System::String(temp.Section);
			char count[5];
			sprintf(count, "%d", temp.Count);
			System::String^ count_ = gcnew System::String(count);

			items_table->Rows->Add(name, date, section, count_);
		}
		fin.close();
	}
	private: System::Void price_button_Click(System::Object^  sender, System::EventArgs^  e) {
		open_items->ShowDialog();

		char* file_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_items->FileName);

		std::ifstream fin(file_name, std::ios::binary);

		if (!fin.is_open() && file_name != "")
		{
			MessageBox::Show("No file selected", "File selecting warning");
		}
		else if (file_name != "")
		{
			price.GetMeds(fin);
		}

		price_table->Rows->Clear();

		for (int i = 0; i < price.get_count(); i++)
		{
			Price temp = price[i];

			System::String^ name = gcnew System::String(temp.Name);
			System::String^ date = gcnew System::String(temp.myDate);
			char price[10];
			sprintf(price, "%f", temp.pr);
			System::String^ pr_ = gcnew System::String(price);

			price_table->Rows->Add(name, date, pr_);
		}
		fin.close();
	}
private: System::Void combo_butotn_Click(System::Object^  sender, System::EventArgs^  e) {
	items.SortUp();
	price.SortUp();
	
	int i = 0, j = 0;
	while (i < items.get_count() && j < price.get_count())
	{
		switch (strcmp(static_cast<char*>(items[i].Name), static_cast<char*>(price[j].Name)))
		{
		case -1:
			i++;
			break;
		case 1:
			j++;
			break;
		case 0:
			Med buf;
			strcpy(buf.Name, static_cast<char*>(items[i].Name));
			strcpy(buf.myDate, static_cast<char*>(items[i].myDate));
			strcpy(buf.Section, static_cast<char*>(items[i].Section));
			buf.Count = static_cast<int>(items[i].Count);
			buf.pr = static_cast<double>(price[j].pr);
			med.append(buf);
			i++;
			j++;
			break;
		}
	}
	med_table->Rows->Clear();

	for (int i = 0; i < med.get_count(); i++)
	{
		Med temp = med[i];

		System::String^ name = gcnew System::String(temp.Name);
		System::String^ date = gcnew System::String(temp.myDate);
		System::String^ section = gcnew System::String(temp.Section);
		char count[10];
		sprintf(count, "%d", temp.Count);
		System::String^ count_ = gcnew System::String(count);
		char price[10];
		sprintf(price, "%f", temp.pr);
		System::String^ pr_ = gcnew System::String(price);

		med_table->Rows->Add(name, date,section, pr_, count_);
	}
}
private: System::Void sort_button_Click(System::Object^  sender, System::EventArgs^  e) {
	ABS_Med* c; 
	c = &items;
	c->SortUp();

	items_table->Rows->Clear();

	for (int i = 0; i < items.get_count(); i++)
	{
		Items temp = items[i];

		System::String^ name = gcnew System::String(temp.Name);
		System::String^ date = gcnew System::String(temp.myDate);
		System::String^ section = gcnew System::String(temp.Section);
		char count[5];
		sprintf(count, "%d", temp.Count);
		System::String^ count_ = gcnew System::String(count);

		items_table->Rows->Add(name, date, section, count_);
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	save_med->ShowDialog();

	char* file_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(save_med->FileName);

	std::ofstream fout(file_name);

	if (!fout.is_open() && file_name != "")
	{
		MessageBox::Show("No file selected", "File chooshing warning");
	}
	else if (file_name != "")
	{
		med.PutMeds(fout);
	}

	fout.close();
}
private: System::Void save1_button_Click(System::Object^  sender, System::EventArgs^  e) {
	save_bin->ShowDialog();

	char* file_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(save_bin->FileName);

	std::ofstream fout(file_name, std::ios::binary);

	if (!fout.is_open() && file_name != "")
	{
		MessageBox::Show("No file selected", "File chooshing warning");
	}
	else if (file_name != "")
	{
		med.WriteMeds(fout);
	}

	fout.close();
}
};
}

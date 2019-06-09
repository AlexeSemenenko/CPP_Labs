#pragma once

#include "MED.h"
#include <msclr/marshal_cppstd.h>
#include <vcclr.h>

MED<Med> med_list;
MED<Price> price_list_1;
MED<Price> price_list_2;
MED<Price> merge_price_list;
MED<Items> items_list_1;
MED<Items> items_list_2;
MED<Items> merge_items_list;

namespace medkr {

	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ main_form
	/// </summary>
	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(void)
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
		~main_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  open_file_price_1;
	protected:
	private: System::Windows::Forms::SaveFileDialog^  save_file_merge_price;
	private: System::Windows::Forms::OpenFileDialog^  open_file_price_2;
	private: System::Windows::Forms::OpenFileDialog^  open_file_items_1;
	private: System::Windows::Forms::OpenFileDialog^  open_file_items_2;
	private: System::Windows::Forms::SaveFileDialog^  save_file_merge_items;
	private: System::Windows::Forms::Button^  open_price_1_button;
	private: System::Windows::Forms::DataGridView^  price_1_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name1_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  price1_col;
	private: System::Windows::Forms::Button^  open_price_2_butto;
	private: System::Windows::Forms::DataGridView^  price_2_table;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name2_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  price2_col;
	private: System::Windows::Forms::DataGridView^  price_merege_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name3_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  price3_col;
	private: System::Windows::Forms::Button^  save_price_button;
	private: System::Windows::Forms::Button^  merege_price_button;




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
			this->open_file_price_1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->save_file_merge_price = (gcnew System::Windows::Forms::SaveFileDialog());
			this->open_file_price_2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->open_file_items_1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->open_file_items_2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->save_file_merge_items = (gcnew System::Windows::Forms::SaveFileDialog());
			this->open_price_1_button = (gcnew System::Windows::Forms::Button());
			this->price_1_table = (gcnew System::Windows::Forms::DataGridView());
			this->name1_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price1_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->open_price_2_butto = (gcnew System::Windows::Forms::Button());
			this->price_2_table = (gcnew System::Windows::Forms::DataGridView());
			this->name2_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price2_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price_merege_table = (gcnew System::Windows::Forms::DataGridView());
			this->name3_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price3_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->save_price_button = (gcnew System::Windows::Forms::Button());
			this->merege_price_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_1_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_2_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_merege_table))->BeginInit();
			this->SuspendLayout();
			// 
			// open_file_price_2
			// 
			this->open_file_price_2->FileName = L"openFileDialog1";
			// 
			// open_file_items_1
			// 
			this->open_file_items_1->FileName = L"openFileDialog1";
			// 
			// open_file_items_2
			// 
			this->open_file_items_2->FileName = L"openFileDialog1";
			// 
			// open_price_1_button
			// 
			this->open_price_1_button->Location = System::Drawing::Point(84, 3);
			this->open_price_1_button->Name = L"open_price_1_button";
			this->open_price_1_button->Size = System::Drawing::Size(81, 32);
			this->open_price_1_button->TabIndex = 0;
			this->open_price_1_button->Text = L"load price 1";
			this->open_price_1_button->UseVisualStyleBackColor = true;
			this->open_price_1_button->Click += gcnew System::EventHandler(this, &main_form::open_price_1_button_Click);
			// 
			// price_1_table
			// 
			this->price_1_table->AllowUserToAddRows = false;
			this->price_1_table->AllowUserToDeleteRows = false;
			this->price_1_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->price_1_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->name1_col,
					this->price1_col
			});
			this->price_1_table->Location = System::Drawing::Point(12, 41);
			this->price_1_table->Name = L"price_1_table";
			this->price_1_table->ReadOnly = true;
			this->price_1_table->Size = System::Drawing::Size(244, 136);
			this->price_1_table->TabIndex = 1;
			// 
			// name1_col
			// 
			this->name1_col->HeaderText = L"Name";
			this->name1_col->Name = L"name1_col";
			this->name1_col->ReadOnly = true;
			// 
			// price1_col
			// 
			this->price1_col->HeaderText = L"Price";
			this->price1_col->Name = L"price1_col";
			this->price1_col->ReadOnly = true;
			// 
			// open_price_2_butto
			// 
			this->open_price_2_butto->Location = System::Drawing::Point(84, 183);
			this->open_price_2_butto->Name = L"open_price_2_butto";
			this->open_price_2_butto->Size = System::Drawing::Size(81, 29);
			this->open_price_2_butto->TabIndex = 2;
			this->open_price_2_butto->Text = L"load price 2";
			this->open_price_2_butto->UseVisualStyleBackColor = true;
			this->open_price_2_butto->Click += gcnew System::EventHandler(this, &main_form::open_price_2_butto_Click);
			// 
			// price_2_table
			// 
			this->price_2_table->AllowUserToAddRows = false;
			this->price_2_table->AllowUserToDeleteRows = false;
			this->price_2_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->price_2_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->name2_col,
					this->price2_col
			});
			this->price_2_table->Location = System::Drawing::Point(12, 218);
			this->price_2_table->Name = L"price_2_table";
			this->price_2_table->ReadOnly = true;
			this->price_2_table->Size = System::Drawing::Size(244, 150);
			this->price_2_table->TabIndex = 3;
			// 
			// name2_col
			// 
			this->name2_col->HeaderText = L"Name";
			this->name2_col->Name = L"name2_col";
			this->name2_col->ReadOnly = true;
			// 
			// price2_col
			// 
			this->price2_col->HeaderText = L"Price";
			this->price2_col->Name = L"price2_col";
			this->price2_col->ReadOnly = true;
			// 
			// price_merege_table
			// 
			this->price_merege_table->AllowUserToAddRows = false;
			this->price_merege_table->AllowUserToDeleteRows = false;
			this->price_merege_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->price_merege_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->name3_col,
					this->price3_col
			});
			this->price_merege_table->Location = System::Drawing::Point(12, 408);
			this->price_merege_table->Name = L"price_merege_table";
			this->price_merege_table->Size = System::Drawing::Size(244, 150);
			this->price_merege_table->TabIndex = 4;
			// 
			// name3_col
			// 
			this->name3_col->HeaderText = L"Name";
			this->name3_col->Name = L"name3_col";
			// 
			// price3_col
			// 
			this->price3_col->HeaderText = L"Price";
			this->price3_col->Name = L"price3_col";
			// 
			// save_price_button
			// 
			this->save_price_button->Location = System::Drawing::Point(42, 374);
			this->save_price_button->Name = L"save_price_button";
			this->save_price_button->Size = System::Drawing::Size(86, 28);
			this->save_price_button->TabIndex = 5;
			this->save_price_button->Text = L"save";
			this->save_price_button->UseVisualStyleBackColor = true;
			this->save_price_button->Click += gcnew System::EventHandler(this, &main_form::save_price_button_Click);
			// 
			// merege_price_button
			// 
			this->merege_price_button->Location = System::Drawing::Point(134, 374);
			this->merege_price_button->Name = L"merege_price_button";
			this->merege_price_button->Size = System::Drawing::Size(81, 28);
			this->merege_price_button->TabIndex = 6;
			this->merege_price_button->Text = L"merge";
			this->merege_price_button->UseVisualStyleBackColor = true;
			this->merege_price_button->Click += gcnew System::EventHandler(this, &main_form::merege_price_button_Click);
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1036, 566);
			this->Controls->Add(this->merege_price_button);
			this->Controls->Add(this->save_price_button);
			this->Controls->Add(this->price_merege_table);
			this->Controls->Add(this->price_2_table);
			this->Controls->Add(this->open_price_2_butto);
			this->Controls->Add(this->price_1_table);
			this->Controls->Add(this->open_price_1_button);
			this->Name = L"main_form";
			this->Text = L"Main menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_1_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_2_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->price_merege_table))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void redraw_price_list(System::Windows::Forms::DataGridView^ table, MED<Price>& m_list)
		{
			table->Rows->Clear();

			for (size_t i = 0; i < m_list.get_count(); i++)
			{
				Price temp = m_list[i];

				System::String^ name = gcnew System::String(temp.name);
				char price[10];
				sprintf(price, "%f", temp.pr);
				System::String^ price_ = gcnew System::String(price);

				table->Rows->Add(name, price_);
			}
		}

	private: System::Void open_price_1_button_Click(System::Object^  sender, System::EventArgs^  e) {
		open_file_price_1->ShowDialog();

		char* file_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_price_1->FileName);

		std::ifstream fin(file_name);
	
		if (!fin.is_open() && file_name != "")
		{
			MessageBox::Show("No file selected", "File selecting warning");
		}
		else if (file_name != "")
		{
			price_list_1.clear();
			while (!fin.eof())
			{
				fin >> price_list_1;
			}
		}
		fin.close();

		redraw_price_list(price_1_table, price_list_1);
	}

	private: System::Void open_price_2_butto_Click(System::Object^  sender, System::EventArgs^  e) {
		open_file_price_2->ShowDialog();

		char* file_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_price_2->FileName);

		std::ifstream fin(file_name);

		if (!fin.is_open() && file_name != "")
		{
			MessageBox::Show("No file selected", "File selecting warning");
		}
		else if (file_name != "")
		{
			price_list_2.clear();
			while (!fin.eof())
			{
				fin >> price_list_2;
			}
		}
		fin.close();

		redraw_price_list(price_2_table, price_list_2);
	}
private: System::Void merege_price_button_Click(System::Object^  sender, System::EventArgs^  e) {
	merge_price_list = price_list_1 + price_list_2;
	redraw_price_list(price_merege_table, merge_price_list);
}
private: System::Void save_price_button_Click(System::Object^  sender, System::EventArgs^  e) {
	save_file_merge_price->ShowDialog();

	char* file_name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(save_file_merge_price->FileName);

	std::ofstream fout(file_name);

	if (!fout.is_open() && file_name != "")
	{
		MessageBox::Show("No file selected", "File chooshing warning");
	}
	else if (file_name != "")
	{
		fout << merge_price_list;
	}

	fout.close();
}
};
}

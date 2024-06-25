#pragma once


#define PI 3.14159265359
#define G 9.8

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_format.h"

struct profile player1;
struct profile player2;
struct weapon_profile wea1;
struct weapon_profile wea2;
struct Round round_count;
struct protect protectwall[5];
struct protect protectwall2[5];
struct item_profile obstacle[24];
struct weapon_profile wea1big;
struct weapon_profile wea2big;

int system_counter = 0;
float X = 0;
float Y = 0;
float Theta = 1.57;
int V = 0;
float W = 0;
float dt = 0.1;
float wea1_time = 0.1;
float wea2_time = 0.1;
float compute_round_time = 0;
int use_protectwall = 0;       //計算P1防護網使用次數
int use_protectwall2 = 0;      //計算P2防護網使用次數
int use_wea1big = 0;           //計算P1大子彈使用次數
int use_wea2big = 0;           //計算P2大子彈使用次數
int useP1HP = 0;
int useP2HP = 0;
int V1 = 0;   //計算player1的V
int V2 = 0;   //計算player2的V
int click1 = 0;  //計算能量條
int click2 = 0;  //計算能量條
int wea1V = 0;  
int wea2V = 0;
int k;  //計算障礙物隨機出現變數
float wea1big_time = 0.1;
float wea2big_time = 0.1;
int wea1Vbig = 0;
int wea2Vbig = 0;


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(132, 73);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(124, 31);
			this->progressBar1->TabIndex = 8;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(1018, 65);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(124, 31);
			this->progressBar2->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 15);
			this->label1->TabIndex = 10;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(936, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 15);
			this->label2->TabIndex = 11;
			this->label2->Text = L"label2";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(542, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 15);
			this->label3->TabIndex = 12;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(542, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 15);
			this->label4->TabIndex = 13;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(48, 132);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 15);
			this->label5->TabIndex = 16;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(936, 132);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 15);
			this->label6->TabIndex = 17;
			this->label6->Text = L"label6";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(999, 999);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 27;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(999, 999);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 26;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(999, 999);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 25;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(999, 999);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 24;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(999, 999);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 23;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(999, 999);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 22;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(999, 999);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 21;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(999, 999);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 20;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(999, 999);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 19;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(999, 999);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 18;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(48, 159);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 15);
			this->label7->TabIndex = 28;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(48, 183);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 15);
			this->label8->TabIndex = 29;
			this->label8->Text = L"label8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(936, 159);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 15);
			this->label9->TabIndex = 30;
			this->label9->Text = L"label9";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(936, 183);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 15);
			this->label10->TabIndex = 31;
			this->label10->Text = L"label10";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1282, 453);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void plot_HMI(void)
		{
			Graphics^ e1 = this->CreateGraphics();
			e1->Clear(Color::Pink);
			Pen^ pen_R = gcnew Pen(Color::Red, 10);  //player1
			Brush^ brush_GR = gcnew SolidBrush(Color::Gray); // map
			Pen^ pen_R10 = gcnew Pen(Color::Red, 10); //weapon1 gun
			Pen^ pen_B10 = gcnew Pen(Color::Blue, 10); //weapon2 gun
			Pen^ pen_Br = gcnew Pen(Color::Brown, 5);
			
			Brush^ brush_P = gcnew SolidBrush(Color::Purple); //background
			Pen^ pen_BK = gcnew Pen(Color::Black, 3);
			Brush^ brush_Gr = gcnew SolidBrush(Color::Green);
			Brush^ brush_Br = gcnew SolidBrush(Color::Brown);
			Brush^ brush_R = gcnew SolidBrush(Color::Red);
			Brush^ brush_BL = gcnew SolidBrush(Color::Blue);

			int R_size = 30;     //tank_size
			int grid_width = 400;
			int grid_height = 400;
			int grid_resolution = 1;  //解析度
			int shift_x = (grid_width / 2); //
			int shift_y = (grid_height)+0;
			int Y_shift = 0;

			e1->FillRectangle(brush_GR, shift_x - 200 - R_size / 2, shift_y - 50 - R_size / 2, 1000, 100);
			
			// plot player1 
			int x1 = (player1.pos.X) / grid_resolution;
			int y1 = (player1.pos.Y + Y_shift) / grid_resolution;

			e1->FillEllipse(brush_R, shift_x + x1 - R_size / 2, shift_y - y1 - R_size / 2, R_size, R_size);//戰車車身
			
			int dir_x1 = 40 * cos(player1.pos.Theta);
			int dir_y1 = 40 * sin(player1.pos.Theta);

			e1->DrawLine(pen_R, shift_x + 0 + x1, shift_y - y1, shift_x + x1 + 0 + dir_x1, shift_y - y1 - dir_y1); //砲管

			// plot wea1		
			if (wea1.enable == 1 && wea1.counter > 0)
			{
				int R_size1 = wea1.diameter;
				x1 = (wea1.pos.X) / grid_resolution;
				y1 = (wea1.pos.Y + Y_shift) / grid_resolution; 
				e1->DrawEllipse(pen_R10, shift_x + x1 - R_size1 / 2, shift_y - y1 - R_size1 / 2,
					R_size1, R_size1);
			}

			// plot player2 
			int x2 = (player2.pos.X) / grid_resolution;
			int y2 = (player2.pos.Y + Y_shift) / grid_resolution;

			e1->FillEllipse(brush_BL, shift_x + x2 - R_size / 2, shift_y - y2 - R_size / 2, R_size, R_size);  //戰車車身

			int dir_x2 = 40 * cos(player2.pos.Theta);
			int dir_y2 = 40 * sin(player2.pos.Theta);

			e1->DrawLine(pen_B10, shift_x + 0 + x2, shift_y - y2, shift_x + x2 + 0 + dir_x2, shift_y - y2 - dir_y2); //砲管

			// plot wea2		
			if (wea2.enable == 1 && wea2.counter > 0)
			{
				int R_size1 = wea2.diameter;
				x1 = (wea2.pos.X) / grid_resolution;
				y1 = (wea2.pos.Y + Y_shift) / grid_resolution;
				e1->DrawEllipse(pen_B10, shift_x + x1 - R_size1 / 2, shift_y - y1 - R_size1 / 2,
					R_size1, R_size1);
			}

			//protectwall
			
			for (int i = 0;i < 5;i++)
			{
				if (protectwall[i].enable == 1)
				{
					R_size = protectwall[i].diameter;
					x1 = (protectwall[i].pos.X) / grid_resolution;
					y1 = (protectwall[i].pos.Y + Y_shift) / grid_resolution;
					e1->DrawEllipse(pen_R10, shift_x + x1 - R_size / 2, shift_y - y1 - R_size / 2,
						R_size, R_size);
				}
			}

			//protectwall2

			for (int i = 0;i < 5;i++)
			{
				if (protectwall2[i].enable == 1)
				{
					R_size = protectwall2[i].diameter;
					x1 = (protectwall2[i].pos.X) / grid_resolution;
					y1 = (protectwall2[i].pos.Y + Y_shift) / grid_resolution;
					e1->DrawEllipse(pen_B10, shift_x + x1 - R_size / 2, shift_y - y1 - R_size / 2,
						R_size, R_size);
				}
			}

			// 能量條1
			e1->DrawRectangle(pen_BK, 60, 230, 96, 20);
			e1->FillRectangle(brush_Gr, 60, 230, V1, 20);

			// 能量條2
			e1->DrawRectangle(pen_BK, 760, 230, 96, 20);
			e1->FillRectangle(brush_Gr, 760, 230, V2, 20);

			
			// obstacles
			for (int i = 0; i < 24; i++)
			{
				if (obstacle[i].enable == 1)
				{
					R_size = obstacle[i].diameter;
					x1 = (obstacle[i].pos.X) / grid_resolution;
					y1 = (obstacle[i].pos.Y + Y_shift) / grid_resolution;
					e1->FillRectangle(brush_Br, shift_x + x1 - R_size / 2, shift_y - y1 - R_size / 2, R_size, R_size);
				}
			}


			// plot wea1big		
			if (wea1big.enable == 1 && wea1big.counter > 0)
			{
				int R_size1 = wea1big.diameter+50;
				x1 = (wea1big.pos.X) / grid_resolution;
				y1 = (wea1big.pos.Y + Y_shift) / grid_resolution;
				e1->FillEllipse(brush_R, shift_x + x1 - R_size1 / 2, shift_y - y1 - R_size1 / 2,
					R_size1, R_size1);
			}

			// plot wea2big		
			if (wea2big.enable == 1 && wea2big.counter > 0)
			{
				int R_size1 = wea2big.diameter+50;
				x1 = (wea2big.pos.X) / grid_resolution;
				y1 = (wea2big.pos.Y + Y_shift) / grid_resolution;
				e1->FillEllipse(brush_BL, shift_x + x1 - R_size1 / 2, shift_y - y1 - R_size1 / 2,
					R_size1, R_size1);
			}							
		}

		void initialize()
		{
			srand(time(NULL));
			// player1
			player1.pos.X = -80;    
			player1.pos.Y = 80;
			player1.pos.Theta = 1.57;
			player1.point.HP = 100;

			// weapon1 gun		
			wea1.point.HP = 20;   //傷害
			wea1.range = 100;    //射程
			wea1.Velocity = 12;  //速度 12-17
			wea1.enable = 0;

			// player2
			player2.pos.X = 620;
			player2.pos.Y = 80;
			player2.pos.Theta = 1.57;
			player2.point.HP = 100;

			// weapon2 gun
			wea2.point.HP = 20;
			wea2.range = 100;
			wea2.Velocity = 12;
			wea2.enable = 0;

			//protectwall
			protectwall[0].pos.X = 0;
			protectwall[0].pos.Y = 50;
			protectwall[1].pos.X = 0;
			protectwall[1].pos.Y = 100;
			protectwall[2].pos.X = 0;
			protectwall[2].pos.Y = 150;
			protectwall[3].pos.X = 0;
			protectwall[3].pos.Y = 200;
			protectwall[4].pos.X = 0;
			protectwall[4].pos.Y = 250;
			//protectwall[5].pos.X = 0;
			//protectwall[5].pos.Y = 300;

			//protectwall2
			protectwall2[0].pos.X = 500;
			protectwall2[0].pos.Y = 50;
			protectwall2[1].pos.X = 500;
			protectwall2[1].pos.Y = 100;
			protectwall2[2].pos.X = 500;
			protectwall2[2].pos.Y = 150;
			protectwall2[3].pos.X = 500;
			protectwall2[3].pos.Y = 200;
			protectwall2[4].pos.X = 500;
			protectwall2[4].pos.Y = 250;
			//protectwall2[5].pos.X = 500;
			//protectwall2[5].pos.Y = 300;
			
			// obstacles
			//k=0
			obstacle[0].pos.X = 90;
			obstacle[0].pos.Y = 75;
			obstacle[1].pos.X = 90;
			obstacle[1].pos.Y = 90;			
			obstacle[2].pos.X = 90;
			obstacle[2].pos.Y = 105;
			obstacle[3].pos.X = 90;
			obstacle[3].pos.Y = 120;
			obstacle[4].pos.X = 90;
			obstacle[4].pos.Y = 135;
			//k==1
			obstacle[5].pos.X = 200;
			obstacle[5].pos.Y = 100;
			obstacle[6].pos.X = 200;
			obstacle[6].pos.Y = 115;
			obstacle[7].pos.X = 200;
			obstacle[7].pos.Y = 130;
			obstacle[8].pos.X = 200;
			obstacle[8].pos.Y = 145;
			obstacle[9].pos.X = 200;
			obstacle[9].pos.Y = 160;
			obstacle[10].pos.X = 200;
			obstacle[10].pos.Y = 175;
			obstacle[11].pos.X = 200;
			obstacle[11].pos.Y = 190;
			//k==2
			obstacle[12].pos.X = 320;
			obstacle[12].pos.Y = 90;
			obstacle[13].pos.X = 320;
			obstacle[13].pos.Y = 105;
			obstacle[14].pos.X = 320;
			obstacle[14].pos.Y = 120;
			obstacle[15].pos.X = 320;
			obstacle[15].pos.Y = 135;
			obstacle[16].pos.X = 320;
			obstacle[16].pos.Y = 150;
			obstacle[17].pos.X = 320;
			obstacle[17].pos.Y = 165;
			obstacle[18].pos.X = 320;
			obstacle[18].pos.Y = 180;
			//k==3
			obstacle[19].pos.X = 450;
			obstacle[19].pos.Y = 75;
			obstacle[20].pos.X = 450;
			obstacle[20].pos.Y = 90;
			obstacle[21].pos.X = 450;
			obstacle[21].pos.Y = 105;
			obstacle[22].pos.X = 450;
			obstacle[22].pos.Y = 120;
			obstacle[23].pos.X = 450;
			obstacle[23].pos.Y = 135;

			// weapon1big gun		
			wea1big.point.HP = 40;   //傷害
			wea1big.range = 100;    //射程
			wea1big.Velocity = 12;  //速度 12-17
			wea1big.enable = 0;

			// weapon2big gun
			wea2big.point.HP = 40;
			wea2big.range = 100;
			wea2big.Velocity = 12;
			wea2big.enable = 0;

		}
		void Motion_Model(void)
		{
			// player1's angle
			player1.pos.Theta = player1.pos.Theta + player1.vel.W * dt;

			// weapon1
			if (wea1.enable == 1 && wea1.counter > 0)  //counter與range相關(射程)
			{
				wea1.pos.Theta = player1.pos.Theta;
				double launchAngle = wea1.pos.Theta; // 發射角度（單位：弧度）
				wea1V = wea1.Velocity + V1 /16+ rand() % 5 - 2;
				double vx = wea1V * cos(launchAngle); // X 軸方向速度分量
				double vy = wea1V * sin(launchAngle) - G * wea1_time; // Y 軸方向速度分量

				wea1.pos.X = wea1.pos.X + vx * wea1_time;
				wea1.pos.Y = wea1.pos.Y + wea1V * sin(launchAngle) * wea1_time - 0.5 * G * pow(wea1_time, 2);

				wea1_time += 0.1;
				wea1.counter--;
			}

			else
			{
				wea1.enable = 0;
			}

			// player2's angle
			player2.pos.Theta = player2.pos.Theta + player2.vel.W * dt;

			// weapon2
			if (wea2.enable == 1 && wea2.counter > 0)  //counter與range相關(射程)
			{
				wea2.pos.Theta = player2.pos.Theta;
				double launchAngle = wea2.pos.Theta; // 發射角度（單位：弧度）

				wea2V = wea2.Velocity + V2 / 16+ rand() % 5 - 2;
				double vx = wea2V * cos(launchAngle); // X 軸方向速度分量
				double vy = wea2V * fabs(sin(launchAngle)) - G * wea2_time; // Y 軸方向速度分量

				wea2.pos.X = wea2.pos.X + vx * wea2_time;
				wea2.pos.Y = wea2.pos.Y + wea2V * fabs(sin(launchAngle)) * wea2_time - 0.5 * G * pow(wea2_time, 2);

				wea2_time += 0.1;
				wea2.counter--;
			}
			else
			{
				wea2.enable = 0;
			}

			// weapon1big
			if (wea1big.enable == 1 && wea1big.counter > 0)  //counter與range相關(射程)
			{
				wea1big.pos.Theta = player1.pos.Theta;
				double launchAngle = wea1big.pos.Theta; // 發射角度（單位：弧度）
				wea1Vbig = wea1big.Velocity + V1 / 16+ rand() % 5 - 2;
				double vx = wea1Vbig * cos(launchAngle); // X 軸方向速度分量
				double vy = wea1Vbig * sin(launchAngle) - G * wea1big_time; // Y 軸方向速度分量

				wea1big.pos.X = wea1big.pos.X + vx * wea1big_time;
				wea1big.pos.Y = wea1big.pos.Y + wea1Vbig * sin(launchAngle) * wea1big_time - 0.5 * G * pow(wea1big_time, 2);

				wea1big_time += 0.1;
				wea1big.counter--;
			}

			else
			{
				wea1big.enable = 0;
			}

			// weapon2big
			if (wea2big.enable == 1 && wea2big.counter > 0)  //counter與range相關(射程)
			{
				wea2big.pos.Theta = player2.pos.Theta;
				double launchAngle = wea2big.pos.Theta; // 發射角度（單位：弧度）

				wea2Vbig = wea2big.Velocity + V2 / 16+ rand() % 5 - 2;
				double vx = wea2Vbig * cos(launchAngle); // X 軸方向速度分量
				double vy = wea2Vbig * fabs(sin(launchAngle)) - G * wea2big_time; // Y 軸方向速度分量

				wea2big.pos.X = wea2big.pos.X + vx * wea2big_time;
				wea2big.pos.Y = wea2big.pos.Y + wea2Vbig * fabs(sin(launchAngle)) * wea2big_time - 0.5 * G * pow(wea2big_time, 2);

				wea2big_time += 0.1;
				wea2big.counter--;
			}
			else
			{
				wea2big.enable = 0;
			}
		}

		void collsion_detection(void)
		{
			// between wea1 and player2
			float dis1 = sqrt((wea1.pos.X - player2.pos.X) * (wea1.pos.X - player2.pos.X) + (wea1.pos.Y - player2.pos.Y) * (wea1.pos.Y - player2.pos.Y));
			if (dis1 < 25 && wea1.enable == 1 && player2.enable == 1) {

				player2.point.HP = player2.point.HP - wea1.point.HP;

				wea1.enable = 0; // weapon disappear

				if (player2.point.HP <= 0)
				{
					player2.enable = 0; 
				}
			}

			// between wea2 and player1 
			float dis2 = sqrt((wea2.pos.X - player1.pos.X) * (wea2.pos.X - player1.pos.X) + (wea2.pos.Y - player1.pos.Y) * (wea2.pos.Y - player1.pos.Y));
			if (dis2 < 25 && wea2.enable == 1 && player1.enable == 1) {
				player1.point.HP = player1.point.HP - wea2.point.HP;

				wea2.enable = 0; // weapon disappear

				if (player1.point.HP <= 0)
				{
					player1.enable = 0; 
				}
			}

			//between protectwall and player2_weapon(wea2)
			for (int i = 0;i < 5;i++)
			{
				float dis = sqrt((wea2.pos.X - protectwall[i].pos.X) * (wea2.pos.X - protectwall[i].pos.X) + (wea2.pos.Y - protectwall[i].pos.Y) * (wea2.pos.Y - protectwall[i].pos.Y));
				if (dis < 50 && protectwall[i].enable == 1)
				{
					wea2.enable = 0;
					protectwall[0].enable = 0;
					protectwall[1].enable = 0;
					protectwall[2].enable = 0;
					protectwall[3].enable = 0;
					protectwall[4].enable = 0;
				}
			}

			//between protectwall2 and player1_weapon(wea1)
			for (int i = 0;i < 5;i++)
			{
				float dis = sqrt((wea1.pos.X - protectwall2[i].pos.X) * (wea1.pos.X - protectwall2[i].pos.X) + (wea1.pos.Y - protectwall2[i].pos.Y) * (wea1.pos.Y - protectwall2[i].pos.Y));
				if (dis < 50 && protectwall2[i].enable == 1)
				{
					wea1.enable = 0;
					protectwall2[0].enable = 0;
					protectwall2[1].enable = 0;
					protectwall2[2].enable = 0;
					protectwall2[3].enable = 0;
					protectwall2[4].enable = 0;
				}
			}
			// obs between wea1
			for (int i = 0; i < 24; i++)
			{
				float dis = sqrt((wea1.pos.X - obstacle[i].pos.X) * (wea1.pos.X - obstacle[i].pos.X) + (wea1.pos.Y - obstacle[i].pos.Y) * (wea1.pos.Y - obstacle[i].pos.Y));
				if (dis < 20)
				{
					wea1.enable = 0;
				}
			}

			// obs between wea2
			for (int i = 0; i < 24; i++)
			{
				float dis = sqrt((wea2.pos.X - obstacle[i].pos.X) * (wea2.pos.X - obstacle[i].pos.X) + (wea2.pos.Y - obstacle[i].pos.Y) * (wea2.pos.Y - obstacle[i].pos.Y));
				if (dis < 20)
				{
					wea2.enable = 0;
				}
			}

			// between wea1big and player2
			float dis1big = sqrt((wea1big.pos.X - player2.pos.X) * (wea1big.pos.X - player2.pos.X) + (wea1big.pos.Y - player2.pos.Y) * (wea1big.pos.Y - player2.pos.Y));
			if (dis1big < 40 && wea1big.enable == 1 && player2.enable == 1) {

				player2.point.HP = player2.point.HP - wea1big.point.HP;

				wea1big.enable = 0; // weapon disappear

				if (player2.point.HP <= 0)
				{
					player2.enable = 0;
				}
			}

			// between wea2big and player1 
			float dis2big = sqrt((wea2big.pos.X - player1.pos.X) * (wea2big.pos.X - player1.pos.X) + (wea2big.pos.Y - player1.pos.Y) * (wea2big.pos.Y - player1.pos.Y));
			if (dis2big < 40 && wea2big.enable == 1 && player1.enable == 1) {
				player1.point.HP = player1.point.HP - wea2big.point.HP;

				wea2big.enable = 0; // weapon disappear

				if (player1.point.HP <= 0)
				{
					player1.enable = 0;
				}
			}						
		};

		void text_displayer(void)  //顯示lable的文字
		{
			this->progressBar1->Value = player1.point.HP;
			this->label1->Text = ("HP:" + Convert::ToString(player1.point.HP) + "/100");
			this->progressBar2->Value = player2.point.HP;
			this->label2->Text = ("HP:" + Convert::ToString(player2.point.HP) + "/100");
			this->label3->Text = ("Time:" + Convert::ToString(round_count.compute_round_time));
			if (round_count.stage == 0)
			{
				this->label4->Text = "Player1回合";
			}
			if (round_count.stage != 0)
			{
				this->label4->Text = "Player2回合";
			}
			if (player1.point.HP <= 0)
			{
				this->label4->Text = "Player2 Win!";
			}
			if (player2.point.HP <= 0)
			{
				this->label4->Text = "Player1 Win!";
			}
			if (use_protectwall == 2)
			{
				this->label5->Text = "沒有防護網了";
			}
			else if (use_protectwall == 0)
			{
				this->label5->Text = "你有兩個防護網";
			}
			else if (use_protectwall == 1)
			{
				this->label5->Text = "剩下一個防護網";
			}
			if (use_protectwall2 == 2)
			{
				this->label6->Text = "沒有防護網了";
			}
			else if (use_protectwall2 == 0)
			{
				this->label6->Text = "你有兩個防護網";
			}
			else if (use_protectwall2 == 1)
			{
				this->label6->Text = "剩下一個防護網";
			}
			if (use_wea1big == 0)
			{
				this->label7->Text = "你有兩個大砲";
			}
			else if (use_wea1big == 1)
			{
				this->label7->Text = "剩下一個大砲";
			}
			else if (use_wea1big == 2)
			{
				this->label7->Text = "沒有大砲了";
			}
			if (use_wea2big == 0)
			{
				this->label9->Text = "你有兩個大砲";
			}
			else if (use_wea2big == 1)
			{
				this->label9->Text = "剩下一個大砲";
			}
			else if (use_wea2big == 2)
			{
				this->label9->Text = "沒有大砲了";
			}
			if (useP1HP == 0)
			{
				this->label8->Text = "你有一次回血機會";
			}
			else if (useP1HP == 1)
			{
				this->label8->Text = "回血機會已用完";
			}
			if (useP2HP == 0)
			{
				this->label10->Text = "你有一次回血機會";
			}
			else if (useP2HP == 1)
			{
				this->label10->Text = "回血機會已用完";
			}
		}

		void compute_stage(void)
		{
			if (round_count.stage < 1)
			{
				round_count.stage++;				
			}

			else
			{
				round_count.stage = 0;

			}
		}

		void compute_round(void)
		{

			if (round_count.stage == 0)  // player1攻擊
			{
				this->button1->Enabled = true;
				this->button2->Enabled = true;
				this->button3->Enabled = true;
				this->button4->Enabled = true;
				this->button5->Enabled = false;
				this->button6->Enabled = false;
				this->button7->Enabled = false;
				this->button8->Enabled = false;
				this->button9->Enabled = true;
				this->button10->Enabled = false;
			
			}

			else if (round_count.stage == 1)   // player2攻擊
			{
				//enemy_wea.enable = 0;
				this->button1->Enabled = false;
				this->button2->Enabled = false;
				this->button3->Enabled = false;
				this->button4->Enabled = false;
				this->button5->Enabled = true;
				this->button6->Enabled = true;
				this->button7->Enabled = true;
				this->button8->Enabled = true;
				this->button9->Enabled = false;
				this->button10->Enabled = true;
				
			}

			else if (round_count.stage >= 1)
			{
				round_count.stage == 0;
			}

			
			if (round_count.compute_round_time < 100)  
			{
				round_count.stage == 0;
			}

			else if (round_count.compute_round_time % 100 == 0)    //如果回合計時器時間 %100的餘數 =0 (每十秒)  開啟敵人武器
			{
				round_count.stage == 1;
				wea2_time = 0;
			}
			

			//一人最多使用兩次防護牆，使用兩次後沒收buttom
			if (use_protectwall == 2)
			{
				this->button9->Enabled = false;
			}
			if (use_protectwall2 == 2)
			{
				this->button10->Enabled = false;
			}

			//obs
			if (round_count.compute_round_time % 100 == 0)    //障礙物每十秒更新一次
			{
				k = rand() % 4;
			}			
		}
		void power(void)
		{
			if (click1 % 2 == 1) {
				if (V1 > 96) {
					V1 = 0;
				}
				V1 += 4;
			}

			if (click2 % 2 == 1) {
				if (V2 > 96) {
					V2 = 0;
				}
				V2 += 4;
			}
		}

#pragma endregion
		private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (system_counter == 0)
	{
		initialize();
	}
	system_counter++;
	round_count.compute_round_time++;
	
	Motion_Model();
	plot_HMI();
	text_displayer();
	collsion_detection();
	compute_round();
	if (click1 % 2 == 1) {
		power();
	}

	if (click2 % 2 == 1) {
		power();
	}	
}

	   private:System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		   //player1
		   if (round_count.stage == 0)
		   {

			   if (e->KeyCode == Keys::W)
			   {
				   player1.vel.W = 0.174 * 5;
			   }
			   if (e->KeyCode == Keys::X)
			   {
				   player1.vel.W = -0.174 * 5;
			   }
			   if (e->KeyCode == Keys::S)
			   {
				   player1.vel.V = 0;
				   player1.vel.W = 0;
			   }
			   if (e->KeyCode == Keys::Z)
			   {
				   compute_stage();
				   wea1_time = 0;
				   wea1.enable = 1;
				   wea1.pos.X = player1.pos.X;
				   wea1.pos.Y = player1.pos.Y;
				   //tank_profile.point.SP = tank_profile.point.SP - wea.point.SP;
				   wea1.counter = int((wea1.range / wea1.Velocity) * (1 / dt)) + 50;				   
			   }
			   if (e->KeyCode == Keys::A)
			   {
				   if (use_protectwall < 2)
				   {
					   compute_stage();
					   protectwall[0].enable = 1;
					   protectwall[1].enable = 1;
					   protectwall[2].enable = 1;
					   protectwall[3].enable = 1;
					   protectwall[4].enable = 1;
					   use_protectwall++;
				   }
			   }

			   if (e->KeyCode == Keys::Q)
			   {
				   click1++;
			   }

			   if (e->KeyCode == Keys::R)
			   {
				   if (use_wea1big < 2)
				   {
					   compute_stage();
					   wea1big_time = 0;
					   wea1big.enable = 1;
					   wea1big.pos.X = player1.pos.X;
					   wea1big.pos.Y = player1.pos.Y;
					   //tank_profile.point.SP = tank_profile.point.SP - wea.point.SP;
					   wea1big.counter = int((wea1big.range / wea1big.Velocity) * (1 / dt)) + 50;
					   use_wea1big++;
				   }
			   }

			   if (e->KeyCode == Keys::E)
			   {
				   if (useP1HP < 1)
				   {
					   compute_stage();
					   player1.point.HP = player1.point.HP + 40;
					   useP1HP++;
				   }
			   }
		   }

		   //player2

		   if (round_count.stage == 1)
		   {
			   if (e->KeyCode == Keys::M)
			   {
				   player2.vel.W = 0.174 * 5;
			   }
			   if (e->KeyCode == Keys::U)
			   {
				   player2.vel.W = -0.174 * 5;
			   }
			   if (e->KeyCode == Keys::J)
			   {
				   player2.vel.V = 0;
				   player2.vel.W = 0;
			   }
			   if (e->KeyCode == Keys::N)
			   {
				   compute_stage();
				   wea2_time = 0;
				   wea2.enable = 1;
				   wea2.pos.X = player2.pos.X;
				   wea2.pos.Y = player2.pos.Y;
				   //tank_profile.point.SP = tank_profile.point.SP - wea.point.SP;
				   wea2.counter = int((wea2.range / wea2.Velocity) * (1 / dt)) + 50;
			   }
			   if (e->KeyCode == Keys::H)
			   {
				   if (use_protectwall2 < 2)
				   {
					   compute_stage();
					   protectwall2[0].enable = 1;
					   protectwall2[1].enable = 1;
					   protectwall2[2].enable = 1;
					   protectwall2[3].enable = 1;
					   protectwall2[4].enable = 1;
					   use_protectwall2++;
				   }
			   }
			   if (e->KeyCode == Keys::Y)
			   {
				   click2++;
			   }

			   if (e->KeyCode == Keys::P)
			   {
				   if (use_wea2big < 2)
				   {
					   compute_stage();
					   wea2big_time = 0;
					   wea2big.enable = 1;
					   wea2big.pos.X = player2.pos.X;
					   wea2big.pos.Y = player2.pos.Y;
					   //tank_profile.point.SP = tank_profile.point.SP - wea.point.SP;
					   wea2big.counter = int((wea2big.range / wea2big.Velocity) * (1 / dt)) + 50;
					   use_wea2big++;
				   }
			   }

			   if (e->KeyCode == Keys::O)
			   {
				   if (useP2HP < 1)
				   {
					   compute_stage();
					   player2.point.HP = player2.point.HP + 40;
					   useP2HP++;
				   }
			   }
		   }
	   }
};
}
/*
			if (k == 0)
			{
				obstacle[0].enable = 1;
				obstacle[1].enable = 1;
				obstacle[2].enable = 1;
				obstacle[3].enable = 1;
				obstacle[4].enable = 1;
			}
			if (k == 1)
			{
				obstacle[5].enable = 1;
				obstacle[6].enable = 1;
				obstacle[7].enable = 1;
				obstacle[8].enable = 1;
				obstacle[9].enable = 1;
				obstacle[10].enable = 1;
				obstacle[11].enable = 1;
			}
			if (k == 2)
			{
				obstacle[12].enable = 1;
				obstacle[13].enable = 1;
				obstacle[14].enable = 1;
				obstacle[15].enable = 1;
				obstacle[16].enable = 1;
				obstacle[17].enable = 1;
				obstacle[18].enable = 1;
			}
			if (k == 3)
			{
				obstacle[19].enable = 1;
				obstacle[20].enable = 1;
				obstacle[21].enable = 1;
				obstacle[22].enable = 1;
				obstacle[23].enable = 1;
			}


								  //其餘的障礙物enable為0

			if (k == 0)
			{
				obstacle[5].enable = 0;
				obstacle[6].enable = 0;
				obstacle[7].enable = 0;
				obstacle[8].enable = 0;
				obstacle[9].enable = 0;
				obstacle[10].enable =0;
				obstacle[11].enable = 0;
				obstacle[12].enable = 0;
				obstacle[13].enable = 0;
				obstacle[14].enable = 0;
				obstacle[15].enable = 0;
				obstacle[16].enable = 0;
				obstacle[17].enable = 0;
				obstacle[18].enable = 0;
				obstacle[19].enable = 0;
				obstacle[20].enable = 0;
				obstacle[21].enable = 0;
				obstacle[22].enable = 0;
				obstacle[23].enable = 0;
			}
			if (k == 1)
			{
				obstacle[0].enable = 0;
				obstacle[1].enable = 0;
				obstacle[2].enable = 0;
				obstacle[3].enable = 0;
				obstacle[4].enable = 0;
				obstacle[12].enable = 0;
				obstacle[13].enable = 0;
				obstacle[14].enable = 0;
				obstacle[15].enable = 0;
				obstacle[16].enable = 0;
				obstacle[17].enable = 0;
				obstacle[18].enable = 0;
				obstacle[19].enable = 0;
				obstacle[20].enable = 0;
				obstacle[21].enable = 0;
				obstacle[22].enable = 0;
				obstacle[23].enable = 0;
			}
			if (k == 2)
			{
				obstacle[0].enable = 0;
				obstacle[1].enable = 0;
				obstacle[2].enable = 0;
				obstacle[3].enable = 0;
				obstacle[4].enable = 0;
				obstacle[5].enable = 0;
				obstacle[6].enable = 0;
				obstacle[7].enable = 0;
				obstacle[8].enable = 0;
				obstacle[9].enable = 0;
				obstacle[19].enable = 0;
				obstacle[20].enable = 0;
				obstacle[21].enable = 0;
				obstacle[22].enable = 0;
				obstacle[23].enable = 0;
			}
			if (k == 3)
			{
				obstacle[0].enable = 0;
				obstacle[1].enable = 0;
				obstacle[2].enable = 0;
				obstacle[3].enable = 0;
				obstacle[4].enable = 0;
				obstacle[5].enable = 0;
				obstacle[6].enable = 0;
				obstacle[7].enable = 0;
				obstacle[8].enable = 0;
				obstacle[9].enable = 0;
				obstacle[10].enable = 0;
				obstacle[11].enable = 0;
				obstacle[12].enable = 0;
				obstacle[13].enable = 0;
				obstacle[14].enable = 0;
				obstacle[15].enable = 0;
				obstacle[16].enable = 0;
				obstacle[17].enable = 0;
				obstacle[18].enable = 0;
			}
			*/

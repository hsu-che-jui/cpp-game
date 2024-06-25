#pragma once

struct bits
{
	unsigned char hit : 1;
	unsigned char speedup : 1;
	unsigned char sp_disable : 1;
	unsigned char mp_disbale : 1;
	unsigned char freeze : 1;
	unsigned char sp_up : 1;
	unsigned char mp_up : 1;
	unsigned char hp_up : 1;
};

union byte_bits
{
	bits b;
	unsigned char B;
};

struct vw
{
	float V;
	float W;
};

struct vxy
{
	float Vx;
	float Vy;
};

struct position
{
	float X;
	float Y;
	float Theta = 1.57;
};



struct points
{
	float HP;
	float SP;
	float MP;
};

struct profile
{
	char name[20];
	struct position pos;
	struct vw vel;
	struct points point;
	int t;
	union byte_bits status;
	float width = 20;
	bool enable = 1;
};


struct weapon_profile
{
	char name[20];
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	int counter;
	float diameter = 10;
	bool enable = 0;
	bool bosswea_enable = 0;
};



struct item_profile     //·Å¬u 
{
	char c;
	struct position pos;
	int counter;
	float diameter = 15;
	bool enable = 1;
};


struct Round
{
	int stage = 0;
	int round1 = 1;
	bool tank_round = 1;
	bool enemy_round = 1;
	int compute_round_time = 0;
};


struct protect
{
	char c;
	struct position pos;
	int counter;
	float diameter = 20;
	bool enable = 0;
};


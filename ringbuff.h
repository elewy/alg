#pragma once
#include <vector>
#include <string>
#define MAX_SIZE 512
using namespace std;

struct __info
{
	string str;
	int num;
	void clear()
	{
		str = "";
		num = 0;
	}
	//void operator =( __info da )
	//{
	//	this->num = da.num;
	//	this->str = da.str;
	//}
};

class ringbuff
{
public:
	vector<__info> data;
	int n_r_pos;
	int n_w_pos;
	ringbuff();
	~ringbuff();
	int size_write();
	int read_size(vector<__info>&, int );
	int write_size(vector<__info>&);
};


#include "ringbuff.h"

int ringbuff::size_write()
{
	if (n_r_pos + 1 == n_w_pos)
	{
		return MAX_SIZE;
	}
	else if (n_r_pos < n_w_pos)
	{
		return MAX_SIZE - n_w_pos + n_r_pos + 1;
	}
	else
	{
		return n_r_pos - n_w_pos;//配合 n_r_pos = -1 , n_w_pos = 1 使其中间间隔一位，隔绝冲突的可能
	}
}
int ringbuff::read_size( vector<__info>& da, int size )
{
	int tmp = MAX_SIZE - size_write();
	if (tmp > size)
	{
		tmp = size;
	}
	for (int i = 0; i < tmp; i++)
	{
		if( ++n_r_pos < MAX_SIZE )
			da.push_back( data[n_r_pos] );
		else
		{
			n_r_pos = 0;
			da.push_back( data[0] );
		}
	}
	return 0;
}
int ringbuff::write_size( vector<__info>& da )
{
	int tmp = da.size();
	if (tmp > size_write() || tmp == 0 )
	{
		return -1;
	}
	else
	{
		for (vector<__info>::iterator it = da.begin(); it != da.end(); it++)
		{
			if (n_w_pos + 1 == MAX_SIZE)
			{
				data[n_w_pos] = *it;
				n_w_pos = 0;
			}
			else
			{
				data[n_w_pos++] = *it;
			}
		}
	}
	return 0;
}

ringbuff::ringbuff()
{
	n_r_pos = -1;
	n_w_pos = 0;
	__info tmp;
	tmp.clear();
	for (int i = 0; i < MAX_SIZE; i++)
	{
		data.push_back( tmp );
	}
}

ringbuff::~ringbuff()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		data.pop_back();
	}
}
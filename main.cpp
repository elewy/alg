#include "ringbuff.h"
#include <iostream>
#include <fstream>
int main()
{
	ringbuff as;
	__info data;
	data.num = 0;
	data.str = "h";
	long i = 0;
	vector<__info> dat;
	dat.push_back( data );
	vector<__info> li;
	ofstream co1;
	co1.open( "E:\\1.txt", std::fstream::app );
	ofstream co2;
	co2.open( "E:\\2.txt", std::fstream::app );
	while ( ++i )
	{
		dat[0].num++;
		if (i % 377 == 0)
		{//读
			as.read_size(li,10);
			for (auto it = li.begin(); it != li.end(); it++)
			{
				static int abc = 0;
				co1 << abc++ << "\t----" << it->num << "\t----" << it->str << "\n";
			}
			int i = li.size();
			for (int it = 0; it < i; it++)
			{
				li.pop_back();
			}
		}
		else
		{
			if ( 0 == as.write_size( dat ))//只有写入ringbuff成功的数值，才被写入文件
			{
				static int cba = 0;
				co2 << cba++ << "\t----" << dat[0].num << "\t----" << dat[0].str << "\n";
			}
		}
	}
	return 0;
}
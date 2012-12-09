/*
ID: azizi.h1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int times[7];
int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int a;
	fin >> a;
	int month[12];
	month[0]=31;
	month[1]=28;
	month[2]=31;
	month[3]=30;
	month[4]=31;
	month[5]=30;
	month[6]=31;
	month[7]=31;
	month[8]=30;
	month[9]=31;
	month[10]=30;
	month[11]=31;
	int day=0;
	int year=1900;
	for(int i=0;i < a;i++)
	{
		month[1]=28;
		if((year%100) != 0)
		{
			if(year%4 == 0)
				month[1]=29;		
		}
		else
			if(year%400 == 0)
				month[1]=29;		
		for(int n=0;n < 12;n++)
		{
			for(int t=0;t < month[n];t++)
			{
				if(t==12)
					times[day]++;
				day++;
				if(day==7)
					day=0;
			}
		}
		year++;
	}
	fout << times[5] << ' ' << times[6] << ' ' << times[0] << ' ' << times[1] << ' ' << times[2] << ' ' << times[3] << ' ' << times[4] << endl;
}

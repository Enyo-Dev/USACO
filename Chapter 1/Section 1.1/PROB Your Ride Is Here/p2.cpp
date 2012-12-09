/*
ID: azizi.h1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string s,s1;
	fin >> s >> s1;
	int a, b=1, c=1;
	for(int i=0;i < s.length();i++)
	{
		a=((int)s[i])-64;
		if(a < 1)
            		a=1;
		b *= a;
	}
	for(int i=0;i < s.length();i++)
	{
		a=((int)s1[i])-64;
		if(a < 1)
            		a=1;
		c *= a;
	}
	b = b%47;
	c = c%47;
	if(b==c)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;
	fout.close();
	return 0;
}

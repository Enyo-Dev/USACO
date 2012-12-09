/*
ID: azizi.h1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	int a;
	fin >> a;
	string name[a];
	int start[a];
	int end[a];
	string s;
	for(int i=0;i < a;i++)
	{
		fin >> name[i];
		end[i]=0;
	}
	int y=0;
	int r=0;
	for(int i=0;i < a;i++)
	{
		fin >> s;
		int u;
		for(int w=0;w < a;w++)
			if(name[w]==s)
				u=w;
		fin >> start[u];
		y=0;
		fin >> y;
		r=0;
		if(y==0)
			r=0;
		else
			r=(int)start[u]/y;
		end[u]+= start[u]-(r*y);
		for(int e=0;e < y;e++)
		{
			fin >> s;
			for(int w=0;w < a;w++)
				if(name[w]==s)
				{
					end[w]+=r;
					break;
				}
		}
	}
	for(int t=0;t < a;t++)
		fout << name[t] << ' ' << (end[t]-start[t]) << endl;
}

/*
ID: azizi.h1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int a;
	fin >> a;
	char beads[a+1];
	fin >> beads;
	int j=1;
	char current;
	bool reshte;
	int max=0;
	for(int i=0;i < a;i++)
	{
		reshte=false;
		j=1;
		current=beads[i];
		while(j < a)
		{
			if( current == 'w' )
			{
				current = beads[(i+j)%a];
			}
			else
			{
				if( (beads[(i+j)%a]!='w') && (beads[(i+j)%a]!=current) )
				{
					if(reshte==true)
						break;
					reshte=true;
					current=beads[(i+j)%a];
					
				}
			}
			j++;
		}
		if(j > max)
			max=j;
	}
	fout << max << endl;
	return 0;
}

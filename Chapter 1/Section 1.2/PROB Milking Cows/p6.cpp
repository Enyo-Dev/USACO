/*
ID: azizi.h1
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int a;
int milk[1000000];
int milk1[1000000][2];

void sort()
{
	int minx;
	for(int y=0; y < a; y++)
        {
        	for ( int k =0; k < (a-1-y); k++ )
        	if(milk1[k][0]>milk1[k+1][0])
            	{
                	minx = milk1[k+1][0];
                	milk1[k+1][0] = milk1[k][0];
                	milk1[k][0] = minx;
			minx = milk1[k+1][1];
                	milk1[k+1][1] = milk1[k][1];
                	milk1[k][1] = minx;
            	}
        }
}

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	fin >> a;
	int start;
	int end;
	int maxget=0;
	int minget=1000000;
	for(int i=0;i < a;i++)
	{
		fin >> start >> end;
		milk1[i][0]=start;
		milk1[i][1]=end;
		if(start < minget)
			minget=start;
		if(end > maxget)
			maxget=end;
		for(int y=start;y < end;y++)
		{
			milk[y-1]=1;
		}
	}
	sort();
	int max=0;
	int min=0;
	int maxin;
	int w=0;
	for(int i=minget-1;i < maxget;i++)
	{
		if(milk[i]==1)
			w++;
		else
		{	
			if(w > max)
				max=w;
			w=0;
		}
	}
	w=0;
	for(int i=minget;i < maxget;i++)
	{
		if(milk[i]==0)
			w++;
		else
		{	
			if(w > min)
				min=w;
			w=0;
		}
	}
	fout << max << ' ' << min << endl;
}

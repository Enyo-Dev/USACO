/*
ID: azizi.h1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int table[8];

int main()
{
	/*
	Translate:(using [x][y] form)

		0.#1: [y][n-x-1].
		1.#2: [n-x-1][n-y-1].
		2.#3: [n-y-1][x].
		3.#4.1: [x][n-y-1].
		4.#4.2: [n-x-1][y].
		5.#5.1#1: [x][n-y-1] -> [n-y-1][n-x-1].
		6.#5.1#2: [x][n-y-1] -> [n-x-1][y].
		7.#5.1#3: [x][n-y-1] -> [y][x].
		8.#5.2#2: [x][n-y-1] -> [x][n-y-1].
		#6: [x][y].
		#7: Not Exist.
	*/
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	int n;
	fin >> n;
	char now[n][n];
	char target[n][n];
	for(int i=0;i < n;i++)
		for(int y=0;y < n;y++)
			fin >> now[i][y];
	for(int i=0;i < n;i++)
		for(int y=0;y < n;y++)
			fin >> target[i][y];
	for(int x=0;x < n;x++)
		for(int y=0;y < n;y++)
		{
			if( now[x][y]==target[y][n-x-1] )
				table[0]++;
			if( now[x][y]==target[n-x-1][n-y-1] )
				table[1]++;
			if( now[x][y]==target[n-y-1][x] )
				table[2]++;
			if( now[x][y]==target[x][n-y-1] )
				table[3]++;
			//if( now[x][y]==target[n-x-1][y] )
				//table[4]++;
			if( now[x][y]==target[n-y-1][n-x-1] )
				table[4]++;
			if( now[x][y]==target[n-x-1][y] )
				table[5]++;
			if( now[x][y]==target[y][x] )
				table[6]++;
			//if( now[x][y]==target[x][n-y-1] )
				//table[8]++;
			if( now[x][y]==target[x][y] )
				table[7]++;
		}
	int max=-1;
	for(int i=0;i < 9;i++)
	{
		if(table[i]==(n*n))
		{
			max=i;
			break;
		}
	}
	max++;
	if(max==0)
		fout << 7 << endl;
	else if( (max==5) || (max==6) || (max==7) )
		fout << 5 << endl;
	else if(max==8)
		fout << 6 << endl;
	else fout << max << endl;
	return 0;
}

/*
ID: azizi.h1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string reverse(string s)
{
	char s1;
	for(int i=0;i < s.length()/2;i++)
	{
		s1=s[i];
		s[i]=s[s.length()-1-i];
		s[s.length()-1-i]=s1;
	}
	return s;
}

string inbase(int a,int b)
{
	stringstream ans;
	int tagh;
	int baghi;
	char c;
	while(a > 1)
	{
		tagh = a / b;
		baghi = a % b;
		if(baghi > 9)
		{
			c = ((baghi -10) + 'A');
			ans << c;
		}
		else
			ans << baghi;
		a = tagh;
	}
	if(a == 1) 
	{
		ans << 1;
	}
	string s = ans.str();
	s = reverse(s);
	return s;
}

bool palin(string s)
{
	bool a=true;
	for(int i=0;i < s.length()/2;i++)
	{
		if(s[s.length()-1-i] != s[i])
		{
			a=false;
			break;
		}
	}
	if(a)
		return true;
	else
		return false;
}

int main() {
    	ofstream fout ("palsquare.out");
    	ifstream fin ("palsquare.in");
	int b;
	fin >> b;
	for(int i=1; i<300; i++) 
	{
		string s = inbase(i*i, b);
		if(palin(s))
			fout << inbase(i, b) << " " << s << endl;
	}
	return 0;
}


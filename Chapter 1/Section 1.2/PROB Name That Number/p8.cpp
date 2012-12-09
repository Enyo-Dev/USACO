/*
ID: azizi.h1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string doit(string get)
{
    string n;
    for (int i = 0; i < get.length(); ++i)
    {
        switch(get[i]){
	case 'A':
	case 'B':
	case 'C': {
	    n.append("2");
	}
	    break;
	case 'D':
	case 'E':
	case 'F':{
	    n.append("3");
	}
	    break;
	case 'G':
	case 'H':
	case 'I':{
	    n.append("4");
	}
	    break;
	case 'J':
	case 'K':
	case 'L':{
	    n.append("5");
	}
	    break;
	case 'M':
	case 'N':
	case 'O':{
	    n.append("6");
	}
	    break;
	case 'P':
	case 'R':
	case 'S':{
	    n.append("7");
	}
	    break;
	case 'T':
	case 'U':
	case 'V':{
	    n.append("8");
	}
	    break;
	case 'W':
	case 'X':
	case 'Y':{
	    n.append("9");
	}
	    break;

	}
    }
    return n;
}

int main()
{
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream fdict ("dict.txt");
	string number;
	fin >> number;
	string all;
	int nu=number.length();
	int w=0;
     	while(fdict >> all)
		if(all.length() == nu)
			if( doit(all) == number )
			{
				fout << all << endl;
				w=1;
			}
	if(w==0)
		fout << "NONE" << endl;
	fdict.close();
	return 0;
}

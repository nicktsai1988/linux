//#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;
string str;
int len;

void ReadFileDataFromLBLIntoString()
{  
	ifstream fin("connect.c");
	if(!fin.eof())
	getline(fin,str,(char)EOF);
	len=str.length()-1;
	cout<<"len : "<<len<<endl;
	fin.close();
}

int main()
{
	map<char,int> word_count;
	char word;

	int i=0;
	ReadFileDataFromLBLIntoString();

	while(i<len)
	{
		word=str[i];
	    i++;
		++(word_count[word]);
   }
	//cout<<word<<" "<<word_count[word];
	cout<<" Element number: "<<word_count.size()<<endl;


	return 0;
} 


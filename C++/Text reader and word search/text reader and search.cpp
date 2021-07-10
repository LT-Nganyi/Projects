#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
int main()
{
	vector <string> word;
	string a;
	string szFilename="";
	cout<<"Enter name of file to read.\n def for default"<<endl;
	cin>>szFilename;
	
	ifstream read;
	if(szFilename=="def")
	{
	   	read.open("text reader trial.txt");	
	}else
	{
		szFilename+=".txt";
		read.open(szFilename.c_str());	
	}
		try
	{
		if(!read.is_open())
		{
			throw 2020;
		}	
	}
	
	catch(int x)
	{	
		cerr<<"Could not find file!"<<endl;
		cout<<"Error "<<x<<endl;
	}
	while(read>>a)
	{	
		word.push_back(a);	
	}
	static int cnt=word.size();
	cout<<"Word count = "<<cnt<<endl;
	for(int i=0;i<cnt;i++)
	{
		cout<<word[i]<<" ";
	}
	
	cout<<"\n\n\nEnter word to search: "<<endl;
	cin>>a;
	string b=(a+",");
	static int no=0;
	for(int i=0;i<cnt;i++)
	{
		if(word[i]==a)
		{
			
			no++;	 	
		}
		if(word[i]==b)
		{
		   	no++;
		}
	}
	
	cout<<"\nThe word "<<a<<" has been found "<<no<<" times."<<endl;
	
	
	return 0;
}
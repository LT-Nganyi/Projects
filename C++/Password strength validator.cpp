///Code to calidate the strength of a password and give the specifications.

#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

int main()
{
	char username[25];
	char a[25];
	
	cout<<"Enter username."<<endl;
	cin>>username;
	system("CLS");
//	cout<<sizeof(username)<<endl;
//	cout<<strlen(username)<<endl;\\ length of the characters in the array.
	cout<<"confirm username..."<<endl;
	cin>>a;
	int n=0;
	for(unsigned x=0;x<strlen(username);x++)
	{
		if(isupper(username[x]))//if uppercase is present
		{
			cout<<"uppercase present."<<endl;
			n++;
		}
		if(isdigit(username[x]))//if number is present
		{
			cout<<"Number present"<<endl;
			n++;
		}
		if(ispunct(username[x]))//if special character is present
		{
			cout<<"Punctuation present."<<endl;
			n++;
		}
	}
switch(n)
{
	case 0:
		cout<<"Very weak."<<endl;
		break;
	case 1:
		cout<<"Weak."<<endl;
	   	break;
	case 2:
		cout<<"Moderate."<<endl;
		break;
	case 3:
		cout<<" Strong."<<endl;
		break;
}if(n>3)
{
	cout<<"Very strong."<<endl;
}
	if(strcmp(username,a)==0)
	{
		cout<<"correct username."<<endl;
	}else
	{
		cout<<"Wrong username."<<endl;
	}

	
	
	
	
	return 0;
}
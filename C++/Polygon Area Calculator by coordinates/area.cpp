#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int n;
	double p=0,q=0;
	double area;

	cout<<"    Welcome to the Tc Area Calculator.\n  How many points in the polygon?"<<endl;
	cin>>n;
	double N[n+1],E[n+1];
	system("CLS");

	int verify=2;
	do
	{	int x=0;
		cout<<"Input coordinates of stations in clockwise order."<<endl;
		do
		{
	  		cout<<"\nPoint "<<x+1<<": "<<endl;
	  		cout<<"N: ";
	  		cin>>N[x];
	  		cout<<"E: ";
	  		cin>>E[x];
	  		x++;

		}while(x<n);
		cout<<"Check your values!\n\n 1) Proceed to compute.\n 2) Make changes."<<endl;
		cin>>verify;
		system("CLS");
	}while(verify==2);

	// assign values of the 1st station to the last extra station created by the n+1 operator
	N[n]=N[0]; E[n]=E[0];
//	cout<<N[n+1]<<endl;
//	cout<<E[n+1]<<endl;
	for(int x=0;x<n;x++)
	{
		p+=N[x]*E[x+1];
	}
	for(int x=n;x>0;x--)
	{
		q+=N[x]*E[x-1];
	}
	if(p>q)
		area=(p-q)/2;
	else
	{
		area=(q-p)/2;
	}

//	cout<<p<<endl;
//	cout<<q<<endl;
	cout<<"\nArea = "<<area<<" sq metres."<<endl;
	area=area/10000;
	cout<<"\nArea = "<<area<<" Ha."<<endl;
	cout<<"\n\nThank you for using a TC Geospatial product!\n\n\t\t © 2020."<<endl;
	system("PAUSE");



	return 0;
}

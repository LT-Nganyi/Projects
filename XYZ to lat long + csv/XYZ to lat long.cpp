#include <bits/stdc++.h>
#include <fstream>

using namespace std;
double toRad(double x)
{
	return x/57.29577;
}
double toDeg(double x)
{
	return x*57.29577;
}
void printDMS(double f)
{
	int	x=(floor(f));
	int y=(floor((f-x)*60));
	double	z=(((f-x)*60)-y)*60;
	int	u=roundf(z);
cout<< x<<"�"<<y<<"'"<<u <<"\""<<endl;; 
}
double sqr(double x)
{
	return x*x;
}
int main()
{
ofstream write("Iterations.csv");
	if(!write.is_open())
	{
		cerr<<"File is already open!"<<endl;
		return 1;
	}
	write << "Iteration"<<"," << "V" << "," << "Latitude" <<endl;


	
	long double a,f,x,y,z=0.0;
	long double lat,lon =0.0;
	cout<<"Enter the following values:"<<endl;
	cout<<"a:";
	cin>>a;
	cout<<"\n1/f:";
	cin>>f;
	cout<<"\nX:";
	cin>>x;
	cout<<"\nY:";
	cin>>y;
	cout<<"\nZ:";
	cin>>z;
	cout<<endl;
	lon= atan(y/x);
	
	
	////end of longitude
	double latNew = asin(z/a);
//	cout<<latNew<<endl;
	double b=((f*a)-a)/f;
//	cout<<b<<endl;
	long double e =((a*a)-(b*b))/(b*b);
//	cout<<setprecision(8)<<e<<endl;
	int count=1;
	do
	{
	lat= latNew;	
	long double sinLat =sin(latNew);
	long double v= a/sqrt((1-(e*sqr(sinLat))));
	latNew = atan((z+(v*e*sinLat))/sqrt(sqr(x)+sqr(y)));
	cout << fixed << setprecision(8)<<endl;
	cout<<"Iteration "<<count<<endl;
	cout<<" V:"<< v<<endl;
	cout<<" Lat:"<<latNew<<endl;
//	cout<<"\n"<<lat<<endl;
//	cout<<latNew<<endl;
	write << fixed << setprecision(10) << count << "," << v <<"," << toDeg(latNew)<< endl;
	count++;
	}while(lat!=latNew || count ==11);
	
	cout<<"\nFinal Results."<<endl;
	//print Latitude
	cout<<"\nLatitude: "<<toDeg(lat)<<endl;
	printDMS(toDeg(lat));
	//print Longitude
	cout<<"\nLongitude: "<<toDeg(lon)<<endl;
	printDMS(toDeg(lon));

	write.close();	
	return 0;
}
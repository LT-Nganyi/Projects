#include<iostream>
#include<string>
#include<stdlib.h>
#include<cctype>

using namespace std;
int main()
{
    string username;
    int pin;
    int *p= new int;
    cout<<"Enter user name."<<endl;
    cin>>username;
    cout<<"Enter new pin."<<endl;
    cin>>pin;
    do {
        cout<<"Confirm new pin."<<endl;
        cin>>*p;

    } while(pin!=*p);
    delete p;

    cout<<"Welcome "<<username<<". Your account has been successfully created!"<<endl;
    cout<<"\n Do you want to login?.\n    Yes-Y\n    No -N"<<endl;
    char x;
    cin>>x;
    if(x=='y')
    {   cout<<"Username: "<<endl;
        cin>>username;
        cout<<"Password: "<<endl;
        cin>>*p;
		int x=3;
        while(*p!=pin)
        {   
           if(x>0)
            {
                cerr<<"Incorrect Password! Try again"<<x<<" Attempts remaining!"<<endl;
                cout<<"Password:"<<endl;
                cin>>*p;
                x--;
                system("CLS");
            }else
			{
				cerr<<"You have entered an incorrect password 3 times. You cannot login.\n Please contact customer care. "<<endl;
        		delete p;
				return 0;
			}
            
        }
        delete p;
        cout<<"Successfully logged in!"<<endl;
    }
    return 0;
}

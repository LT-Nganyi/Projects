/// This is a demo warehouse management system. it has 3 rows with 3 columns 
/// and 3 levels high. It can be used to manage stuff and paired with a robot
/// it can direct the robot where to go and which item to retreive. 
/// 
/// 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <conio.h>
using namespace std;

int ID;	
bool back;
//bool noSpace=false;

vector <int> vecID;
vector <int> vecX;
vector <int> vecY;
vector <int> vecZ;
// This initialises the vector with zeros to avoid storing data in the zero 
// shelf. Which does not exist.
void InitialiseVectors()
{
	int rd;
	vecID.push_back(0);
	vecX.push_back(0);
	vecY.push_back(0);
	vecZ.push_back(0);
	
	ifstream readID;
	ifstream readX;
	ifstream readY;
	ifstream readZ;
	readID.open("Data\\ID.csv");
	while(readID>>rd)
	{
		vecID.push_back(rd);
	}
	readID.close();
	
	readX.open("Data\\X.csv");
	while(readX>>rd)
	{
		vecX.push_back(rd);
	}
	readX.close();
	
	readY.open("Data\\Y.csv");
	while(readY>>rd)
	{
		vecY.push_back(rd);
	}
	readY.close();
	
	readZ.open("Data\\Z.csv");
	while(readZ>>rd)
	{
		vecZ.push_back(rd);
	}
	readZ.close();
	
}
// Checking available space in the warehouse
int chkSpace()
{
//	cout<<"Space Available: "<<28-vecID.size()<<" slots"<<endl;
	return 28-vecID.size();
}
// Adds items to the warehouse with the item ID being the argument
// If a location is found in the vector, the for loop goes to the next iteration
// If not,the location is then placed in the vector together with its ID
// and all the other loops are terminated.
// The vector index[x] has data for a single item. 
void addItem(int ItemID)
{	int n=1;
	bool placeSuccess= false;
	for(int i=1;i<=3;i++)//row(x)
	{
		if(placeSuccess)
			break;
		for(int j=1;j<=3;j++)//column(y)
		{
			if(placeSuccess)
				break;
			for(int k=1;k<=3;k++)// height(z) or stack level
			{
				if(placeSuccess)
					break;
/*				if(n>26)
				{
					noSpace=true;
					placeSuccess=true;
				}
*/				if(i==vecX[n] && j== vecY[n] && k==vecZ[n])
				{	
					n++;
				}
							
				else
				{
				/*	vecID.push_back(ItemID);
					vecX.push_back(i);
					vecY.push_back(j);
					vecZ.push_back(k);
				*/
					vecID.insert(vecID.begin()+n,ItemID);
					vecX.insert(vecX.begin()+n,i);
					vecY.insert(vecY.begin()+n,j);
					vecZ.insert(vecZ.begin()+n,k);
					placeSuccess=true;
							
				}
						
			}
		}
	}
	if(placeSuccess)
	{
		cout<<"Item ID: "<<ItemID<<" has been succesfully placed!"<<endl;
	}
/*	if(placeSuccess && noSpace)
		cout<<"Oops No more Space!"<<endl;
		
	cout<<"Number of Items: "<<vecID.size()-1<<endl;
*/	
}
// Items in the warehouse are shown using this function
void showItems()
{
		for(unsigned int n=1;n<vecID.size();n++)
	{
		cout<<"Item"<<n<<":"<<endl;
		cout<<"\tID: "<<vecID[n]<<endl;
		cout<<"\tX: "<<vecX[n]<<endl;
		cout<<"\tY: "<<vecY[n]<<endl;
		cout<<"\tz: "<<vecZ[n]<<endl;
		
	}
}
void showItemDesc(int idIndex)
{
	
	    cout<<"Item Details."<<endl;
    	cout<<"\tID: "<<vecID[idIndex]<<endl;
		cout<<"\tX: "<<vecX[idIndex]<<endl;
		cout<<"\tY: "<<vecY[idIndex]<<endl;
		cout<<"\tz: "<<vecZ[idIndex]<<endl;
		cout<<"...add More Details..."<<endl;	
	

}
// Data is saved onto individual files for retreival later when the program is run again.
// 
void printItems()
{
	ofstream writeId("Data\\ID.csv");
	ofstream writeX("Data\\X.csv");
	ofstream writeY("Data\\Y.csv");
	ofstream writeZ("Data\\Z.csv");
	for(unsigned int x=1;x<vecID.size();x++)
	{
		writeId<<vecID[x]<<endl;
		writeX<<vecX[x]<<endl;
		writeY<<vecY[x]<<endl;
		writeZ<<vecZ[x]<<endl;
	}
	writeId.close();
	writeX.close();
	writeY.close();
	writeZ.close();
}

// function searches for the ID and returns its index in the ID vector for further processing.
int searchItem(int ItemID)
{
	bool itemFound= false;
	for(unsigned int x=1;x<vecID.size();x++)
	{
		if(ItemID==vecID[x])
		{
			cout<<"Item ID number : "<<ItemID<<" has been found!"<<endl;
			itemFound=true;
			return x;
		}
	}
	if(!itemFound)
		cout<<"Ooops! Item ID not found."<<endl;
	return 0;
}
void removeItem(int itemID)
{
	int index= searchItem(itemID);
	//changed from (index >1) to (index>=1) because item in pos 1,1,1 was not being retreived
	if(index>=1)
	{
		cout<<"The item is on its way."<<endl;
		//send item location to retreiver and receive acknowledgement of retreival before deleting
		vecID.erase(vecID.begin()+index);
		vecX.erase(vecX.begin()+index);
		vecY.erase(vecY.begin()+index);
		vecZ.erase(vecZ.begin()+index);
	}
	
}
////  WARNING DELETES ALL SAVED DATA.
void deleteAll()
{
	vecID.erase(vecID.begin()+1,vecID.end());
	if(vecID.size()==1)
	{
		system("cls");
		cout<<"Database has been cleared successfully!"<<endl;
			
	}
		
}
void goBack()
{
	back=false;
	cout<<"\n  1. Back.\n  0. Save and Exit."<<endl;
	cin>>back;	
}

int main()
{
	InitialiseVectors();

	int option;
	do 
	{
		system("cls");
		cout<<"Welcome to the TC W.M.S "<<endl;
		cout<<"What would you like to do?\n\n  1. Add Item to storage.\n  2. Search for Item in storage."<<endl;
		cout<<"  3. Retreive Item.\n  4. Show All Items.\n  5. Clear Database. \n  0. Exit"<<endl;
		
//		try
//		{
//			if(!__is_integer(cin.get()))
//			{throw 111;}
//		}
//		catch( int error)
//		{cout<<"Wrong input. Please try again."<<endl;
//		goBack();}
		cin>>option;

		system("cls");
	
		switch(option)
		{
			case 1:
				{
					int Number,x=0;
					cout<<"Space Available: "<<chkSpace()<<" slots."<<endl;
					cout<<"How many items do you want to place"<<endl;
					cin>>Number;
					// try block to handle exception if user enters a number more
					// than the number of spaces available.
					// Flags and returns to main menu
						try
						{
							if(Number>chkSpace())
								throw 101;
							if(Number<=0) // added this option 
								throw 102;
						}
						catch(int err)
						{
							cout<<"\nError "<<err<<endl;
							if(err == 101)
							{cout<<"Number of items exceeds storage space available!"<<endl;}
							else{cout<<"Cannot add zero items to inventory."<<endl;}
							
							cout<<"Please Try again."<<endl;
							goBack();
							break;
						}
						if(Number<=0) // added this option 
						{goBack();}
					do
					{
						cout<<"\nAdd item ID to place: ";
						cin>>ID;
						addItem(ID);
						x++;
					}while(x<Number);
					printItems();
					goBack();
				}
				break;
			case 2:
				{
					int searchID,index;
					cout<<"\nItem ID to search: ";
					cin>>searchID;
					index=searchItem(searchID);
					showItemDesc(index);
					goBack();
				}
				break;
			case 3:
				{
					cout<<"Enter Item ID to retreive: ";
					cin>>ID;
					removeItem(ID);	
					printItems();
					goBack();
				}
				break;
			case 4:
				cout<<"Number of items in storage: "<<vecID.size()-1<<endl;
				showItems();
				goBack();
				break;
			case 5:
				{
					int opn;
					cout<<"Are you sure you want to clear the database?\nThis cannot be undone!"<<endl;
					cout<<" 1. NO\n 2. YES"<<endl;
					cin>>opn;
					if(opn==2)
					{
						deleteAll();
						printItems();
					}
				}
				goBack();
				break;
			case 0:
				cout<<"Goodbye"<<endl;
				back=false;
				break;
			default: //added the default case incase of wrong input
				cout<<"Wrong input. Please try again."<<endl;
				goBack();
				break;
		}
	}while(back);
	
		system("pause");

return 0;
}


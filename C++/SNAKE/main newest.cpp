#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int height=20,width=20;
int x,y,fruitX,fruitY,score;
int level,slow=100,medium=75,fast=50;
int tailX[100],tailY[100];
int nTail;
enum eDirection {STOP =0, LEFT, RIGHT, UP,DOWN} ;
eDirection dir;
void Setup()
{
   gameover=false;
   dir=STOP;
   x=width/2;
   y=height/2;
   fruitX= rand()% width;
   fruitY = rand()% height;
   score = 0;
   cout<<"Welcome to the TC snake game.\n Controls:\n\t Left =A\n\t Right=D\n\t Up= W\n\t Down=S\n\t KillGame=X\n Watch out for your Tail! ;-)"<<endl;
   system("pause"); 
   system("cls");
   cout<<"Select Level.\n 1.Easy \n 2.Medium \n 3.Hard"<<endl;
   cin>>level;
   system("pause");
   system("cls");
   cout<<"WARNING !! \n\nSCREEN FLICKERING MAY TRIGGER EPILEPTIC SHOCK. \n PLEASE CLOSE IMMEDIATEDLY IF EXPERIENCING EYESTRAIN."<<endl;
   system("pause");

}
void Draw()
{
    system("cls");
    for(int i=0;i<width+2;i++)
        cout<<" ";
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<" ";
            if(i==y && j==x)
                cout<<"0";
            else if(i==fruitY && j== fruitX)
                cout<<"$";
            else
			{
				bool printTail=false;
				for(int k=0;k<nTail;k++)
				{
					if(tailX[k]==j && tailY[k]==i)
					{
						cout<<"o";
						printTail=true;
					}
					
				}
				if(!printTail)
					cout<<" ";
			}
             if(j== width-1)
                cout<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<width+2;i++)
        cout<<" ";
    cout<<"\nScore: "<< score <<endl;
}
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir =DOWN;
            break;
        case 'x':
            gameover=true;
            break;

        }
    }

}
void Logic()
{
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1;i< nTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
//    if(x>=width|| x<0|| y<0 || y>=height)
//        gameover=true;
	if(x>=width)
		x=0;
	else if(x<0)
		x=width-1;
	
	if(y>=height)
		y=0;
	else if(y<0)
		y=height-1;
	
    if(x==fruitX && y==fruitY)
    {
		score+=10;
        fruitX= rand()% width;
        fruitY = rand()% height;
		nTail++;
    }
    // for loop to evaluate whether snake has bitten itself
    for(int k=0;k<nTail;k++)
	{
		if(tailX[k]==x && tailY[k]==y)
			gameover=true;
	}
	//speed increment of game baased on score.
	switch(score)
	{
		case 100:
			slow-=1;
			medium-=1;
			fast-=1;
			break;
		case 200:
			slow-=1;
			medium-=1;
			fast-=1;
			break;
		case 300:
			slow-=1;
			medium-=1;
			fast-=1;
			break;
	}
		

    if(gameover)
    {
         cout<<"Oops! Game over.\n Try Again."<<endl;
/*       cout<<"Do you want to play again?\n Y or N"<<endl;
         if(_kbhit())
		 {
		 	switch(_getch())
		 	{
			 	case 'y':
			 		gameover=false;
			 		break;
			 	case 'n':
			 		cout<<"Thank you for playing the TC snake game. \nPlease give me feedback.:-)"<<endl;
					system("pause");	
					break;
					 
			}
		 }
*/         system("pause");
    }


}
void setLevel()
{
	switch(level)
	{
		case 1:
			Sleep(slow);
			break;
		case 2:
			Sleep(medium);
			break;
		case 3:
			Sleep(fast);
			break;
	}

}
int main()
{
    Setup();
    while(!gameover)
    {
        Draw();
        Input();
        Logic();
        setLevel();
    }



    return 0;
}

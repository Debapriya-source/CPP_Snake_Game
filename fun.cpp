#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int height=20,width=30;
int x,y,foodX,foodY,score,tailX[100],tailY[100],ntail;
enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;
void setup();
void screen();
void input();
void logic();

void setup()
{
	gameover=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	foodX= rand()%width;
	foodY= rand()%height;
	score=0;
}
void screen()
{
	system("cls");
	cout<<"\tSNAKE GAME\n";
	for(int i=0;i<width+2;i++)
	cout<<"*";
	cout<<endl;
	for(int i=0;i<height;i++)
	{	
		for(int j=0;j<width;j++)
		{
			if(j==0)
				cout<<"*";
			if(j==x && i==y)
				cout<<"O";
			else if(j==foodX && i==foodY)
				cout<<"#";
			else
			{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					if(j==tailX[k] && i==tailY[k])
					{
						cout<<"o";
						print=true;
					}
				}
				if(!print)
					cout<<" ";
			}
			if(j==width-1)
				cout<<"*";
		}		
		cout<<endl;
	}	
	for(int i=0;i<width+2;i++)
	cout<<"*";
	cout<<endl;
	cout<<"SCORE: "<<score;
	cout<<"\n\nHIT 'q' TO QUIT!";
}
void input()
{	
	if(_kbhit())
	{
	
		switch(_getch())
		{
			case 75 :                          //scroll key codes: w=72,a=75,s=80,d=77 ;-)
				dir=LEFT;
			break;
			case 'a':
				dir=LEFT;
				break;
			case 72:
				dir=UP;
			break;
			case 'w':
				dir=UP;
			break;
			case 80:
				dir=DOWN;
			break;
			case 's':
				dir=DOWN;
			break;
			case 77:
				dir=RIGHT;
			break;
			case 'd':
				dir=RIGHT;
			break;
			case 'q':
				gameover=true;
			break;
		}
	}
}
void logic()
{
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1;i<ntail;i++)
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
	if(x==width)
	x=0;
	if(x<0)
	x=width;
	if(y==height)
	y=0;
	if(y<0)
	y=height;
	for(int i=0;i<ntail;i++)
	{
		if(tailX[i]==x && tailY[i]==y)
		gameover=true;
	}
	if(x==foodX && y==foodY)
	{
		ntail++;
		score+=10;
		foodX=rand()%width;
		foodY=rand()%height;
	}
	
}

int main()
{
	setup();
	while(!gameover)
	{
		screen();
		input();
		logic();
	}	
	return 0;
}


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<vector>
#include<string>
#include<windows.h>
#include<time.h>
#include<map>
#include<graphics.h>

template<class T>inline T read()
{
	char c='\0';
	int sgn=1;
	T sum=0;
	while((c=getchar())<'0'||c>'9')
		if(!(c^'-'))
			sgn=-1;
	while(c>='0'&&c<='9')
	{
		sum=(sum<<1)+(sum<<3)+(c^48);
		c=getchar();
	}

	return sum*sgn;
}

template<class T>inline void write(T x)
{
	if(x<0)
		putchar('-');
	x=x>0?x:-x;
	if(x>9)
		write(x/10);
	putchar(x%10+48);
	return;
}

int win;
int gameMap[7][7];
int pos[16][2]={{1,1},{1,2},{1,3},{1,4},{2,1},{2,2},{2,3},{2,4},{3,1},{3,2},{3,3},{3,4},{4,1},{4,2},{4,3},{4,4}};
void drawNumber();
bool toSeeIfGameIsOverOrNot();
void moveUp(int p);
void moveDown(int p);
void moveLeft(int p);
void moveRight(int p);
void runGame();
int game2048();

void drawNumber()
{
	/*IMAGE img;
	loadimage(&img,_T("2.jpg"));
	putimage(0,0,&img);
	getch();
	cleardevice();*/
	cleardevice();
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			int x=100*i-100,y=100*j-100;
			IMAGE img;
			switch(gameMap[i][j])
			{
				case 2:
					loadimage(&img,_T("numbers\\2.jpg"));
					break;
				case 4:
					loadimage(&img,_T("numbers\\4.jpg"));
					break;
				case 8:
					loadimage(&img,_T("numbers\\8.jpg"));
					break;
				case 16:
					loadimage(&img,_T("numbers\\16.jpg"));
					break;
				case 32:
					loadimage(&img,_T("numbers\\32.jpg"));
					break;
				case 64:
					loadimage(&img,_T("numbers\\64.jpg"));
					break;
				case 128:
					loadimage(&img,_T("numbers\\128.jpg"));
					break;
				case 256:
					loadimage(&img,_T("numbers\\256.jpg"));
					break;
				case 512:
					loadimage(&img,_T("numbers\\512.jpg"));
					break;
				case 1024:
					loadimage(&img,_T("numbers\\1024.jpg"));
					break;
				case 2048:
					loadimage(&img,_T("numbers\\2048.jpg"));
					break;
				case 4096:
					loadimage(&img,_T("numbers\\4096.jpg"));
					break;
				case 8192:
					loadimage(&img,_T("numbers\\8192.jpg"));
					break;
				case 16384:
					loadimage(&img,_T("numbers\\16384.jpg"));
					break;
				case 32768:
					loadimage(&img,_T("numbers\\32768.jpg"));
					break;
				case 65536:
					loadimage(&img,_T("numbers\\65536.jpg"));
					break;
				case 131072:
					loadimage(&img,_T("numbers\\131072.jpg"));
					break;


			}

			putimage(y,x,&img);
		}
}

bool toSeeIfGameIsOverOrNot()
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(gameMap[i][j]==0||gameMap[i][j]==gameMap[i-1][j]||gameMap[i][j]==gameMap[i+1][j]||gameMap[i][j]==gameMap[i][j+1]||gameMap[i][j]==gameMap[i][j-1])
				return 0;
	return 1;
}

void moveUp(int p)
{
	int moved=0;
	for(int j=1;j<=4;j++)
	{
		int code[5]={};
		for(int i=2;i<=4;i++)
			for(int k=i-1;k>=1;k--)
				if(gameMap[i][j]&&!code[k]&&gameMap[i][j]==gameMap[k][j])
				{
					code[i]=code[k]=k;
					break;
				}
				
				else if(!gameMap[i][j]||gameMap[i][j]!=gameMap[k][j]&&gameMap[k][j]||code[k]!=code[i])
					break;
					
		for(int i=2;i<=4;i++)
			for(int k=i-1;k>=1;k--)
				if(code[i]==code[k]&&code[i])
				{
					gameMap[k][j]+=gameMap[i][j];
					gameMap[i][j]=0;
					moved=1;
					break;
				}
					
		for(int i=1;i<=3;i++)
			if(!gameMap[i][j])
				for(int k=i+1;k<=4;k++)
					if(gameMap[k][j])
					{
						gameMap[i][j]+=gameMap[k][j];
						gameMap[k][j]=0;
						moved=1;
						break;
					}
	}

	if(moved)
	{
		if(!p)
		{
			srand((unsigned)time(NULL));
			int r1=rand()%16;
			while(gameMap[pos[r1][0]][pos[r1][1]])
				r1=rand()%16;
			int r2=rand()%16;
			gameMap[pos[r1][0]][pos[r1][1]]=(r2?2:4);
			drawNumber();
			system("cls");
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=4;j++)
					printf("%d\t",gameMap[i][j]);
				putchar('\n');
			}
		}
	}
}

void moveDown(int p)
{
	int moved=0;
	for(int j=1;j<=4;j++)
	{
		int code[5]={};
		for(int i=3;i>=1;i--)
			for(int k=i+1;k<=4;k++)
				if(gameMap[i][j]&&!code[k]&&gameMap[i][j]==gameMap[k][j])
				{
					code[i]=code[k]=k;
					break;
				}
				
				else if(!gameMap[i][j]||gameMap[i][j]!=gameMap[k][j]&&gameMap[k][j]||code[k]!=code[i])
					break;
					
		for(int i=3;i>=1;i--)
			for(int k=i+1;k<=4;k++)
				if(code[i]==code[k]&&code[i])
				{
					gameMap[k][j]+=gameMap[i][j];
					gameMap[i][j]=0;
					moved=1;
					break;
				}
					
		for(int i=4;i>=2;i--)
			if(!gameMap[i][j])
				for(int k=i-1;k>=1;k--)
					if(gameMap[k][j])
					{
						gameMap[i][j]+=gameMap[k][j];
						gameMap[k][j]=0;
						moved=1;
						break;
					}
	}

	if(moved)
	{
		if(!p)
		{
			srand((unsigned)time(NULL));
			int r1=rand()%16;
			while(gameMap[pos[r1][0]][pos[r1][1]])
				r1=rand()%16;
			int r2=rand()%16;
			gameMap[pos[r1][0]][pos[r1][1]]=(r2?2:4);
			drawNumber();
			system("cls");
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=4;j++)
					printf("%d\t",gameMap[i][j]);
				putchar('\n');
			}
		}
	}
}

void moveLeft(int p)
{
	int moved=0;
	for(int i=1;i<=4;i++)
	{
		int code[5]={};
		for(int j=2;j<=4;j++)
			for(int k=j-1;k>=1;k--)
				if(gameMap[i][j]&&!code[k]&&gameMap[i][j]==gameMap[i][k])
				{
					code[j]=code[k]=k;
					break;
				}
				
				else if(!gameMap[i][j]||gameMap[i][j]!=gameMap[i][k]&&gameMap[i][k]||code[k]!=code[j])
					break;
					
		for(int j=2;j<=4;j++)
			for(int k=j-1;k>=1;k--)
				if(code[j]==code[k]&&code[j])
				{
					gameMap[i][k]+=gameMap[i][j];
					gameMap[i][j]=0;
					moved=1;
					break;
				}
					
		for(int j=1;j<=3;j++)
			if(!gameMap[i][j])
				for(int k=j+1;k<=4;k++)
					if(gameMap[i][k])
					{
						gameMap[i][j]+=gameMap[i][k];
						gameMap[i][k]=0;
						moved=1;
						break;
					}
	}

	if(moved)
	{
		if(!p)
		{
			srand((unsigned)time(NULL));
			int r1=rand()%16;
			while(gameMap[pos[r1][0]][pos[r1][1]])
				r1=rand()%16;
			int r2=rand()%16;
			gameMap[pos[r1][0]][pos[r1][1]]=(r2?2:4);
			drawNumber();
			system("cls");
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=4;j++)
					printf("%d\t",gameMap[i][j]);
				putchar('\n');
			}
		}
	}
}

void moveRight(int p)
{
	int moved=0;
	for(int i=1;i<=4;i++)
	{
		int code[5]={};
		for(int j=3;j>=1;j--)
			for(int k=j+1;k<=4;k++)
				if(gameMap[i][j]&&!code[k]&&gameMap[i][j]==gameMap[i][k])
				{
					code[j]=code[k]=k;
					break;
				}
				
				else if(!gameMap[i][j]||gameMap[i][j]!=gameMap[i][k]&&gameMap[i][k]||code[k]!=code[j])
					break;
					
		for(int j=3;j>=1;j--)
			for(int k=j+1;k<=4;k++)
				if(code[j]==code[k]&&code[j])
				{
					gameMap[i][k]+=gameMap[i][j];
					gameMap[i][j]=0;
					moved=1;
					break;
				}
					
		for(int j=4;j>=2;j--)
			if(!gameMap[i][j])
				for(int k=j-1;k>=1;k--)
					if(gameMap[i][k])
					{
						gameMap[i][j]+=gameMap[i][k];
						gameMap[i][k]=0;
						moved=1;
						break;
					}
	}

	if(moved)
	{
		if(!p)
		{
			srand((unsigned)time(NULL));
			int r1=rand()%16;
			while(gameMap[pos[r1][0]][pos[r1][1]])
				r1=rand()%16;
			int r2=rand()%16;
			gameMap[pos[r1][0]][pos[r1][1]]=(r2?2:4);
			drawNumber();
			system("cls");
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=4;j++)
					printf("%d\t",gameMap[i][j]);
				putchar('\n');
			}
		}
	}
}

void runGame()
{
	srand((unsigned)time(NULL));
	int r1=rand()%16,r2=rand()%16;
	while(r1==r2)
		r2=rand()%16;
	int r3=rand()%16,r4=rand()%16;
	gameMap[pos[r1][0]][pos[r1][1]]=(r3?2:4);
	gameMap[pos[r2][0]][pos[r2][1]]=(r4?2:4);
	drawNumber();
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
			printf("%d\t",gameMap[i][j]);
		putchar('\n');
	}

	char c;
	while((c=getch())!=27)
	{
		if(c=='\340')
		{
			c=getch();
			switch(c)
			{
				case 72:
					moveUp(0);
					break;
				case 80:
					moveDown(0);
					break;
				case 75:
					moveLeft(0);
					break;
				case 77:
					moveRight(0);
					break;
			}

			if(!win)
				for(int i=1;i<=4;i++)
					for(int j=1;j<=4;j++)
						if(gameMap[i][j]==2048)
						{
							win=1;
							puts("\nYou win!");
						}

			if(toSeeIfGameIsOverOrNot())
			{
				puts("\nGame over!");
				IMAGE img;
				loadimage(&img,_T("numbers\\GameOver.jpg"));
				putimage(0,0,&img);
				char c=getch();
				while(c!='\r')
					c=getch();
				cleardevice();
				return;
			}
		}
	}
}

int main()
{
	initgraph(400,400/*,SHOWCONSOLE*/);
	/*IMAGE img;
	loadimage(&img,_T("2.jpg"));
	putimage(0,0,&img);
	getch();
	cleardevice();*/
	char c;
	while((c=getch())!='\r');
	runGame();
	return 0;
}



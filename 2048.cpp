#include<bits/stdc++.h>
#include<conio.h> 

const int L = 4;

int a[L][L];

bool game_over()
{
	for(int i = 0; i <= L-1; i++)
		for(int j = 0; j <= L-1; j++)
			if(!a[i][j] || (i-1 >= 0 && a[i-1][j] == a[i][j]) || (j-1 >= 0 && a[i][j-1] == a[i][j]) || (i+1 <= L-1 && a[i+1][j] == a[i][j]) || (j+1 <= L-1 && a[i][j+1] == a[i][j]))
				return false;
	return true;
}

int main()
{
	srand((unsigned)time(NULL));
	bool moved = true;
	int r = (rand()%4)?2:4;
	int x = rand()%L, y = rand()%L;
	a[x][y] = r; 
	
	while(true)
	{
		r = (rand()%4)?2:4;
		if(moved)
		{
			do {
				x = rand()%L, y = rand()%L;
			}while(!a[x][y]);
			a[x][y] = r;
			moved = false;
		}
		
		if(game_over())
			break;
		system("cls");
		for(int i = 0; i <= L-1; i++)
		{
			for(int j = 0; j <= L-1; j++)
				std::cout<<a[i][j]<<'\t';
			std::cout<<'\n';
		}
		
		char c = getch();
		switch(c)
		{
			case 'w':
				for(int j = 0; j <= L-1; j++)
					for(int i = 0; i < L-1; i++)
					{
						if(!a[i][j])
							for(int k = i+1; k <= L-1; k++)
								if(a[k][j])
								{
									for(int l = 0; l+k <= L-1; l++)
										a[i+l][j] = a[l+k][j], a[l+k][j] = 0;
									moved = true;
									break;
								}
							
						if(a[i][j])
							for(int k = i+1; k <= L-1; k++)
								if(a[k][j])
								{
									if(a[i][j] == a[k][j])
										a[i][j] <<= 1, a[k][j] = 0, moved = true;
									break;
								}
					}
				break;
			case 's':
				for(int j = 0; j <= L-1; j++)
					for(int i = L-1; i > 0; i--)
					{
						if(!a[i][j])
							for(int k = i-1; k >= 0; k--)
								if(a[k][j])
								{
									for(int l = 0; k-l >= 0; l++)
										a[i-l][j] = a[k-l][j], a[k-l][j] = 0;
									moved = true;
									break;
								}
							
						if(a[i][j])
							for(int k = i-1; k >= 0; k--)
								if(a[k][j])
								{
									if(a[i][j] == a[k][j])
										a[i][j] <<= 1, a[k][j] = 0, moved = true;
									break;
								}
					}
				break;
			case 'a':
				for(int i = 0; i <= L-1; i++)
					for(int j = 0; j < L-1; j++)
					{
						if(!a[i][j])
							for(int k = j+1; k <= L-1; k++)
								if(a[i][k])
								{
									for(int l = 0; l+k <= L-1; l++)
										a[i][j+l] = a[i][l+k], a[i][l+k] = 0;
									moved = true;
									break;
								}
							
						if(a[i][j])
							for(int k = j+1; k <= L-1; k++)
								if(a[i][k])
								{
									if(a[i][j] == a[i][k])
										a[i][j] <<= 1, a[i][k] = 0, moved = true;
									break;
								}
					}
				break;
			case 'd':
				for(int i = 0; i <= L-1; i++)
					for(int j = L-1; j > 0; j--)
					{
						if(!a[i][j])
							for(int k = j-1; k >= 0; k--)
								if(a[i][k])
								{
									for(int l = 0; k-l >= 0; l++)
										a[i][j-l] = a[i][k-l], a[i][k-l] = 0;
									moved = true;
									break;
								}
							
						if(a[i][j])
							for(int k = j-1; k >= 0; k--)
								if(a[i][k])
								{
									if(a[i][j] == a[i][k])
										a[i][j] <<= 1, a[i][k] = 0, moved = true;
									break;
								}
					}
				break;
		}
	}
	
	return 0;
}













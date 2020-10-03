#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
const int n = 9;
void creartablero(char matriz[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				matriz[i][j]='*';
				
			}
			
	
	}
}
void creartablerop(char matriz[n][n], int matrizp[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				if (matriz[i][j]=='*')
				{
					matrizp[i][j]=1;
				}
				else
				{
					matrizp[i][j]=0;
				}
				
			}
			
	
	}
}
int iados(int &dx,int dy,int ddx,int ddy,int dos,char tablero[n][n])
{
	if(tablero[dx+1][dy]!='*')
	{
		dx=dx+2;
	}
	else
	{
		dx=dx+1;
	}
	tablero[dx][dy]='d';
	return dx;
};
void pintartablero(char matriz[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				
				cout<<matriz[i][j];
			}
			cout<<endl;
	
	}
}
void pintartablerop(int matriz[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				
				cout<<matriz[i][j];
			}
			cout<<endl;
	
	}
}
void ganador(char tablero[n][n],bool flag)
{
	if ((tablero[0][0]=='u')||(tablero[0][1]=='u')||(tablero[0][2]=='u')||(tablero[0][3]=='u')||(tablero[0][4]=='u')||(tablero[0][5]=='u')||(tablero[0][6]=='u')||(tablero[0][7]=='u')||(tablero[0][8]=='u'))
	{
		flag=false;
		cout<<"gana uno"<<endl;
	}
	else if((tablero[8][0]=='d')||(tablero[8][1]=='d')||(tablero[8][2]=='d')||(tablero[8][3]=='d')||(tablero[8][4]=='d')||(tablero[8][5]=='d')||(tablero[8][6]=='d')||(tablero[8][7]=='d')||(tablero[8][8]=='d'))
	{
		flag=false;
		cout<<"gana dos"<<endl;
	}
	else if((tablero[0][8]=='t')||(tablero[1][8]=='t')||(tablero[2][8]=='d')||(tablero[3][8]=='d')||(tablero[4][8]=='d')||(tablero[5][8]=='d')||(tablero[6][8]=='d')||(tablero[7][8]=='d')||(tablero[8][8]=='d'))
	{
		flag=false;
		cout<<"gana tres"<<endl;
	}
}
void iatres(int &tx,int &ty,int &tdx,int &tdy,char tres,int tablerop[n][n],char tablero[n][n])
{

			
			if (tablerop[tx][ty+1]==1)
			{
				
				
				ty=ty+1;
				tablerop[tx][ty]=2;
				tablero[tx][ty]='t';
				//creartablerop(tablero,tablerop);
				
			}
			else if(tablerop[tx+1][ty]==1)
			{
				//creartablerop(tablero,tablerop);
				tx=tx+1;
				tablerop[tx][ty]=2;
				
				tablero[tx][ty]='t';
				
				//creartablerop(tablero,tablerop);
			}
			else if (tablerop[tx-1][ty]==1)
			{
				//creartablerop(tablero,tablerop);
				tx=tx-1;
				tablerop[tx][ty]=2;
				
				tablero[tx][ty]='t';
				//creartablerop(tablero,tablerop);
			}
			else if (tablerop[tx][ty-1]==1)
			{
				//creartablerop(tablero,tablerop);
				ty=ty-1;
				tablerop[tx][ty]=2;
				
				tablero[tx][ty]='t';
				//creartablerop(tablero,tablerop);
			}
			else if(tablerop[tx+1][ty]==2)
			{
				//creartablerop(tablero,tablerop);
				tx=tx+1;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='t';
			//	creartablerop(tablero,tablerop);
				
			}
			else if (tablerop[tx][ty+1]==2)
			{
				//creartablerop(tablero,tablerop);
				ty=ty+1;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='t';
				//creartablerop(tablero,tablerop);
			}
			else if (tablerop[tx-1][ty]==2)
			{
				//creartablerop(tablero,tablerop);
				tx=tx-1;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='t';
				//creartablerop(tablero,tablerop);
			}
			else if (tablerop[tx][ty-1]==2)
			{
				//creartablerop(tablero,tablerop);
				ty=ty-1;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='t';
				//creartablerop(tablero,tablerop);
			}
			creartablerop(tablero,tablerop);

}
int main()
{
	char tablero[n][n];
	int tablerop[n][n];

	creartablero(tablero);
	
	char uno, dos, tres, cuatro;
	uno='u'; dos='d';tres='t';cuatro='c';
	int ux=8;
	int uy=4;
	int udx=0;
	int udy=4;
	int dx=0;
	int dy=4;
	int ddx=0;
	int ddy=0;
	int tx=4;
	int ty=0;
	int tdx=0;
	int tdy=0;
	
	tablero[ux][uy]=uno;
	tablero[dx][dy]=dos;
	tablero[tx][ty]=tres;
	creartablerop(tablero,tablerop);
	bool flag=true;
	char mov;
	
	pintartablero(tablero);
	pintartablerop(tablerop);
	while(flag==true)
	{
		cin>>mov;
		if (mov=='w')
		{
			system("CLS");
			
			
			udx=udx+1;
			creartablero(tablero);
			tablero[ux-udx][uy]=uno;
			iados(dx,dy,ddx,ddy,dos,tablero);
			tablero[dx][dy]=dos;
			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			pintartablero(tablero);
			ganador(tablero,flag);
			//pintartablerop(tablerop);
			
		}
		else if(mov =='s')
		{
			system("CLS");
			
			udx=udx-1;
			creartablero(tablero);
			tablero[ux-udx][uy]=uno;
			iados(dx,dy,ddx,ddy,dos,tablero);
			tablero[dx][dy]=dos;
			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			pintartablero(tablero);
			ganador(tablero,flag);
			//pintartablerop(tablerop);
		}
		else if(mov =='a')
		{
			system("CLS");
			
			udy=udy-1;
			creartablero(tablero);
			tablero[ux-udx][uy]=uno;
			iados(dx,dy,ddx,ddy,dos,tablero);
			tablero[dx][dy]=dos;
			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			pintartablero(tablero);
			ganador(tablero,flag);
			//pintartablerop(tablerop);
		}
		else if(mov =='d')
		{
			system("CLS");
			
			udy=udy+1;
		    creartablero(tablero);
			tablero[ux-udx][uy]=uno;
			iados(dx,dy,ddx,ddy,dos,tablero);
			tablero[dx][dy]=dos;
			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			pintartablero(tablero);
			ganador(tablero,flag);
			//pintartablerop(tablerop);
		}
		else
		{
			
		}
	}
	
	
}

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
	char matriz[7][7]=
	{{'*','*','*','*','*','*','*'}
	,{'i','l','l','l','l','l','*'}
	,{'*','*','*','*','*','l','*'}
	,{'*','*','l','l','l','l','*'}
	,{'*','*','l','*','l','*','*'}
	,{'f','l','l','*','l','*','*'}
	,{'*','*','*','*','*','*','*'}};
	int matrizv[7][7];
	for(int i=0;i<7;i++)
	{
			for(int j=0;j<7;j++)
			{
				if (matriz[i][j]=='*')
				{
					matrizv[i][j]=0;
				}
				else
				{
					matrizv[i][j]=1;
				}
				
			}
    }
	
	int m,ix,iy,idx,idy;
	
	bool flag=true;
	for(int i=0;i<7;i++)
	{
			for(int j=0;j<7;j++)
			{
				if (matriz[i][j]=='i')
				{
					ix=i;
					iy=j;
				}
				
			}
			
	
	}
	cout<<ix<<iy<<endl;
	int dx=0;
	int dy=0;
	int c;
	for(int i=0;i<7;i++)
    {
			for(int j=0;j<7;j++)
			{
				cout<<matrizv[i][j];
				
			}	
			cout<<endl;			
	}
	while(flag)
	{
		cin>>c;
		if (c<100)
		{
			if((matriz[ix][iy]=='f'))
			{
				cout<<"encontraste la salida"<<endl;
				return
				flag=false;
				
			}
			
			if(matrizv[ix+1][iy]==1)
			{
				matrizv[ix][iy]=2;
				ix=ix+1;
				
			}
			else if (matrizv[ix][iy+1]==1)
			{
				matrizv[ix][iy]=2;
				iy=iy+1;
			}
			else if (matrizv[ix-1][iy]==1)
			{
				matrizv[ix][iy]=2;
				ix=ix-1;
			}
			else if (matrizv[ix][iy-1]==1)
			{
				matrizv[ix][iy]=2;
				iy=iy-1;
			}
			else if(matrizv[ix+1][iy]==2)
			{
				matrizv[ix][iy]=0;
				ix=ix+1;
				
			}
			else if (matrizv[ix][iy+1]==2)
			{
				matrizv[ix][iy]=0;
				iy=iy+1;
			}
			else if (matrizv[ix-1][iy]==2)
			{
				matrizv[ix][iy]=0;
				ix=ix-1;
			}
			else if (matrizv[ix][iy-1]==2)
			{
				matrizv[ix][iy]=0;
				iy=iy-1;
			}
			
		}
		system("CLS");
		for(int i=0;i<7;i++)
     	{
			for(int j=0;j<7;j++)
			{
				cout<<matrizv[i][j];
				
			}	
			cout<<endl;			
	   }
		
	}
}

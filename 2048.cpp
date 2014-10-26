#include<iostream>
#include<iomanip>
#include<time.h>
#include <conio.h> 
using namespace std;
int list[5][5];
inline int produce(int x)
{
	if(x==0)return 2;
	else return 4;
}
void fill()
{
	int p=rand()%4+1;
	int q=rand()%4+1;
	if(list[p][q]==0)
		list[p][q]=produce(rand()%2);
	else fill();
}
void display()
{
	cout<<endl<<"-------------------------------------------------"<<endl;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
			if(list[i][j]==0)cout<<setw(10)<<" ";
			else cout<<setw(10)<<list[i][j];
		cout<<endl<<"-------------------------------------------------"<<endl;
	}
	cout<<endl<<endl;
}
int get_key()
{
	int key1=0,key2=0;
	while(key1!=224)
		key1=getch();
	key2=getch();
	if(key2==72)return 1;
	if(key2==80)return 2;
	if(key2==75)return 3;
	if(key2==77)return 4;
}
int dfs_up(int i,int j)
{
	if(list[i][j]==0)return 0;
	else if(i==1)return list[i][j];
	else if(dfs_up(i-1,j)==0)
	{
		list[i-1][j]=list[i][j];
		list[i][j]=0;
		return dfs_up(i-1,j);
	}
	else if(dfs_up(i-1,j)==list[i][j])
	{
		list[i-1][j]*=2;
		list[i][j]=0;
		return 0;
	}
	else return list[i][j];
}
bool check_up()
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(list[i][j]==0)
				for(int k=i;k<=4;k++)
					if(list[k][j]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=4;j++)
			if(list[i][j]==list[i+1][j]&&list[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}
bool check_down()
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(list[i][j]==0)
				for(int k=i;k>=1;k--)
					if(list[k][j]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=4;j++)
			if(list[i][j]==list[i+1][j]&&list[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}
bool check_left()
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(list[i][j]==0)
				for(int k=j;k<=4;k++)
					if(list[i][k]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=3;j++)
			if(list[i][j]==list[i][j+1]&&list[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}
bool check_right()
{
	bool b=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(list[i][j]==0)
				for(int k=j;k>=1;k--)
					if(list[i][k]!=0)
					{
						b=1;
						break;
					}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=3;j++)
			if(list[i][j]==list[i][j+1]&&list[i][j]!=0)
				{
					b=1;
					break;
				}
	return b;
}
void deal_up()
{
	for(int i=2;i<=4;i++)
		for(int j=1;j<=4;j++)
			dfs_up(i,j);
}
int dfs_down(int i,int j)
{
	if(list[i][j]==0)return 0;
	else if(i==4)return list[i][j];
	else if(dfs_down(i+1,j)==0)
	{
		list[i+1][j]=list[i][j];
		list[i][j]=0;
		return dfs_down(i+1,j);
	}
	else if(dfs_down(i+1,j)==list[i][j])
	{
		list[i+1][j]*=2;
		list[i][j]=0;
		return 0;
	}
	else return list[i][j];
}
void deal_down()
{
	for(int i=3;i>=1;i--)
		for(int j=1;j<=4;j++)
			dfs_down(i,j);
}
int dfs_left(int i,int j)
{
	if(list[i][j]==0)return 0;
	else if(j==1)return list[i][j];
	else if(dfs_left(i,j-1)==0)
	{
		list[i][j-1]=list[i][j];
		list[i][j]=0;
		return dfs_left(i,j-1);
	}
	else if(dfs_left(i,j-1)==list[i][j])
	{
		list[i][j-1]*=2;
		list[i][j]=0;
		return 0;
	}
	else return list[i][j];
}
void deal_left()
{
	for(int i=1;i<=4;i++)
		for(int j=2;j<=4;j++)
			dfs_left(i,j);
}
int dfs_right(int i,int j)
{
	if(list[i][j]==0)return 0;
	else if(j==4)return list[i][j];
	else if(dfs_right(i,j+1)==0)
	{
		list[i][j+1]=list[i][j];
		list[i][j]=0;
		return dfs_right(i,j+1);
	}
	else if(dfs_right(i,j+1)==list[i][j])
	{
		list[i][j+1]*=2;
		list[i][j]=0;
		return 0;
	}
	else return list[i][j];
}
void deal_right()
{
	for(int i=1;i<=4;i++)
		for(int j=3;j>=1;j--)
			dfs_right(i,j);
}
int check()
{
	int b=1;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			if(list[i][j]==0&&b==1)
				b=0;
			else if(list[i][j]==2048&&b==1)
				b=2048;
		}
	return b;
}
int main()
{
	memset(list,0,sizeof(int)*5*5);
	cout<<"Code By TuringMac"<<endl;
	cout<<"Start!"<<endl;
	system("pause");
	srand(time(NULL));
	fill();
	fill();
	while(1)
	{
		display();
		switch(get_key())
		{
			case 1:
				if(check_up()==1)
				{
					deal_up();
					fill();
				}
				break;
			case 2:
				if(check_down()==1)
				{
					deal_down();
					fill();
				}
				break;
			case 3:
				if(check_left()==1)
				{
					deal_left();
					fill();
				}
				break;
			case 4:
				if(check_right()==1)
				{
					deal_right();
					fill();
				}
				break;
			default:
				continue;
		}
		if(check()==2048)
		{
			display();
			cout<<"Got 2048!"<<endl;
			system("pause");
			break;
		}
		else if(check()==1)
		{
			display();
			cout<<"Failed!"<<endl;
			system("pause");
			break;
		}
	}
	return 0;
}

// jisuanji.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "time.h"
#include "conio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
using namespace std;
void srand(unsigned int seed);
void getNumber(int &a,int &b,int &c,int &d)
{
	
	a=rand()%100;//生成一个100以内的随机整数
	b=rand()%100;
	c=rand()%100;
	d=rand()%100;
}
void getmode(int &mode1,int &mode2,int &mode3)
{
	mode1=rand()%4;//生成一个0-4之间的随机整数
	mode2=rand()%5;
	mode3=rand()%5;
}
void mode(int b,int m,int &i)
{
	switch(m)
		{
		case 0:
			printf("+");
			break;
		case 1:
			printf("-");
			break;
		case 2:
			printf("*");
			break;
		case 3:
			if(b==0)
			{
				i--;
				break;
			}
			printf("/");
			break;
		}
}
void mod(int b,int m,int &i,char &mo)
{
	switch(m)
		{
		case 0:
			mo='+';
			break;
		case 1:
			mo='-';
			break;
		case 2:
			mo='*';
			break;
		case 3:
			if(b==0)
			{
				i--;
				break;
			}
			mo='/';
			break;
		}
}
void printfsuanshi(int &a,int &b,int &c,int &d,int &r,int &mode1,int &mode2,int &mode3,int &i)
{
	char mo;
	ofstream shiti("题目.txt",ios::app);
	ofstream daan("答案.txt",ios::app);
	shiti<<i+1<<". ";
	shiti<<a;
	mod(b,mode1,i,mo);
	shiti<<mo;
	shiti<<b;
	if(mode2!=4)
	{
		mod(c,mode2,i,mo);
		shiti<<mo;
	}
	else
	{
		shiti<<"=\n";
		daan<<i+1<<". "<<r<<endl;
		return;
	}
	shiti<<c;
	if(mode3!=4)
	{
		mod(d,mode3,i,mo);
		shiti<<mo;
	}
	else
	{
		shiti<<"=\n";
		daan<<i+1<<". "<<r<<endl;
		return;
	}
	shiti<<d<<"="<<endl;
	daan<<i+1<<". "<<r<<endl;
	shiti.close();
	daan.close();
}
int _tmain(int argc, _TCHAR* argv[])
{	
	int n=0;//生成题目个数
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int r=0;//答案
	int m;
	int mode1=0;//0 加，1  减，2  乘，3  除
	int mode2=0;//0 加，1  减，2  乘，3  除,4 无
	int mode3=0;//0 加，1  减，2  乘，3  除,4 无
	printf("输入生成题目数：");
	scanf("%d",&n); //输入生成题目的个数
	srand((int)time(NULL));//初始化随机数发生器，使得每次运行生成的随机数不同
	ofstream("题目.txt");
	ofstream("答案.txt");
	for(int i=0;i<n;i++)
	{
		getNumber(a,b,c,d);
		getmode(mode1,mode2,mode3);
		r=a;
		if(!(mode1==0 || mode1==1 || mode2==0 || mode2==1 || mode2==4))//1 1 (1 0 4)
		{
			switch(mode1)
			{
			case 2:r=a*b;break;
			case 3:
				if(b==0 || a%b!=0)
				{
					i--;
					goto part2;
				}
				else
					r=a/b;
				break;
			}
			switch(mode2)
			{
			case 2:r*=c;break;
			case 3:
				if(c==0 || r%c!=0)
				{
					i--;
					goto part2;
				}
				else
					r/=c;
				break;
			}
			if(mode3!=4)
			{
				switch(mode3)
				{
				case 0:r+=d;break;
				case 1:r-=d;break;
				case 2:r*=d;break;
				case 3:
					if(d==0 || r%d!=0 )
					{
						i--;
						goto part2;
					}
					else
						r/=d;
					break;
				}
			}
		}
		if(!(mode1==0 || mode1==1 || mode2==2 || mode2==3 || mode2==4))//1 0 (1 0 4)
		{
			int c1=0;
			switch(mode1)
			{
			case 2:r=a*b;break;
			case 3:
					if(b==0 || a%b!=0)
					{
						i--;
						goto part2;
					}
					else
						r=a/b;
					break;
			}
			if(!(mode3==4 || mode3==0 || mode3==1))
			{
				switch(mode3)
				{
				case 2:c1=c*d;break;
				case 3:
					if(d==0 || c%d!=0)
					{
						i--;
						goto part2;
					}
					else
						c1=c/d;
					break;
				}
				switch(mode2)
				{
				case 0:r+=c1;break;
				case 1:r-=c1;break;
				}
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))
			{
				switch(mode2)
				{
				case 0:r+=c;break;
				case 1:r-=c;break;
				}
				switch(mode3)
				{
				case 0:r+=d;break;
				case 1:r-=d;break;
				}
			}
			else
			{
				switch(mode2)
				{
				case 0:r+=c;break;
				case 1:r-=c;break;
				}
			}
		}
		if(!(mode1==2 || mode1==3|| mode2==0 || mode2==1|| mode2==4))//0 1 (1 0 4)
		{
			int c2=0;
			switch(mode2)
			{
			case 2:c2=b*c;break;
			case 3:
				if(c==0 || b%c!=0)
				{
					i--;
					goto part2;
				}
				else
					c2=b/c;
				break;
			}
			r=c2;
			if(!(mode3==4 || mode3==0 || mode3==1))
			{
				switch(mode3)
				{
				case 2:r=c2*d;break;
				case 3:
					if(d==0 || c2%d!=0)
					{
						i--;
						goto part2;
					}
					else
						r=c2/d;
					break;
				}
				switch(mode1)
				{
				case 0:r+=a;break;
				case 1:r=a-r;break;
				}
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))
			{
				switch(mode1)
				{
				case 0:r+=a;break;
				case 1:r=a-c2;break;
				}
				switch(mode3)
				{
				case 0:r+=d;break;
				case 1:r-=d;break;
				}
			}
			else
			{
				switch(mode1)
				{
				case 0:r+=a;break;
				case 1:r=a-c2;break;
				}
			}

		}
		if(!(mode1==2 || mode1==3|| mode2==2 || mode2==3 || mode2==4))//0 0 (1 0 4)
		{
			int c3=0;
			int b1=0;
			if(!(mode3==4 || mode3==0 || mode3==1))
			{
				switch(mode3)
				{
				case 2:c3=c*d;break;
				case 3:
					if(d==0 || c%d!=0)
					{
						i--;
						goto part2;
					}
					else
						c3=c/d;
					break;
				}
				switch(mode1)
				{
				case 0:r=a+b;break;
				case 1:r=a-b;break;
				}
				switch(mode2)
				{
				case 0:r=r+c3;break;
				case 1:r=r-c3;break;
				}
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))
			{
				switch(mode1)
				{
				case 0:r=a+b;break;
				case 1:r=a-b;break;
				}
				switch(mode2)
				{
				case 0:r=r+c;break;
				case 1:r=r-c;break;
				}
				switch(mode3)
				{
				case 0:r=r+d;break;
				case 1:r=r-d;break;
				}
			}
			else
			{
				switch(mode1)
				{
				case 0:r=a+b;break;
				case 1:r=a-b;break;
				}
				switch(mode2)
				{
				case 0:r=r+c;break;
				case 1:r=r-c;break;
				}
			}
		}
		if(mode2==4)
		{
			switch(mode1)
			{
			case 0:r=a+b;break;
			case 1:r=a-b;break;
			case 2:r=a*b;break;
			case 3:
				if(b==0 || a%b!=0)
				{
					i--;
					goto part2;
				}
				else
					r=a/b;
				break;
			}
		}
		if(r<0)
		{
			i--;
			goto part2;
		}
		printfsuanshi(a,b,c,d,r,mode1,mode2,mode3,i);
		m=i+1;
		printf("%d.\n",m);
		printf("%d",a);
		mode(b,mode1,i);
		printf("%d",b);
		if(mode2!=4)
		{
			mode(c,mode2,i);
		}
		else
		{
			printf("=");
			printf("%d\n",r);
			continue;
		}
		printf("%d",c);
		if(mode3!=4)
		{
			mode(d,mode3,i);
		}
		else
		{
			printf("=");
			printf("%d\n",r);
			continue;
		}
		printf("%d=",d);
		printf("%d\n",r);
part2 :
		printf("");
	}	return 0;
}






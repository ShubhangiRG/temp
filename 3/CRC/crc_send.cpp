//============================================================================
// Name        : crc_send.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include<string.h>
#include<queue>
using namespace std;

class data
{
	int data[10],poly[5],crc[20],rem[5],quo[10],dl=0,dl1=0,pl=0;

public:
	void accept();
	void display();
	void attatch();
	void bin_div();
};
void data::accept()
{

	int i,polylen=0;
	cout<<"How many bit data u want to insert?";
	cin>>dl;
	dl1=dl;
	cout<<"\nEnter Data:";
	for(i=0;i<dl;i++)
	cin>>data[i];

    cout<<"How many bit Polynomial u want to insert?";
		cin>>pl;
	cout<<"\nEnter polynomial:";
	for(i=0;i<pl;i++)
		cin>>poly[i];


	polylen=pl-1;

	int j=0;
	j=dl+polylen;
	for(i=dl;i<j;i++)
	{
		data[i]=0;
	}
	dl=j;
	cout<<"\nNow data=";
	for(i=0;i<j;i++)
		cout<<data[i];
}
void data::bin_div()
{
	int i,j,p,looplen=0;

	int div1[pl],div2[pl];
	looplen=dl-pl;
	looplen=looplen+1;

	for(p=0;p<pl;p++)
	{
		div1[p]=data[p];
		div2[p]=poly[p];
	}
	cout<<"\ndiv1=";
	for(i=0;i<pl;i++)
		{
			cout<<div1[i];

		}
	cout<<"\ndiv2=";
	for(i=0;i<pl;i++)
		{

			cout<<div2[i];
		}

		cout<<"\nLooplen="<<looplen;

		for(i=0;i<looplen;i++)
		{
			if(div1[0]==1)
			{
			for(j=0;j<pl;j++)
			{
				div1[j]=div1[j]^div2[j];
			}
			}
			else
			{
				for(j=0;j<pl;j++)
							{
								div1[j]=div1[j]^0;
							}
			}
			for(j=0;j<pl;j++)
			{
				div1[j]=div1[j+1];
			}
			div1[j-1]=data[p];
			p++;
			cout<<"\nNow div1=";
			for(j=0;j<pl;j++)
				cout<<div1[j];
		}

		cout<<"\n\n\t\t\tRemainder=";
		for(i=0;i<pl-1;i++)
		{
			cout<<div1[i];
			rem[i]=div1[i];
		}
}
void data::attatch()
{
	int i,j;
	j=dl1;
	for(i=0;i<pl-1;i++)
	{
		data[j]=rem[i];
		j++;
	}
	cout<<"\nData to be send with redundancy bit=";
	for(i=0;i<j;i++)
		cout<<data[i];
}
int main()
{
	data d;
	d.accept();
	d.bin_div();
	d.attatch();
}

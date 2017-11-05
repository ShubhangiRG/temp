//============================================================================
// Name        : crc_receiver.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class receiver
{
	int data[20],poly[10],dl=0,pl=0,rem[6];
public:
	void accept();
	void bin_div();
};
void receiver::accept()
{
	int i;
	cout<<"\nHow many bit data received?";
	cin>>dl;
	cout<<"\nEnter the received data=";
	for(i=0;i<dl;i++)
		cin>>data[i];
	cout<<"\nEnter the number of polynomial bits=";
	cin>>pl;
	cout<<"\nEnter polynomial=";
	for(i=0;i<pl;i++)
		cin>>poly[i];
}
void receiver::bin_div()
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
		int flag=0;
		for(i=0;i<pl-1;i++)
		{
			if(rem[i]==1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"\nData received is corrupted!";
		}
		else
			cout<<"\nData received has no errors!";
}
int main()
{
	receiver r;
	r.accept();
	r.bin_div();
	return 0;
}

//============================================================================
// Name        : Hamming_rec.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<math.h>
using namespace std;

class hamming
{
	char data[11],arr[4];
public:
	int accept();
	void operation();
};
int hamming::accept()
{
	int i;
	cout<<"\nEnter received data(11 bit)=";
	for(i=10;i>=0;i--)
	{
		cin>>data[i];
	}
	for(i=10;i>=0;i--)
	{
		if(data[i]!='0' || data[i]!='1')
		{
			cout<<"\nEnter only binary numbers!";
			return 1;
		}
	}
	for(i=10;i>=0;i--)
	cout<<"\ndata="<<data[i];
	return 0;
}
void hamming::operation()
{
	for(int i=0;i<4;i++)
		arr[i]=0;

		data[0]=data[0]^data[2]^data[4]^data[6]^data[8]^data[10];
		data[1]=data[1]^data[2]^data[5]^data[6]^data[9]^data[10];
		data[3]=data[3]^data[5]^data[4]^data[6];
		data[7]=data[7]^data[8]^data[9]^data[10];
		int i,tot=0;



			tot=tot+pow(2,data[0]);
			tot=tot+pow(2,data[1]);
			tot=tot+pow(2,data[3]);
			tot=tot+pow(2,data[7]);

		if(data[0]==0 && data[1]==0 && data[3]==0 && data[7]==0)
			cout<<"\nNo Error present!";
		else
			cout<<"\nError is present at "<<tot<<"th position.";

}
int main()
{
	hamming h;
	int flag=0;
	flag=h.accept();
	if(flag==1)
		h.accept();
	h.operation();
	return 0;
}

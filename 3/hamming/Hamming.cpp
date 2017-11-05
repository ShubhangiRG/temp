//============================================================================
// Name        : Hamming.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class hamming
{
	char data[11],arr[7];
public:
	void accept();
	void operation();
};
void hamming::accept()
{
	cout<<"\n Enter Data(7 bit)=";
	cin>>arr;
	int i;
	data[10]=arr[0];
	data[9]=arr[1];
	data[8]=arr[2];
	data[6]=arr[3];
	data[5]=arr[4];
	data[4]=arr[5];
	data[2]=arr[6];
	data[0]=data[1]='-';
	data[3]='-';
	data[7]='-';
	cout<<"\n Entered data=";
	for(i=10;i>=0;i--)
		cout<<data[i];

}
void hamming::operation()
{
	data[0]=data[2]^data[4]^data[6]^data[8]^data[10];
	data[1]=data[2]^data[5]^data[6]^data[9]^data[10];
	data[3]=data[5]^data[4]^data[6];
	data[7]=data[8]^data[9]^data[10];
	int i;
	cout<<"\nData to be sent=";
	for(i=10;i>=0;i--)
		cout<<data[i];
}
int main()
{
	hamming h;
	h.accept();
	h.operation();
	return 0;
}

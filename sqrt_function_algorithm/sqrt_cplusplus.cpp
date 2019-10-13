#include<iostream.h>
#include<conio.h>

double sq(double n)
{
	double beg=0,last=n,mid;
	while(beg<=last)
	{
		mid=(beg+last)/2;
		if(n>mid*mid)
		{
		if(n-mid*mid<=0.000001)return mid;
		}else
		{
		if(mid*mid-n<=0.000001)return mid;
		}
		if(n>mid*mid)beg=mid;
		else last=mid;
	}
	return -1;
}
void main()
{
	clrscr();
	double n;
	cout<<"Enter no : ";cin>>n;
	if(sq(n)!=-1)
	cout<<"\nSqrt : "<<sq(n);
	else
	cout<<"\nERROR !\n";
	getch();
}

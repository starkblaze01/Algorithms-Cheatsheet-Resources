#include<iostream>
using namespace std;

double sqrt_fun(double n) {
	
	double beg=0,last=n,mid;
	
	while(beg<=last) {
		
		mid=(beg+last)/2;
		
		if(n>mid*mid) {
			if(n-mid*mid<=0.000001)
			return mid;
		} else {
			if(mid*mid-n<=0.000001)
			return mid;
		}
		if(n>mid*mid) beg=mid;
		else last=mid;
	}
	return -1;
}

int main() {
	
	double n;
	cout<<"Enter the number : ";
	cin>>n;
	if(sqrt_fun(n)!=-1) cout<<"\nSquare root of "<<n<<" = "<<sqrt_fun(n)<<endl;
	else cout<<"\nERROR !"<<endl;
	
	system("pause");
	return 0;
}

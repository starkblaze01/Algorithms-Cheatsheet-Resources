#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i=1;
    while(i<=n) {
        int j=1;
        while (j<=n)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}

/*
Pattern 1 -> same number of rows and columns 
For example:
input n=3

output:
***
***
***

*/
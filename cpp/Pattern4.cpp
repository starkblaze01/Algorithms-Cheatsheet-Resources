/* Pattern 4

For example: 
input = 5

output: 
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1

*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i=1;
    while (i<=n)
    {
        int j=1;
        while (j<=n)
        {
            cout << n-j+1 << " ";
            j++;
        }
        cout <<endl;
        i++;
    }
    
}
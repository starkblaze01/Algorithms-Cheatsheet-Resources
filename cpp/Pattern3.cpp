/* Pattern 3 

For example: 
input = 3

output: 
1 2 3
1 2 3
1 2 3

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
            cout << j << " ";
            j++;
        }
        cout <<endl;
        i++;
    }
    
}
/* Pattern 9

For example: 
input = 5

output: 
1
2 1
3 2 1 
4 3 2 1 
5 4 3 2 1

*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        int val=i;
        while(j<=i)
        {
            cout<<val << " ";
            val--;
            j++;
        }
        cout<<endl;
        i++;
    }
}
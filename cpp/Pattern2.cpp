/* Pattern2 is similar to Pattern1 but instead of stars we are printing the numbers as per the row number it is situated in (basically write the row number in that row for n times)
Note: Here too rows and columns value are same

For example: 
input = 3

output: 
1 1 1
2 2 2
3 3 3

*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 1;
    while (i<=n)
    {
        int j = 1;
        while (j<=n)
        {
            cout << i << " " ;
            j++;
        }
        cout << endl;
        i++;
    }
}
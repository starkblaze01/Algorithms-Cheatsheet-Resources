#include<stdio.h>
#include<stdlib.h>
#include<iostream>

unsigned long long fibo(unsigned long long);
unsigned long long factorialR(unsigned long long);

using namespace std;

int main ()
{
    char opc('X');
    unsigned long long aux;

    while(opc!='e')
    {
        system("cls");
        cout<< "Menu:\n1)Fibonacci\n2)Factorial\ne) exit" << endl;
        fflush(stdin);
        cin>>opc;

        if(opc == '1')
        {
            cout << "Write number for fibonacci" << endl;
            fflush(stdin);
            cin >> aux;
            cout <<fibo(aux)<<endl;
        }


        if(opc == '2')
        {
            cout << "Write number for factorial" << endl;
            fflush(stdin);
            cin >> aux;
            cout <<factorialR(aux)<<endl;
        }

        system("pause");
    }

    return 0;
}

unsigned long long fibo (unsigned long long n)
{
    if (n<2) 
    {
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
}

unsigned long long factorialR(unsigned long long n)
{
    if (n<2)
    {
        return 1;
    }
    return n * factorialR(n-1);
}


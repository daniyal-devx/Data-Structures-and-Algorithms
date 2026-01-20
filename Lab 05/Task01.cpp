#include <iostream>
#include <string>
#include <vector>
using namespace std;
void dec2oct(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        dec2oct(n / 8);
        cout << n % 8;
    }
}
int main()
{
    int n = 69;
    cout << "Octal equivalent of" << n << "is:";
    dec2oct(n);
    cout << endl;
    n = 389;
    cout << "Octal equivalent of" << n << "is";
    dec2oct(n);
    cout << endl;
    return 0;
}
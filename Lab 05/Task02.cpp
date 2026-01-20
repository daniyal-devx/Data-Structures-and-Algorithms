#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isprime(char ch)
{
    bool result = true;
    int n = ch - '0';
    if (n == 1 || n == 2)
    {
        return result;
    }
    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                result = false;
            }
        }
        return result;
    }
}
bool isGoodNumber(const string &s, int index = 0)
{
    if (index >= s.length())
    {
        return true;
    }
    char ch = s[index];
    if (index % 2 == 0)
    {
        if ((ch - '0') % 2 != 0)
        {
            return false;
        }
    }

    else
    {
        if (!isprime(ch))
        {
            return false;
        }
    }
    return isGoodNumber(s, index + 1);
}
int main()
{
    string digit_strings[] = {"02468", "23478", "224365"};
    for (string digits : digit_strings)
    {
        bool is_good = isGoodNumber(digits, 0);
        cout << "Digit string: " << digits << " is " << (is_good ? "good" : "not good") << endl;
    }
    return 0;
}
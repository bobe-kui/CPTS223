#include <iostream>

using namespace std;

int sumofn(int n)
{
    if (n==0)
    {return 0;
    }
    else
    {
        return n + sumofn(n-1);
    }

}

int main(void)
{
    int input = 4;
    cout << sumofn(input) << endl;
    return 0;
}
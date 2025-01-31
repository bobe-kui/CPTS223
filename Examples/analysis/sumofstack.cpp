#include <iostream>
#include <stack>

using namespace std;

int sumofstack(stack<int> stk)
{
    if(stk.empty()){
        return 0;
    }
    int top = stk.top();
    stk.pop();
    int sum = top + sumofstack(stk);
    cout << "State of stack" << stk.top() << endl;
    return sum;
}

int main(void)
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    cout << sumofstack(stk) << endl;
    return 0;
}
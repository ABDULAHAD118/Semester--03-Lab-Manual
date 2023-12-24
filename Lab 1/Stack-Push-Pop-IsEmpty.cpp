#include <iostream>
using namespace std;
const int STKSIZE = 5;
class cstack
{
private:
    int top;
    int STK[STKSIZE];

public:
    cstack()
    {
        top = -1;
    }
    void push(int x);
    int pop();
    int emptystack();
    int stacktop();
    void display();
};
void cstack::push(int x)
{
    if (top == 4)
    {
        cout << "STACK is OVERFLOW\n";
        return;
    }
    ++top;
    STK[top] = x;
}
int cstack::pop()
{
    if (emptystack())
    {
        cout << "STACK is EMPTY\n";
        return -1;
    }
    return STK[top--];
}
int cstack::emptystack()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int cstack::stacktop()
{
    if (emptystack())
    {
        cout << "STACK is EMPTY\n";
        return top;
    }
    return STK[top];
}
void cstack::display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << "\n"
             << STK[i];
    }
}
int main()
{
    cstack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);
    stack.push(25);

    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    return 0;
}

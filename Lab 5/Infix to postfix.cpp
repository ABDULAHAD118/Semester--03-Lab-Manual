#include <iostream>
using namespace std;
const int STKSIZE = 20;
int len;
class cstack
{
private:
    int top;
    char STK[STKSIZE];

public:
    cstack()
    {
        top = -1;
    }
    void push(char x);
    char pop();
    int emptystack();
    char stacktop();
    int precedence(char);
    string conversion(char);
};
void cstack::push(char x)
{
    if (top == STKSIZE-1)
    {
        cout << "STACK is OVERFLOW\n";
        return;
    }
    STK[++top] = x;
}
char cstack::pop()
{
    if (emptystack())
    {
        cout << "STACK is EMPTY\n";
        return '\0';
    }
    return STK[top--];
}
int cstack::emptystack()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
char cstack::stacktop()
{
    if (emptystack())
    {
        cout << "STACK is EMPTY\n";
        return '\0';
    }
    return STK[top];
}

int cstack::precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^' || op == '$')
        return 3;
    return 0;
}


string cstack::conversion(char character)
{
    string poststr;
    char symb = character;

    if (isalpha(symb) || isalnum(symb))
    {
        poststr = symb;
    }
    else
    {
        if (symb == '(')
        {
            push(symb);
        }
        else if (symb == ')')
        {

            while (!emptystack() && stacktop() != '(')
            {
                char topOperator = pop();
                poststr += topOperator;
            }
            if (!emptystack() && stacktop() == '(')
            {
                pop();
            }
        }
        else
        {
            while (!emptystack() && precedence(stacktop()) >= precedence(symb))
            {
                char topOperator = pop();
                poststr += topOperator;
            }
            push(symb);
        }
    }

    return poststr;
}

int main()
{
    cstack stk;
    string oprt, post;
    char str;
    cout << "Enter the Expression : ";
    cin >> oprt;
    len = oprt.length();
    for (int i = 0; i <= len; i++)
    {
        str = oprt[i];
        post += stk.conversion(str);
    }

    cout << "OUTPUT OF POSTFIX EXPRESSION \t" << post;
}

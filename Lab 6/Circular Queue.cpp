#include <iostream>
using namespace std;
const int size = 100;
int queue[size], front = -1, rare = -1;
void enqueue()
{
    int val;

    if (rare == size - 1)
    {
        cout << "Circular queue over flow or full";
        return;
    }
    else
    {
        cout << "Insert the element in circular queue  : " << endl;
        cin >> val;
        if (front == -1)
        {
            front++;
        }
        else if (front!=0 && front!=rare){
        	rare=-1;
		}
        queue[++rare] = val;
        cout << "The inserted Element is:" << val;
    }
}
void dequeue()
{
    if (front == -1 || front > rare)
    {
        cout << "Circular Queue Underflow";
        front = rare = -1;
        return;
    }
    else
    {
        cout << "Element delete from circular queue is \n";
        front++;
    }
}
void Display()
{
    if (front == -1)
        cout << "Circular Queue is empty" << endl;
    else
    {
        cout << "Circular Queue element are :";
        for (int i = front; i <= rare; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}
int main()
{
    int ch;
    cout << "1) Insert element to circular queue" << endl;
    cout << "2) Delete element from circular queue" << endl;
    cout << "3) Display all elements of circular queue" << endl;
    cout << "4) Exit" ;
    do
    {
        cout << "\nEnter your choice :" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
    return 0;
}

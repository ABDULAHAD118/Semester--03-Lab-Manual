#include <iostream>
using namespace std;
const int size = 100;
int queue[size], front = -1, rare = -1;
void Insert()
{
	int val;

	if (rare == size - 1)
	{
		cout << "Queue over flow or full";
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
		queue[++rare] = val;
		cout << "The inserted Element is:" << val;
	}
}
void Delete()
{
	if (front == -1 || front > rare)
	{
		cout << "Queue Underflow";
		return;
	}
	else
	{
		cout << "Element delete from queue is \n";
		front++;
		if (front>rare){
			front=-1;
		}
	}
}
void Display()
{
	if (front == -1)
		cout << "Queue is empty" << endl;
	else
	{
		cout << "Queue element are :";
		for (int i = front; i <= rare; i++)
			cout << queue[i] << " ";
		cout << endl;
	}
}
int main()
{
	int ch;
	cout << "1) Insert element to queue" << endl;
	cout << "2) Delete element from queue" << endl;
	cout << "3) Display all elements of queue" << endl;
	cout << "4) Exit" ;
	do
	{
		cout << "\nEnter your choice :" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
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

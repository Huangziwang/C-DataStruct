#include "CirQueue.h"
#include "process.h"
using namespace std;
char pause;
typedef int T;
int main()
{
	int i;
	T e;
	CirQueue<int>Q(20);
	int choice;
	do
	{
		cout<<"1-element enqueue"<<endl;
		cout<<"2-element dequeue"<<endl;
		cout<<"3-get front element"<<endl;
		cout<<"4-get last element"<<endl;
		cout<<"5-measure the queue empty"<<endl;
		cout<<"6-disp the list"<<endl;
		cout<<"7-drop out"<<endl;
		cout<<"Enter Choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"please show the number you want to enqueue"<<endl;
				cin>>i;
				Q.EnQueue(i);
				break;
			case 2:
				cout<<Q.DeQueue()<<endl;
				break;
			case 3:
				cout<<Q.GetHead()<<endl;
				break;
			case 4:
				cout<<Q.GetLast()<<endl;
				break;
			case 5:
				cout<<Q.QueueEmpty()<<endl;
				break;
			case 6:
				Q.QueueDisp();
				break;
			case 7:
				break;
		 }
	}while(choice!=7);
	return 0;
}

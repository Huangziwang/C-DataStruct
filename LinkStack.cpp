#include "LinkStack.h"
#include "process.h"
using namespace std;
char pause;
typedef int T;
int main()
{
	int i;
	T e;
	LinkStack<int>S;
	int choice;
	do
	{
		cout<<"1-built the linear list"<<endl;
		cout<<"2-pop element"<<endl;
		cout<<"3-gettop element"<<endl;
		cout<<"4-make the stack empty"<<endl;
		cout<<"5-measure the stack empty"<<endl;
		cout<<"6-disp the list"<<endl;
		cout<<"7-drop out"<<endl;
		cout<<"Enter Choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"push element into stack"<<endl;
				cin>>i;
				S.Push(i);
				break;
			case 2:
				cout<<"Pop element"<<endl;
				cout<<S.Pop()<<endl;
				break;
			case 3:
				cout<<S.GetTop()<<endl;
				break;
			case 4:
				S.ClearStack();
				break;
			case 5:
				cout<<S.StackEmpty()<<endl;
				break;
			case 6:
				S.StackDisp();
				break;
			case 7:
				break;
		 }
	}while(choice!=7);
	return 0;
}

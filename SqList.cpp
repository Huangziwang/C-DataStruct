#include <iostream>
#include "SqList.h"
#include "process.h"
using namespace std;
char pause;
typedef int T;
int main()
{
	int i;
	T e;
	SqList<int>L(20);
	int choice;
	do
	{
		cout<<"1-built the linear list"<<endl;
		cout<<"2-insert element e in the location i"<<endl;
		cout<<"3-delete the element e in teh location i"<<endl;
		cout<<"4-return the ith element in the linear list"<<endl;
		cout<<"5-find the location of element e"<<endl;
		cout<<"6-clear the list"<<endl;
		cout<<"7-if list empty"<<endl;
		cout<<"8-if list full"<<endl;
		cout<<"9-measure list length"<<endl;
		cout<<"10-disp the list"<<endl;
		cout<<"11-drop out"<<endl;
		cout<<"Enter Choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Please enter the number of the linear list you want to built"<<endl;
				cin>>i;
				L.CreateList(i);
				break;
			case 2:
				cout<<"Please input the location i and element e"<<endl;
				cin>>i>>e;
				L.Insert(i,e);
				break;
			case 3:
				cout<<"Please input the location i you want to delete"<<endl;
				cin>>i;
				L.Delete(i);
				break;
			case 4:
				cout<<"Please input the location i to get the element"<<endl;
				cin>>i;
				cout<<L.GetElem(i)<<endl;
				break;
			case 5:
				cout<<"Please input the element e you wnat to find it location"<<endl;
				cin>>e;
				cout<<L.Locate(e)<<endl;
				break;
			case 6:
				L.Clear();
				break;
			case 7:
				cout<<L.Empty()<<endl;
				break;
			case 8:
				cout<<L.Full();
				break;
			case 9:
				cout<<L.Length()<<endl;
				break;
			case 10:
				L.ListDisp();
				break;
			case 11:
				break;
		 }
	}while(choice!=11);
	return 0;
}

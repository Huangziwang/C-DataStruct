#include <iostream>
using namespace std;
template<class T>
struct Node
{
	T data;				//data space to save the element
	Node *next;			//node space to direct teh next node
};

template<class T>
class CLinkList
{
	private:
		Node<T> *Head;
	public:
		CLinkList();		//construct function,construct empty linklist
		~CLinkList();	//destructor,delete linklist
		void CreateList(int n);	//create linklist with n element
		void Insert(int i,T e);	//insert the element e in location i
		T Delete(int i);		//delete the ith element and return
		T GetElem(int i);		//get the ith element
		int Locate(T e);		//find the first location of element e in the linklist
		T Prior(T e);			//return the before element of element e
		int Empty();			//if linklist empty
		int Length();			//length of the linklist
		void ListDisp();		//disp the linklist
};

template<class T>
CLinkList<T>::CLinkList()			//construct function,construct empty linklist
{
	Head=new Node<T>;
	Head->next=Head;
}

template<class T>
CLinkList<T>::~CLinkList()		//destructor,delete linklist from the first
{
	Node<T> *p=Head,*s;
	while(p->next!=Head)
	{
		s=p;
		p=p->next;
		delete s;
	}
	Head=NULL;
}

template<class T>
void CLinkList<T>::CreateList(int n)		//create linklist with n element
{
	Node<T> *p,*s;
	T e;
	p=Head;
	cout<<"Please input "<<n<<" numbers"<<endl;
	for(int i=0;i<n;i++)
	{
		s=new Node<T>;
		cin>>e;
		s->data=e;
		p->next=s;
		s->next=Head;
		p=s;
	}
}

template<class T>
int CLinkList<T>::Length()				//measure the length of this linklist
{
	Node<T> *p;
	int length=0;
	p=Head;
	while(p->next!=Head)
	{
		p=p->next;
		length++;
	}
	return length;
}

template<class T>
void CLinkList<T>::Insert(int i,T e)		//insert the element e in location i
{
	if(i<1||i>Length()) cout<<"insert location errror"<<endl;
	else {
		Node<T> *p,*s;
		p=Head;
		for(int j=1;j<i;j++)
		p=p->next;
		s=new Node<T>;
		s->data=e;
		s->next=p->next;
		p->next=s;
	}
}

template<class T>
T CLinkList<T>::Delete(int i)		//delete the element in location i
{
	if(i<1||i>Length()) cout<<"delete location error"<<endl;
	else
	{
		T e;
		Node<T> *p=Head,*s;
		for(int j=1;j<i;j++)
		p=p->next;
		s=p->next;
		p->next=s->next;
		e=s->data;
		delete s;
		return e;
	}
}

template<class T>
int CLinkList<T>::Locate(T e)		//find the first location of element e in the linklist
{
	int i=1;
	Node<T> *p=Head->next,*s;
	while(p!=Head&&p->data!=e)
	{
		p=p->next;
		i++;
	}
	if(p==Head) return 0;
	else return i;
	
}

template<class T>
T CLinkList<T>::GetElem(int i)			//get the element in location i
{
	Node<T> *p=Head->next;
	if(i<1||i>Length()) cout<<"the getelem locaiton errro"<<endl;
	else{
		for(int j=1;j<i;j++)
		p=p->next;
	}
	return p->data;
}

template<class T>
int CLinkList<T>::Empty()				//judge if linklist empty
{
	if(Head->next==Head) return 1;
	else return 0;
}

template<class T>
void CLinkList<T>::ListDisp()			//disp the linklist
{
	Node<T> *p=Head->next;
	while(p!=Head)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

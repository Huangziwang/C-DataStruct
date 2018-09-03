#include <iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkStack
{
	private:
		Node<T> *top;			//stack top pointer
	public:
		LinkStack() {top=NULL;};		//construct function,initlize with m container
		~LinkStack();			//destructor
		void Push(T e);		//push element into stack top
		T Pop();			//pop element from stack top
		T GetTop();			//get element from stack top
		int StackEmpty();	//if stack is empty
		void ClearStack();	//clear stack
		void Stacktop();	//return stack top pointer
		void StackDisp();	//disp stack element with
};

template<class T>
LinkStack<T>::~LinkStack()	//deconstructor
{
	Node<T> *p;
	while(top)
	{
		p=top;
		top=top->next;
		delete p;
		}	
}

template<class T>
void LinkStack<T>::Push(T x)	//push element into stack top
{
	Node<T> *p;
	p=new Node<T>;
	p->data=x;
	p->next=top;
	top=p;
}

template<class T>
T LinkStack<T>::Pop()			//pop element from stack top
{
	T e;
	Node<T> *p;
	p=top;
	top=top->next;
	e=p->data;
	delete p;
	return e;
}

template<class T>
T LinkStack<T>::GetTop()		//get the stack top element
{
	if(top!=NULL) return top->data;
}

template<class T>
int LinkStack<T>::StackEmpty()	//if stack empty
{
	if(top==NULL) return 1;
	else return 0;
}

template<class T>
void LinkStack<T>::ClearStack()	//clear stack
{
	while(top)
	{
		Node<T> *p;
		p=top;
		top=top->next;
		delete p;
	}
}

template<class T>
void LinkStack<T>::StackDisp()	//disp stack
{
	Node<T> *p=top;
	while(p){
		cout<<p->data<<'\t';
		p=p->next;
	}
	cout<<endl;
}

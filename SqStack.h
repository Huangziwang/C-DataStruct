#include <iostream>
using namespace std;
template<class T>
class SqStack
{
	private:
		T *base;			//stack pointer
		int top;			//stack top pointer
		int stacksize;		//container of stack
	public:
		SqStack(int m);		//construct function,initlize with m container
		~SqStack() {delete [] base; top=-1;stacksize=0;}  //destructor
		void Push(T e);		//push element into stack top
		T Pop();			//pop element from stack top
		T GetTop();			//get element from stack top
		int StackEmpty();	//if stack is empty
		void ClearStack();	//clear stack
		void Stacktop();	//return stack top pointer
		void StackDisp();	//disp stack element with
};

template<class T>
SqStack<T>::SqStack(int m)	//construct function,initlize with m container
{
	base=new T[m];
	if(base==NULL)
	{
		cout<<"built stack fail"<<endl;
		exit(1);
	}
	stacksize=m;
	top=-1;
}

template<class T>
void SqStack<T>::Push(T x)	//push element into stack top
{
	if(top>stacksize-2) cout<<"stack is full"<<endl;
	else
	{
		base[++top]=x;
	}
}

template<class T>
T SqStack<T>::Pop()			//pop element from stack top
{
	if(top<0) cout<<"stack is empty"<<endl;
	else	return base[top--];
}

template<class T>
T SqStack<T>::GetTop()		//get the stack top element
{
	if(top!=-1) return base[top];
	else cout<<"stack is emtpy";
}

template<class T>
int SqStack<T>::StackEmpty()	//if stack empty
{
	if(top==-1) return 1;
	else return 0;
}

template<class T>
void SqStack<T>::ClearStack()	//clear stack
{
	top=-1;
}

template<class T>
void SqStack<T>::StackDisp()	//disp stack
{
	for(int i=top;i>-1;i--)
	cout<<base[i]<<'\t';
	cout<<endl;
}

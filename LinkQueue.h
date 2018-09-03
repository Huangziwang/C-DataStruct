#include <iostream>
using namespace std;
template<class T>
struct Node
{
	T data;				//save element value
	Node<T> *next;		//the pointer point next node
};

template<class T>
class LinkQueue
{
	private:
		Node<T> *front;		//pointer front
		Node<T> *rear;		//pointer rear
		public:
			LinkQueue();	//construct function,initlize queue with m size
			~LinkQueue();		//destructor,release the space of queue
			void EnQueue(T e);	//send element e into queue rear
			T DeQueue();		//get element out from queue front
			T GetHead();		//get element from queue front
			T GetLast();		//get element from queue rear
			int QueueEmpty();	//if queue empty
			int QueueFull();	//if queue full
			void ClearQueue();	//clear queue
			void QueueDisp();	//disp queue
};

template<class T>
LinkQueue<T>::LinkQueue()	//construct function,initlize queue with m size
{
	front=new Node<T>;
	front->next=NULL;
	rear=front;
}

template<class T>
LinkQueue<T>::~LinkQueue()		//destructor,release the space of queue
{
	Node<T> *p;
	while(front!=rear){
		p=front;
		front=front->next;
		delete p;
	}
}

template<class T>
void LinkQueue<T>::EnQueue(T e)	//send element e into queue rear
{
	Node<T> *p;
	p=new Node<T>;
	p->data=e;
	rear->next=p;
	p->next=NULL; 
	rear=p;
	
}

template<class T>
T LinkQueue<T>::DeQueue()		//get element out from queue front
{
	if(front==rear) cout<<"queue is empty"<<endl;
	else{
		T e=front->data;
		Node<T> *p;
		p=front;
		front=front->next;
		delete p;
		return e;
	}
}

template<class T>
T LinkQueue<T>::GetHead()		//get element from queue front
{
	if(front==rear) cout<<"queue is empty"<<endl;
	else{
		return front->next->data;
	}
}

template<class T>
T LinkQueue<T>::GetLast()		//get element from queue rear
{
	if(front==rear) cout<<"queue is empty"<<endl;
	else{
	return rear->data;
	}
}

template<class T>
int LinkQueue<T>::QueueEmpty()	//if queue empty
{
	if(front==rear) return 1;
	else return 0;
}

template<class T>
void LinkQueue<T>::ClearQueue()	//clear the queue
{
	Node<T> *p;
	while(front!=rear){
		p=front;
		front=front->next;
		delete p;}
}

template<class T>
void LinkQueue<T>::QueueDisp()	//disp the queue
{
	Node<T> *p=front;
	while(p!=rear){
		cout<<p->next->data<<'\t';
		p=p->next;
	}
	cout<<endl;
}

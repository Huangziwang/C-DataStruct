#include <iostream>
using namespace std;

template<class T>
class CirQueue
{
	private:
		T *base;		//save the pointer of Queue front
		int front;		//pointer front
		int rear;		//pointer rear
		int queuesize;	//queue container
		public:
			CirQueue(int m);	//construct function,initlize queue with m size
			~CirQueue();		//destructor,release the space of queue
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
CirQueue<T>::CirQueue(int m)	//construct function,initlize queue with m size
{
	queuesize=m;
	base=new T[m];
	front=rear=0;
}

template<class T>
CirQueue<T>::~CirQueue()		//destructor,release the space of queue
{
	delete [] base;
	rear=0;
	front=0;
	queuesize=0;
}

template<class T>
void CirQueue<T>::EnQueue(T e)	//send element e into queue rear
{
	if((rear+1)%queuesize==front) cout<<"queue is full"<<endl;
	else{
		base[rear]=e;
		rear=(rear+1)%queuesize;
	}
}

template<class T>
T CirQueue<T>::DeQueue()		//get element out from queue front
{
	if(front==rear) cout<<"queue is empty"<<endl;
	else{
		T e=base[front];
		front=(front+1)%queuesize;
		return e;
	}
}

template<class T>
T CirQueue<T>::GetHead()		//get element from queue front
{
	if(front==rear) cout<<"queue is empty"<<endl;
	else{
		return base[front];
	}
}

template<class T>
T CirQueue<T>::GetLast()		//get element from queue rear
{
	if(front==rear) cout<<"queue is empty"<<endl;
	else{
	return base[rear-1];
	}
}

template<class T>
int CirQueue<T>::QueueEmpty()	//if queue empty
{
	if(front==rear) return 1;
	else return 0;
}

template<class T>
int CirQueue<T>::QueueFull()	//if queue full
{
	if((rear+1)%queuesize==front) return 1;
	else return 0;
}

template<class T>
void CirQueue<T>::ClearQueue()	//clear the queue
{
	front=rear=0;
}

template<class T>
void CirQueue<T>::QueueDisp()	//disp the queue
{
	int i=front;
	for(;i%queuesize!=rear;i++)
	cout<<base[i]<<'\t';
	cout<<endl;
}

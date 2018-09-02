#include <iostream>
using namespace std;
template<class T>
class SqList
{
	private:
		T *elem;          	//the first address of the list
		int length;       	//length of the list 
		int listsize;     	//contain of the list 
	public:
		SqList(int m);    	//construct function,initlize the list with m contain
		~SqList();			//destructor,delete the list
		void CreateList(int n);	//build the linear list with n element
		void Insert(int i,T e);	//insert element e in location i
		T Delete(int i);	//delete the element in location i and return
		T GetElem(int i);	//get the element e in location i
		int Locate(T e);	//get the first location of element e if it's in the list,else return zero
		void Clear();		//clear the list
		int Empty();		//measure if the list is empty
		int Full();			//measure if the list is full
		int Length();		//measure the length of the list
		void ListDisp();	//disp the list 
};

template<class T>
SqList<T>::SqList(int m)			//construct function,initlize the list with m contain
{
	elem=new T[m];
	length=0;
	listsize=m;
}

template<class T>					
SqList<T>::~SqList()				//destructor,delete the list
{
	delete [] elem;
	length=0;
	listsize=0;
}

template <class T>
void SqList<T>::CreateList(int n)	//build the linear list with n element
{
	if(n>listsize) cout<<"number overflow"<<endl;
	else cout<<"Please input "<<n<<" numbers"<<endl;
	for(int i=0;i<n;i++)
	cin>>elem[i];
	length=n;
} 

template<class T>
void SqList<T>::Insert(int i,T e)	//insert element e in location i
{
	if(i<0||i>=length) cout<<"insert location error"<<endl;
	else if(length>=listsize-1) cout<<"overflow"<<endl; 
	else for(int j=length;j>i;j++)
	elem[j]=elem[j-1];
	elem[i-1]=e;
	length++;
}

template<class T>
T SqList<T>::Delete(int i)			//delete the element in location i and return
{
	if(length<1) cout<<"underflow"<<endl;
	else if(i<1||i>length+1) cout<<"delete locaiton error"<<endl;
	else {
	T e=elem[i-1];
	for(int j=i;j<length;j++)
	elem[j-1]=elem[j];
	length--;
	return e;}
}

template<class T>
T SqList<T>::GetElem(int i)			//get the element e in location i
{
	if(i<1||i>length) cout<<"get location error"<<endl;
	else return elem[i-1];
 } 
 
template<class T>
int SqList<T>::Locate(T e)			//get the first location of element e if it's in the list,else return zero
{
	int i=0;
	for(i=0;i<length;i++)
	if(elem[i]==e) break;
	if(i<length) return i+1;
	else return 0;
 }
 
 template<class T>
 void SqList<T>::Clear()			//clear the list,make the length become zero
 {
 	length=0;
  }
  
template<class T>
int SqList<T>::Empty()				//measure if the list is empty
{
	if(length==0) return 1;
	else return 0;
 }
 
template<class T>
int SqList<T>::Full()				//measure if the list is full
{
	if(length==listsize) return 1;
	else return 0;
 }

template<class T>
int SqList<T>::Length()				//measure the length of the list
{
	return length;
 }
 
 template<class T>
 void SqList<T>::ListDisp()			//disp the list 
 {
 	for(int i=0;i<length;i++)
 	cout<<elem[i]<<endl;
  }

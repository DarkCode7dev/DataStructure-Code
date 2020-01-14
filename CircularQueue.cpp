#include<iostream>
using namespace std;
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;

bool isempty(){
	if(front==-1 && rear==-1)
	return true;
	else
	return false;
}

void enqueue(int value)
{
	if((rear+1)%SIZE==front)//QUEUE IS FULL==========================
		cout<<"Queue is full\n";
	else
	{
		if(front==-1)//first element is inserted
			front=0;
			rear=(rear+1)%SIZE;//============================
			queue[rear]=value;//insert at rear
		
	}	
	
}
void dequeue()
{
	if(isempty())
	 cout<<"Queue is empty\n";
	 else
	 if(front==rear)//only one element
	 	front=rear=-1;
	 else
	 front=(front+1)/SIZE;//=====================================
}
void showfront()
{
	if(isempty())
	cout<<"Queue is empty\n";
	else
	cout<<"element at front is:"<<queue[front];
	
}

void displayQueue()
{
 if(isempty())
  cout<<"Queue is empty\n";
 else
 {
  int i;
  if( front <= rear )
  {
   for( i=front ; i<= rear ; i++)
   cout<<queue[i]<<" ";
  }
  else
  {
   i=front;
   while( i < SIZE)
   {
   cout<<queue[i]<<" ";
   i++;
   }
   i=0;
   while( i <= rear)
   {
   cout<<queue[i]<<" ";
   i++;
   }
  }
 }
}

int main()
{
	int val,ch;
	while(ch!=5)
	{	
		cout<<"1.Enqueue 2.Dequeue 3.ShowFront 4.DisplayQueue 5.Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:cout<<"Enter the value to be entered\n";
			cin>>val;
			enqueue(val);
			break;
			case 2: dequeue();
			break;
			case 3: showfront();
			break;
			
			case 4: displayQueue();
			break;
			
			default:cout<<"Exit";
		}
	}
}

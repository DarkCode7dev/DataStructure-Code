#include<stdlib.h>
#include<stdio.h>

//defined your own data type
struct Node{
	//it contain data variable AND pointer to next link
	int data;
	Node* next;
};

/*create head pointer declare it as global So that it can be accessed anywhere 
intiallized  it to null because it is not pointing to any Node
*/ 
Node* head=NULL;// this pointer is going to store datatype of node

void Insert(int data,int n)
{
	
	//new operator to dynamically allocate memory
	//for load and returning starting address to ptr
	Node* temp1 = new Node();

	/*Now we use this pointer temp1 to put values "data" in data part of the
	 Node we do this using right arrow operator  which is used to access the parts of Node 
	using pointer*/
	temp1->data = data;
	
	/*Similarly we put Null in the link part Remember we have to put Null to show that 
	this is the end of link list and and current Node is Node pointing to any other Node*/
	temp1->next= NULL;
   
   //if we want to insert at the begining
   if(n==1)	
	{
		//we store the value in head in the link part of our newly created 
		temp1->next = head;
		
		/*finally we equate head pointer to  temp1 thus pointing the head pointer to newly created node
		which will be starting point of our linklist*/
	head = temp1;
		
		return;
	}
	
	Node* temp2 = head; //creating another pointer to node
	
	//go to the n-1 node
	for(int i=0;i<n-2;i++)
	{
		temp2 =temp2->next;
	}
	
temp1->next = temp2->next;//set link field of newly created node to link field of n-1 created node//
 temp2->next = temp1;//adjust n-1 node to newly created node
}

void Delete(int n){
	
	//if link list is Empty that is head is equal to null then we simply print that the list is 
	//empty and we can't delete any node from it
	if(head==NULL)
	printf("list is empty");
 else{
 	
	//But if the list is not empty we will create our pointer temp1  and we will equate to head
	//that is the first Node in our linkList
	Node* temp1=head;
	
	if(n==1)
	{
		head=temp1->next;//setting head to second link
		free(temp1);
		return;
	}
	
	for(int i=0;i<n-2;i++)//go to node n-1
	{
		temp1=temp1->next;
	}
	
	Node* temp2=temp1->next;
	temp1->next=temp2->next;// trying to connect the link
	
	free(temp2);
	
	
	
	}
}

void Print(){
	Node* temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
		
	}
	
	printf("\n");
}

int main()
{
	head=NULL;//intially list is empty
	int choice=1,data,loc;
	do
	{
		printf("the operation in Linked List are \n");
		printf("1.... to Insert into linklist\n");
		printf("2.... to Delete node from Linked List\n");
		printf("3... Display whole link list\n");
		printf("4 to exit\n");
		printf("Enter your choice:");
    	scanf("%d", &choice); 
    	switch(choice)
    	{
    		case 1:
    		{
    			printf("Enter data:");
    			scanf("%d", &data);
    			printf("Enter location:");
    			scanf("%d", &loc); 
				Insert(data,loc); 
				break;
			}
			case 2:
			{
				printf("Enter location:");
    			scanf("%d", &loc); 
    			Delete(loc);
    			break;
			}
			case 3:
			{
				Print();
				break;
			}
			default:
			{
				break;
			}
		}
	}while(choice!=4);

}

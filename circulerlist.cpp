#include<iostream>
using namespace std;
#include<malloc.h>

struct node{
	int info;
	struct node *next;
};
struct node *createlist(struct node*);
void display(struct node*);
int main()
{
	struct node *first=NULL;
	first=createlist(first);

		first=createlist(first);
		
				first=createlist(first);
    display(first);
   // display(first);
}

struct node *createlist(struct node *first)
{
	struct node *temp=NULL;
	int data;
	cout<<"info\t";
	cin>>data;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->info = data;
	new_node->next=NULL; 
	cout<<"new_node address--->"<<new_node<<"\n";
	if(first==NULL)
	{
		new_node->next=new_node;
		cout<<"INSIDE IF\n";
		first=new_node;
		temp = new_node;
//		cout<<"1st node\t"<<first->next<<"\n\t new node address--->"<<new_node->next<<"\t";
		return first;
	}else{
	temp = first;
//	cout<<"inside else\n";
while(temp->next!=first){
	temp= temp->next;
}
	new_node->next = temp->next;
	temp->next=new_node;
	temp=new_node;	

return first;
}
	
}
void display(struct node *first)
{

	struct node *temp=NULL;

	if(first==NULL)
	{
		cout<<"list is empty";
	}
	temp=first;

	do{
	
	   //	pre=temp;
		cout<<"|"<<temp->info<<"|"<<temp->next<<"|"<<"-->";
		 temp=temp->next;
		 
}while(temp!=first);
		 
	}


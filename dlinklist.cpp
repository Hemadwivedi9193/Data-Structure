#include<iostream>
using namespace std;
#include<malloc.h>
struct node{
	struct node *pre;
	int info;
	struct node *next;
};
struct node *createlist(struct node *);
void display(struct node *);
struct node *insertnode(struct node *,int ,int);
struct node *deletenode(struct node *,int);
int main(){
	struct node *first=NULL;
	int data,pos,del,flag=0,ch;
	cout<<"double list is empty so first create list\n";
	first = createlist(first);
		do{
			cout<<"\nThe Operations on Double Linked List\n";
  cout<<"1........Insert\n";
  cout<<"2........Delete\n";
  cout<<"3........Display\n";
  cout<<"4........Exit\n";
  cout<<"\nEnter your choice :\n";
  cin>>ch;
			switch(ch){
		case 1:
			{
			 cout<<"enter the number u want to add\t";
             cin>>data;
             cout<<"after what num you want to insert\t";
             cin>>pos;
             first = insertnode(first,data,pos);
			 break;	
			}
		case 2:
			{
				cout<<"node u want to delete\t";
                cin>>del;
                first = deletenode(first,del);
			 break;			
			}
		case 3:
			{
			 display(first); 
			  break;		
			}
		case 4:
			{
			 exit(1);	
			}
		default:
			break;			
			}
			cout<<"press 0 to exit or any other key to continue with operation\t";
			cin>>flag;
		}while(flag!=0);
		
}

struct node *createlist(struct node *first)
{
	struct node *temp = NULL;
	int flag =0;
	int data;
	
	do{
		cout<<"INFO\t";
	cin>>data;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->info = data;
	new_node->pre=NULL;
	new_node->next=NULL;
	cout<<"new_node address(create)---->\t"<<new_node;
		if(first==NULL)
		{
			first = new_node;
			temp = new_node;
			//return first;
		}else
		{
		temp->next = new_node;
		new_node->pre = temp;
		temp = new_node;
		}
		cout<<"\nwant to contnue press any key else 0\t";
		cin>>flag;
	}while(flag!=0);
	
	return first;
}
void display(struct node *first){
	struct node *temp = NULL;
	if(first==NULL)
	{
		cout<<"list is empty";
	}
	else{
		temp = first;
	}
	while(temp!=NULL)
	{
		cout<<"|"<<temp->pre<<"|"<<temp->info<<"|"<<temp->next<<"|-->";
		temp = temp->next;
	}
	
}

struct node *insertnode(struct node *first,int data,int pos)
{
	struct node *temp = NULL;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->info = data;
	new_node->pre=NULL;
	new_node->next=NULL;
	cout<<"new_node address(create)---->\t"<<new_node<<"\n";
	if(first==NULL)
	{
		cout<<"LIST IS EMPTY.FIRST CREATE IT THEN INSERT IT\n";
		first = createlist(first);
		return first;
	}
	else
	temp = first;
	while(temp->next!=NULL&&temp->info!=pos)
	{
		temp = temp->next;
	}
	if(temp->next==NULL)
	{
		temp->next = new_node;
		new_node->pre = temp;
		temp =new_node;
	}
	else{
		new_node->next = temp->next;
		temp->next->pre = new_node;
		new_node->pre = temp;
		temp->next = new_node;
		
	}
	return first;
}

struct node *deletenode(struct node *first,int del)
{
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;
	if(first==NULL){
		cout<<"LIST IS EMPTY\n";
	
		return first;
	}else{
		temp1 = first;
		
	}
	while(temp1->info!=del&&temp1->next!=NULL){
		cout<<"!!!!!!!!\n";
		temp2 = temp1;
		temp1 = temp1->next;
	}
	if(temp1->info==del){
           if(temp1==first){
              first = first->next;
              first->pre=NULL;
              free(temp1);
		   
		   	return first;
		     }
			 else if(temp1->next==NULL){
			 temp2->next=NULL;
			 free(temp1);
			 return first;
			 
			 }else{
			 
			temp2->next=temp1->next;		
		    temp1->next->pre = temp1->pre;
     		free(temp1);
     		return first;
	     }
	}
	else{
		
		 cout<<"DATA NOT FOUND\n";
	}
	return first;
	
}





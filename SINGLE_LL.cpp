#include<iostream>
using namespace std;
#include<malloc.h>

struct node{
	int info;
	struct node *next;
};

struct node* createlist(struct node *);
void display(struct node *);
struct node* deletenode(struct node *,int);
struct node* insert(struct node *,int,int);
int main()
{ 
int flag=0,num,target,del,ch;
	struct node *first=NULL;
	cout<<"at starting there is no list,create list\n";	
    first = createlist(first);

do{
	cout<<"\nThe Operations on Linked List";
  cout<<"1........Insert\n";
  cout<<"2........Delete\n";
  cout<<"3........Display\n";
  cout<<"4........Exit\n";
  cout<<"\nEnter your choice :\n";
  cin>>ch;
  switch(ch)
     	{
	   	case 1:
			{
			 cout<<"enter the number u want to add\t";
             cin>>num;
             cout<<"after what num you want to insert\t";
             cin>>target;
             first = insert(first,num,target);
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
cout<<"press any key for continue or 0 for exit:\t";
		        cin>>flag;
	
}while(flag!=0);

}

struct node* createlist(struct node *first)
{
		int num;
	struct node *temp=NULL;	
	int flag =0;

		do{
	   
		struct node *new_node=(struct node*)malloc(sizeof(struct node));
		cout<<"INFO\t";
		cin>>num;
	    new_node->info = num;
	    new_node->next = NULL;
		if(first==NULL)
		{
			first = new_node;
			temp = new_node;
			}
			else{
				temp->next = new_node;
				temp=new_node;
		
			}
				cout<<"press 1 for continue or 0 for exit:\t";
		        cin>>flag;	
}while(flag!=0);
return first;
	
}

void display(struct node *first)
{
	struct node*temp = NULL;
	if(first==NULL)
	{cout<<"list is empty";
	}
	else{
		temp = first;
	}
	while(temp!=NULL)
	{
		cout<<"|"<<temp->info<<"|"<<temp->next<<"|"<<"-->";
		temp=temp->next;
	}
	cout<<"\n";
}
	
struct node *insert(struct node *first,int num,int target)
{
	struct node *temp=NULL;
		struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->info=num;
	new_node->next=NULL;
	if(first==NULL)
	{
//	//	cout<<"list is empty"
       first=createlist(first);
// 	temp = first;
////	cout<<"@@@@@@@@@@";
//		first->next = new_node;
//	first = new_node;;
////	cout<<"@@@@@@@@@@";
		return first;
	}else{
		temp = first;
	}

	while(temp->next!=NULL&&temp->info!=target)
	{
		temp=temp->next;
		
	}
	if(temp->next==NULL)
	{
		temp->next = new_node;
	}
	else
	{
		new_node->next = temp->next;
		temp->next = new_node;
	
	}
	return first;
	
		}		

struct node* deletenode(struct node *first,int del)
{
	struct node *temp=NULL;
	struct node *pre=NULL;
	if(first == NULL)
	{
		cout<<"list is already empty";
		return first;
	}
	
		temp = first;
	
	
	while(temp->next!=NULL&&temp->info!=del)
	{
		pre = temp;
		temp=temp->next;
		
	}
	if(temp->info==del)
	{
			if(temp == first)
		{
			first = temp->next;
			free(temp);
			return first;
		}else{
			pre->next=temp->next;
			free(temp);
			return first;
		}
	
	}else
	{
		cout<<"ELEMENT "<<del<<" IS NOT FOUND\n";
		return first;
	}
	return first;
}

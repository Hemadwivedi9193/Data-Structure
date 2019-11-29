#include<iostream>
#include<malloc.h>
using namespace std;

struct stack{
	int info;
	struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
void display(struct stack *);
int main(){
	struct stack *temp = NULL;
	int data,flag =0;
	do{
		cout<<"Element:\t";
		cin>>data;
		top = push(top,data);
		cout<<"1:continue\t0:exit\t";
		cin>>flag;
	}while(flag!=0);
	
   // cout<<"before pop\t"<<top->info<<"|"<<top->next<<"|-->\n";
	display(top);
	top = pop(top);
//	cout<<"after pop\t"<<top->info<<"|"<<top->next<<"|-->\n";
	display(top);
}

struct stack *push(struct stack *top,int data){
    struct stack *temp=NULL;
	struct stack *new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->info = data;
	new_node->next = NULL;
	cout<<"address of new_node\t"<<new_node<<endl;
	if(top==NULL){
		top = new_node;
	//	temp = new_node;
	}else{
		new_node->next=top;
		top = new_node;
	}
return top;
}
void display(struct stack *top){
	struct stack *temp = NULL;
	if(top==NULL){
		cout<<"stack is Empty \t";
	}
	else{
		while(top){
		
		cout<<top->info<<"|"<<top->next<<"|-->";
		top = top->next;
	}
	}
	
}


struct stack *pop(struct stack *top)
{
		struct stack *temp = NULL;
	if(top==NULL){
		cout<<"underflow";
	}else{
		temp = top;
		top = top->next;
		free(temp);
	}
	return top;
}

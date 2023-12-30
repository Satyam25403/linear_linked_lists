#include<stdio.h>
#include<stdlib.h>
//a self referential data structure
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addatend(struct node* head,int data);
struct node* addtoempty(struct node* head,int data);
struct node* createlist(struct node* head);
struct node* delfirst(struct node* head);
struct node* dellast(struct node* head);
struct node* delatpos(struct node* head,int pos);
void print (struct node* head);

int main(){
    struct node* head =NULL;
    
    return 0;
}

struct node* createlist(struct node* head){
    int data,n,i;
    printf("enter number of nodes:");
    scanf("%d",&n);
    if(n==0)
        return head;
    //first we will make one node 
    printf("enter element for node1:");
    scanf("%d",&data);
    head=addtoempty(head,data);
    //and then attatch other nodes to it
    for(i=1;i<n;i++){
        printf("enter data for the node %d:",i+1);
        scanf("%d",&data);
        head=addatend(head,data);
    }
    return head;
}
struct node* addtoempty(struct node* head,int data){
    //function to create a node in an empty list
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* addatend(struct node* head,int data){
    //function to add nodes at the end of the list
    struct node* temp,*tp;
    temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;        //pointer to traverse to the end node of the given list
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
struct node* dellast(struct node* head){
    //delete the last node of a list
    struct node* temp=head,*temp2=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;       //helps in adjustments
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}
struct node* delatpos(struct node* head,int pos){
    struct node* temp=head,*temp2=NULL;
    if(pos==1){
        head=delfirst(head);
        return head;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        //means we have reached the end node
        head=dellast(head);
    }
    else{
        temp2=temp->prev;
        temp2->next=temp->next;
        (temp->next)->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}
struct node* delfirst(struct node* head){
    //since in double ll we have reference to prev node we dont need to create an extra pointer for storing that
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}
void print (struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
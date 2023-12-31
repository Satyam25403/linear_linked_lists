#include<stdio.h>
#include<stdlib.h>
//a self referential data structure
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* create_node(struct node* head,int data);
struct node* insert_at_first(struct node* head,int data);
struct node* insert_at_loc(struct node* head,int loc,int data);
struct node* insert_after_node(struct node* head,int target,int data);
struct node* insert_at_end(struct node* head,int data);
//struct node* createlist(struct node* head);
struct node* del_first(struct node* head);
struct node* del_at_pos(struct node* head,int pos);
struct node* del_after_node(struct node* head,int data);
struct node* del_last(struct node* head);
void print (struct node* head);

int main(){
    head=insert_at_first(head,89);
    head=insert_at_first(head,33);
    head=insert_at_first(head,45);
    head=insert_at_first(head,27);
    head=insert_at_first(head,67);
    print(head);
    head=insert_at_loc(head,3,89);
    print(head);
    head=insert_at_loc(head,2,89);
    print(head);
    head=insert_at_end(head,90);
    print(head);
    head=insert_after_node(head,45,66);
    print(head);
    head=del_first(head);
    print(head);
    head=del_last(head);
    print(head);
    head=del_at_pos(head,2);
    print(head);
    head=del_after_node(head,66);
    print(head);
    return 0;
}

// struct node* createlist(struct node* head){
//     int data,n,i;
//     printf("enter number of nodes:");
//     scanf("%d",&n);
//     if(n==0)
//         return head;
//     //first we will make one node 
//     printf("enter element for node1:");
//     scanf("%d",&data);
//     head=addtoempty(head,data);
//     //and then attatch other nodes to it
//     for(i=1;i<n;i++){
//         printf("enter data for the node %d:",i+1);
//         scanf("%d",&data);
//         head=addatend(head,data);
//     }
//     return head;
// }
struct node* create_node(struct node* head,int data){
    //function to create a node in an empty list
    struct node* temp=malloc(sizeof(struct node));
    if(temp==NULL){
        printf("out of memory");
    }
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    return temp;
}
struct node* insert_at_first(struct node* head,int data){
    struct node* temp=create_node(head,data);
    if(head==NULL){
        return temp;
    }
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node* insert_at_loc(struct node* head,int loc,int data){
    // for nth positions n-2 passes needed
    //can give a valid location greater than 1
    struct node* temp=head;
    int i=1;
    while(i<loc-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("cant be inserted at a given location");
    }
    struct node* ptr=create_node(head,data);
    ptr->next=temp->next;
    ptr->next->prev=ptr;
    temp->next=ptr;
    ptr->prev=temp;
    return head;
}
struct node* insert_after_node(struct node* head,int target,int data){
    struct node* temp=head;
    while(temp->data!=target){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("node not found");
        return head;
    }
    struct node* ptr=create_node(head,data);
    ptr->next=temp->next;
    ptr->next->prev=ptr;
    temp->next=ptr;
    ptr->prev=temp;
    return head;
}
struct node* insert_at_end(struct node* head,int data){
    //function to add nodes at the end of the list
    struct node* temp=create_node(head,data);
    if(head==NULL){
        return temp;
    }
    struct node* tp=head;        //pointer to traverse to the end node of the given list
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
struct node* del_first(struct node* head){
    //since in double ll we have reference to prev node we dont need to create an extra pointer for storing that
    if(head==NULL){
        printf("linked list is already empty");
        return head;
    }
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}
struct node* del_at_pos(struct node* head,int pos){
    struct node* temp=head;
    int i=1;
    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("cant be inserted at a given location");
    }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    temp2->next->prev=temp;
    free(temp2);
    return head;
}
struct node* del_after_node(struct node* head,int data){
    struct node* temp=head;
    while(temp->data!=data){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("node not found");
        return head;
    }
    struct node* ptr=temp->next;
    temp->next=ptr->next;
    ptr->next->prev=temp;
    free(ptr);
    return head;
}
struct node* del_last(struct node* head){
    //delete the last node of a list
    if(head==NULL){
        printf("list is already empty");
        return head;
    }
    struct node* temp=head,*temp2=NULL;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->next;       //helps in adjustments
    temp->next=NULL;
    free(temp2);
    return head;
}
void print (struct node* head){
    if(head==NULL){
        printf("list is empty");
        return;
    }
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
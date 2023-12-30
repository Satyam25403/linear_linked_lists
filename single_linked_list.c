#include<stdio.h>
#include<stdlib.h>
//a self referential data structure
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* insert_at_beg(struct node* head,int data);
struct node* insert_at_end(struct node* head,int data);
struct node* insert_at_loc(struct node* head,int loc,int data);
struct node* insert_after_node(struct node* head,int target,int data);
struct node* create_node(struct node* head,int data);
struct node* del_first(struct node* head);
struct node* del_last(struct node* head);
struct node* del_at_loc(struct node* head,int loc);
struct node* del_after_node(struct node* head,int data);
void print (struct node* head);

int main(){
    head=insert_at_beg(head,89);
    head=insert_at_beg(head,33);
    head=insert_at_beg(head,45);
    head=insert_at_beg(head,27);
    head=insert_at_beg(head,67);
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
    head=del_at_loc(head,2);
    print(head);
    head=del_after_node(head,66);
    print(head);
    
    return 0;
}
struct node* create_node(struct node* head,int data){
    struct node* temp=malloc(sizeof(struct node));
    if(temp==NULL){
        printf("out of memory");
        exit(1);
    }
    temp->data=data;
    temp->next=NULL;
    return temp;
}
struct node* insert_at_beg(struct node* head,int data){
    if(head==NULL){
        return create_node(head,data);
    }
    else{
        struct node* temp=create_node(head,data);
        temp->next=head;
        head=temp;
        return head;
    }
}
struct node* insert_at_end(struct node* head,int data){
    if(head==NULL){
        return create_node(head,data);
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=create_node(head,data);
        return head;
    }
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
    struct node* ptr=create_node(head,data);
    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}
struct node* insert_after_node(struct node* head,int target,int data){
    struct node* temp=head;
    while(temp->data!=target){
        temp=temp->next;
    }
    struct node* ptr=create_node(head,data);
    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}
struct node* del_first(struct node* head){
    if(head==NULL){
        return NULL;
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node* del_last(struct node* head){
    if(head==NULL){
        return NULL;
    }
    struct node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
struct node* del_at_loc(struct node* head,int loc){
    struct node* temp=head;
    int i=1;
    while(i<loc-1 && temp!=NULL){
        temp=temp->next;
    }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    return head;
}
struct node* del_after_node(struct node* head,int data){
    struct node* temp=head;
    while(temp->data!=data){
        temp=temp->next;
    }
    struct node* ptr=temp->next;
    temp->next=ptr->next;
    free(ptr);
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
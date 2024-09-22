#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;  // Pointer to the next node
};

struct Node* createNode (int data){
    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtStart(struct Node* head,int data){
    struct Node* new=createNode(data);
    if(new==NULL) printf("bro we out of space!!!!");
    // else if(head->next=NULL) head->next=new; unecesarry
    else{
        new->next=head->next;
        head->next=new;
    }
}

void insertAtEnd(struct Node* head,int data){
    struct Node* new=createNode(data);
    if(new==NULL) printf("bro we out of space!!!!");
    // else if(head->next=NULL) head->next=new; unecesarry
    else{
        struct Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new;
    }
}

void insertBeforeAPoint(struct Node* head,int data,int key){
    struct Node* new=createNode(data);
    if(new==NULL) printf("bro we out of space!!!!");
    // else if(head->next=NULL) head->next=new; unecesarry
    else{
        struct Node* ptr=head;
        struct Node* ptr1;
        while(ptr->data!=key){
            ptr1=ptr;//prev
            ptr=ptr->next;//next
        }

        new->next=ptr1->next;
        ptr1->next=new;
    }
}
void deleteAtAPoint(struct Node* head,int key){
    
    

    struct Node* ptr=head;
    struct Node* ptr1;
    while(ptr->data!=key){
        ptr1=ptr;//prev
        ptr=ptr->next;//next
    }
    ptr1->next=ptr->next;
    
}
void insertAtAPoint(struct Node* head,int data,int key){
    struct Node* new=createNode(data);
    if(new==NULL) printf("bro we out of space!!!!");
    // else if(head->next=NULL) head->next=new; unecesarry
    else{
        struct Node* ptr=head;
        
        while(ptr->data!=key){
            
            ptr=ptr->next;//next
        }

        new->next=ptr->next;
        ptr->next=new;
    }
}

void process(struct Node* head){
    struct Node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        printf("%d\n",ptr->data);
    }
}

int main(){
    struct Node* header=createNode(3);
    insertAtStart(header,3);
    insertAtStart(header,5);
    insertAtStart(header,7);
    insertAtStart(header,9);
    deleteAtAPoint(header,7);
    insertAtEnd(header,178);
    process(header);
}


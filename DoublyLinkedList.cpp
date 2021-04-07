#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* head=NULL;

void insertAtBeg(int data){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    if(head==NULL){
        newNode->prev=NULL;
        newNode->next=NULL;
        head=newNode;
        return;
    }
    newNode->next=head;
    newNode->prev=NULL;
    head->prev=newNode;
    head=newNode;
}

void insertAtEnd(int data){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    if(head==NULL){
        newNode->prev=NULL;
        newNode->next=NULL;
        head=newNode;
        return;
    }
    node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=NULL;
}

void insertAtPos(int data, int pos){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    if(head==NULL){
        newNode->prev=NULL;
        newNode->next=NULL;
        head=newNode;
        return;
    }
    node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    temp->next->prev=newNode;
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteFromBeg(){
    node* toDel=head;
    head->next->prev=NULL;
    head=head->next;
    free(toDel);
}

void deleteFromEnd(){
    node* temp=head;
    while(temp->next != NULL && temp->next->next != NULL){
        temp=temp->next;
    }
    node* toDel=temp->next;
    temp->next=NULL;
    free(toDel);
}



void display(){
    node* temp=head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int data;
            cin>>data;
            insertAtEnd(data);
        }
        display();
        cout<<endl;
        //deleteFromBeg();
        deleteFromEnd();
        display();
        head=NULL;
    }
   
    return 0;
}

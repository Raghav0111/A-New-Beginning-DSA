#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }

};

void insertAtTail(node* &head, int val){
    node*n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp -> next!= NULL){
        temp = temp->next;
    }
    temp->next = n;
    
}

void insertAtHead(node *&head, int val){
    node *n = new node(val);
    n->next = head;
    head = n;
}

void Display(node *head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtHead(node * &head){
    node * todelete = head;
    head = head ->next;
    delete todelete;
}


void deletion(node * &head, int val){
    if(head == NULL){
        return;
    }
    if(head -> next == NULL){
        deleteAtHead(head);
    }
    node *temp = head;
    while(temp ->next ->data != val){
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next= temp ->next->next;
    delete todelete;
}

node * reverse(node * &head){
    node *prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL){
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* reverseRecursive (node * &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node * newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}



int main(){

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    Display(head);
    insertAtHead(head, 5);
    Display(head);

    // deletion(head, 3);
    // Display(head);
    node* newhead = reverseRecursive (head);
    Display(newhead);



    return 0;

}
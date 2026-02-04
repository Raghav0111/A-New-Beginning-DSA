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

node * reversek(node *&head, int k){
    node *prev = NULL;
    node *curr = head;
    node *next;

    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }
    if(next !=NULL){
        head ->next = reversek(next, k);
    }

    return prev;
    
}

bool detectCycle(node * &head){
    node *slow = head;
    node *fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

void removeCycle(node *&head){
    node * slow = head;
    node * fast = head;
    do{
        slow = slow->next;
        fast = fast ->next->next;
    }while(slow != fast);
    fast = head;
    while(slow ->next != fast ->next){
        slow = slow ->next;
        fast = fast ->next;
    
    }
    slow ->next = NULL;
}

int length(node*head){
    int l =0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        l++;
    }
    return l;
}

int intersection(node* &head1, node * &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d =0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;

    } else {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1 ==NULL){
            return -1;
        }
        d--;
    }
    while (ptr1!=NULL && ptr2 != NULL){
        if (ptr1 == ptr2){
            return ptr1->data;
        };
        ptr1 = ptr1 ->next;
        ptr2 = ptr2 -> next;

    }
    return -1;
}

node * merge(node * &head1, node * &head2){
    node *p1 = head1;
    node *p2 = head2;
    node *dummynode = new node(-1);
    node*p3 = dummynode;
    while(p1!=NULL && p2 !=NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        } else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1!=NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummynode->next;
}

node * mergerecursive(node * head1, node * head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    node * result;
    if(head1->data < head2 -> data){
        result = head1;
        result -> next = mergerecursive(head1->next, head2);
    } else {
        result = head2;
        result->next = mergerecursive(head1, head2->next);
    }
    return result;
}

int main(){

    node *head1 = NULL;
    node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 7);
    
    insertAtTail(head2, 4);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    Display(head1);
    Display(head2);
    // int ans = intersection(head1, head2);
    // cout<< ans;

    // deletion(head, 3);
    // Display(head);
    // node* newhead = reverseRecursive (head);
    // Display(newhead);
    // int k =2;
    // node *newhead = reversek(head, k);
    //Display(newhead);
    node * newhead = mergerecursive(head1, head2);
    Display(newhead);

    

    return 0;

}
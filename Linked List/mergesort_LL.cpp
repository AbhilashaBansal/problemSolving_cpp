// merge sort on 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

node* merge(node* first_ll, node* sec_ll) {
    node* temp_h = new node(0);
    node* head = temp_h;
    while(first_ll!=NULL && sec_ll!=NULL){
        if(first_ll->data < sec_ll->data){
            temp_h->next = new node(first_ll->data);
            first_ll = first_ll->next;
        }
        else{
            temp_h->next = new node(sec_ll->data);
            sec_ll = sec_ll->next;
        }
        temp_h = temp_h->next;
    }
    while(first_ll!=NULL){
        temp_h->next = new node(first_ll->data);
        first_ll = first_ll->next;
        temp_h = temp_h->next;
    }
    while(sec_ll!=NULL){
        temp_h->next = new node(sec_ll->data);
        sec_ll = sec_ll->next;
        temp_h = temp_h->next;
    }
    return head->next;
}

node* mergeSort(node *head){
    if(head->next==NULL) return head; // 1 membered list always sorted
    
    node* slow = head;
    node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* first_ll = head;
    node* sec_ll = slow->next;
    slow->next = NULL; // to separate the LL into 2 diff LLs
    
    first_ll = mergeSort(first_ll);
    sec_ll = mergeSort(sec_ll);
    
    // merge the two
    node* fin_head = merge(first_ll, sec_ll);
    return fin_head;
}

void printLL(node* head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    node* h1=NULL;
    node* t1=NULL;
    while(n--){
        int x; cin>>x;
        if(h1==NULL){
            h1 = new node(x);
            t1 = h1;
        }
        else{
            t1->next = new node(x);
            t1 = t1->next;
        }
    }

    h1 = mergeSort(h1);
    // cout<<h1<<endl;
    printLL(h1);

    // cout<<endl<<h1->data<<endl;
    // cout<<endl<<h1<<endl;
    return 0;
}

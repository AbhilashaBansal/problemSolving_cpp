// merge sort on Linked Lists
// O(nlogn)

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

// recursive merge
node* mergeRec(node* a, node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;

    node* c;
    if(a->data<=b->data){
        c=a;
        c->next = mergeRec(a->next, b);
    }
    else{
        c=b;
        c->next = mergeRec(a, b->next);
    }
    return c;
}

// iterative merge
node* merge (node* first, node* sec) {
    if(first==NULL) return sec;
    if(sec==NULL) return first;

    node* head=NULL, *temp=NULL;
    
    while(first!=NULL && sec!=NULL){
        if(first->data <= sec->data){
            if(head==NULL){
                head = temp = first;
            }
            else{
                temp->next = first;
                temp = temp->next; // moving temp pointer forward
            }
            first = first->next; // covered a node 
        }
        else{
            if(head==NULL){
                head = temp = sec;
            }
            else{
                temp->next = sec;
                temp = temp->next;
            }
            sec = sec->next;
        }
    }

    if(first!=NULL){
        temp->next = first;
        first=NULL;
    }
    if(sec!=NULL){
        temp->next = sec;
        sec = NULL;
    }

    return head;
}

node* mergeSort(node *head) {
    // 0 or 1 membered list always sorted
    if(head==NULL || head->next==NULL) return head; 
    
    node* slow = head;
    node* fast = head;
    // 1 divide into 2 LLs
    //can also be done in a separate fn that finds out mid pt
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* first = head;
    node* sec = slow->next;
    slow->next = NULL; // to separate the LL into 2 diff LLs
    
    // 2 recursively sort 2 LLs
    first = mergeSort(first);
    sec = mergeSort(sec);
    
    // 3 merge the two LL
    // node* result = merge(first, sec);
    node* result = mergeRec(first, sec);
    return result;
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

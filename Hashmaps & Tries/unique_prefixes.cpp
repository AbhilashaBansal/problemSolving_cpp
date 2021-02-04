// UNIQUE PREFIX ARRAY

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node {
    public:
    char data;
    unordered_map <char, node*> children;
    bool terminal;
    int vis_cnt;

    node(char d){
        data=d;
        terminal = false;
        vis_cnt = 0;
    }
};

class Trie {
    public: 
    node* root;
    int count;

    Trie(){
        root = new node('\0');
        count = 0;
    }

    void insert(string word){
        node* temp = root;
        for(int i=0; word[i]!='\0'; i++){
            char ch=word[i];
            if(temp->children.count(ch)==0){
                node* n = new node(ch);
                temp->children[ch] = n;
            }
            temp->children[ch]->vis_cnt ++;
            temp = temp->children[ch];
        }
        temp->terminal=true;
        count++;
        return;
    }

    bool search (string word){
        node* temp = root;
        for(int i=0; word[i]!='\0'; i++){
            char ch=word[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->terminal;
    }

    string unique_prefix(string word){
        string ans="";
        node* temp = root;
        for(int i=0; word[i]!='\0'; i++){
            char ch=word[i];

            if(temp->children.count(ch)==0) return "-1";

            temp = temp->children[ch];
            ans += ch;
            if(temp->vis_cnt==1) return ans;
        }
        return "-1";
    }

};

int main() {
    int n;
    cin>>n;
    string words[100];
    Trie t;

    for(int i=0; i<n; i++){
        cin>>words[i];
        t.insert(words[i]);
    }

    if(t.search("cob")) cout<<"Cob is present.\n";
    else cout<<"Cob is absent.\n";
    if(t.search("cab")) cout<<"Cab is present.\n";
    else cout<<"Cab is absent.\n";

    for(int i=0; i<n; i++){
        cout<<t.unique_prefix(words[i])<<" ";
    }

    return 0;
}

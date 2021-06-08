#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// Rotate array Anti Clock-wise by factor D
// O(N) time & O(1) space solution

void rotateArr(int a[], int d, int n){
    // M-1 go in cycles, replacing elements in one set
    int g = __gcd(d, n);
    for(int i=0; i<g; i++){
        int temp = a[i];
        
        int j=i, k;
        while(true){
            k = (j+d)%n;
            if(k==i) {
                // k has reached initial point, jahan se chale they
                // j is at last bucket that needs to be updated w/ first element of cycle, temp
                a[j] = temp;
                break;
            }
            
            a[j] = a[k];
            j=k;
        }
    }
}

void rotate2(int a[], int d, int n){
    // M-2 Use reversals
    // 1 Reverse pt 1
    for(int i=0; i<(d)/2; i++){
        swap(a[i], a[d-1-i]);
    }
    
    // 2 Reverse pt 2
    int s=d, e=n-1;
    while(s<e){
        swap(a[s++], a[e--]);
    }
    
    // 3 Reverse entire array
    for(int i=0; i<n/2; i++) swap(a[i], a[n-1-i]);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    rotateArr(a, 2, n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    rotate2(a, 3, n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

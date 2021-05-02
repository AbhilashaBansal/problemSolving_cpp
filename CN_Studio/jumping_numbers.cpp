// recursion & backtracking

// O( 9 * 2^(max_no_of_digits_in_no))

int cnt = 0;
vector <int> ans;

void rec(int cur_no, int n, int cur_dig, int max_dig) {
    if(cur_dig==max_dig){
        if(cur_no<=n) {
            ans.push_back(cur_no);
            cnt++;
        }
        return;
    }
    
    ans.push_back(cur_no);
    int last_dig = cur_no%10;
    if(last_dig>=1){
        int op1 = cur_no*10 + (last_dig-1);
        rec(op1, n, cur_dig+1, max_dig);
    }
    if(last_dig<=8){
        int op2 = cur_no*10 + (last_dig+1);
        rec(op2, n, cur_dig+1, max_dig);
    }
    return;
}

int digits(int n) {
    int len=0; 
    while(n){
        len++;
        n/=10;
    }
    return len;
}

vector<int> jumpingNumbers(int n) {
    int max_dig = digits(n);
    int first_dig = n/pow(10, max_dig-1);
    ans.clear();
    ans.push_back(0);
    for(int i=1; i<=9; i++){
        rec(i, n, 1, max_dig);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

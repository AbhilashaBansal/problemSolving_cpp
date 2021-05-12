// based on Kadane's Algorithm

#include <vector>

vector<int> maxset(int *a, int siz)
{
    // Write your code here
    int cur_sum=0, len=0;
    
    int max_sum = -1;
    int ans_len = 0, end=-1;
    int i;
    for(i=0; i<siz; i++){
        if(a[i]<0){
            if(cur_sum>max_sum){
                max_sum = cur_sum;
                ans_len = len;
                end = i-1;
            }
            else if(cur_sum==max_sum && len>ans_len){
                ans_len = len;
                end = i-1;
            }
            cur_sum=0; len=0;
        }
        else{
            len++;
            cur_sum += a[i];
        }
    }
    if(cur_sum>max_sum){
        max_sum = cur_sum;
        ans_len = len;
        end = i-1;
    }
    else if(cur_sum==max_sum && len>ans_len){
        ans_len = len;
        end = i-1;
    }
    
    vector <int> ans;
    for(int it=end-ans_len+1; it<=end; it++){
        ans.push_back(a[it]);
    }
    // cout<<ans_len<<" "<<end<<" "<<max_sum<<endl;
    return ans;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long minSort(){
    long long n,k=0,max;
    cin>>n;
    vector<long long> array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    if(is_sorted(array.begin(),array.end())) return 0;
    vector<long long> ans;
    max=array[0];
    for(int i=1;i<n;i++){
        if(array[i]>max) max=array[i];
        if(array[i]<max) ans.push_back(max-array[i]);
    }
    sort(ans.begin(),ans.end());
    long long remaining = ans.size() + 1;
    long long prev=0; 
    for (long long val : ans) {
        k += (val-prev) * remaining;
        prev+=val;
        remaining--;
    }
    return k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a=minSort();
        cout<<a<<endl;
    }
}
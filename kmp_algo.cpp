#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_sum(string s){
    int n=s.size();
    vector<int>pi(n,0);
    int j=0;
    for(int i=1;i<n;i++){
        if(s[j]==s[i]){
            j++;
            pi[i]=j;
        }
        else{
            j=0; 
        }
    }
    return pi; 
    
}
int main()
{
    string text="aabaaabaaac"; 
    string pat="aab";
    vector<int>res;
    vector<int>ans=prefix_sum(pat); 
    int i=0,j=0; 
    while(i<text.size()){
        if(pat[j]==text[i]){
            i++; 
            j++; 
        }
        else{
            if(j!=0){
                j=ans[j-1]; 
            }
            else{
                i++;
            }
        }
        if(j==pat.size()){
            int x=i-pat.size();
            res.push_back(x); 
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}

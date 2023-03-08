#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_sum(string pat){
    int n=pat.size();
    vector<int>pi(n,0);
    int j=0;
    for(int i=1;i<n;i++){
        while (j > 0 && pat[j] != pat[i]) {
                j = pi[j - 1];
            }
        if (pat[j] == pat[i]) {
            j++;
        }
        pi[i] = j;
    }
    return pi; 
    
}
int main()
{
    string text="aabaaabaaac"; 
    string pat="aabaaac";
    vector<int>res;
    vector<int>ans=prefix_sum(pat); 
    int i=0,j=0,k=0; 
    while(i<text.size()){
        if(pat[j]==text[i]){
            i++; 
            j++; 
        }
        else if(i<text.size() && pat[j]!=text[i] ){
            if(j==0){
                i++; 
            }
            else{
                j=ans[j-1];
            
            }
        }
        if(j==pat.size()){
            int x=i-pat.size();
            res.push_back(x);
            j=ans[j-1];
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}

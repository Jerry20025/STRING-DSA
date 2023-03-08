#include <bits/stdc++.h>

using namespace std;
const int CHAR=256;

bool aresame(int cp[], int ct[]){
    for(int i=0;i<26;i++){
        if(cp[i]!=ct[i]){
            return false ;
        }
    }
    return true; 
}
vector<int> ispresent(string text, string pat){
    int n=text.size(); 
    int m=pat.size();
    vector<int>ans;
    int ft[26]={0}; 
    int fp[26]={0}; 
    for(int i=0;i<m;i++){
        fp[pat[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if(i<m-1){
            ft[text[i]-'a']++; 
        }
        else if(i==m-1){
            ft[text[i]-'a']++;
            if(aresame(fp,ft)){
                ans.push_back(i-m+1);
            }
        }
        else{
            ft[text[i-m]-'a']--;
            ft[text[i]-'a']++; 
            if(aresame(fp,ft)){
                ans.push_back(i-m+1);
            }
        }
    }
    return ans;
}
int main()
{
    string text="geeksforgeeks"; 
    string pat="gskee";    //here gskee is present in geeks which is present at 0 and 8 so output is 0,8 from vector
    vector<int>ans=ispresent(text,pat);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" "; 
    }

    return 0;
}

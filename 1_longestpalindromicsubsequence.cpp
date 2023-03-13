//time complexity for this algorithm is O(n^3)

#include <bits/stdc++.h>

using namespace std;

string printstr(string s,int low , int high){
    string str="";
    for(int i=low;i<=high;i++){
        str+=s[i];
    }
    return str;
}
string longestPal(string s){
    int n=s.size();
    int maxlength=1,start=0;
    string result="";
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            int flag=1;
            for(int k=0;k<(j-i+1)/2;k++){
                if(s[i+k]!=s[j-k]){
                    flag=0;
                }
            }
            if(flag && maxlength<j-i+1){
                    start=i; 
                    maxlength=j-i+1;
                }
        }
    }
    result=printstr(s,start,start+maxlength-1); 
    return result;
    
}
int main()
{
    string s="helloworld";
    string result=longestPal(s); 
    for(int i=0;i<result.size();i++){
        cout<<result[i]; 
    }

    return 0;
}

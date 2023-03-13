// from this algorithm we can return our maxlength of palindromic substring

#include <bits/stdc++.h>

using namespace std;
string print_str(string str, int low , int high){
    string s=""; 
    for(int i=low ; i<=high;i++){
        s+=str[i];
    }
    return s; 
}

string longest(string str){
    int n=str.size(); 
    bool table[n][n]; 
    int maxlength=1; 
    int start=0; 
    memset(table,0,sizeof(table)); 
    for(int i=0;i<n;++i){
        table[i][i]=true;
    }
    //here we will check for the substring of length 2 
    for(int i=0;i<n-1;++i){
        if(str[i]==str[i+1]){
            table[i][i+1]=true; 
            start=i; 
            maxlength=2; 
        }
    }
    //here we will check for substring of length more than 2
    for(int k=3;k<=n;++k){
        for(int i=0; i<n-k+1; ++i){
            int j=i+k-1; 
            if(table[i+1][j-1] && str[i]==str[j]){
                table[i][j]=true; 
               
                if(k>maxlength){
                    start=i; 
                    maxlength=k;
                }
            }
        }
    }
    string res=""; 
    res=print_str(str,start, start+maxlength-1); 
    return res; 
}
int main()
{
    string str = "helloworld";
    string res=longest(str); 
    cout<<res;

    return 0;
}

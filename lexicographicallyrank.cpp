#include <bits/stdc++.h>

using namespace std;
//here we use the permutation concept to find the rank 

int fact(int n){
    if(n==0 || n==1){
        return 1; 
    }
    int x=n*fact(n-1); 
    return x;
}

int lexrank(string str){
    int n=str.size();
    int res=1; 
    const int CHAR=256; 
    int mul=fact(n);
    int count[CHAR]={0};
    
    for(int i=0;i<n;i++){
        count[str[i]]++;
    }
    
    for(int i=1;i<CHAR;i++){
        count[i]+=count[i-1]; 
    }
    
    for(int i=0;i<n-1;i++){
        mul=mul/(n-i); 
        
        res=res+count[str[i]-1]*mul; 
        for(int j=str[i] ; j<CHAR ; j++){
            count[j]--;
        }
    }
    return res; 
}
int main()
{
    string str="epwlz"; 
    cout<<lexrank(str);

    return 0;
}

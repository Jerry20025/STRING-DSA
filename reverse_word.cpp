#include<bits/stdc++.h>
using namespace std;
void reverse(char s[] , int start, int end){
    while(start<=end){
        swap(s[start],s[end]); 
        start++; 
        end--; 
    }
} 
void reverse_str(char s[], int n){
    int start =0;
    for(int ending=0;ending<n;ending++){
        if(s[ending]==' '){
            int x=ending-1;
            reverse(s,start,x); 
            start=ending+1; 
        }
    }
    reverse(s,start,n-1);// this function is called for reversing the last word 
    reverse(s,0,n-1); //this will reverse the whole string , if we will not use this then o/p : i evol gnidoc
}
int main(){
    char s[]="i love coding"; 
    int n=sizeof(s)/sizeof(s[0])-1; //here if i dont sub 1 then the size will be 11 but size is 10 , it is bcz of null at end
    reverse_str(s,n); 
    for(int i=0;i<n;i++){
        cout<<s[i]; 
    }
    return 0; 
}

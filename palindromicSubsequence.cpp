//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
//Input: s = "bbbab"
//Output: 4
//Explanation: One possible longest palindromic subsequence is "bbbb".
int longestPalindromeSubseq(string str) {
        int n=str.size(); 
        vector<int>dp(n+1,0); 
        vector<int>temp(n+1,0);
        string str2=str; 
        reverse(str2.begin(),str2.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(str[i-1]==str2[j-1]){
                    dp[j]=temp[j-1]+1; 
                }
                else{
                    dp[j]=max(dp[j-1],temp[j]);
                }
            }
            temp=dp;
        }
        return dp[n];
    }

/*
Given a positive integer n, 
find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
given n = 13, return 2 because 13 = 4 + 9.
*/
//348ms
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++){dp[i]=INT_MAX;}
        for(int i=1;i*i<=n;i++){
            dp[i*i] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;i+j*j<=n;j++){
                dp[i+j*j] = min(dp[i]+1,dp[i+j*j]);
            }
        }
        return dp[n];
    }
};

//12ms
//数论，四平和定理
class Solution {
public:
    int numSquares(int n) {
         while(n%4==0){n/=4;}
         if(n%8==7){return 4;}
         bool min2 = false;
         for(int i=2;i<=n;++i){
             if(i>n/i) i=n;
             int e=0;
             while(n%i == 0){
                 n/=i;
                 ++e;
             }
             if(e%2 && i%4==3) return 3;
             min2 |= e%2;
         }
         return 1+min2;
    }
};
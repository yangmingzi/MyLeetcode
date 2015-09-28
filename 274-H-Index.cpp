/*
Given an array of citations (each citation is a non-negative integer) of a researcher, 
write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: 
"A scientist has index h if h of his/her N papers have at least h citations each, 
and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], 
which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. 
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/
class Solution {
public:
    void quicksort(vector<int>& s,int l,int r){
        int i,j,x;
        if(l<r){
            i=l;
            j=r;
            x=s[i];
            while(i<j){
                while(i<j && s[j]>x) j--;
                if(i<j) s[i++] = s[j];
                while(i<j&&s[i]<x) i++;
                if(i<j) s[j--] = s[i];
            }
            s[i]=x;
            quicksort(s,l,i-1);
            quicksort(s,i+1,r);
        }
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        quicksort(citations,0,n-1);
        int count = 0;
        if(n == 0) return 0;
        for(int i=n-1;i>=0;i--){
            if(n==1){
                if(citations[0]>0) return 1;
                else return 0;
            }
            else if(count>=citations[i]){
                return count;
            }
            count++;
            if(count == n){
                return count;
            }
        }
    }
};
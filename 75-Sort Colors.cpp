class Solution {
public:
    void sortColors(int A[], int n) {
        int num1=0,num2=0,num3=0;
        for(int i=0;i<n;++i)
        {
            if (A[i]==0) num1++;
            if (A[i]==1) num2++;
            if (A[i]==2) num3++;
        }
      //需要注意此处的逻辑
      int k=0;
      while(num1--) A[k++]=0;
      while(num2--) A[k++]=1;
      while(num3--) A[k++]=2;
    }
};
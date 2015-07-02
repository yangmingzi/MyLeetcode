class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> a(rowIndex + 1);
        
        a[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
            //为了保证已经改过的元素，后面不会用到该元素的原值，采用逆序
            //例如a[3]=a'[2]+a'[3],a[4]=a'[3]+a'[4],
            //如果按照算：a[4]=a[3]+a'[4],not a'[3]+a'[4]
            for(int j = i; j >= 0; j--)
                if (j == i)
                    a[j] = a[j-1];
                else if (j == 0)
                    a[j] = a[j];
                else
                    a[j] = a[j-1] + a[j];
                    
        return a;                    
    }
};
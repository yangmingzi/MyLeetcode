//帕斯卡尔三角形
//a[i][j]=a[i-1][j-1]+a[i-1][j]
class Solution {
private:
    vector<vector<int> > ret;
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        
        for(int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                vector<int> a;
                a.push_back(1);
                ret.push_back(a);
            }
            else
            {
                vector<int> a;
                for(int j = 0; j <= i; j++)
                    if (j == 0)
                        a.push_back(ret[i-1][j]);
                    else if (j == i)
                        a.push_back(ret[i-1][j-1]);
                    else
                        a.push_back(ret[i-1][j-1] + ret[i-1][j]);
                ret.push_back(a); 
            }
        }
        
        return ret;
    }
};
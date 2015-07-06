/*
依次把每个节点作为根节点，左边节点作为左子树，右边节点作为右子树，那么总的数目等于左子树数目*右子树数目，
实际只要求出前半部分节点作为根节点的树的数目，然后乘以2（奇数个节点还要加上中间节点作为根的二叉树数目）
还有非递归实现，参考博客：http://www.cnblogs.com/TenosDoIt/p/3448569.html

在C语言中，数组名除作为变量的标识符之外，数组名还代表了该数组在内存中的起始地址，
因此，当数组名作函数参数时，实参与形参之间不是"值传递"，而是"地址传递"，
实参数组名将该数组的起始地址传递给形参数组，两个数组共享一段内存单元，编译系统不再为形参数组分配存储单元。
*/
class Solution {
public:
    int numTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int nums[n+1]; //nums[i]表示i个节点的二叉查找树的数目
        memset(nums, 0, sizeof(nums));
        return numTreesRecur(n, nums);
    }
    int numTreesRecur(int n, int nums[])
    {
        if(nums[n] != 0)return nums[n];
        if(n == 0){nums[0] = 1; return 1;}
        int tmp = (n>>1);
        for(int i = 1; i <= tmp; i++)
        {
            int left,right;
            if(nums[i-1])left = nums[i-1];
            else left = numTreesRecur(i-1, nums);
            if(nums[n-i])right = nums[n-i];
            else right = numTreesRecur(n-i, nums);
            nums[n] += left*right;
        }
        nums[n] <<= 1;
        if(n % 2 != 0)
        {
            int val;
            if(nums[tmp])val = nums[tmp];
            else val = numTreesRecur(tmp, nums);
            nums[n] += val*val;
        }
        return nums[n];
    }
};
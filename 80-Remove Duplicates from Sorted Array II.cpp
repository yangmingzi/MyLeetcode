/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/
//16ms
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //只要当前元素和前一个的前一个不同就保留
        int n=nums.size();
        if(n == 0) {return 0;}
        if(n <= 2)return n;
        int index = 2;
        int lastChange, lastChangeIndex = -1; //上一次被覆盖的位置和被覆盖的值
        for(int i = 2; i < n; i++)
        {
            int prepre = nums[i-2];
            if(i-2 == lastChangeIndex)prepre = lastChange;//原来的A[i-2]有可能被覆盖了
            if(nums[i] != prepre)
            {
                lastChangeIndex = index;
                lastChange = nums[index];
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

//24ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int st = 0;
        bool isRepeated = false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[st]){
                isRepeated = false;
                st++;
                nums[st] = nums[i];
            }else{
                if(isRepeated == false){
                    st++;
                    nums[st] = nums[i];
                    isRepeated = true;
                }
            }
        }
        return st+1;
    }
};

//20ms
class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        int n= A.size();
        int start = 0;
        for(int i = 0;i < n;i++) {
            if(i == 0 || i == 1) {
                A[start++] = A[i];
            }
            else {
                //using start
                if(A[i] == A[start-2]) {
                     
                }
                else {
                    A[start++] = A[i];
                }
            }
        }
        return start;
    }
};
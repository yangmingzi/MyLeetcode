/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = digits.size();
        vector<int> res(digits);
        int carrybit = 1, i;
        for(i = len-1; i >= 0; i--)
        {
            if(carrybit == 0)break;
            else
            {
                res[i] += carrybit;
                if(res[i] >= 10)
                {
                    carrybit = 1;
                    res[i] -= 10;
                }
                else carrybit = 0;
            }
        }
        if(i < 0 && carrybit == 1)
            res.insert(res.begin(), carrybit);
        return res;
    }
};
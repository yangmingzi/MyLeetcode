/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/
//4ms,第一梯队的速度
class Solution {
public:
    const char* digits[20] = {"Zero"," One"," Two"," Three"," Four"," Five"," Six"," Seven"," Eight"," Nine",
                    " Ten"," Eleven"," Twelve"," Thirteen"," Fourteen"," Fifteen"," Sixteen"," Seventeen"," Eighteen"," Nineteen"};
    const char* tens[10] = {"",""," Twenty"," Thirty"," Forty"," Fifty"," Sixty"," Seventy"," Eighty"," Ninety"};
    const char* many[5] = {""," Thousand"," Million"," Billion"," Trillion"};

    string lessThousandToWords(int num) {
        string ans;
        if (num / 100)
            ans = ans + digits[num/100] + " Hundred";
        num %= 100;
        if (num < 20 && num > 0)
            ans += digits[num];
        else {
            ans +=  tens[num/10];
            num %= 10;
            if (num > 0)
                ans += digits[num];
        }
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0)
            return digits[0];
        string ans, sub;
        int level = 0;
        while (num) {
            sub = lessThousandToWords(num%1000);
            if (sub != "")
                ans = sub + many[level] + ans;
            ++level;
            num /= 1000;
        }
        return ans.substr(1,ans.size()-1);
    }
};
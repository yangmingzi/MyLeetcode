/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/
class Solution {
    public:
        string removeDuplicateLetters(string s) {
            int sLen = s.size(), i, lastIdx[26]={0},resLen=0, included[26]={0};
            string res;
            for(i=sLen-1; i>=0 && resLen<26;--i) //generate lastIdx array
                   if(!lastIdx[s[i]-'a']) {
                    lastIdx[s[i]-'a'] = i; 
                    ++resLen;
                  }  
            for(i=0; i<sLen;++i) 
            { //scan s from left to right
                if(!included[s[i]-'a'])
                { // if s[i] is not included in s[i]
                    while(!res.empty() && s[i]<res.back() && lastIdx[res.back()-'a']>i)
                    { // pop res as much as possible to reduce res
                        included[res.back()-'a'] = 0;
                        res.pop_back();
                    }
                    included[s[i]-'a'] = 1; // add s[i] to res
                    res.push_back(s[i]);
                }
            }
            return res;
        }
};
//
public class Solution {
   public String removeDuplicateLetters(String s) {
        /**
         * First loop: use an array cnt[] to count the number of times
         * appeared for each letter in s.
         * 
         * Second loop (Greedy): use a stack, pop() while (!stack.isEmpty()
         * && (sc = stack.peek()) >= c && cnt[sc] > 0)
         */

        int i, n = s.length();
        int[] cnt = new int[128];
        boolean[] inRes = new boolean[128]; // whether a char is in res[]
        char[] res = s.toCharArray(); // simulate a stack

        for (i = 0; i < n; i++)
            cnt[res[i]]++;

        char c, sc;
        int end = -1;
        // now cnt[c] means the remaining count of the char c
        for (i = 0; i < n; i++) {
            c = res[i];
            if (inRes[c]) {
                cnt[c]--;
                continue;
            }

            while (end >= 0 && (sc = res[end]) >= c && cnt[sc] > 0) {
                end--;
                inRes[sc] = false;
            }

            res[++end] = c;
            cnt[c]--;
            inRes[c] = true;
        }
        return String.valueOf(res).substring(0, end + 1);
    }
}

/*
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
//参考博客：http://www.cnblogs.com/yuzhangcmu/p/4114656.html
/*
这道题让我们求串联所有单词的子串，
就是说给定一个长字符串，再给定几个长度相同的单词，
让我们找出串联给定所有单词的子串的起始位置，还是蛮有难度的一道题。
这道题我们需要用到两个哈希表，
第一个哈希表先把所有的单词存进去，然后从开头开始一个个遍历，停止条件为当剩余字符个数小于单词集里所有字符的长度。
这时候我们需要定义第二个哈希表，
然后每次找出给定单词长度的子串，看其是否在第一个哈希表里，
如果没有，则break，如果有，则加入第二个哈希表，
但相同的词只能出现一次，如果多了，也break。
如果正好匹配完给定单词集里所有的单词，则把i存入结果中，具体参见代码如下：
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1;
        for (auto &a : words) ++m1[a];
        for (int i = 0; i <= (int)s.size() - n * m; ++i) {
            unordered_map<string, int> m2;
            int j = 0; 
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * m, m);
                if (m1.find(t) == m1.end()) break;
                ++m2[t];
                if (m2[t] > m1[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
//九章算法提供的答案，很快，52ms
// This solution cost only O(n * m) time where n is length of the master string s. m is the length of each word.
// This solution's algorithm is using sliding window to optimize the traverse of the string.
// directly for every start index and then determine whether this start index is a legal result will cost O(n * m * k) time 
//where k is the numbers of words.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0) {
            return result;
        }
        
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            if (hash.find(words[i]) == hash.end()) {
                hash[words[i]] = 1;
            } else {
                hash[words[i]]++;
            }
        }
        
        int wSize = words[0].length();
        for (int start = 0; start < wSize; start++) {
            int wCount = 0;
            unordered_map<string, int> slidingWindow;
            for (int i = start; i + wSize <= s.length(); i+=wSize) {
                string word = s.substr(i, wSize);
                if (hash.find(word) == hash.end()) {
                    slidingWindow.clear();
                    wCount = 0;
                } else {
                    if (wCount == words.size()) {
                        string removedWord = s.substr(i - wCount * wSize, wSize);
                        slidingWindow[removedWord]--;
                        wCount--;
                    }
                    wCount++;
                    if (slidingWindow.find(word) == slidingWindow.end()) {
                        slidingWindow[word] = 1;
                    } else {
                        slidingWindow[word]++;
                    }
                    while (hash[word] < slidingWindow[word]) {
                        string removedWord = s.substr(i - (wCount-1) * wSize, wSize);
                        slidingWindow[removedWord]--;
                        wCount--;
                    }
                }
                
                if (wCount == words.size()) {
                    result.push_back(i - (wCount - 1) * wSize);
                }
            }
        }
        
        return result;
    }
};
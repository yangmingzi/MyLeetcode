/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly Lcharacters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example, 
words: ["This", "is", "an", "example", "of", "text", "justification."] 
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
Corner Cases:
A line other than the last line might contain only one word. What should you do in this case? 
In this case, that line should be left-justified.
*/
/*
分析：这一题需要注意两个点，
a、当该行只放一个单词时，空格全部在右边 
b、最后一行中单词间只有一个空格，其余空格全部在右边。
然后只要贪心选择，在一行中尽量放多的单词。        
*/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string>res;
        int len = words.size(), i = 0;
        while(i < len)
        {
            //if(words[i].size() == 0){i++; continue;}
            int rowlen = 0, j = i;
            while(j < len && rowlen + words[j].size() <= L)
                rowlen += (words[j++].size() + 1);
            //j-i是该行放入单词的数目
            if(j - i == 1)
            {//处理放入一个单词的特殊情况
                res.push_back(words[i]);
                addSpace(res.back(), L - words[i].size());
                i = j; continue;
            }
            //charaLen是当前行字母总长度
            int charaLen = rowlen - (j - i);
            //平均每个单词后的空格,j < len 表示不是最后一行
            int meanSpace = j < len ? (L - charaLen) / (j - i - 1) : 1;
            //多余的空格
            int leftSpace = j < len ? (L - charaLen) % (j - i - 1) : L - charaLen - (j - i -1);
            string tmp;
            for(int k = i; k < j - 1; k++)
            {
                tmp += words[k];
                addSpace(tmp, meanSpace);
                if(j < len && leftSpace > 0)
                {
                    tmp.push_back(' ');
                    leftSpace--;
                }
            }
            tmp += words[j - 1];//放入最后一个单词
            if(leftSpace > 0)addSpace(tmp, leftSpace); //对最后一行
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
     
    void addSpace(string &s, int count)
    {
        for(int i = 1; i <= count; i++)
            s.push_back(' ');
    }
};
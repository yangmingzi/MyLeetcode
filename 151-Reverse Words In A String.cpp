/*
1 从后往前遍历string
2 保存单词，然后需要逆转，在保存到结果中
注意题目中的clarification，处理好其中的空格。
利用了两个额外string保存中间结果。空间复杂度为O(n).
时间复杂度是O(n)，
*/
//另一种实现：http://www.cnblogs.com/easonliu/p/3630617.html
class Solution {
public:
    void reverseWords(string &s)
	{
		string rs;
		for (int i = s.length()-1; i >= 0; )//主义这种写法，将i的变化写在内部
		{
			while (i >= 0 && s[i] == ' ') i--;
			if (i < 0) break;
			if (!rs.empty()) rs.push_back(' ');
			string t;
			while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);
			reverse(t.begin(), t.end());
			rs.append(t);
		}
		s = rs;
	}
};

//空间复杂度为O(1)
class Solution {
public:
    void reverse(string &s, int low, int high) {
        char tmp;
        while(low < high) {
            tmp = s[low];
            s[low] = s[high];
            s[high] = tmp;
            low++;
            high--;
        }
    }
    
    void removeBlank(string &s) {
        if (s.length() == 0) {
            return;
        }
        int count = 0;
        bool flag = false;
        for (int i = 0; i <= s.length(); ++i) {
            if (s[i] == ' ' && !flag) {
                count++;
            } else if (s[i] == ' ' && flag) {
                flag = false;
                s[i-count] = s[i];
            } else if (s[i] != ' ') {
                flag = true;
                s[i-count] = s[i];
            }
        }
        int len = s.length() - count;
        if (s[len-1] == ' ') {
            s[len-1] = '\0';
            len--;
        }
        s.resize(len);
    }

    void reverseWords(string &s) {
        removeBlank(s);
        reverse(s,0,s.length()-1);
        int a = 0, b;
        for (int i=0; i<=s.length();++i){
            if(s[i]==' '||s[i]=='\0'){
                b = i-1;
                reverse(s,a,b);
                a = i+1;
            }
        }
        return;
    }
};

//不能AC的O(1)
#include <iostream>
#include <string>
using namespace std;

class ReverseStr
{
public:
	void reverseWords(string &s)
	{
		int begin = 0;
		int end = 0;

		while (end < (int)s.size())
		{
			if (s[end] == ' ')
			{
				swapString(s, begin, end - 1);
				begin = end + 1;
				end = begin;           //将begin和end调到下个单词位置
			}
			else
			{
				end++;
			}
		}

		swapString(s, begin, end - 1); //最后一个单词的逆置

		swapString(s, 0, s.size() - 1);//再从头到尾逆置
	}

	void swapString(string &s, int begin, int end)
	{
		while (end > begin)
		{
			char c = s[begin];
			s[begin] = s[end];
			s[end] = c;
			begin++;
			end--;
		}
	}
};

int main()
{
	string str = "All the things in their being are good for sonething!";
	cout << "原单词顺序："<< str << endl;

	ReverseStr rstr;
	rstr.reverseWords(str);
	cout << "单词逆置后：" << str << endl;
	return 0;
}
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


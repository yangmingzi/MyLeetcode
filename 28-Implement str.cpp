//KMP算法
//后缀最长前缀匹配
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        int* next = new int[nlen];		
        getNext(needle, next);
		//next[i]的含义：
		//在needle[i]处，后缀与前缀的的最大匹配长度为next[i]
		//如果在匹配haystack[i]与needle[j]的时候失败
		//下一次匹配，应是由比较haystack[i+1]与needle[next[j+1]]开始
        int i = 0;
        int j = 0;
        while(i < hlen && j < nlen)
        {
            if(j == -1 || haystack[i] == needle[j])
            {// match current position, go next
                i ++;
                j ++;
            }
            else
            {// jump to the previous position to try matching
			////从模式串的第几位开始尝试匹配。
                j = next[j];
            }
        }
        if(j == nlen)
        // all match
            return i-nlen;
        else
            return -1;
    }
    void getNext(char *needle, int next[])
    {// self match to contruct next array
        int nlen = strlen(needle);
        int j = -1;     // slow pointer
        int i = 0;      // fast pointer
        next[i] = -1;    //init next has one element
        while(i < nlen-1)
        {
            if(j == -1 || needle[i] == needle[j])
            {
                j ++;
                i ++;           //thus the condition (i < nlen-1)
                next[i] = j;    //if position i not match, jump to position j
            }
            else
            {
				//j=-1也行
                j = next[j];    //jump to the previous position to try matching
            }
        }
    }
};
//简介的代码
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        for (i = j = 0; i < haystack.size() && j < needle.size();) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
            } else {
                i -= j - 1; j = 0;
            }
        }
        return j != needle.size() ? -1 : i - j;
    }
};
//参数不同，由指针变成字符串，KMP
class Solution {
public:
    void getNext(vector<int> &next,string &needle){
        int i=0,j=-1;
        next[i] = j;
        while(i<needle.size()-1){
            while(j != -1 && needle[i]!=needle[j]){
                j = next[j];
            }
            i++;
            j++;
            if(needle[i] == needle[j]) next[i]=next[j];
            else next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (haystack.empty()) return needle.empty() ? 0 : -1;
        if (needle.empty())   return 0;
        vector<int> next(needle.size()+1);
        getNext(next,needle);
        int i=0,j=0;
        while(i != haystack.size()){
            while(j!=-1 && haystack[i] != needle[j]){j=next[j];}
            i++;
            j++;
            if(j == needle.size()) return i-j;
        }
        return -1;
    }
};
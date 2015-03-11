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
        int j = -1;     /=/ slow pointer
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
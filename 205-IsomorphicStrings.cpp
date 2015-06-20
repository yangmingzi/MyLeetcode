//将同构关系转为映射去思考，双向映射（如果单向映射不能满足，例如aa和ab）
//考虑到映射，就选择了Map数据结构
//不可以多个字符映射到同一个字符中去，比如aa和ab。因此要有两个hash表来记录
//由于是字符，不会超过256个，因此可以用数组来记录这种映射。
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        if(len1!=len2){
            return false;
        }
        char charMap1[256];
        char charMap2[256];
        memset(charMap1, 0, sizeof(char)*256);
        memset(charMap2, 0, sizeof(char)*256);
        for(int i=0; i<len1; i++){
            if(charMap1[s[i]]==0){
                charMap1[s[i]] = t[i];
            }else if(charMap1[s[i]]!=t[i]){
                return false;
            }
            if(charMap2[t[i]]==0){
                charMap2[t[i]] = s[i];
            }else if(charMap2[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};
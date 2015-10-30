/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
/*
所谓的anagrams，就是某个单词打乱其字母顺序形成的新单词，新单词和原单词包含的字母种类相同，每个字母的数目相同。           

用哈希map存储排序后的字符串，map中key为排序后字符串，value为该字符串对应的第一个原字符串在数组中的位置。
如果value = -1，表示该字符串对应的第一个源字符串已经输出过
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        typedef unordered_map<string, int> Umap;
        Umap hashtable;
        vector<string> res;
        for(int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            Umap::iterator ite = hashtable.find(s);
            if(ite == hashtable.end())
                hashtable.insert(Umap::value_type(s, i));
            else
            {
                if(ite->second != -1)
                {
                    res.push_back(strs[ite->second]);
                    ite->second = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};

//二刷
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> m;
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs.size();i++){
           m[getOr(strs[i])].push_back(strs[i]);
        }
        for(map<string,vector<string>>::iterator it = m.begin();it!=m.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
    string getOr(string s){
        sort(s.begin(),s.end());
        return s;
    }
};
  
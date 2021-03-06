/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
//Trie树特点
//性质：它有3个基本性质：
//(1)根节点不包含字符，除根节点外每一个节点都只包含一个字符；
//(2)从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串；
//(3)每个节点的所有子节点包含的字符都不相同。
//字典树
//每一层都可能有26^(n-1)个节点
//每个节点的iskey表示从根节点追溯到该节点所代表额度词汇是否存在
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *ch[26];
    bool isKey;
    TrieNode() : isKey(false) {
        for (auto &a : ch) a = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (p->ch[i] == NULL) p->ch[i] = new TrieNode();
            p = p->ch[i];
        }
        p->isKey = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (p->ch[i] == NULL) return false;
            p = p->ch[i];
        }
        return p->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto &a : prefix) {
            int i = a - 'a';
            if (p->ch[i] == NULL) return false;
            p = p->ch[i];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

//二刷
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for(int i=0;i<26;i++){
            next[i] = NULL;
        } 
        isString = false;
    }
    TrieNode* next[26];
    bool isString;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.size();i++){
            if(p->next[word[i]-'a']==NULL){p->next[word[i]-'a'] = new TrieNode();}
            p = p->next[word[i]-'a'];
        }
        p->isString = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.size();i++){
            if(p->next[word[i]-'a'] == NULL){return false;}
            p = p->next[word[i]-'a'];
        }
        if(p==NULL || p->isString == false) return false;//p==NULL 一定要放在前面
        else return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i=0;i<=prefix.size();i++){
            if(p == NULL){return false;}
            p = p->next[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
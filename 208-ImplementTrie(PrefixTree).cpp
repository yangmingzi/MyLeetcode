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
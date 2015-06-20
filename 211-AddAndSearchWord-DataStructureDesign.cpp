//字典树变形

class WordDictionary {
public:
	struct TrieNode
	{
		TrieNode* childs[26];
		bool isWord;
		TrieNode(){
			for(auto &a:childs){
				a=NULL;
			}
			isWord=false;
		}	
	};
	
	struct Trie
	{
		TrieNode *root;
		Trie(){root = new TrieNode();}
	};
	Trie T;
    // Adds a word into the data structure.
    void addWord(string word) {
    	TrieNode *p = T.root;
		for(auto &a : word){
			int i = a-'a';
			if(!p->childs[i]){ p->childs[i]=new TrieNode();}
			p=p->childs[i];
		}
		p->isWord=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelp(T.root,word,0);
    }
    //要求此函数可以从字符串的任意位置检索剩下的部分，所以有参数i
    bool searchHelp(TrieNode* node,string& word,int i){
    	if(node==NULL){return false;}
    	int len=word.length();
    	if(i>=len){return node->isWord;}
    	if(word[i]!='.'){
    		return searchHelp(node->childs[word[i]-'a'],word,i+1);
    	}else{//遇到‘.’，对.以后的字符暴力搜索
    		for(int k=0;k<26;k++){
    			if(searchHelp(node->childs[k],word,i+1)){
    				return true;
    			}
    		}
    		return false;
    	}
    }

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
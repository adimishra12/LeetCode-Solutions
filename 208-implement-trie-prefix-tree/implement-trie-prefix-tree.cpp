class TrieNode
{
public:
    bool Word;
    TrieNode *child[26];
    TrieNode()
    {
        Word = false;
        for(int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};
class Trie {
public:
    TrieNode* node;
    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode* curr = node;
        for(int i = 0; i < n; i++)
        {
            if(curr -> child[word[i] - 'a'] == nullptr)
                curr -> child[word[i] - 'a'] = new TrieNode();

            curr = curr -> child[word[i] - 'a'];    
        }
        curr -> Word = true; 
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* curr = node;

        for(int i = 0; i < n; i++)
        {
            curr = curr -> child[word[i] - 'a'];
            if(curr == nullptr)
                return false;
             
        }
        return curr -> Word;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* curr = node;

        for(int i = 0; i < n; i++)
        {
            curr = curr -> child[prefix[i] - 'a'];
            if(curr == nullptr)
                return false;   
        }   
        return true;     
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
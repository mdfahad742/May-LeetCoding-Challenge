// Standard Trie Question

struct trie {
    bool end;
    map<char, trie*> mp;
};

void insert1(string s, trie *head) {
    trie *curr = head;
    for (auto ch : s) {
        if (curr->mp.find(ch) == curr->mp.end()) {
            curr->mp[ch] = new trie();
            curr->mp[ch]->end=0;
        }
        curr = curr->mp[ch];
        if (!curr->end)
            curr->end = 0;
    }
    curr->end = 1;
}

bool query(string s, trie *head,int type) {
    trie *curr = head;
    for (auto ch : s) {
        if (curr->mp.find(ch) == curr->mp.end()) {
            
            return 0;
        }
        curr = curr->mp[ch];
    }
    if(type == 1){
        if(curr->end)
            return 1;
        return 0;
    }
    return 1;
    
}
class Trie {
public:
    /** Initialize your data structure here. */
    trie *head;
    Trie() {
        head = new trie();
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        insert1(s, head);
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return query(word,head,1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return query(prefix,head,2);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

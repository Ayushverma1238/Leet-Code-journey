struct Node {
    Node * links[26];
    bool flag = false;
    bool containeKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put (char ch, Node * node){
        links[ch-'a'] = node;
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node * root;
    
public:
    Trie() {
        root = new Node();    
    }
    
    void insert(string word) {
        Node * node = root;
        for(auto c : word){
            if(!node->containeKey(c)){
                node->put(c, new Node());
            }
            node= node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        for(auto c : word){
            if(!node->containeKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return (node->isEnd());
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(auto c : prefix){
            if(!node->containeKey(c)){
                return false;
            }
            node = node->get(c);
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
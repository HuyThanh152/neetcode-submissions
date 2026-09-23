class PrefixTree {
private :
    struct Node{
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };
public:
  
Node *root;
    PrefixTree() {
     root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char c : word){
            int i = c - 'a';
            if (!curr->children[i]){
                curr->children[i] = new Node();
            }
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char c : word){
            int i = c - 'a';
            if(!curr->children[i]) return false;
            curr = curr->children[i];
        }
        if(curr->isEnd ) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
         Node* curr = root;
        for(char c : prefix){
            int i = c - 'a';
            if(!curr->children[i]) return false;
            curr = curr->children[i];
        }
        return true;

    }
};

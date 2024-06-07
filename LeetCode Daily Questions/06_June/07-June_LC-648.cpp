// https://leetcode.com/problems/replace-words/description/

class Trie{
public:
    Trie* children[26];
    bool isEnd;

    Trie(){
        for (int i = 0; i<26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Solution {
public:
    Trie* root;

    Solution(){
        root = new Trie();
    }   

    void insert(string word){
        Trie* node = root;
        for (char ch : word){
            int i = ch - 'a';
            if (node->children[i] == NULL){
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    string search(string word){
        Trie* node = root;
        string result;
        for (char ch : word){
            int i = ch- 'a';
            if (node->children[i]==NULL){
                return word;
            }
            result += ch;
            if (node->children[i]->isEnd){
                return result;
            }
            node = node->children[i];
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary){
            insert(word);
        }
        stringstream ss(sentence);
        string word, result;
        while(ss >> word){
            if (!result.empty()){
                result += " "; 
            }
            result += search(word);
        }
        return result;
    }
};
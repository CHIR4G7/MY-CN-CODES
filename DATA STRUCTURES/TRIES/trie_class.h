// #include "trienode_class.h"
#include<iostream>
#include <string>
using namespace std;

// class Trie
// {
// private:
//     TrieNode *root;

// public:
//     int count;

// public:
//     Trie()
//     {
//         this->count = 0;
//         root = new TrieNode('\0');
//     }

//     // INSERT WORD

//     /*
//         void insertWord(TrieNode *root, string word)
//         {

//             // BASE CASE
//             if (word.length() == 0)
//             {
//                 root->isTerminal = true;
//                 return;
//             }

//             // SMALL CALCULATIONS
//             int index = word[0] - 'a';
//             TrieNode *child;
//             if (root->children[index] != NULL)
//             {
//                 child = root->children[index];
//             }
//             else
//             {
//                 child = new TrieNode(word[0]);
//                 root->children[index] = child;
//             }

//             // RECURSIVE CALL
//             insertWord(child, word.substr(1));
//         }

//         void insertWord(string word)
//         {
//             insertWord(root, word);
//         }

//         */

//     // SEARCH IN A TRIE

//     /*
//     bool searchWord(TrieNode *root, string word)
//     {
//         // BASE CASE
//         if (word.length() == 0)
//         {
//             return root->isTerminal;
//         }

//         // SMALL CALCULATIONS
//         int index = word[0] - 'a';
//         if (root->children[index] != NULL)
//         {
//             TrieNode *child = root->children[index];
//             return searchWord(child, word.substr(1));
//         }
//         else
//         {
//             return false;
//         }
//     }

//     bool searchWord(string word)
//     {
//         if (word.length() == 0)
//         {
//             return false;
//         }
//         return searchWord(root, word.substr(1));
//     }
//     */

//     // REMOVE WORD

//     /*
//     void removeWord(TrieNode *root, string word)
//     {
//         // BASE CASE
//         if (word.length() == 0)
//         {
//             root->isTerminal = false;
//             return;
//         }
//         // SMALL CALCULATION
//         int index = word[0] - 'a';
//         TrieNode *child;
//         if (root->children[index] != NULL)
//         {
//             child = root->children[index];
//         }
//         else
//         {
//             // word not found.
//             return;
//         }

//         // RECURSIVE CALLS
//         removeWord(child, word.substr(1));

//         // REMOVE CHILD NODE IF ITS USELESS

//         // CONDITION-1
//         if (child->isTerminal == false)
//         {
//             // CONDITION-2
//             for (int i = 0; i < 26; i++)
//             {
//                 if (child->children[i] != NULL)
//                 {
//                     return;
//                 }
//             }
//             delete child;                 // deallocated
//             root->children[index] = NULL; // removed.
//         }
//     }

//     void removeWord(string word)
//     {
//         removeWord(root, word);
//     }
//     // if we want ot also deallocate the the element, then only its parent element can do that.
// */

//     // PATTERN MATCHING

//     /*
//         bool patternMatching(TrieNode *root, string pattern)
//         {
//             if(pattern.length()==0)
//             {
//                 return true;
//             }
//             int index = pattern[0] - 'a';
//             if(root->children[index]!=NULL)
//             {
//                 TrieNode *child;
//                 child = root->children[index];
//                 return patternMatching(child,pattern.substr(1));

//             }
//             else
//             {
//                 return false;
//             }

//         }
//         */

//     // bool patternMatching(vector<string> vect, string pattern)
//     // {
//     //     /*AGAR MAI NORMALLY INSERT KARDUNGA TO PROBLEM HOGI JAISE...
//     //     abc def ghi me agar mujhe (hi) search krna hai to nhi krpaunga kyunki h root se connected nhi to vo aage nhi jayega..
//     //     to solve this hame har sbstr ko daalna pdega in the trie.

//     //     for (int i = 0; i < vect.size(); i++)
//     //     {
//     //         insertWord(vect[i]);
//     //     }

//     //     */

//     //    for(int i=0;i<vect.size();i++)
//     //    {
//     //        string word = vect[i];
//     //        for(int j=0;j<word.length();j++)
//     //        {
//     //            insertWord(word.substr(j));//har ek poosible substr jitne bhi elemnets hai vect me un sbko trie me individually as a word daaldia.
//     //        }
//     //        return patternMatching(root,pattern);//search function for this question.
//     //    }
//     // }

//     // AUTO COMPLETE

//     bool insertWord(TrieNode *root, string word)
//     {
//         if (word.size() == 0)
//         {
//             if (root->isTerminal == false)
//             {
//                 root->isTerminal = true;
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         int index = word[0] - 'a';
//         TrieNode *child;
//         if (root->children[index] != NULL)
//         {
//             child = root->children[index];
//         }
//         else
//         {
//             child = new TrieNode(word[0]);
//             root->children[index] = child;
//         }

//         return insertWord(child, word.substr(1));
//     }

//     bool insertWord(string word)
//     {
//         if (insertWord(root, word))
//         {
//             this->count++;
//         }
//     }

//     void print
// };
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */



class Node
{
    public :
    bool flag = false;
    Node *links[26];
    
    bool containsKey(char ch)
    {
        if(links[ch - 'a']!=NULL)
        {
            return true;
        }
        return false;
    }
    void put(char ch,Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
    
    private :
    Node *root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Node *node = root;//dummy node pointing intiLLY TO ROOT
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])==false)
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);//moves to the reference trie
        }
        node->setEnd();//word exists
    }

    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Node *node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])==false)
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Node *node = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(node->containsKey(prefix[i])==false)
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

};
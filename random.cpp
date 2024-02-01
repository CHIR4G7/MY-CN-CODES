#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* t[ALPHABET_SIZE];
    int isEnd;
};

TrieNode* getNode() {
    TrieNode* temp = new TrieNode; // Initialize new node with null
    for (int i = 0; i < ALPHABET_SIZE; i++)
        temp->t[i] = NULL;
    temp->isEnd = 0;
    return temp;
}

void insert(TrieNode* root, string key) {
    TrieNode* trail;
    trail = root;
    for (int i = 0; i < key.length(); i++) {
        if (trail->t[key[i] - 'a'] == NULL) {
            TrieNode* temp;
            temp = getNode();
            trail->t[key[i] - 'a'] = temp;
        }
        trail = trail->t[key[i] - 'a'];
    }
    (trail->isEnd)++;
}

bool search_mod(TrieNode* root, string word) {
    TrieNode* trail;
    trail = root;
    for (int i = 0; i < word.length(); i++) {
        if (trail->t[word[i] - 'a'] == NULL)
            return false;
        trail = trail->t[word[i] - 'a'];
    }
    if ((trail->isEnd) > 0 && trail != NULL) {
        (trail->isEnd)--;
        return true;
    } else
        return false;
}

void checkPossibility(string sentence[], int m, TrieNode* root) {
    int flag = 1;
    // Iterate for all words in the string
    for (int i = 0; i < m; i++) {
        if (search_mod(root, sentence[i]) == false) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void insertToTrie(string dictionary[], int n, TrieNode* root) {
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
}


int main() {
    TrieNode* root;
    root = getNode();

    string dictionary[] = { "find", "a", "geeks",
                            "all", "for", "on",
                            "geeks", "answers", "inter" };
    int N = sizeof(dictionary) / sizeof(dictionary[0]);

    insertToTrie(dictionary, N, root);

    string sentence[] = { "find", "all", "answers", "on",
                            "geeks", "for", "geeks" };
    int M = sizeof(sentence) / sizeof(sentence[0]);

    checkPossibility(sentence, M, root);

    return 0;
}

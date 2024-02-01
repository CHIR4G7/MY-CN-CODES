 #include <iostream>
 #include <string>
 class TrieNode
 {
     public :

     char data;
     TrieNode **children;
     bool isTerminal;

     TrieNode(char data)
     {
         this->data = data;
         children = new TrieNode*[26];
         //initializing every memeber with NULL, else it would be garbage.
         for(int i=0;i<26;i++)
         {
             children[i] = NULL;
         }
         isTerminal = false;
     }

 }; 


 //26 represents 26 alphabets(all in lower case here assumed).
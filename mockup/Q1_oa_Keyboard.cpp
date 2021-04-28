#include<iostream>
#include<string>
#include<unordered_map>
#include<cmath>

using std::cout;
using std::abs;
using std::unordered_map;
using std::string;
/*
There is a special keyboard with all keys in a single row.

You have given a string keyboard of length 26 indicating the layout of the keyboard (indexed from 0 to 25), 
initially your finger is at index 0. To type a character, you have to move your finger to the index of the 
desired character. The time taken to move your finger from index i to index j is |i – j|.

Input :- Keyboard = "abcdefghijklmnopqrstuvwxyz", Word = "cba"
Output :- 4
Input :- Keyboard = "pqrstuvwxyzabcdefghijklmno", Word = "hello"
Output :- 31

Analysis: Time = sum of index distance bewteen current char and next char (distance is always positive int.)
          the index is the index of char in the keyboard dictionary

The time complexity is O(n) and space complexity is O(1);
*/

class KeyBoard{
public:
    int TypeTime(string keyboard, string word){
        if(word.empty()) return 0;
        unordered_map<char,int> umap;
        for(int i = 0; i < keyboard.size(); i++){
            umap[keyboard[i]] = i;
        }
        int sum = umap[word[0]];
        for(int i = 1; i < word.size(); i++){
            sum += abs(umap[word[i]] - umap[word[i - 1]]);
        }
        return sum;
    }
};

int Test(string Keyboard, string word){
    KeyBoard kb;
    cout << kb.TypeTime(Keyboard,word);
    return 0;
}

int main(){
    Test("abcdefghijklmnopqrstuvwxyz","cba");
    cout << "\n";
    Test("pqrstuvwxyzabcdefghijklmno","hello");
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

vector<string> readFile(fstream &wordlist);
void findAnagram(vector<string> words);
bool iswordOk(string word);
bool isAnagram(string word1, string word2);
string toLower(string word);
void printResult(vector<string> result);
vector<string> findMaximumAnagram(vector<string> words);

int main(int argc, char *argv[]) {
    if( argc < 2){
        cerr << "Usage: ./anagramfinder <dictionary file>" << endl;
        return 1;
    }
    if(argc > 2) {
        cerr << "Usage: ./anagramfinder <dictionary file>" << endl;
        return 1;
    }
    fstream wordlist;
    wordlist.open(argv[1]);
    if(!wordlist.is_open()) {
        cerr << "Error: File " << argv[1] << " not found." << endl;    
        return 1;
    }    
    vector<string> words = readFile(wordlist);
    findAnagram(words);
    return 0;
}

vector<string> readFile(fstream &wordlist) {
    string line;
    vector<string> dictList;
    while (getline(wordlist, line)) {
        dictList.push_back(line);
    }
    return dictList;
}

void findAnagram(vector<string> words) {
    vector<string> resultList;
    for(int i=0; i < words.size();i++){
        bool result = iswordOk(words[i]);
        if(!result)
            continue;
        for(int j=0; j<words.size(); j++) {
            if(i == j)
                continue;
            result = isAnagram(words[i],words[j]);
            if(result) {
                resultList.push_back(words[i]);
                break;
            } 
        }
    }
    vector<string> results = findMaximumAnagram(resultList);
    printResult(results);
}

bool iswordOk(string word) {
    for(int i=0; i < word.length(); i++) {
        if(word.at(i) > 126){
            return false;
        }
    }
    return true;
}

bool isAnagram(string word1, string word2) {
    string value1 = toLower(word1);
    string value2 = toLower(word2);
    sort(value1.begin(), value1.end());
    sort(value2.begin(), value2.end());
    if(value1 == value2) {
        return true;
    }
    return false;
}

string toLower(string word) {
    string result = "";
    for(int i = 0; i < word.length(); i++) {
        result += tolower(word.at(i));
    }
    return result;
}

void printResult(vector<string> result) {
    if(result.size()==0) {
        cout << "No anagrams found." << endl;
        return;
    }
    cout<<"Max anagram length: "<<result[0].length()<<endl;
    for(int i=0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

vector<string> findMaximumAnagram(vector<string> words) {
    int max = 0;
    for(int i=0;i<words.size(); i++) {
        if(max < words[i].length()){
            max = words[i].length();
        }
    }
    vector<string> result;
    for(int i=0; i < words.size(); i++){
        if(max == words[i].length()){
            result.push_back(words[i]);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
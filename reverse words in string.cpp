#include<iostream>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    reverse(s.begin(),s.end());
    int size = s.size();
    string result = "";
    for (int i = 0; i < size; i++)
    {
        string word = "";
        while(i<size && s[i]!=' '){
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if(word.size() > 0){
            result += ' ' + word;
        }
    }
    return result.substr(1);
}

int main(){
    string str = "Hello world";
    string result = reverseWords(str);
    cout << "reverse: " << result << endl;
    return 0;
}
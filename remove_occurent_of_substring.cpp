#include<iostream>

using namespace std;

int main(){
    string str = "daabcbaabcbc";
    string part = "abc";

    int totalCharacterInPart = part.size();
    while(str.find(part) < str.size()){
        int start = str.find(part);
        int totalCharacterToRemove = totalCharacterInPart;
        str.erase(start, totalCharacterToRemove);
    }
    cout << "After removing part: " << str << endl;
    return 0;
}
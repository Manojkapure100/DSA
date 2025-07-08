#include<iostream>

using namespace std;

bool isAlfaNumberic(char ch){
    if( (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z') ){
        return true;
    }
    return false;
}

int main(){
    string str = "A man, a plan, a canal: Panama";
    bool ans = true;
    int start = 0;
    int end = str.size() - 1;
    while(start < end){
        if(!isAlfaNumberic(str[start])){
            start++; 
            continue;
        } 
        if(!isAlfaNumberic(str[end])){
            end--; 
            continue;
        }
        if(tolower(str[start]) != tolower(str[end])){
            ans = false;
            break;
        }
        start++;
        end--;
    }
    cout << "String is pelindrome: " << ans << endl;
    return 0;
}
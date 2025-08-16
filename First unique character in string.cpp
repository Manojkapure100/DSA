#include<iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// we use unorder map to store friquency of unique character
// we use queue to get to know queue.first() to get first char in string
// will check if friquency of chatacter in map is more then 1 then we remove it from queue
int firstUniqChar(string s) {
    unordered_map<char,int> map;
    queue<int> queue;

    for (int i = 0; i < s.size(); i++)
    {
        if(map.find(s[i]) == map.end()){
            queue.push(i);
        }

        map[s[i]]++;

        while(queue.size() > 0 && map[s[queue.front()]] > 1){
            queue.pop();
        }
    }

    if(queue.size() == 0){
        return -1;
    }

    return queue.front();
}

int main(){
    string str = "mamata";
    int index = firstUniqChar(str);
    cout << "index: " << index << endl;
    cout << "First Unique Character from " << str << " is " << str[index] << endl;
    return 0;
}
/**
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i = 1; i < n; i++){
            string temp = "";
            int s = 0;
            int j = 1;
            for(j = 1; j < str.size(); j++){
                if(str[s] != str[j]){
                    temp += to_string(j - s) + str[s];
                    s = j;
                }
            }
            temp += to_string(j - s) + str[s];
            str = temp;
        }
        return str;
    }
};

int main(){
    Solution solution;
    cout << solution.countAndSay(6) << endl;
}

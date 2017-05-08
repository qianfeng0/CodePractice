/**
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size() == 0)
            return prefix;
        for (int index = 0; index < strs[0].size(); index++){
            for(int i = 0; i < strs.size(); i++){
                if(index >= strs[i].size() || strs[i][index] != strs[0][index]){
                    return prefix;
                }
            }
            prefix += strs[0][index];
        }
        return prefix;
    }
};

int main(){
    Solution solution;
    
    vector<string> strs;
    strs.push_back("csdyjfg");
    strs.push_back("asdvb");
    strs.push_back("dsd");

    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
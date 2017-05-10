/**
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include <string>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        if(haystack.size() < needle.size())
            return -1;
        for(int i = 0; i <= haystack.size() - needle.size(); i++){
            int j = 0;
            for(j = 0; j < needle.size(); j++){
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};

//use KMP?????

int main(){
    Solution solution;

    string s1 = "asdfgdwe";
    string s2 = "fg";

    int index = solution.strStr(s1, s2);
    printf("%d\n", index);
    return 0;
}


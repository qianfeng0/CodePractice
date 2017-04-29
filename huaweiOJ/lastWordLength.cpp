/**
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。

输入描述:
一行字符串，非空，长度小于5000。


输出描述:
整数N，最后一个单词的长度。

输入例子:
hello world

输出例子:
5
*/


#include <stdio.h>
#include <string.h>

int lastWordLength (const char* str);

int main(){
    char a[6000];
    //scanf("%s", a);
    gets(a);
    printf("%d", lastWordLength(a));
    getchar();
    return 0;
}

int lastWordLength (const char* str){
    if (str == 0)
        return -1;

    int length = strlen(str);
    int count = 0;
    for (int i = length - 1; i >= 0; i--){
        if (str[i] == ' ')
            break;
        count++;
    }
    return count;
}
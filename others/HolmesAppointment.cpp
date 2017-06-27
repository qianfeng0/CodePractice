/**
题目描述
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很

 快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是

 第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、

 以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，

 请帮助福尔摩斯解码得到约会的时间。

输入描述:
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。


输出描述:
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期

四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入例子:
3485djDkxh4hhGE

2984akDfkkkkggEdsb

s&hgsfdk

d&Hyscvnm

输出例子:
THU 14:04
*/

#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>

typedef bool (*IS_FOUND_FUN)(char c);

bool isDay(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

bool isHour(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'N'))
        return true;
    else
        return false;
}

bool isMinute(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c < 'z'))
        return true;
    else
        return false;
}

int findFirstSameAlph(char* str1, char* str2, int str1_start, IS_FOUND_FUN isFoundFun)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = std::min(len1, len2);

    for (int i = str1_start; i < len; i++){
        if (str1[i] == str2[i] && isFoundFun(str1[i]))
            return i;
    }
    return len;
}

const char *dayStr[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    /*
    char str[4][100] = {0};
    for (int i = 0; i < 4; i++){
        scanf("%s", str[i]);
    }
    */
    char str[4][100] = {"3485djDkxh4hhGE","2984akDfkkkkggEdsb","s&hgsfdk","d&Hyscvnm"};

    int index = 0;

    index = findFirstSameAlph(str[0], str[1], index, isDay);
    printf("%s ",dayStr[str[0][index] - 'A']);
    index++;
    index = findFirstSameAlph(str[0], str[1], index, isHour);
    if (str[0][index] >= '0' && str[0][index] <= '9')
        printf("0%c:", str[0][index]);
    else
        printf("%d:", str[0][index] - 'A' + 10);
    
    index = findFirstSameAlph(str[2], str[3], 0, isMinute);
    if (index >= 0 && index <= 9)
        printf("0%d", index);
    else
        printf("%d", index);
    printf("\n");

    return 0;
}
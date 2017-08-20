/*
1. 猎人把一对兔子婴儿(一公一母称为一对)放到一个荒岛上，两年之后，它们生下一对小兔，之后开始每年都会生下一对小兔。生下的小兔又会以同样的方式继续繁殖。
2. 兔子的寿命都是x(x>=3)年，并且生命的最后一年不繁殖。
3. 如果岛上的兔子多于10对，那么猎人会每年在兔子们完成繁殖或者仙逝之后，从岛上带走两对最老的兔子。
请问y年(y>=3)后荒岛上所有的兔子加起来多少岁?(注意, 在条件3执行完之后)
 
输入: 从命令行输入两行整数，第一行是x，第二行是y
输出: y年后荒岛上所有的兔子岁数的总和
*/


#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    //x 兔子寿命，y年数
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);

    vector<int> count(x, 0);
    count[0] = 1;
    int sum = 1;
    

    for (int i = 0; i < y; i++){
        bool hunter = false;
        if (sum > 10)
            hunter = true;

        count[x-1] = 0;     //dead
        sum -= count[x-1];

        //[1]~[x-1]
        int cnt_baby = 0;
        for (int j = x - 1; j >= 2; j--){
            count[j] = count[j-1];
            cnt_baby++;
        }
        count[1] = count[0];

        //[0]
        count[0] = cnt_baby;
        sum+=cnt_baby;

        int del = 2;
        if (hunter == true){
            for (int i = count.size()-1; i >= 0; i--){
                if (del == 0)
                    break;
                if (count[i] > 0){
                    del--;
                    count[i]--;
                    i++;
                }
            }
        }
    }

    int year_sum = 0;
    for (int i = count.size()-1; i >= 0; i++){
        year_sum += count[i] * 0;
    }
    year_sum *= 2;
    printf("%d\n", year_sum);
    return 0;
}
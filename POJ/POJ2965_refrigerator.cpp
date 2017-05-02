/**
Description

The game “The Pilots Brothers: following the stripy elephant” has a quest where a player needs to open a refrigerator.

There are 16 handles on the refrigerator door. Every handle can be in one of two states: open or closed. The refrigerator is open only when all handles are open. The handles are represented as a matrix 4х4. You can change the state of a handle in any location [i, j] (1 ≤ i, j ≤ 4). However, this also changes states of all handles in row i and all handles in column j.

The task is to determine the minimum number of handle switching necessary to open the refrigerator.

Input

The input contains four lines. Each of the four lines contains four characters describing the initial state of appropriate handles. A symbol “+” means that the handle is in closed state, whereas the symbol “−” means “open”. At least one of the handles is initially closed.

Output

The first line of the input contains N – the minimum number of switching. The rest N lines describe switching sequence. Each of the lines contains a row number and a column number of the matrix separated by one or more spaces. If there are several solutions, you may give any one of them.

Sample Input

-+--
----
----
-+--
Sample Output

6
1 1
1 3
1 4
4 1
4 3
4 4
*/

#include <assert.h>
#include <stack>
#include <stdint.h>
#include <stdio.h>

bool matrix[16] = {0, 1, 0, 0,
                   0, 0, 0, 0,
                   0, 0, 0, 0,
                   0, 1, 0, 0};
std::stack<int> log;
std::stack<int> resultLog;
int minTimes = INT32_MAX;

bool isAllOpen()
{
    for(int i = 0; i < 16; i++)
    {
        if(matrix[i] == true)
            return false;
    }
    return true;
}

void changeState(int n)
{
    assert(n >= 0 && n < 16);

    int row = n / 4;
    int col = n % 4;
    for (int i = 0; i < 4; i++)
    {
        //matrix[row][i] = !matrix[row][i];
        //matrix[i][col] = !matrix[i][col];
        matrix[4 * row + i] = !matrix[4 * row + i];
        matrix[4 * i + col] = !matrix[4 * i + col];
    }
    //matrix[row][col] = !matrix[row][col];
    matrix[4 * row + col] = !matrix[4 * row + col];
}

void dfs(int index, int times)
{
    if (isAllOpen())
    {   
        if(times < minTimes)
        {
            minTimes = times;
            resultLog = log;
        }
            return;
    }

    if (index >= 16)
        return;
    
    dfs(index + 1, times);

    changeState(index);
    log.push(index);

    dfs(index + 1, times + 1);
    
    changeState(index);
    log.pop();
}

int main()
{
    dfs(0,0);
    printf("%d\n", minTimes);
    
    int index;
    while(!resultLog.empty())
    {
        index = resultLog.top();
        resultLog.pop();
        printf("%d %d\n", index / 4 + 1, index % 4 + 1);
    }
    return 0;
}

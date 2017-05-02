/**
Description

Flip game is played on a rectangular 4x4 field with two-sided pieces placed on each of its 16 squares. One side of each piece is white and the other one is black and each piece is lying either it's black or white side up. Each round you flip 3 to 5 pieces, thus changing the color of their upper side from black to white and vice versa. The pieces to be flipped are chosen every round according to the following rules: 
Choose any one of the 16 pieces. 
Flip the chosen piece and also all adjacent pieces to the left, to the right, to the top, and to the bottom of the chosen piece (if there are any).

Consider the following position as an example: 

bwbw 
wwww 
bbwb 
bwwb 
Here "b" denotes pieces lying their black side up and "w" denotes pieces lying their white side up. If we choose to flip the 1st piece from the 3rd row (this choice is shown at the picture), then the field will become: 

bwbw 
bwww 
wwwb 
wwwb 
The goal of the game is to flip either all pieces white side up or all pieces black side up. You are to write a program that will search for the minimum number of rounds needed to achieve this goal. 
Input

The input consists of 4 lines with 4 characters "w" or "b" each that denote game field position.
Output

Write to the output file a single integer number - the minimum number of rounds needed to achieve the goal of the game from the given position. If the goal is initially achieved, then write 0. If it's impossible to achieve the goal, then write the word "Impossible" (without quotes).
Sample Input

bwwb
bbwb
bwwb
bwww
Sample Output

4
*/

#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stack>
/*
bwwb
bbwb
bwwb
bwww
*/
bool map[16] = {1, 0, 0, 1,
                1, 1, 0, 1,
                1, 0, 0, 1,
                1, 0, 0, 0};

std::stack<int> log;
std::stack<int> resultLog;

int flipTimes = INT32_MAX;

bool isAllWhiteOrBlack()
{
    for (int i = 1; i < 16; i++)
    {
        if (map[0] != map[i])
            return false;
    }
    return true;
}

void flip(int flipIndex)
{
    assert(flipIndex >= 0 && flipIndex < 16);
    map[flipIndex] = !map[flipIndex];

    //top
    if (flipIndex / 4 != 0)
        map[flipIndex - 4] = !map[flipIndex - 4];
    //bottom
    if (flipIndex / 4 != 3)
        map[flipIndex + 4] = !map[flipIndex + 4];
    //left
    if (flipIndex % 4 != 0)
        map[flipIndex - 1] = !map[flipIndex - 1];
    //right
    if (flipIndex % 4 != 3)
        map[flipIndex + 1] = !map[flipIndex + 1];
}

void dfs(int flipIndex, int times)
{
    if (isAllWhiteOrBlack())
    {
        if (flipTimes > times)
        {
            flipTimes = times;
            resultLog = log;
        }
        return;
    }

    if (flipIndex >= 16)
        return;

    dfs(flipIndex + 1, times);

    flip(flipIndex);
    log.push(flipIndex);

    dfs(flipIndex + 1, times + 1);

    flip(flipIndex);
    log.pop();

    return;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        char temp[5];
        scanf("%s", temp);
        for (int j = 0; j < 4; j++)
        {
            if(temp[j] == 'w')
                map[4*i+j] = false;
            else if(temp[j] == 'b')
                map[4*i+j] = true;
            else
            {
                printf("input error!\n");
                return 1;
            }
        }
    }

    dfs(0, 0);

    if (flipTimes == INT32_MAX)
        printf("Impossible\n");
    else
    {
        printf("%d\n", flipTimes);
        /*
        while(!resultLog.empty())
        {
            printf("%d, ",resultLog.top());
            resultLog.pop();
        }
        */
    }

    return 0;
}
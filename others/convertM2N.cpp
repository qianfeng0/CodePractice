#include <stdio.h>



void convertM2N(const char* mNum, int M, char* nNum, int N);

int main()
{
    printf("hello\n");
    const char* mNum = "5154AB1";
    char nNum[1000];

    printf("src: %s \n", mNum);
    convertM2N(mNum, 16, nNum, 16);
    printf("obj: %s \n", nNum);
    getchar();
    return 0;
}




int getDecFromChar(char str)
{
    if(str >= '0' && str <= '9')
        return str - '0';
    else if(str >= 'A' && str <= 'Z')
        return str - 'A' + 10;
    else
        return str - 'a' + 10;
}

char getCharFromDec(int dec)
{
    static const char dec2ChrMap[36] = {'0','1','2','3','4','5','6','7','8','9',
                                        'A','B','C','D','E','F','G','H','I','J',
                                        'K','L','M','N','O','P','Q','R','S','T',
                                        'U','V','W','X','Y','Z'};
    return dec2ChrMap[dec];
}

int M2Dec(const char* strNum, int M)
{
    int sum = 0;
    while (*strNum != '\0')
    {
        sum = sum * M + getDecFromChar(*strNum);
        strNum++;
    }
    return sum;
}

void dec2N(int dec, int N, char* Nstr)
{
    char* p = Nstr;
    int temp;
    while((temp = dec/N) != 0)
    {
        *p++ = getCharFromDec(dec % N);
        dec /= N;
    }
    *p++ = getCharFromDec(dec % N) ;
    *p-- = '\0';

    char tempChar;
    while(Nstr < p)
    {
        tempChar = *Nstr;
        *Nstr = *p;
        *p = tempChar;
        p--;
        Nstr++;
    }
}

void convertM2N(const char* mNum, int M, char* nNum, int N)
{
    dec2N(M2Dec(mNum, M), N, nNum);
}
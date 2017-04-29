#include <iostream>

int nextIndex(bool a[], int n, int curIndex){
    curIndex++;
    if(curIndex == n)
        curIndex = 0;

    while(a[curIndex] != true){
        curIndex++;
        if(curIndex == n)
            curIndex = 0;
    }
    return curIndex;
}

int main(){
    bool a[1000] = {0};
    int n;
    while(std::cin >> n){
        if (n > 1000)
            n = 1000;
        for(int i = 0; i < n; i++){
            a[i] = true;
        }

        int  i = 0;
        int count = 0;
        int numOfDel = 0;
		while(numOfDel < n-1){
			i = nextIndex(a,n,i);
            count++;
            if(count == 2){
                count = 0;
                a[i] = false;
                i = nextIndex(a,n,i);
                numOfDel++;
            }
        }
        std::cout << i << std::endl; 
    }
    return 0;
}
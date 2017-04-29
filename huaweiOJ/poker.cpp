#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <sstream>

//4 4 4 4-joker JOKER

int poker2Int(std::string poker){
    static const std::string list("345678910JQKA2jokerJOKER");
    return list.find(poker);
}

int numOfCards(std::string cards){
    int count = 0;
    for (int i = cards.size() - 1; i >= 0; i--){
        if (cards[i] == ' '){
            count++;
        }
    }
    count++;
    return count;
}

int main()
{
    char input[100];
    std::vector<int> L,R;

    std::cin.getline(input,100);
    std::string strInput(input);

    int dis = strInput.find('-');
    std::string cards_L = strInput.substr(0, dis);
    std::string cards_R = strInput.substr(dis+1);

    int result = -1;
    int numOfL = numOfCards(cards_L);
    int numOfR = numOfCards(cards_R);

    if (cards_L == "joker JOKER"){
        result = 0;
    }
    else if (cards_R == "joker JOKER"){
        result = 1;
    }
    else if (numOfL == numOfR){
        int pokerL = -1;
        int pokerR = -1;
        pokerL = poker2Int(cards_L.substr(0, cards_L.find(' ')));
        pokerR = poker2Int(cards_R.substr(0, cards_R.find(' ')));
        if(pokerL > pokerR)
            result = 0;
        else if(pokerL < pokerR)
            result = 1;
        else 
            result = 2;
    }
    else{
        if(numOfL == 4)
            result = 0;
        else if(numOfR == 4)
            result = 1;
        else
            result = 2;
    }

    if (result == 0)
        std::cout << cards_L << std::endl;
    else if(result == 1)
        std::cout << cards_R << std::endl;
    else
        std::cout << "ERROR" << std::endl;

    return 0;
}
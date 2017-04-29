#include  <iostream>
#include <vector>

int main(){
	std::vector<int> studentScoreArray;
    int numOfStudents, numOfOperation;

    while(std::cin >> numOfStudents >> numOfOperation){
        studentScoreArray.resize(numOfStudents);
        //input score
        for(int i = 0; i < numOfStudents; i++)
            std::cin >> studentScoreArray[i];
        
        char operation;
        int arg1, arg2;
        //start operation
        for(int times = 0; times < numOfOperation; times++){
            std::cin >> operation >> arg1 >> arg2;
            if(operation == 'Q'){
                if (arg1 > arg2){
                    int temp = arg2;
                    arg2 = arg1;
                    arg1 = temp;
                }
                int maxScore = 0;
                for(int i = arg1; i <= arg2; i++){
                    if(studentScoreArray[i] > maxScore)
                        maxScore = studentScoreArray[i];
                }
                std::cout << maxScore << std::endl;
            }
            else if (operation == 'U'){
                studentScoreArray[arg1] = arg2;
            }
        }
    }
}
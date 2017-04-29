#if (0)
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct stFileError{

    std::string filename;
    int errorLine;
    int count;

    stFileError() 
    : filename(), errorLine(-1), count(0){};

    stFileError(std::string fn, int eline, int cnt) 
    : filename(fn), errorLine(eline), count(cnt) {};

    bool operator== (const stFileError& compareObj){
        if(filename == compareObj.filename && errorLine == compareObj.errorLine)
            return true;
        else
            return false;
    }
};

std::string getFileName(std::string input){
    int index = input.rfind('\\');
    return input.substr(index + 1);
}

bool fileErrorSort(const stFileError& f1, const stFileError& f2){
    if (f1.count > f2.count)
        return true;
    else
        return false;
}

std::string limit16(const std::string filename){
    return filename.size() > 16 ? filename.substr(filename.size()-16) : filename;
}

int main()
{
    std::vector<stFileError> fileErrorArray;
    fileErrorArray.reserve(20);

    std::string fn;
    int line = -1;
    while(std::cin >> fn >> line){
        bool isInArray = false;
        stFileError tempfileError(getFileName(fn), line, 1);
        for (int i = fileErrorArray.size() - 1; i >= 0; i--){
            if(fileErrorArray[i] == tempfileError)
            {
                fileErrorArray[i].count++;
                isInArray = true;
                break;
            }
        }
        if(!isInArray){
            fileErrorArray.push_back(tempfileError);
        }
    }

    int outSize = (fileErrorArray.size() > 8) ? 8 : fileErrorArray.size();
    std::stable_sort(fileErrorArray.begin(), fileErrorArray.end(), fileErrorSort);
    
    for(int i = 0; i < outSize; i++){
        std::cout << limit16(fileErrorArray[i].filename) << ' ' << fileErrorArray[i].errorLine << ' ' << fileErrorArray[i].count << std::endl;
    }
    return 0;
}
#endif

#include <iostream>
#include <vector>
#include <algorithm>

struct stFileError{
    std::string filename;
    int count;
    
    stFileError(std::string fn, int c) : filename(fn), count(c){};
};

bool fileErrorCompare(const stFileError& f1, const stFileError& f2){
    if(f1.count > f2.count)
        return true;
    else
        return false;
}

std::string toOutFormat(std::string& file){
    int i = file.rfind(' ');
    if (i > 16)
        return file.substr(i - 16);
    else
        return file;
}

int main(){
    char str[100];
    std::vector<stFileError> fileErrorArray;

    while(std::cin.getline(str,100))
    {
        if(str[0] == '\0')
            break;
        std::string filename(str);
        filename = filename.substr(filename.rfind('\\') + 1);
        bool isFound = false;
        for(int i = fileErrorArray.size()-1; i>= 0; i--){
            if(filename == fileErrorArray[i].filename){
                isFound = true;
                fileErrorArray[i].count++;
            }
        }
        if(!isFound){
            fileErrorArray.push_back(stFileError(filename,1));
        }
    }
    
    std::stable_sort(fileErrorArray.begin(), fileErrorArray.end(), fileErrorCompare);

    int outSize = fileErrorArray.size();
    if (outSize > 8){
        outSize = 8;
    }
    for(int i = 0; i < outSize; i++){
        std::cout << toOutFormat(fileErrorArray[i].filename) << ' ' << fileErrorArray[i].count << std::endl;
    }
}
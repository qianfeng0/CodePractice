#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Idea{
public:
    Idea(int PM, int start, int pri, int cost) 
    : mPm(PM-1), mStart(start), mPriority(pri), mCost(cost), mAchieve(0){};

    //true 优先级高
    bool operator< (const Idea &idea)
    {
        // 比较优先级
        if (mPriority > idea.mPriority)
            return true;
        else if (mPriority < idea.mPriority)
            return false;
        
        
        if (mCost < idea.mCost)
            return true;
        else if (mCost > idea.mCost)
            return false;
        
        if (mStart < idea.mStart)
            return true;
        else if (mStart > idea.mStart)
            return false;

        if (mPm < idea.mPm)
            return true;
        else
            return false; 
    };    

public:
    int mPm;
    int mStart;
    int mPriority;
    int mCost;
    int mAchieve;
};

bool sortPIdea(Idea* a, Idea* b){
    if (*a < *b)
        return true;
    else
        return false;
}

void printTime(vector<Idea> &vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i].mAchieve << endl;
    }
}

int main()
{
    int nums_PM, nums_programmer, nums_idea;
    cin >> nums_PM >> nums_programmer >> nums_idea;

    vector<Idea> vec_idea;
    vector<vector<Idea*> > pm_idea;
    vector<int> pro_state;

    pm_idea.resize(nums_PM);
    pro_state.assign(nums_programmer, 0);

    for (int i = 0; i < nums_idea; i++){
        int pm, start, pri, cost;
        cin >> pm >> start >> pri >> cost;

        vec_idea.push_back(Idea(pm, start, pri, cost));
    }

    for (int i = 0; i < nums_idea; i++){
        pm_idea[vec_idea[i].mPm].push_back(&vec_idea[i]);
    }

    int time = 0;
    int sum_idea = nums_idea;
    while (1){
        time++;

        //更新程序员状态
        for (int i = 0; i < pro_state.size(); i++){
            if (pro_state[i] != 0)
                pro_state[i]--;
        }

        //PM任务排序，[0]是PM最想实现的
        for (int i = 0; i < pm_idea.size(); i++){
            int j = 0;
            for (j = 0; j < pm_idea[i].size(); j++){
                if (pm_idea[i][j]->mStart > time){
                    break;
                }
            }
            std::sort(pm_idea[i].begin(), pm_idea[i].begin() + j, sortPIdea);
        }

        //程序源接idea
        for (int i = 0; i < pro_state.size(); i++){
            if (sum_idea == 0)
            {
                printTime(vec_idea);
                return 0 ;
            }

            if (pro_state[i] == 0){
                Idea* p = NULL;
                int index = 0;
                for (int j = 0; j < pm_idea.size(); j++){
                    if (pm_idea[j].size() > 0 && pm_idea[j][0]->mStart <= time){
                        if (p == NULL){
                            p = pm_idea[j][0];
                            index = j;
                        }
                        else{
                            if (pm_idea[j][0]->mCost < p->mCost){
                                p = pm_idea[j][0];
                                index = j;
                            }
                        }
                    }
                }
                
                //暂时没有idea
                if (p == NULL){
                    continue;
                }

                //接idea
                sum_idea--;
                pro_state[i] = p->mCost;
                p->mAchieve = time + p->mCost;
                pm_idea[index].erase(pm_idea[index].begin());
            }
        }
    }

    return 0;
}
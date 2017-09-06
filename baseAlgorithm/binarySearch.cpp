#include <vector>
#include <iostream>

using namespace std;

//查找值为target的下标，不存在返回-1
int binarySearch(vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (target < nums[mid]){
            right = mid - 1;
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }

    return -1;
}

int binarySearch_Recursive(vector<int> &nums, int target, int left, int right)
{
    if (left > right)
        return -1;
    
    int mid = (left + right) / 2;

    if (target < nums[mid]){
        return binarySearch_Recursive(nums, target, left, mid - 1);
    }
    else if(nums[mid] < target){
        return binarySearch_Recursive(nums, target, mid + 1, right);
    }
    else{
        return mid;
    }
}

//查找值key第一次出现的下标x，如果不存在返回-1.

//查找值key最后一次出现的下标x，如果不存在返回-1.

//查找刚好小于key的元素下标x，如果不存在返回-1.

//查找刚好大于key的元素下标x，如果不存在返回-1,等价于std::upper_bound.

//查找第一个>=key的下标，如果不存在返回-1,等价于std::lower_bound.
int main()
{
    vector<int> nums = {0, 10, 12};
    cout << binarySearch(nums, 12) << endl;
    cout << binarySearch_Recursive(nums, 10, 0, nums.size() - 1) << endl;
    return 0;
}
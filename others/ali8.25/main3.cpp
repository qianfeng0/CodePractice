//หับü

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> nums;
	int temp;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}

	vector<int> res;
	vector<int> res_next;

	int cur_index = 0;

	//for (int i = 0; i < n; i++)
	while(res.size() < n)
	{
		if (res.size() > res_next.size())
		{
			int num = res[res_next.size()];
			res_next.push_back(num);
			for (int j = 0; j < num; j++) {
				res.push_back(nums[cur_index]);
			}
		}
		else {
			res_next.push_back(nums[cur_index]);
			for (int j = 0; j < nums[cur_index]; j++) {
				res.push_back(nums[cur_index]);
			}
		}

		cur_index++;
		if (cur_index == nums.size())
		{
			cur_index = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i] << endl;
	}

	return 0;
}
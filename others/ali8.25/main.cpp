#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

vector<pair<int, int>> res;
vector<pair<int, int>> cur;

void dfs(const std::vector<vector<string>> &vec_str, int index)
{
	if (index == vec_str.size()) {
		if (res.empty()) {
			res = cur;
		}
		else if(cur.size() < res.size()) {
			res = cur;
		}
		return;
	}

	if (vec_str[index].size() == 0)
		return;

	for (int i = 0; i < vec_str[index].size(); i++) {
		cur.push_back(pair<int, int>(index, i));
		dfs(vec_str, index + vec_str[index][i].length());
		cur.pop_back();
	}
}

void mincut(const string& str, const vector<string>& dict)
{
	std::map<string, vector<int> > m;
	std::vector<vector<string>> vec_str;
	vec_str.resize(str.size());

	for (string s : dict) {
		int temp = 0;
		while (1) {
			temp = str.find(s, temp);
			if (temp == string::npos)
				break;
			m[s].push_back(temp);
			vec_str[temp].push_back(s);
			temp++;
		}
	}

	dfs(vec_str, 0);
	if (res.size() == 0) {
		cout << "n/a" << endl;
		return;
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << vec_str[res[i].first][res[i].second] << " ";
	}
	cout << endl;
}


int main(int argc, const char * argv[])
{
	string strS;
	string dictStr;
	int nDict;
	vector<string> dict;

	cin >> strS;
	cin >> nDict;
	for (int i = 0; i < nDict; i++)
	{
		cin >> dictStr;
		dict.push_back(dictStr);
	}
	mincut(strS, dict);

	return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<algorithm>


using namespace std;

void init(map<string,vector<string>>& dic);
bool cmp(pair<string, int> p1, pair<string, int> p2) {
	return p1.second >= p2.second;
}



int main()
{
	map<string,vector<string>> dic;
	init(dic);
	while (true) {
		int num;
		string suffic;
		if (cin >> num) {
			vector<pair<string,int>> svec;
			vector<pair<string, int>> svec2;
			for (auto c : dic) {
				if (c.first.size() == num) {
					svec.push_back(pair<string,int>(c.first,c.second.size()));
				}
			}

			sort(svec.begin(), svec.end(), cmp);			
			for (int i = 0; i < 10; ++i) {
					cout << svec[i].first << "    " << svec[i].second << endl;
			}
			
		}
		cin >> suffic;
		for (int i = dic[suffic].size() - 1; i >= 0; --i) {
			cout << dic[suffic][i] << endl;
		}

	}
}

void init(map<string, vector<string>>& dic) {
	string filename = "dictionary.txt";
	string letter;
	ifstream ifs(filename.c_str());
	while (ifs >> letter) {
		int s = letter.size();
		for (int i = 0; i < s; ++i) {
			string sub_s = letter.substr(i, s - i);
			dic[sub_s].push_back(letter);
		}
	}

}


	


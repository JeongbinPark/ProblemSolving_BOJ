/*
//KMP code is wrong....
//did not submit this
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPMT(string);

int times = 0;
string text, str;
vector<int> PMT, idx;

int main() {
	getline(cin, text);
	getline(cin, str);

	PMT = getPMT(str);
	
	int j = 0;
	for (int i = 0; i < (int)text.length();) {
		//not same at the first index, move to just next
		if (j == 0 && text[i] != str[0]) {
			i++;
			continue;
		}
		//use PMT
		for (; j < (int)str.length(); j++) {
			if (text[i+j] != str[j]) {
				i = i + j;
				while (j > 0 && text[i] != str[j]) {
					j = PMT[j - 1];
				}
				break;
			}
		}
		//found text
		if (j == (int)str.length()) {
			times++;
			idx.push_back(i++);
		}
	}

	cout << times << "\n";
	for (int i = 0; i < (int)idx.size(); i++)
		cout << idx[i] << " ";
	return 0;
}

//make Partial Match Table
vector<int> getPMT(string str) {
	int len = (int)str.size();
	vector<int> PMT(len, 0);
	for (int i = 1; i < len; i++) {
		int j = PMT[i - 1];
		if (str[j] == str[i]) 
			PMT[i] = PMT[i - 1] + 1;
		else {
			while (j) {
				if (str[i] == str[--j]) {
					PMT[i] = j + 1;
					break;
				}
			}
		}
	}
	return PMT;
}
*/

/* 
//failed in about 80%
//wrong Partial Match Table
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPMT(string);

string text, str;
vector<int> PMT, idx;

int main() {
	getline(cin, text);
	getline(cin, str);

	PMT = getPMT(str);

	//KMP
	int j = 0; 
	for (int i = 0; i < (int)text.size(); i++) {
		while (j > 0 && text[i] != str[j]) {
			j = PMT[j - 1];
		}
		if (text[i] == str[j]) {
			if (j == (int)str.size() - 1) {
				idx.push_back(i - (int)str.size() + 1);
				j = PMT[j]; 
			} 
			else {
				j++; 
			} 
		} 
	}

	cout << (int)idx.size() << "\n";
	for (int i = 0; i < (int)idx.size(); i++)
		cout << idx[i] + 1 << " ";
	return 0;
}

//make Partial Match Table
vector<int> getPMT(string str) {
	int len = (int)str.size();
	vector<int> PMT(len, 0);
	for (int i = 1; i < len; i++) {
		int j = PMT[i - 1];
		if (str[j] == str[i])
			PMT[i] = PMT[i - 1] + 1;
		else {
			while (j) {
				if (str[i] == str[--j]) {
					PMT[i] = j + 1;
					break;
				}
			}
		}
	}
	return PMT;
}
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPMT(string);

string text, str;
vector<int> PMT, idx;

int main() {
	getline(cin, text);
	getline(cin, str);

	PMT = getPMT(str);

	//KMP
	int j = 0;
	for (int i = 0; i < (int)text.size(); i++) {
		while (j > 0 && text[i] != str[j]) {
			j = PMT[j - 1];
		}
		if (text[i] == str[j]) {
			if (j == (int)str.size() - 1) {
				idx.push_back(i - (int)str.size() + 1);
				j = PMT[j];
			}
			else {
				j++;
			}
		}
	}

	cout << (int)idx.size() << "\n";
	for (int i = 0; i < (int)idx.size(); i++)
		cout << idx[i] + 1 << " ";
	return 0;
}

//make Partial Match Table
vector<int> getPMT(string str) {
	int len = (int)str.size();
	int j = 0;
	vector<int> PMT(len, 0);
	for (int i = 1; i < len; i++) {
		while (j > 0 && str[i] != str[j])
			j = PMT[j - 1];
		if (str[i] == str[j])
			PMT[i] = ++j;
	}
	return PMT;
}
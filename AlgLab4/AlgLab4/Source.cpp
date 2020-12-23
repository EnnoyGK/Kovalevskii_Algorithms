#define CRT_SECURE_NO_WARNINGS_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

vector<string> moveStringToArray(string initialString) {
	vector<string> strVec;
	stringstream ss(initialString);
	string word;

	while (ss >> word) {
		strVec.push_back(word);
	}

	return strVec;
}


vector<string> sortStringArray(vector<string> strVec) {
	 sort(strVec.begin(), strVec.end());
	 return strVec;
}

void findWord(string wordToFind, vector<string> strVec) {
	
	int position = -1;
	double startTime = clock();
	for (int i = 0; i < 10000; ++i) {
		if (!strVec.empty()); {
			for (int i = 0; i < strVec.size(); ++i) {
				if (wordToFind == strVec[i]) {
					position = i;
					break;
				}
			}
		}
	}
	double endTime = clock();
	double resTime = (endTime - startTime) / 10000;
	if (position == -1) {
		cout << "Word not found " << "Time: " << resTime/CLOCKS_PER_SEC << '\n';
	}
	else {
		cout << "Word " << wordToFind << " is found at position " << position << " in a " << resTime/CLOCKS_PER_SEC << " time" << '\n';
	}
}

int main() {
	string str = "sometimes i see how the brave new world arrives and it thrives in the ashes of our lives";
	string wordToFind;
	getline(cin, wordToFind);
	vector<string> strVec = moveStringToArray(str);
	vector<string> sorted = sortStringArray(strVec);
	findWord(wordToFind, sorted);
	return 0;
}
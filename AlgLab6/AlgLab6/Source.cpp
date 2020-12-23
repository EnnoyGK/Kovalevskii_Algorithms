#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> fillArray(vector<int> ar) {
	srand(time(0));
	for (int i = 0; i < ar.size(); ++i) {
		ar[i] = (rand() % 1000) + 1;
	}
	return ar;
}

vector<int> optimizedBubbleSort(vector<int> ar) {
	int k = 1;
	bool transp;
	do {
		transp = false;
		for (int i = 0; i < ar.size() - k; ++i) {
			if (ar[i] > ar[i + 1]) {
				swap(ar[i], ar[i + 1]);
				transp = true;
			}
		}
		++k;
	} while (transp);
	return ar;
}

vector<int> insertionSort(vector<int> ar) {
	int tmp;
	for (int i = 0; i < ar.size(); ++i) {
		tmp = ar[i];
		int j = i;
		while (j > 0 && ar[j - 1] > tmp) {
			ar[j] = ar[j - 1];
			j = j - 1;
		}
		ar[j] = tmp;
	}
	return ar;
}

int main() {

	vector<int> ar(1000);

	ar = fillArray(ar);

	double startTime = clock();
	vector<int> sorted = insertionSort(ar);
	double endTime = clock();
	double resTime = (endTime - startTime) / CLK_TCK;
	cout << "Insertion Sort Time: " << resTime << '\n';

	startTime = clock();
	sorted = optimizedBubbleSort(ar);
	endTime = clock();
	resTime = (endTime - startTime) / CLK_TCK;
	cout << "Bubble Sort Time: " << resTime << '\n';

	for (int i = 0; i < ar.size(); ++i) {
		cout << sorted[i] << " ";
	}
	return 0;
}
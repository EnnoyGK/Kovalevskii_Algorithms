#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

vector < vector <unsigned long long int >> fillMatrix(vector<vector<unsigned long long int>>& matrix, int border) {
	srand(time(0));
	for (int i = 0; i < border; ++i) {
		for (int j = 0; j < border; ++j) {
			matrix[i][j] = (rand() % 10000) + 1;
		}
	}
	return matrix;
}

unsigned long long int findSum(vector<vector<unsigned long long int>> matrix) {
	int sum = 0;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = i; j < matrix.size(); ++j) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

vector<unsigned long long int> countTime(vector<vector<unsigned long long int>> matrix) {
	vector<unsigned long long int> result(2);
	time_t startTime = clock();
	result[0] = findSum(matrix);
	time_t endTime = clock();
	result[1] = endTime - startTime;
	return result;
}


int main() {
	srand(time(0));
	int repeats = 5;
	//int n = (rand() % 10000) + 5;
	int n = 2000;
	vector<vector<unsigned long long int>> matrix(n, vector<unsigned long long int>(n));
	
	for (int i = 0; i < repeats; ++i) {
		fillMatrix(matrix, n);
		vector<unsigned long long int> result = countTime(matrix);
		cout << "The sum is " << result[0] << '\n' << "The time is " << result[1] << " ms" << '\n';
	}
	return 0;
}
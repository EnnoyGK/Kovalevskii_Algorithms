#include <iostream>
#include <ctime>

using namespace std;

long long int notationChange(int number, int base) {
	long long int res = 0;
	long long int tmp = 0;
	if (number >= base) {
		tmp = notationChange(number / base, base);
	}
	res = tmp * 10 + (number % base);
	return res;
}

int main() {
	int number;
	int base;
	long long int result(0);
	cout << "Enter the number\n";
	cin >> number;
	cout << "Enter the base\n";
	cin >> base;
	result = notationChange(number, base);
	double startTime = clock();
	for(int i = 0; i < 10000; ++i)
	notationChange(number, base);
	double endTime = clock();
	double resTime = (endTime - startTime) / 10000;
	cout << "\nResult: " << result << "\nTime: " << resTime / CLOCKS_PER_SEC;
	return 0;
}
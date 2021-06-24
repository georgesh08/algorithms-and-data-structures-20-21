#include <iostream>
using namespace std;

int main() {
	int n;

	freopen("smallsort.in", "r", stdin);
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < n-1; i++)
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	freopen("smallsort.out", "w", stdout);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &a, int l, int r) {
    int i = l;
    int j = r;
    int pivot = a[(r + l) / 2];
    while (i <= j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i >= j)
            break;
        swap(a[i++], a[j--]);
    }
    return j;
}

int kth(vector<int> &array, int k, int n) {
    int left = 0, right = n;
    while (true) {
        int mid = partition(array, left, right);

        if (mid == k) {
            return array[mid];
        } else if (k < mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
}

int main() {
    int a, b, c, n, k;
    freopen("kth.in", "r", stdin);

    cin >> n >> k;

    vector<int> arr(n);

    cin >> a >> b >> c >> arr[0] >> arr[1];

    for (int i = 2; i < n; i++)
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;

    kth(arr, k - 1, n - 1);
    int res = kth(arr, k - 1, n - 1);

    freopen("kth.out", "w", stdout);
    cout << res;
    return 0;
}
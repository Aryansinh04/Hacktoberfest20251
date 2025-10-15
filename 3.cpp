#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Generic binary search using iterators
template<typename Iterator, typename T>
int binarySearch(Iterator begin, Iterator end, T x) {
    int l = 0;
    int r = distance(begin, end) - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        auto it = begin + mid;

        if (*it < x)
            l = mid + 1;
        else if (*it > x)
            r = mid - 1;
        else
            return mid;  // Element found
    }

    return -1;  // Not found
}

int main() {
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int& val : arr)
        cin >> val;

    sort(arr.begin(), arr.end());
    cout << "Sorted array: ";
    for (int val : arr)
        cout << val << " ";
    cout << "\n";

    cout << "Enter value to search: ";
    cin >> x;

    int index = binarySearch(arr.begin(), arr.end(), x);
    if (index != -1)
        cout << "Found at index " << index << "\n";
    else
        cout << "Not found\n";

    return 0;
}

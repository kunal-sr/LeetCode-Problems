#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;        // last index of actual nums1 elements
    int j = n - 1;        // last index of nums2
    int k = m + n - 1;    // last index of nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // copy remaining elements from nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3;
    int n = 3;

    cout << "Before merge: ";
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    merge(nums1, m, nums2, n);

    cout << "After merge: ";
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
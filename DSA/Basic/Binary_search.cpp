#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::sort;

// Time complexity: O(log₂ N)
// Space complexity: O(1)

bool binarySearch (const vector<int> &v, int left, int right, int x){
    while (left <= right){
        int mid = (left + right) / 2;
        if (v[mid] == x)  return true;
        else{
            if (v[mid] < x)  left = mid + 1;
            else  right = mid - 1;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // điều kiện bắt buộc để dùng binary search

    int x; cin >> x;
    if (binarySearch(v, 0, v.size()-1, x))  cout << "YES";
    else  cout << "NO";

    return 0;
}

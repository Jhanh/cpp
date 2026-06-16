#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::sort;

// Time complexity: O(log₂ N)
// Space complexity: O(1)

// Tìm vị trí đầu tiên của số cần tìm (nếu có)
int firstPos(const vector<int> &v, int left, int right, int x){
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (v[mid] == x){
            ans = mid;
            right = mid - 1;
        }
        else{
            if (v[mid] < x)  left = mid + 1;
            else  right = mid - 1;
        }
    }
    return ans;
}

// Tìm vị trí cuối cùng của số cần tìm (nếu có)
int lastPos(const vector<int> &v, int left, int right, int x){
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (v[mid] == x){
            ans = mid;
            left = mid + 1;
        }
        else{
            if (v[mid] < x)  left = mid + 1;
            else  right = mid - 1;
        }
    }
    return ans;
}

// Tìm vị trí đầu tiên của số >= x (nếu có)
int lowerBound(const vector<int> &v, int left, int right, int x){
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (v[mid] >= x){
            ans = mid;
            right = mid - 1;
        }
        else  left = mid + 1;
    }
    return ans;
}

// Tìm vị trí đầu tiên của số > x (nếu có)
int upperBound(const vector<int> &v, int left, int right, int x){
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (v[mid] > x){
            ans = mid;
            right = mid - 1;
        }
        else  left = mid + 1;
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());  // điều kiện bắt buộc để dùng binary search

    int x; cin >> x;
    cout << firstPos(v, 0, v.size()-1, x) << '\n';
    cout << lastPos(v, 0, v.size()-1, x) << '\n';
    cout << lowerBound(v, 0, v.size()-1, x) << '\n';
    cout << upperBound(v, 0, v.size()-1, x) << '\n';

    return 0;
}

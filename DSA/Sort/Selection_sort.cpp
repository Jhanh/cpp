#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::swap;

// Selection sort: Duyệt mảng n-1 lần, ở phần tử hiện tại lần lượt từ trái qua phải ta tìm phần tử nhỏ nhất (lớn nhất theo yêu cầu) rồi swap với phần tử hiện tại
// Time complexity: O(N * N)
// Space complexity: O(1)

void selectionSort (vector<int> &v){
    for (int i = 0; i < (int)v.size()-1; i++){
        int minIdx = i;
        for (int j = i+1; j < (int)v.size(); j++){ // Tìm index của phần tử nhỏ nhất
            if (v[j] < v[minIdx]){
                minIdx = j;
            }
        }

        if (i != minIdx)  swap(v[i], v[minIdx]);

        cout << "Step: " << i+1 << ": ";
        for (int k = 0; k < (int)v.size(); k++){
            cout << v[k] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    selectionSort(v);

    return 0;
}

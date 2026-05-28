#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// Insertion sort: Duyệt từ 1 đến n-1, tại phần tử hiện tại ta xét phần tử trước nó nếu thấy phần tử trước nó lớn hơn (nhỏ hơn theo yêu câu) thì ta đẩy sang phải đến khi gặp phần tử nhỏ hơn hoặc bằng phần tử ta đang xét
// Time complexity: O(N * N) có thể lên O(N) khi mảng đã được sắp xếp
// Space complexity: O(1)

void insertionSort (vector<int> &v){
    if ((int)v.size() <= 1) return;

    for (int i = 1; i < (int)v.size(); i++){
        int tmp = v[i]; // lưu phần tử hiện tại để nếu bị dồn qua phải thì vẫn còn
        int j = i - 1; // index phần tử trước phần tử đang xét

        while (j >= 0 && v[j] > tmp){
            v[j+1] = v[j]; // dồn sang phải
            --j;
        }

        v[j+1] = tmp; // số đang xét được đặt lại trước mảng số lớn hơn nó

        cout << "Step " << i << ": ";
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

    insertionSort(v);

    return 0;
}

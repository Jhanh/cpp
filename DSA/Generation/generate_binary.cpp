#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

/*
Thuật toán sinh: Ta xét từ bit cuối, nếu là 0 thì đổi thành 1 còn nếu là 1 thì cho thành 0 rồi dời trái để kiểm tra lặp lại
*/
// Time complexity: O(N * 2^n)
// Space complexity: O(N)

int n;
vector<int> v;
void init(); // khởi tạo cấu hình đầu tiên, n bit 0
void display(); // in cấu hình
bool generateBin(); // thuật toán sinh nhị phân

int main(){
    cin >> n;
    init();
    do{
        display();
    } while(generateBin());

    return 0;
}

void init(){
    v.assign(n, 0);
}

void display(){
    for (int x : v)  cout << x << ' ';
    cout << '\n';
}

bool generateBin(){
    int i = n-1; // đi từ cuối mảng
    // nếu vẫn còn nằm trong dãy bit, và bit đang xét là 1
    while (i >= 0 && v[i] == 1){
        v[i] = 0;
        --i;
    }

    if (i == -1){ // hết bit để xét, đã tới cấu hình cuối cùng
        return false;
    }
    else{
        v[i] = 1;
        return true;
    }
}

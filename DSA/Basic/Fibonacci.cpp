#include <iostream>
using std::cin;
using std::cout;

// Do giới hạn của long long nên ta chỉ làm việc với 93 số đầu tiên bắt

// Cách 1: dùng mảng lưu trữ sẵn, khi cần thì lấy ra lập tức. Nên dùng trong trường hợp thao tác nhiều lần
// Time complexity: O(N) nhưng với mỗi truy vấn tiếp theo chỉ tốn O(1)
// Space complexity: O(N) với N = 93
long long f[93];
void fibo_1 (){
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < 93; i++){
        f[i] = f[i-1] + f[i-2];
    }
}

// Cách 2: chỉ cần dùng 2 biến và cho nó tự cập nhật liên tục. Nên dùng trong trường hợp chỉ thao tác một lần
// Time complexity: O(N) nhưng vẫn tốn O(N) với mỗi truy vấn tiếp theo
// Space complexity: O(1)
long long fibo_2 (int n){ // tìm số fibo thứ n
    if (n == 0)  return 0;
    if (n == 1)  return 1;

    long long f0 = 0, f1 = 1;
    long long fn = 0;
    for (int i = 2; i <= n; i++){
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

int main(){
    fibo_1();
    for (int i = 0; i < 93; i++){
        cout << f[i] << '\n';
    }

    int n; cin >> n;
    cout << fibo_2(n);

    return 0;
}

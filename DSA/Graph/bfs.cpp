#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::vector;
using std::queue;

/*
G = <V, E>
G : Graph    : Đồ thị
V : Vertices : Đỉnh
E : Edge     : Cạnh
*/
// Code chỉ chạy với đơn đồ thị vô hướng và input là danh sách cạnh
/*
BFS (Breadth-First Search): Duyệt qua tất cả các đỉnh bằng cách đi theo từng lớp từ gốc thông qua queue
*/
// Time complexity: O(V + E) nếu dùng danh sách kề
// Space complexity: O(V + E)

vector<vector<int>> adj; // lưu danh sách kề
vector<bool> check; // mảng đánh dấu các đỉnh đã xét
int v, e; // v: số đỉnh; e: số cạnh

void input(){
    cin >> v >> e;
    adj.assign(v+1, vector<int>());
    check.assign(v+1, false);

    for (int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void bfs (int u){
    queue<int> q;
    q.push(u);
    check[u] = true; // đánh dấu đã xét

    while (!q.empty()){ // nếu queue vẫn còn phần tử
        int x = q.front(); // lấy phần tử ở đỉnh queue
        q.pop(); // xóa phần tử vừa lấy ở đỉnh queue

        // Thao tác gì đó với đỉnh (nếu cần)
        cout << x << ' ';

        for (int neighbor : adj[x]){ // duyệt qua các đỉnh kề với đỉnh đang xét
            if (!check[neighbor]){ // nếu đỉnh kề chưa được xét
                q.push(neighbor);  // thì thêm vào cuối queue
                check[neighbor] = true; // đánh dấu đỉnh kề này đã xét
            }
        }
    }
}

int main(){
    input();
    bfs(1);

    return 0;
}

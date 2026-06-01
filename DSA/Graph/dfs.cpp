#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

/*
G = <V, E>
G : Graph    : Đồ thị
V : Vertices : Đỉnh
E : Edge     : Cạnh
*/
// Code chỉ chạy với đơn đồ thị vô hướng và input là danh sách cạnh
/*
DFS (Depth-First Search): Duyệt qua tất cả các đỉnh bằng cách đi sâu vào 1 nhánh theo đỉnh stack đến khi không còn đỉnh nào thì quay lui (đệ qui) để xét tiếp
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

void dfs(int u){
    // thao tác gì đó với đỉnh đang xét (nếu cần)
    cout << u << ' ';

    check[u] = true; // đánh dấu đã xét
    for (int neighbor : adj[u]){
        if (!check[neighbor]){
            dfs(neighbor);
        }
    }
}

int main(){
    input();
    dfs(1);

    return 0;
}

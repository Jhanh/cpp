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
// Hamilton : Đi qua mọi đỉnh (không lặp đỉnh, có thể không duyệt qua mọi cạnh)
// Time complexity: O(V!)
// Space complexity: O(V + E)
vector<vector<int>> adj; // danh sách kề
vector<bool> check; // đánh dấu các đỉnh đã xét
vector<int> path; // lưu lộ trình hamilton
int v, e;

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

bool flag = false;
void hamilton (int u, int cnt, int start_node){ // cnt: số đỉnh đã đi qua
    if (flag)  return; // nếu đã tìm ra chu trình hamilton thì ngưng

    path.push_back(u);
    check[u] = true; // đánh dấu đã xét

    if (cnt == v){ // nếu đã đi qua đủ v đỉnh
        bool returnStart = false;
        for (int x : adj[u]){ // duyệt qua các đỉnh kề của đỉnh đang xét
            if (x == start_node){ // nếu có đường trở về lại đỉnh xuất phát thì nó sẽ tạo được chu trình
                returnStart = true;
                break;
            }
        }

        if (returnStart){
            cout << "Hamilton: ";
            for (int x : path){
                cout << x << ' ';
            }
            cout << start_node << '\n';

            flag = true;
        }
    }

    else{ // nếu chưa đi đủ v đỉnh
        for (int x : adj[u]){ // duyệt qua các đỉnh kề
            if (!check[x]){ // nếu đỉnh kề này chưa được xét
                hamilton(x, cnt+1, start_node);
            }
        }
    }

    // quay lui, đánh dấu lại u chưa được thăm để nhường đường cho các hướng đi khác
    check[u] = false;
    path.pop_back();
}

int main(){
    input();
    int start_node;
    cin >> start_node;
    hamilton(start_node, 1, start_node);

    if (!flag)  cout << "Not exist";

    return 0;
}

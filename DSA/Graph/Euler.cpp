#include <iostream>
#include <vector>
#include <stack>
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::stack;

/*
G = <V, E>
G : Graph    : Đồ thị
V : Vertices : Đỉnh
E : Edge     : Cạnh
*/
// Euler : Đi qua mọi cạnh (không lập cạnh, có thể lập đỉnh)
/*
Code chỉ chạy với đơn đồ thị vô hướng và input là danh sách cạnh
Nếu input mà tất cả đỉnh đều có bậc chẵn thì code sẽ trả về Chu trình Euler
Nếu input mà có đúng 2 đỉnh bậc lẻ và start_node bạn nhập 1 trong 2 đỉnh đó thì code sẽ trả về Đường đi Euler (Nếu nhập đỉnh khác ngoài 2 đỉnh đó thì code sẽ cho kết quả sai)
*/
// Time complexity: O(V + E)
// Space complexity: O(V + E)

vector<vector<pair<int, int>>> adj; // danh sách kề lưu trữ {đỉnh đích, index của cạnh}
vector<bool> used_edge; // đánh dấu các cạnh đã đi qua
vector<int> current_edge; // lưu index của đỉnh đang xét
int v, e;

void input(){
    cin >> v >> e;
    adj.assign(v+1, vector<pair<int, int>>());
    used_edge.assign(e, false);
    current_edge.assign(v+1, 0);

    for (int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }
}

// Thuật toán Hierholzer
void euler(int start_node){
    stack<int> st;
    vector<int> circuit_euler;
    st.push(start_node);

    while (!st.empty()){ // nếu stack còn chưa rỗng
        int u = st.top(); // lấy phần tử ở đỉnh stack
        bool foundEdge = false; // xác định đỉnh u hiện tại có vào ngõ cụt hay chưa

        // Duyệt qua các cạnh kề với đỉnh đang xét, nhưng từ lần thứ 2 trở đi là duyệt tiếp từ vị trí bị bỏ dở ở lần trước mà không duyệt lại từ đầu
        while (current_edge[u] < adj[u].size()){
            int v = adj[u][current_edge[u]].first; // đỉnh kề
            int idx = adj[u][current_edge[u]].second; // index của cạnh (u, v)

            current_edge[u]++; // nhích lên để lần sau chỉ xét cạnh kề tiếp theo mà không lặp lại từ đầu

            if (!used_edge[idx]){ // nếu cạnh kề này chưa xét
                used_edge[idx] = true; // đánh dấu đã xét
                st.push(v);
                foundEdge = true; // đánh dấu vẫn còn đường đi
                break; // dừng xét các cạnh kề khác mà đi sâu hơn vào cạnh kề đang xét
            }
        }

        if (!foundEdge){ // không còn cạnh kề nào để xét (đi vào ngõ cụt)
            st.pop(); // lấy u ra để lùi lại
            circuit_euler.push_back(u); // ghi nhận u vào hành trình
        }
    }

    cout << "Euler: ";
    for (int i = circuit_euler.size()-1; i >= 0; i--){
        cout << circuit_euler[i] << ' ';
    }
    cout << '\n';
}

int main(){
    input();
    int start_node;
    cin >> start_node;
    euler(start_node);

    return 0;
}

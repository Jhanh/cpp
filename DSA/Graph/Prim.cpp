#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::greater;

/*
G = <V, E>
G : Graph    : Đồ thị
V : Vertices : Đỉnh
E : Edge     : Cạnh
*/
// Code chỉ chạy với đơn đồ thị vô hướng và input là danh sách cạnh
// (Minimum Spanning Tree - MST): Cây khung có trọng số nhỏ nhất
// Time complexity: O(E log(V))
// Space complexity: O(V + E)

vector<vector<pair<int, int>>> adj; // danh sách kề lưu trữ {trọng số, đỉnh kể}
vector<bool> checkMST;
int v, e;

void input(){
    cin >> v >> e;
    adj.assign(v+1, vector<pair<int,int>>());
    checkMST.assign(v+1, false);

    for (int i = 0; i < e; i++){
        int x, y, weight; // weight: trọng số
        cin >> x >> y >> weight;

        adj[x].push_back({weight, y});
        adj[y].push_back({weight, x});
    }
}

void prim (int u){
    // Queue ưu tiên cặp nhỏ nhất lên đỉnh (Min-Heap)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int resWeight = 0; // trọng số cuối cùng của cây khung
    pq.push({0, u});

    while (!pq.empty()){ // nếu pri_queue vẫn còn phần tử
        int minWeight = pq.top().first; // trọng số nhỏ nhất của cung nối đỉnh đang xét với đỉnh có tiềm năng
        int x = pq.top().second; // đỉnh có tiềm năng
        pq.pop(); // xóa đỉnh có tiềm năng ra khỏi pri_queue

        if (checkMST[x] == true){ // nếu đỉnh tiềm năng này đã nằm trong cây khung thì bỏ qua để tránh tạo chu trình
            continue;
        }

        checkMST[x] = true; // đánh dấu đỉnh tiềm năng này đã xét
        resWeight += minWeight;

        // Thao tác gì đó với đỉnh tiềm năng này (nếu cần)


        for (pair<int, int> &neighbor : adj[x]){
            int w = neighbor.first;
            int vertex = neighbor.second;

            if (!checkMST[vertex]){ // nếu các đỉnh kề đỉnh tiềm năng chưa được xét
                pq.push({w, vertex});
            }
        }
    }
    // in trọng số của cây khung nhỏ nhất
    cout << resWeight;
}

int main(){
    input();
    prim(1);

    return 0;
}

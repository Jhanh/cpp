#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::priority_queue;
using std::greater;
const int INF = 1000000000;

/*
G = <V, E>
G : Graph    : Đồ thị
V : Vertices : Đỉnh
E : Edge     : Cạnh
*/
// Time complexity: O((V + E) * log(V))
// Space complexity: O(V + E)
vector<vector<pair<int, int>>> adj; // danh sách kề lưu trữ {đỉnh kề, trọng số}
vector<int> distance; // lưu khoảng cách ngắn nhất từ root cho đến các đỉnh khác
vector<int> trace; // lưu vết đỉnh liền trước để sau này truy ngược lại lộ trình
int v, e;

void input(){
    cin >> v >> e;
    adj.assign(v+1, vector<pair<int, int>>());
    distance.assign(v+1, INF); // lúc đầu chưa biết đường đi nên mọi khoảng cách đều là vô cùng
    trace.assign(v+1, -1); // chưa có đường đi nào

    for (int i = 0; i < e; i++){
        int x, y, weight;
        cin >> x >> y >> weight;
        adj[x].push_back({y, weight});
        adj[y].push_back({x, weight});
    }
}

void dijkstra (int start_node){
    // Queue ưu tiên cặp nhỏ nhất lên đỉnh (Min-Heap)
    // pri_queue lưu trữ {khoảng cách tích lũy, đỉnh đang đứng}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start_node] = 0;
    pq.push({0, start_node}); // khoảng cách từ start_node đến chính nó là 0

    while (!pq.empty()){
        // lấy đỉnh có khoảng cách ngắn nhất ra khởi hàng đợi ưu tiên
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop(); // xóa đỉnh vừa lấy ra

        // nếu khoảng cách với đỉnh vừa lấy ra lớn hơn khoảng cách ta đã từng lưu trữ thì bỏ qua
        if (currentDist > distance[u]){
            continue;
        }

        for (const pair<int, int> &edge : adj[u]){
            int v = edge.first; // đỉnh kề
            int weight = edge.second; // trọng số của (u, v)

            // nếu đi vòng qua u để tới v mà ngắn hơn con đường đã được ghi nhận tại v thì cập nhật lại
            if (distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
                trace[v] = u; // ghi nhận lại là để đến được v ngắn nhất thì phải qua u
                pq.push({distance[v], v}); // đẩy ghi nhận này vào hàng đợi ưu tiên để sau này đi tiếp
            }
        }
    }
}

void print (int start_node, int end_node){
    if (distance[end_node] == INF){
        cout << "Not exist\n";
        return;
    }

    vector<int> path;
    int tmp = end_node;

    // truy vết ngược đích về nguồn thông qua mảng trace[]
    while (tmp != -1){
        path.push_back(tmp);
        tmp = trace[tmp];
    }

    cout << "Dijkstra: " << distance[end_node] << '\n';
    for (int i = path.size()-1; i >= 0; i--){
        cout << path[i] << ' ';
    }
    cout << '\n';
}

int main(){
    input();
    int start_node, end_node;
    cin >> start_node >> end_node;
    dijkstra(start_node);
    print(start_node, end_node);

    return 0;
}

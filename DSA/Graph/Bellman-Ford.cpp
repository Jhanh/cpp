#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
const int INF = 1000000000;

/*
G = <V, E>
G : Graph    : Đồ thị
V : Vertices : Đỉnh
E : Edge     : Cạnh
*/
// Code chỉ chạy với đơn đồ thị có hướng và input là danh sách cạnh
// Time complexity: O(V * E)
// Space complexity: O(V + E)

struct edge{
    int u, v, weight;
};

vector<edge> edges; // danh sách cạnh
vector<int> distance; // khoảng cách từ đỉnh root tới các đỉnh khác
vector<int> trace; // lưu đỉnh liền trước
int n, m;

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
}

bool bellman_ford (int start_node){
    distance.assign(n+1, INF);
    trace.assign(n+1, -1);
    distance[start_node] = 0; // vì khoảng cách giữa đỉnh root với chính nó thì bằng 0 (còn lại thì vẫn là vô cực)

    for (int i = 1; i <= n-1; i++){
        bool update = false;

        for (const auto &x : edges){
            int u = x.u;
            int v = x.v;
            int w = x.weight;

            // nếu đi từ nguồn qua u và qua v mà rẻ hơn đường đi hiện tại của v thì cập nhật
            if (distance[u] != INF && distance[u]+w < distance[v]){
                distance[v] = distance[u] + w;
                trace[v] = u;
                update = true;
            }
        }

        if (!update)  break; // nếu không có đỉnh nào được cập nhật thì dừng luôn vì đã có đáp án cuối cùng
    }

    // duyệt lần cuối cùng để đảm bảo không có chu trình âm
    // Chu trình âm chỉ xuất hiện khi có trọng số âm, chu trình âm là chu trình mà đoạn trung gian có thể lập đi lập lại để làm kết quả ngày càng âm.
    for (const auto &x : edges){
        int u = x.u;
        int v = x.v;
        int w = x.weight;

        if (distance[u] != INF && distance[u]+w < distance[v]){
            return false;
        }
    }
    return true;
}

void print (int start_node, int end_node){
    if (distance[end_node] == INF){
        cout << "Not exist\n";
        return;
    }

    vector<int> path;
    int tmp = end_node;

    // truy ngược về nguồn thông qua trace[]
    while (tmp != -1){
        path.push_back(tmp);
        tmp = trace[tmp];
    }

    cout << "Bellman-ford: ";
    // in ngược lại để theo đúng thứ tự từ nguồn đến đích
    for (int i = path.size()-1; i >= 0; i--){
        cout << path[i] << ' ';
    }
    cout << '\n';
}

int main(){
    input();
    int start_node, end_node;
    cin >> start_node >> end_node;

    // nếu có chu trình âm
    if (!bellman_ford(start_node)){
        cout << "Error: No shortest path (Negative cycle detected)\n";
    }
    else{
        print(start_node, end_node);
    }

    return 0;
}

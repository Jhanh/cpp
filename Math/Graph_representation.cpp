#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::stringstream;
using std::pair;
using std::sort;

/*
G = <V, E>
G : Graph    : Đồ thị
V : Vertices : Đỉnh
E : Edge     : Cạnh
*/

// chuyển về ma trận kề
void edgeToMatrix(); // danh sách cạnh -> ma trận kề   | Time: O(V² + E) | Space: O(V²)
void listToMatrix(); // danh sách kề   -> ma trận kề   | Time: O(V² + E) | Space: O(V²)
// chuyển về danh sách cạnh
void matrixToEdge(); // ma trận kề   -> danh sách cạnh | Time: O(V²)    | Space: O(V²)
void listToEdge();   // danh sách kề -> danh sách cạnh | Time: O(V + E) | Space: O(V + E)
// chuyển về danh sách kề
void matrixToList(); // ma trận kề     -> danh sách kề | Time: O(V²)          | Space: O(V²)
void edgeToList();   // danh sách cạnh -> danh sách kề | Time: O(V + Elog(E)) | Space: O(V + E)

int main(){
    int fromType, toType;
    cin >> fromType >> toType;
    if (toType == 1) {
        if (fromType == 2) edgeToMatrix();
        else if (fromType == 3) listToMatrix();
    }
    else if (toType == 2) {
        if (fromType == 1) matrixToEdge();
        else if (fromType == 3) listToEdge();
    }
    else if (toType == 3) {
        if (fromType == 1) matrixToList();
        else if (fromType == 2) edgeToList();
    }

    return 0;
}

void edgeToMatrix(){ // danh sách cạnh -> ma trận kề
    int v, e;
    cin >> v >> e;
    vector<vector<int>> matr(v+1, vector<int>(v+1, 0));

    for (int i = 0; i < e; i++){
        int x, y;  cin >> x >> y;
        matr[x][y] = matr[y][x] = 1;
    }

    // i,j bắt đầu bằng 1 vì danh sách cạnh bắt đầu bằng đỉnh 1
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            cout << matr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void listToMatrix(){ // danh sách kề -> ma trận kề
    int v;
    cin >> v;
    cin.ignore();
    vector<vector<int>> matr(v+1, vector<int>(v+1, 0));

    string line;
    for (int i = 1; i <= v; i++){
        getline(cin, line); // đọc 1 dòng chứa tất cả đỉnh kề của đỉnh đang xét
        stringstream ss(line); // tách các đỉnh kề
        int adjVertex; // lưu thông tin từng đỉnh kề
        while (ss >> adjVertex){
            matr[i][adjVertex] = 1;
        }
    }

    // i,j bắt đầu bằng 1 vì danh sách kề bắt đầu bằng đỉnh 1
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            cout << matr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void matrixToEdge(){ // ma trận kề -> danh sách cạnh
    int v;
    cin >> v;
    vector<vector<int>> matr(v+1, vector<int>(v+1));
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            cin >> matr[i][j];
        }
    }

    vector<pair<int,int>> edge;
    for (int i = 1; i <= v; i++){
        for (int j = i+1; j <= v; j++){
            if (matr[i][j] == 1){
                edge.push_back({i, j});
            }
        }
    }

    for (pair<int,int> x : edge){
        cout << x.first << ' ' << x.second << '\n';
    }
}

void listToEdge(){ // danh sách kề -> danh sách cạnh
    int v;
    cin >> v;
    cin.ignore();
    vector<pair<int, int>> edge;

    string line;
    for (int i = 1; i <= v; i++){
        getline(cin, line); // đọc 1 dòng chứa tất cả đỉnh kề của đỉnh đang xét
        stringstream ss(line); // tách các đỉnh kề
        int adjVertex; // lưu thông tin từng đỉnh kề
        while (ss >> adjVertex){
            if (i < adjVertex){ // đảm bảo không lập lại cung đã xét
                edge.push_back({i, adjVertex});
            }
        }
    }

    for (pair<int, int> x : edge){
        cout << x.first << ' ' << x.second << '\n';
    }
}

void matrixToList(){ // ma trận kề -> danh sách kề
    int v;
    cin >> v;
    vector<vector<int>> matr(v+1, vector<int>(v+1));
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            cin >> matr[i][j];
        }
    }

    vector<vector<int>> adj(v+1);
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            if (matr[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= v; i++){
        cout << i << ": ";
        for (int x : adj[i]){
            cout << x << ' ';
        }
        cout << '\n';
    }
}

void edgeToList(){ // danh sách cạnh -> danh sách kề
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v+1);

    for (int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= v; i++){
        cout << i << ": ";
        sort(adj[i].begin(), adj[i].end()); // đảm bảo các đỉnh kề không sắp xếp lộn xộn
        for (int x : adj[i]){
            cout << x << ' ';
        }
        cout << '\n';
    }
}

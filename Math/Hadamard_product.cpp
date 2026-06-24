#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

// Time complexity: O(N * M)
// Space complexity: O(N * M)

void inputMatrix(vector<vector<int>> &v, int n, int m);
void outputMatrix(const vector<vector<int>> &v);
vector<vector<int>> hadamard_product(const vector<vector<int>> &a, const vector<vector<int>> &b);

int main(){
	int a_row, a_col, b_row, b_col;
	do{
		cin >> a_row >> a_col >> b_row >> b_col;
        if (a_row != b_row || a_col != b_col){
            cout << "Nhap lai\n";
        }
	} while (a_row != b_row || a_col != b_col);

	vector<vector<int>> a;  inputMatrix(a, a_row, a_col);
	vector<vector<int>> b;  inputMatrix(b, b_row, b_col);

    vector<vector<int>> c = hadamard_product(a, b);
    outputMatrix(c);

	return 0;
}

void inputMatrix(vector<vector<int>> &v, int n, int m){
	for (int i = 0; i < n; i++){
		vector<int> tmp;
		for (int j = 0; j < m; j++){
			int x; cin >> x;
			tmp.push_back(x);
		}
		v.push_back(tmp);
	}
}

void outputMatrix(const vector<vector<int>> &v){
	if (v.size() == 0 || v[0].size() == 0)  return;

	int n = v.size();
	int m = v[0].size();

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

vector<vector<int>> hadamard_product(const vector<vector<int>> &a, const vector<vector<int>> &b){
    int n = a.size();
    int m = a[0].size();

    vector<vector<int>> c(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            c[i][j] = a[i][j] * b[i][j];
        }
    }
    return c;
}

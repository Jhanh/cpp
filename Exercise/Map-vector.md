# Lập danh sách thi đấu (kết hợp Map và Vector)
&emsp;Cho thông tin từng trận đấu sắp diễn ra trong một giải bóng đá. Hãy thống kê lại những đối thủ sẽ gặp với từng đội. Danh sách các đội bóng phải liệt kê theo thứ tự từ điển tăng dần và danh sách đối thủ của từng đội bóng cũng phải liệt kê theo thứ tự từ điển tăng dần. <br>

**Input Format** <br>
Dòng 1: N (Số trận đấu sắp diễn ra) <br>
N dòng còn lại: thông tin đội X đấu với đội Y được biểu diễn theo X - Y <br>

**Output Format** <br>
Danh sách đội bóng theo thứ tự từ điển tăng dần <br>
Danh sách đối thủ tương ứng với từng đội bóng theo thứ tự từ điển tăng dần <br>

**Constraints** <br>
1 <= N <= 1000

**Example Input**
> 13 <br>
  Arsenal - Lyon <br>
  Fullham - Liverpool <br>
  Fullham - Chelsea <br>
  Barcelona - Chelsea <br>
  Barcelona - Fullham <br>
  Lyon - Barcelona <br>
  Chelsea - AC Milan <br>
  PSG - Manchester City <br>
  Arsenal - Fullham <br>
  Fullham - Arsenal <br>
  Real Madrid - Barcelona <br>
  Arsenal - Manchester City <br>
  Manchester United - Liverpool <br>

**Example Output**
> AC Milan: Chelsea <br>
  Arsenal: Fullham, Fullham, Lyon, Manchester City <br>
  Barcelona: Chelsea, Fullham, Lyon, Real Madrid <br>
  Chelsea: AC Milan, Barcelona, Fullham <br>
  Fullham: Arsenal, Arsenal, Barcelona, Chelsea, Liverpool <br>
  Liverpool: Fullham, Manchester United <br>
  Lyon: Arsenal, Barcelona <br>
  Manchester City: Arsenal, PSG <br>
  Manchester United: Liverpool <br>
  PSG: Manchester City <br>
  Real Madrid: Barcelona <br>

### Note / Hint
- Dùng `map<string, vector<string>>`

## Code
``` cpp
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using std::cin;
using std::cout;
using std::map;
using std::vector;
using std::string;
using std::stringstream;
using std::sort;

int main(){
    map<string, vector<string>> mp;
    int n;
    cin >> n; cin.ignore();
    while (n--){
        string s; getline(cin, s);
        stringstream ss(s);
        string team1, team2;

        // cắt ss từ đầu đến '-' thì dừng rồi gán cho team1
        getline(ss, team1, '-');
        // cắt đoạn còn lại trong ss cho đến hết rồi gán cho team2
        getline(ss, team2);

        // Do sau khi cắt thì vẫn còn khoảng trắng nên cần xóa phần thừa, vì trong getline không dùng string được
        if (!team1.empty() && team1.back() == ' '){
            team1.pop_back();
        }
        if (!team2.empty() && team2.front() == ' '){
            team2.erase(0, 1);
        }

        mp[team1].push_back(team2);
        mp[team2].push_back(team1);
    }

    for (map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); it++){
        string team = it->first;
        vector<string> &opponent = it->second;
        sort(opponent.begin(), opponent.end());

        cout << team << ": ";
        for (int i = 0; i < opponent.size(); i++){
            cout << opponent[i];
            if (i < opponent.size()-1){
                cout << ", ";
            }
        }
        cout << '\n';
    }

    return 0;
}
```

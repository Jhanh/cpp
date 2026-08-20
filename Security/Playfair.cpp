#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::string;

void initializeMatrix (char matr[5][5]); // Tạo ma trận 5x5
void modifyMatrix (string key, char matr[5][5]); // Dựa vào key mà biến đổi
string formatText (string text); // Định dạng lại để mã hóa đúng quy tắc
void findPosition (char matr[5][5], char x, int &row, int &col); // Hàm phụ
string encryptPlayfair (string text, char matr[5][5]); // Hàm chính

int main(){
    char matrix[5][5];
    string key, text;
    getline(cin, key);
    getline(cin, text);

    initializeMatrix(matrix);
    modifyMatrix(key, matrix);
    string formattedText = formatText(text);
    string res = encryptPlayfair(formattedText, matrix);
    cout << res << '\n';

    return 0;
}

void initializeMatrix (char matr[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matr[i][j] = '*';
        }
    }
}

void modifyMatrix (string key, char matr[5][5]){
    bool used[26] = {false};
    used['J' - 'A'] = true; // Ta quy ước lấy I làm chuẩn và bỏ J

    int row = 0, col = 0;
    // Điền các chữ cái trong key vào bảng 5x5
    for (char c : key){
        c = toupper(c); // Đảm bảo chữ cái in hoa để đồng bộ logic
        if (c == 'J')  c = 'I';

        if (isalpha(c) && used[c - 'A'] == false){ // Nếu là chữ cái và chưa xuất hiện trong bảng
            matr[row][col] = c;
            used[c - 'A'] = true;
            ++col;
            if (col == 5){
                col = 0;
                ++row;
            }
        }
    }

    // Điền các chữ cái còn lại vào bảng 5x5
    for (char c = 'A'; c <= 'Z'; c++){
        if (used[c - 'A'] == false){ // Từ này chưa được điền
            matr[row][col] = c;
            used[c - 'A'] = true;
            ++col;
            if (col == 5){
                col = 0;
                ++row;
            }
        }
    }
}

string formatText (string text){
    string tmp = "";

    // Đổi J thành I và bỏ khoảng trắng
    for (char c : text){
        if (isalpha(c)){
            c = toupper(c); // Đảm bảo chữ cái in hoa để đồng bộ logic
            if (c == 'J')  c = 'I'; // Quy định J là I vì trong bảng ta mặc định I thay thế cho J
            tmp += c;
        }
    }

    // Chia cặp
    string res = "";
    for (int i = 0; i < (int)tmp.length(); i++){
        res += tmp[i];

        if (i == (int)tmp.length()-1){ // nếu kích thước chuỗi lẻ thì ngắt để chèn X vào cuối
            break;
        }

        if (tmp[i] == tmp[i+1]){ // Nếu 2 kí tự liên tiếp cùng cặp trùng nhau
            res += 'X'; // Chèn X vào sau từ đầu tiên và đẩy từ thứ 2 bị trùng lùi về sau
        }
        else{ // Nếu không trùng thì ta ghép thành 1 cặp rồi nhảy đến cặp tiếp theo
            res += tmp[i+1];
            ++i; // Nhảy cóc
        }
    }
    if (res.length() % 2 != 0){ // Đảm bảo logic
        res += 'X';
    }
    return res;
}

void findPosition (char matr[5][5], char c, int &row, int &col){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (matr[i][j] == c){
                row = i;
                col = j;
                return;
            }
        }
    }
}

string encryptPlayfair (string text, char matr[5][5]){
    string res = "";
    for (int i = 0; i < (int)text.length(); i += 2){ // Xét theo cặp
        char a = text[i];
        char b = text[i+1];
        int r1, c1, r2, c2;

        // Tìm tọa độ của 2 chữ cái trong bảng đã biến đổi
        findPosition(matr, a, r1, c1);
        findPosition(matr, b, r2, c2);

        if (r1 == r2){ // Cùng hàng
            res += matr[r1][(c1 + 1) % 5];
            res += matr[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2){ // Cùng cột
            res += matr[(r1 + 1) % 5][c1];
            res += matr[(r2 + 1) % 5][c2];
        }
        else{ // Tạo thành hình chữ nhật
            res += matr[r1][c2];
            res += matr[r2][c1];
        }
    }
    return res;
}

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

struct payload{
    int a, b;
    string c, d;
    double e, f;
};

struct node{
    payload data;
    node *next;
};

payload input ();
void output (payload x);
node *makeNode (payload val);                      // Tạo node mới
int size (node *head);                         // Kích thước danh sách liên kết
void print (node *head);                       // In danh sách liên kết
void insertHead(node *&head, payload val);         // Thêm vào đầu
void insertTail(node *&head, payload val);         // Thêm vào cuối
void insertMid(node *&head, payload val, int pos); // Thêm vào giữa
void deleteHead(node *&head);                  // Xóa đầu
void deleteTail(node *&head);                  // Xóa cuối
void deleteMid(node *&head, int pos);          // Xóa giữa
void freeList(node *&head);                    // Giải phóng bộ nhớ

int main(){
    node *head = NULL;

    while(1){
        cout << "1. Insert head\n";
        cout << "2. Insert tail\n";
        cout << "3. Insert middle\n";
        cout << "4. Delete head\n";
        cout << "5. Delete tail\n";
        cout << "6. Delete middle\n";
        cout << "7. Print\n";
        cout << "0. END\n";

        int choice;
        do{
            cin >> choice;
            if (choice < 0 || choice > 7)  cout << "ERROR!\n";
        } while (choice < 0 || choice > 7);

        if (choice == 1){
            payload value = input();
            insertHead(head, value);
        }
        else if (choice == 2){
            payload value = input();
            insertTail(head, value);
        }
        else if (choice == 3){
            int position;
            cout << "Enter position: "; cin >> position;
            payload value = input();
            insertMid(head, value, position);
        }
        else if (choice == 4){
            deleteHead(head);
        }
        else if (choice == 5){
            deleteTail(head);
        }
        else if (choice == 6){
            int position;
            cout << "Enter position: ";
            cin >> position;
            deleteMid(head, position);
        }
        else if (choice == 7){
            print(head);
        }
        else{
            break;
        }
    }

    freeList(head);
    return 0;
}

payload input (){
    payload x;
    cin >> x.a >> x.b;
    cin.ignore();
    getline(cin, x.c);  getline(cin, x.d);
    cin >> x.e >> x.f;
    return x;
}

void output (payload x){
    cout << x.a << x.b << x.c << x.d << x.e << x.f;
}

node *makeNode(payload val){
    node *newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int size (node *head){
    if (head == NULL)  return 0;

    int cnt = 0;
    node *tmp = head;
    do{
        ++cnt;
        tmp = tmp->next;
    } while (tmp != head);
    return cnt;
}

void print (node *head){
    if (head == NULL){
        cout << "EMPTY\n";
        return;
    }

    node *tmp = head;
    do{
        output(tmp->data);
        cout << '\n';
        tmp = tmp->next;
    } while (tmp != head);
    cout << '\n';
}

void insertHead(node *&head, payload val){
    node *newNode = makeNode(val);

    if (head == NULL){ // nếu DSLK vòng rỗng
        head = newNode;
        newNode->next = head; // node mới tự nối vào chính nó
        return;
    }

    // nếu DSLK vòng không rỗng
    node *tmp = head;
    while (tmp->next != head){ // đi đến node cuối cùng
        tmp = tmp->next;
    }
    newNode->next = head; // node mới nối vào node đang đứng đầu
    head = newNode; // chuyển head thành node mới
    tmp->next = newNode; // node cuối nối vào node mới (node đầu)
}

void insertTail(node *&head, payload val){
    node *newNode = makeNode(val);

    if (head == NULL){ // nếu DSLK vòng rỗng
        head = newNode;
        newNode->next = head; // node mới tự nối vào chính nó
        return;
    }

    // nếu DSLK vòng không rỗng
    node *tmp = head;
    while (tmp->next != head){ // Đi đến node cuối cùng
        tmp = tmp->next;
    }
    tmp->next = newNode; // node cuối cùng nối vào node mới
    newNode->next = head; // node mới nối vào node đầu
}

void insertMid(node *&head, payload val, int pos){
    int listSize = size(head);
    if (pos < 0 || pos > listSize){ // nếu vị trí cần chèn không tồn tại
        return;
    }
    else if (pos == 0){
        insertHead(head, val);
        return;
    }
    else if (pos == listSize){
        insertTail(head, val);
        return;
    }

    node *newNode = makeNode(val);

    node *tmp = head;
    --pos; // đảm bảo node tmp đứng ở node trước node cần chèn
    while (pos--){
        tmp = tmp->next;
    }
    // Yêu cầu tuân theo đúng thứ tự sau:
    newNode->next = tmp->next; // node mới nối vào node sau node tmp
    tmp->next = newNode; // node tmp nối vào node mới
}

void deleteHead(node *&head){
    if (head == NULL){ // nếu DSLK vòng rỗng
        cout << "EMPTY\n";
        return;
    }

    if (head->next == head){  // nếu DSLK vòng có đúng 1 phần tử
        delete head;
        head = NULL;
        return;
    }

    // Nếu DSLK vòng có nhiều hơn 1 phần tử
    node *tmp = head;
    while (tmp->next != head){
        tmp = tmp->next;
    }
    node *needDel = head;
    head = head->next; // chuyển head lên node kế bên
    tmp->next = head;
    delete needDel;
}

void deleteTail(node *&head){
    if (head == NULL){ // nếu DSLK vòng rỗng
        cout << "EMPTY\n";
        return;
    }

    if (head->next == head){ // nếu DSLK chỉ có duy nhất 1 phần tử
        delete head;
        head = NULL;
        return;
    }

    node *tmp = head;
    while (tmp->next->next != head){ // Đi đến node kế cuối
        tmp = tmp->next;
    }
    node *needDel = tmp->next;
    tmp->next = head; // nối node kế cuối vào node đầu
    delete needDel;
}

void deleteMid(node *&head, int pos){
    int listSize = size(head);
    if (pos < 0 || pos >= listSize){ // nếu vị trí cần xóa không tồn tại
        return;
    }
    else if (pos == 0){
        deleteHead(head);
        return;
    }
    else if (pos == listSize-1){
        deleteTail(head);
        return;
    }

    node *tmp = head;
    --pos; // đảm bảo node tmp đứng ở node trước node cần xóa
    while (pos--){
        tmp = tmp->next;
    }
    node *needDel = tmp->next;
    tmp->next = tmp->next->next; // node tmp trỏ nối với node sau node cần xóa
    delete needDel;
}

void freeList(node *&head){
    if (head == NULL)  return;

    node *tmp = head->next;
    while (tmp != head){
        node *needDel = tmp;
        tmp = tmp->next;
        delete needDel;
    }
    delete head;
    head = NULL;
}

#include <iostream>
using std::cin;
using std::cout;

struct node{
    int data;
    node *next;
    node *prev;
};

node *makeNode (int val);                      // Tạo node mới
int size (node *head);                         // Kích thước danh sách liên kết
void print (node *head);                       // In danh sách liên kết
void insertHead(node *&head, int val);         // Thêm vào đầu
void insertTail(node *&head, int val);         // Thêm vào cuối
void insertMid(node *&head, int val, int pos); // Thêm vào giữa
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
        cout << "8. END\n";

        int choice;
        do{
            cin >> choice;
            if (choice < 1 || choice > 8)  cout << "ERROR!";
        } while (choice < 1 || choice > 8);

        if (choice == 1){
            int value;
            cout << "Enter value: ";
            cin >> value;
            insertHead(head, value);
        }
        else if (choice == 2){
            int value;
            cout << "Enter value: ";
            cin >> value;
            insertTail(head, value);
        }
        else if (choice == 3){
            int value, position;
            cout << "Enter value: ";    cin >> value;
            cout << "Enter position: "; cin >> position;
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

node *makeNode(int val){
    node *newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int size (node *head){
    int cnt = 0;
    while (head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void print (node *head){
    if (head == NULL){
        cout << "EMPTY\n";
        return;
    }

    while (head != NULL){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

void insertHead(node *&head, int val){
    node *newNode = makeNode(val);

    if (head == NULL){ // nếu DSLK đôi rỗng
        head = newNode;
        return;
    }

    // nếu DSLK đôi không rỗng
    newNode->next = head; // node mới nối vào node đang đứng đầu
    head->prev = newNode; // node đang đứng đầu nối ngược vào node mới
    head = newNode; // chuyển head thành node mới
}

void insertTail(node *&head, int val){
    node *newNode = makeNode(val);

    if (head == NULL){ // nếu DSLK đôi rỗng
        head = newNode;
        return;
    }

    // nếu DSLK đôi không rỗng
    node *tmp = head;
    while (tmp->next != NULL){ // Đi đến node cuối cùng
        tmp = tmp->next;
    }
    tmp->next = newNode; // node cuối cùng nối vào node mới
    newNode->prev = tmp; // node mới nối ngược vào node cuối
}

void insertMid(node *&head, int val, int pos){
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
    newNode->prev = tmp; // node mới nối ngược vào node tmp
    tmp->next->prev = newNode; // node sau node tmp nối ngược vào node mới
    tmp->next = newNode; // node tmp nối vào node mới
}

void deleteHead(node *&head){
    if (head == NULL){ // nếu DSLK đôi rỗng
        cout << "EMPTY\n";
        return;
    }

    node *needDel = head;
    head = head->next; // chuyển head lên node kế bên
    if (head != NULL){ // nếu DSLK đôi có nhiều hơn 1 node
        head->prev = NULL;
    }
    delete needDel;
}

void deleteTail(node *&head){
    if (head == NULL){ // nếu DSLK đôi rỗng
        cout << "EMPTY\n";
        return;
    }

    if (head->next == NULL){ // nếu DSLK chỉ có duy nhất 1 phần tử
        delete head;
        head = NULL;
        return;
    }

    node *tmp = head;
    while (tmp->next != NULL){ // đi đến node cuối cùng (node cần xóa)
        tmp = tmp->next;
    }
    node *needDel = tmp;
    tmp->prev->next = NULL; // node kế cuối nối vào NULL
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
    while (pos--){
        tmp = tmp->next;
    }
    node *needDel = tmp;
    tmp->prev->next = tmp->next; // node trước tmp nối vào node sau tmp
    tmp->next->prev = tmp->prev; // node sau tmp nối ngược vào node trước tmp
    delete needDel;
}

void freeList(node *&head){
    if (head == NULL)  return;

    while (head != NULL){
        node *needDel = head;
        head = head->next;
        delete needDel;
    }
    head = NULL;
}


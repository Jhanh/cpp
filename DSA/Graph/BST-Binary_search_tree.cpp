#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

struct node{
    int data;
    node *left;
    node *right;
};

node *makeNode (int val);
void insertNode (node *&root, int val);
void deleteNode (node *&root, int val);
void printTree (node *root, int option);
void freeTree (node *&root);

int main(){
    node *root = NULL;

    while(1){
        system("cls");
        cout << "1. Insert node\n";
        cout << "2. Delete node\n";
        cout << "3. Print tree (Choose order)\n";
        cout << "0. END\n";

        int choice;
        do{
            cin >> choice;
            if (choice < 0 || choice > 3)  cout << "ERROR\n";
        } while (choice < 0 || choice > 3);

        if (choice == 1){
            int value;
            cin >> value;
            insertNode(root, value);
        }
        else if (choice == 2){
            int value;
            cin >>value;
            deleteNode(root, value);
        }
        else if (choice == 3){
            cout << "1. Print Node - Left - Right\n";
            cout << "2. Print Node - Right - Left\n";
            cout << "3. Print Left - Node - Right\n";
            cout << "4. Print Right - Node - Left\n";
            cout << "5. Print Left - Right - Node\n";
            cout << "6. Print Right - Left - Node\n";

            int option;
            do{
                cin >> option;
                if (option < 1 || option > 6)  cout << "ERROR\n";
            } while (option < 1 || option > 6);

            switch(option){
                case 1: printTree(root, 1); break;
                case 2: printTree(root, 2); break;
                case 3: printTree(root, 3); break;
                case 4: printTree(root, 4); break;
                case 5: printTree(root, 5); break;
                case 6: printTree(root, 6); break;
            }
            cout << '\n';
        }


        if (choice != 0){
            system("pause");
        }
        else{
            break;
        }
    }

    freeTree(root);
    return 0;
}

node *makeNode (int val){
    node *newNode = new node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode (node *&root, int val){
    if (root == NULL){ // nếu cây rỗng
        node *newNode = makeNode(val);
        root = newNode;
        return;
    }

    // nếu cây có nhiều hơn 1 node
    // nếu phần tử muốn thêm nhỏ hơn node hiện tại -> thêm trái
    if (val < root->data){
        insertNode(root->left, val);
    }
    // nếu phần tử muốn thêm lớn hơn node hiện tại -> thêm phải
    else if (val > root->data){
        insertNode(root->right, val);
    }

    // nếu phần tử muốn thêm bằng node hiện tại -> bỏ qua
}

void deleteNode (node *&root, int val){
    if (root == NULL)  return;

    // nếu phần tử muốn xóa nhỏ hơn node hiện tại -> đi qua trái kiếm
    if (val < root->data){
        deleteNode(root->left, val);
    }
    // nếu phần tử muốn xóa lớn hơn node hiện tại -> đi qua phải kiếm
    else if (val > root->data){
        deleteNode(root->right, val);
    }

    else{  // val == root->data (đã tìm được node cần xóa)
        // nếu node cần xóa là node lá hoặc node có 1 con
        if (root->left == NULL){ // node cần xóa không có node con trái
            node *needDel = root;
            // đã bao gồm trường hợp xóa node lá, vì nếu là node lá thì root->right là NULL
            root = root->right; // kéo node con phải lên thay thế
            delete needDel;
        }
        else if (root->right == NULL){ // node cần xóa không có node con phải
            node *needDel = root;
            // đã bao gồm trường hợp xóa node lá, vì nếu là node lá thì root->left là NULL
            root = root->left; // kéo node con trái lên thay thế
            delete needDel;
        }

        // nếu node cần xóa là node có đủ 2 con
        // có 2 cách và code này đi theo hướng: đi qua phải 1 lần, đi qua trái nhiều lần
        else{
            node *replaceNode = root;
            replaceNode = replaceNode->right;
            while (replaceNode->left != NULL){
                replaceNode = replaceNode->left;
            }

            root->data = replaceNode->data;

            // có thể đổi root->right thành root->left dựa theo hướng từ đầu ta chọn để tìm thừa kế
            deleteNode(root->right, replaceNode->data);
        }
    }
}

void printTree (node *root, int option){
    if (root == NULL)  return;

    switch(option){
        case 1: // Node - Left - Right
            cout << root->data << ' ';
            printTree(root->left, 1);
            printTree(root->right, 1);
            break;
        case 2: // Node - Right - Left
            cout << root->data << ' ';
            printTree(root->right, 2);
            printTree(root->left, 2);
            break;
        case 3: // Left - Node - Right
            printTree(root->left, 3);
            cout << root->data << ' ';
            printTree(root->right, 3);
            break;
        case 4: // Right - Node - Left
            printTree(root->right, 4);
            cout << root->data << ' ';
            printTree(root->left, 4);
            break;
        case 5: // Left - Right - Node
            printTree(root->left, 5);
            printTree(root->right, 5);
            cout << root->data << ' ';
            break;
        case 6: // Right - Left - Node
            printTree(root->right, 6);
            printTree(root->left, 6);
            cout << root->data << ' ';
            break;
    }
}

void freeTree (node *&root){
    if (root == NULL){ // nếu cây rỗng
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    delete root;
    root = NULL;
}

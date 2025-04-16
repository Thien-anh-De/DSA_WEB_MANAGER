#include<bits/stdc++.h>
using namespace std;

struct Node {
    string ten;
    string que;
    string ngaysinh; // dd/mm/yyyy
    Node* next;
};

typedef Node* node;

node makeNode(string x, string y, string z) {
    node tmp = new Node();
    tmp->ten = x;
    tmp->que = y;
    tmp->ngaysinh = z;
    tmp->next = NULL;
    return tmp;
}

// Thêm vào cuoi danh sách
void insertLast(node &head, string x, string y, string z) {
    node tmp = makeNode(x, y, z);
    if (head == NULL) head = tmp;
    else {
        node p = head;
        while (p->next != NULL) p = p->next;
        p->next = tmp;
    }
}

// In danh sách
void in(node a) {
    if (a == NULL) {
        cout << "Danh sach trong.\n";
        return;
    }
    while (a != NULL) {
        cout << a->ten << " | " << a->que << " | " << a->ngaysinh << endl;
        a = a->next;
    }
}

// Tim kiem theo ten
void searchName(node head, string x) {
    bool found = false;
    while (head != NULL) {
        if (head->ten == x) {
            cout << head->ten << " | " << head->que << " | " << head->ngaysinh << endl;
            found = true;
        }
        head = head->next;
    }
    if (!found) cout << "Khong tim thay sinh vien trong danh sach.\n";
}

// Tim kiem theo que quan
void searchQue(node head, string y) {
    bool found = false;
    while (head != NULL) {
        if (head->que == y) {
            cout << head->ten << " | " << head->que << " | " << head->ngaysinh << endl;
            found = true;
        }
        head = head->next;
    }
    if (!found) cout << "Khong tim thay sinh vien trong danh sach.\n";
}

// chuyen ngay sinh thanh chuoi so de so sanh
// ham stoi de doi string sang int và substr de cat chuoi
int convertDate(string date) {
    int d = stoi(date.substr(0,2));
    int m = stoi(date.substr(3,2));
    int y = stoi(date.substr(6,4));
    return y * 10000 + m * 100 + d;
}

// sap xep ngay sinh
void sortByDate(node &head) {
    vector<node> v;
    node cur = head;
    //gan cac node vao vector
    while (cur != NULL) {
        v.push_back(cur);
        cur = cur->next;
    }
    //sap xep vector
    sort(v.begin(), v.end(), [](node a, node b) {//ham an so sanh giua 2 node voi nhau
        return convertDate(a->ngaysinh) < convertDate(b->ngaysinh);
    });
    // gan lai danh sach
    for (int i = 0; i < v.size() - 1; i++) {
        v[i]->next = v[i+1];
    }
    if (!v.empty()) v.back()->next = NULL;
    head = v.empty() ? NULL : v[0];
}

// Menu chuong trình
void menu() {
    cout << "\n==================== MENU ====================\n";
    cout << "1. Them sinh vien\n";
    cout << "2. Hien thi danh sach sinh vien\n";
    cout << "3. Tim kiem sinh vien theo ten\n";
    cout << "4. Tim kiem sinh vien theo que quan\n";
    cout << "5. Sap xep sinh vien theo do tuoi\n";
    cout << "6. Thoat\n";
    cout << "=============================================\n";
}

int main() {
    node head = NULL;
    int choice;
    do {
        menu();
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string ten, que, ns;
            cout << "Nhap ten sinh vien: ";
            getline(cin, ten);
            cout << "Nhap que quan: ";
            getline(cin, que);
            cout << "Nhap ngay sinh (dd/mm/yyyy): ";
            getline(cin, ns);
            insertLast(head, ten, que, ns);
        } else if (choice == 2) {
            cout << "Danh sach sinh vien:\n";
            in(head);
        } else if (choice == 3) {
            string x;
            cout << "Nhap ten sinh vien can tim: ";
            getline(cin, x);
            searchName(head, x);
        } else if (choice == 4) {
            string y;
            cout << "Nhap que quan sinh vien can tim: ";
            getline(cin, y);
            searchQue(head, y);
        } else if (choice == 5) {
            sortByDate(head);
            cout << "Danh sach sau khi sap xep theo tuoi:\n";
            in(head);
        } else if (choice == 6) {
            cout << "Thoat chuong trinh!\n";
        } else {
            cout << "Lua chon khong hop le.\n";
        }

    } while (choice != 6);

    return 0;
}


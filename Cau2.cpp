#include <iostream>
#include <iomanip>

using namespace std;

class VeMayBay {
public:
    void nhap();
    void xuat();
    int get_giave() {
        return giave;
    }
private:
    string tenchuyen;
    int ngaybay, giave;
};

class Nguoi {
public:
    void nhap();
    void xuat();
protected:
    string hoten, gioitinh;
    int tuoi;
};

class HanhKhach : public Nguoi {
public:
    HanhKhach() : ve(nullptr), soluong(0) {}
    ~HanhKhach() {
        delete ve;
    }

    void nhap();
    void xuat();
    int TongTien() {
        if (ve != nullptr) {
            return (ve->get_giave()) * soluong;
        }
        return 0;
    }

private:
    int soluong;
    VeMayBay* ve;
};

void VeMayBay::nhap() {
    cin.ignore();
    cout << "Ten chuyen: "; getline(cin, tenchuyen);
    cout << "Ngay bay: "; cin >> ngaybay;
    cout << "Gia ve: "; cin >> giave;
}

void Nguoi::nhap() {
    cout << "Ho va ten: "; cin.ignore(); getline(cin, hoten);
    cout << "Gioi tinh: "; getline(cin, gioitinh);
    cout << "tuoi: "; cin >> tuoi;
}

void HanhKhach::nhap() {
    Nguoi::nhap();
    ve = new VeMayBay;
    ve->nhap();
    cout << "Nhap so luong ve: "; cin >> soluong;
    cin.ignore();
}

void HanhKhach::xuat() {
    cout << left << setw(20) << hoten << left << setw(20) << gioitinh << left << setw(15) << tuoi << right << setw(30) << TongTien() << endl;
}

int main() {
    int n;
    cout << "Nhập số hành khách: "; cin >> n;
    HanhKhach* hk = new HanhKhach[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "--Thông tin khách hàng--" << endl;
        hk[i].nhap();
    }
    cout << "danh sách khách hàng" << endl;
    cout << left << setw(20) << "Họ và tên" << left << setw(20) << "Giới tính" << left << setw(15) << "Tuổi" << right << setw(30) << "Tổng tiền" << endl;
    for (int i = 0; i < n; i++) {
        hk[i].xuat();
    }

    return 0;
}

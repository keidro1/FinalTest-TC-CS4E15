#include <iostream>
#include <stack>
#include <string>

using namespace std;

string to_string(long long n) {
    string s = "";
    while (n > 0) {
        s = char(n % 10 + '0') + s;
        n /= 10;
    }
    return s;
}

int main() {
    string s;
    cout << "Nhap vao sau s: ";
    getline(cin, s);
    s = s + '@'; // Thêm một @ để end string
    stack<char> st;
    string str = "";
    for (int i = 0; i < s.length(); i++) {
        if (st.empty() || st.top() == s[i]) {
            st.push(s[i]);
        } else {
            int count = 0;
            str = str + st.top();
            while (!st.empty()) {
                count++;
                st.pop();
            }
            str = str + to_string(count);
            st.push(s[i]);
        }
    }
    cout << "Chuoi ma hoa: " << str << endl; // In ra chuỗi mã hóa
    return 0;
}

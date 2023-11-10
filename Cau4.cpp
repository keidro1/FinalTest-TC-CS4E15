#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void TaoSNT(int n) {
    queue<int> SNT;
    for (int i = 2; i <= 9 && i <= n; ++i) {
        if (isPrime(i)) {
            SNT.push(i);
        }
    }

    while (!SNT.empty()) {
        int current = SNT.front();
        SNT.pop();
        cout << current << " ";
        // Duyet n de tim ra cac so nguyen to moi NT -> day nguoc len queue
        for (int n = 1; n <= 9; n += 2) {
            int NT = current * 10 + n;
            if (NT <= n && isPrime(NT)) {
                SNT.push(NT);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap vao so n: ";
    cin >> n;

    cout << "Cac so sieu Nguyen To < hoac = " << n << " la: ";
    TaoSNT(n);

    return 0;
}

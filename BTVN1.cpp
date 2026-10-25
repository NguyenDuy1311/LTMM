
#include <iostream>
using namespace std;

int n ;
int mx ;

// x*g(x)
int xgx(int g) {
    int mask = (1 << n) - 1;
    int overflow = g & (1 << (n - 1));

    g = (g << 1) & mask;

    if (overflow)
        g ^= mx & mask;

    return g;
}

// x^k * g(x)
int xkgx(int g, int k) {
    if (k == 0)
        return g & ((1 << n) - 1);

    return xgx(xkgx(g, k - 1));
}

// f(x) * g(x)
int fxg(int a, int b) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (b & (1 << i))
            result ^= xkgx(a, i);
    }

    return result;
}

int main() {
    int choice;

     cout << "1. GF(2^4)\n";
    cout << "2. GF(2^8)\n";
    cout << "Chon truong: ";
    cin>>choice;
    switch (choice) {
        case 1:
            n = 4;
            mx = 0b10011; // x^4 + x + 1
            break;  
        case 2:
            n = 8;
            mx = 0x11B;// x^8 + x^4 + x^3 + x^2 + 1
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            return 1;
    }
   cout << "Nhap a: ";
    int a;
    cin >> a;
    cout << "Nhap b: ";
    int b;
    cin >> b;
    cout << "GF(2^" << n << "): " << fxg(a, b) << '\n';
    return 0;
}

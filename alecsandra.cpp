// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n, k;
    cout << "Numar randuri (N): ";
    cin >> n;
    
    if (n < 3 || n > 100000) {
        cout << "N trebuie sa fie intre 3 si 100000!!!";
        return 0;
    }
    
    cout << "Cate dale gri (K)?: ";
    cin >> k;
    
    if (k < 1 || k > 100000) {
        cout << "K trebuie sa fie intre 1 si 100000!!!";
        return 0;
    }
    
    int gri[k];
    for (int i = 1; i <= k; i++) {
        cout << "Dala gri numarul " << i << " este: ";
        cin >> gri[i];
    }
    
    //dale gri
    for (int i = 1; i <= k; i++) {
        cout << gri[i] << "|";
    }
    cout << "\n";
    
    for (int i = 1; i <= n; i++) {
        for (int j = i*(i-1)/2+1; j <= i*(i+1)/2; j++) {
            bool exists = std::find(gri, gri + k, j) != gri + k;
            if (!exists) {
                cout << ":" << j;
            } else {
                cout << ":X";
            }
        }
        cout << "\n";
    }
    
    cout << "GATA";

    return 0;
}

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

bool exists(int k, int gri[], int val) {
    for(int i = 0; i < k; i++){
        if(gri[i] == val){
            return true;
        }
    }
    
    return false;
}

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
    
    for (int i = 1; i <= n; i++) {
        for (int j = i*(i-1)/2+1; j <= i*(i+1)/2; j++) {
            if (!exists(k, gri, j)) {
                cout << ":" << j;
            } else {
                cout << ":X";
            }
        }
        cout << "\n";
    }

    return 0;
}

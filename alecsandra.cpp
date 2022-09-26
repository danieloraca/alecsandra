#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

bool exista(int gri[], int k, int val) {
    for (int i = 1; i <= k; i++) {
        if (gri[i] == val) {
            return true;
        }
    }

    return false;
}

int max_int(int arr[], int s)
{
    int Max,temp;
    int i=0;
    temp=i;
    Max=arr[i];
    while(i < s)
    {
        if (Max < arr[i])
        {
            Max=arr[i];
            temp=i;
        }
        i++;
    }

    return temp;
}

int main() {
    int n, k;
    cout << "Numar randuri (N): ";
    cin >> n;
    
    if (n < 3 || n > 100000) {
        cout << "N trebuie sa fie intre 3 si 100000!!!" << endl;
        return 0;
    }
    
    cout << "Cate dale gri (K)?: ";
    cin >> k;
    
    if (k < 1 || k > 100000) {
        cout << "K trebuie sa fie intre 1 si 100000!!!" << endl;
        return 0;
    }
    
    int gri[k];
    for (int i = 1; i <= k; i++) {
        cout << "Dala gri numarul " << i << " este: ";
        cin >> gri[i];
    }
    
    //construieste sir dale gri
    for (int i = 1; i <= k; i++) {
        cout << gri[i] << "|";
    }
    cout << endl;
    
    int daleMax = 0;
    //afiseaza sotron
    for (int i = 1; i <= n; i++) {
        for (int j = i*(i-1)/2+1; j <= i*(i+1)/2; j++) {
            if (exista(gri, k, j)) {
                cout << ":X";
                // return 0;
            } else {
                cout << ":" << j;
            }
        }
        cout << endl;
    }

    //calcul dale max
    vector<int> vect;
    for (int i = 1; i <= n; i++) {
        int daleMaxRow = 0;
        for (int j = i*(i-1)/2+1; j <= i*(i+1)/2; j++) {
            if (exista(gri, k, j)) {
                daleMaxRow++;
            }
        }
        vect.push_back(daleMaxRow);
    }

    int maxDaleIndex = max_element(vect.begin(),vect.end()) - vect.begin();
    maxDaleIndex++; //pentru ca index incepe de la 0 iar numerotarea randurilor de la 1

    cout << "R: "
         << maxDaleIndex
         << endl;


    return 0;
}

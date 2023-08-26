#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

//bubble sort
//1. sa se ordoneze crescator elem vectorului n (nr intregi)
void bubble_sort(){
    int n, a[1005];
    cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        bool sorted = false;
        while (!sorted){
            sorted = true;
            for (int i = 1; i < n; i++){
                if (a[i] < a[i+1]){
                    swap (a[i], a[i+1]);
                    sorted = false;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
}

// sortare prin selectie
void selection_sort(){
  int n, a[1005];
  cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    } 
    for (int i = 1; i <= n; i++){ // este in fata pozitiei i
        int mini = a[i];
        int pos = i;
        for (int j = i+1; j <= n; j++){ // porneste de la urmatorul dupa i
            if (a[j] < mini){
                mini = a[j];
                pos = j;
            }
        }
        swap (a[i], a[pos]);
    }
    for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
}

 


//o functie pt a decide daca un nr e prim sau nu:
bool prim(int x){ 
    if (x <= 1){
        return false;
    }
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}


//problema 1:  sa se afiseze in ordine crescatoare valorile prime din acest vector;
void afisare_prim_cresc(){
    int n, a[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    } 
    int b[1005], k = 0;
    for (int i = 1; i <= n; i++){ // am pus intr-un vector numerele prime folosind metoda container-ului
        if (prim(a[i])){
            k++;
            b[k] = a[i];
        }
    }
    bool sorted = false;
        while (!sorted){
            sorted = true;
            for (int i = 1; i < k; i++){
                if (b[i] < b[i+1]){
                    swap (b[i], b[i+1]);
                    sorted = false;
                }
            }
        }
for (int i = 1; i <= k; i++){
        cout << b[i] << " ";
    }
}

//problema 2: Se dau inaltimile a doi copii, numerotati de la 1 la n (nr. nat).
//afisati nr de ordine ale copiilor in ordinea crescatoare a inaltimii lor.

void afisare_index(){
    int n, a[1005], pos[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pos[i] = i;
    } 
    for (int i = 1; i <= n; i++){ // este in fata pozitiei i
        int mini = a[i];
        int pos1 = i;
        for (int j = i+1; j <= n; j++){ // porneste de la urmatorul dupa i
            if (a[j] < mini){
                mini = a[j];
                pos1 = j;
            }
        }
        swap (a[i], a[pos1]);
        swap(pos[i], pos[pos1]);
    }

    for (int i = 1; i <= n; i++){
        cout << pos[i] << " ";
    }
}


int main (){





    return 0;
}
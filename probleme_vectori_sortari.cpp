#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;


bool primes (int a, int b){ // algoritm pt nr prime intre ele
    while ( b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a == 1;
}


//1: un vector cu n elem, nr nat. afisati descresc valorile din vector care sunt prime cu ultimul elem al vectorului.
void afisare_elemPrime_ultim(){
    int n, a[10005], b[10005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int k = 0;
    for (int i = 1; i <= n; i++){
        if (primes(a[i], a[n])){ // daca nr sunt prime intre ele
            k++;
            b[k] = a[i]; // le punem intr-un vector
        }
    } // sortam vectorul descrescator
    bool sorted = false;
        while (!sorted){
            sorted = true;
            for (int i = 1; i < n; i++){
                if (b[i] > b[i+1]){
                    swap (b[i], b[i+1]);
                    sorted = false;
                }
            }
        }

    for (int i = 1; i <= k; i++){
        cout << b[k] << " ";
    }
}

//2. se da un vector cu n elem nr nat si un nr k. ordonati crescator primele k elem, si descresc ultimele n-k elem.
void sort_descCresc(){
    int n, k, v[1005];
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= k; i++){
        bool sorted = false;
        while (!sorted){
            sorted = true;
            for (int i = 1; i < k; i++){
                if (v[i] > v[i+1]){
                    swap(v[i], v[i+1]);
                    sorted = false;
                }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
            }
        }
    } 
    for (int i = k + 1; i < n; i++){ 
        int maxi = v[i];
        int pos = i;
        for (int j = k + 2; j <= n; j++){
            if (v[j] > maxi){
                maxi = v[j];
                pos = j;
            }
        }
        swap (v[i], v[pos]);
    }

    for (int i = 1; i <= n; i++){
            cout << v[i] << " ";
        }
}

//2. Se dă un vector cu n elemente, numere naturale distincte. 
//Ordonați crescător elementele situate înaintea valorii maxime din vector și descr eleme situate după MAX.
//.................de verificat.............................?????
void sortare_dupa_pozMax(){
    int n, v[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int maxi = v[1], k = 1;
    for (int i = 2; i <= n; i++){
        if (v[i] > maxi){
            maxi = v[i];
            k = i;
        }
    }
    for (int i = 1; i <= k; i++){ 
        int mini = v[i];
        int pos = i;
        for (int j = i+1; j <= n; j++){
            if (v[j] < mini){
                mini = v[j];
                pos = j;
            }
        }
        swap (v[i], v[pos]);
    }
    for (int i = k+1; i < n-1; i++){ 
        int maxi = v[i];
        int pos = i;
        for (int j = i+1; j <= n; j++){
            if (v[j] > maxi){
                maxi = v[j];
                pos = j;
            }
        }
        swap (v[i], v[pos]);
    }
    for (int i = 1; i <= n; i++){
            cout << v[i] << " ";
        }
}

//Se dă un vector cu n elemente, numere naturale. 
//Afișați în ordine descrescătoare valorile divizibile cu 10 din acest vector.
void sort10(){
    int n, v[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (int i = n; i >= 1; i--){
        if (v[i] % 10 == 0){
            cout << v[i] << " ";
        }
    }
}

//Se citesc n numere naturale reprezentând înălțimile a n clădiri. 
// realiza un proiect de arhitectură în care clădirile sunt ordonate descrescător după înălțimea lor.
 void sort_descr(){
    int n, v[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++){ // am folosit selection sort
        int maxi =  v[i];
        int pos = i;
        for (int j = i+1; j <= n; j++){
            if(v[j] > maxi){
                maxi = v[j];
                pos = j;
            }
        }
        swap (v[i], v[pos]);
    }
    for (int i = 1; i <= n; i++){
            cout << v[i] << " ";
        }
 } 








int main (){
    //afisare_elemPrime_ultim();
    //sort_descCresc();
    //sortare_dupa_pozMax();
    //sort10();
    sort_descr();



    



    return 0;
}
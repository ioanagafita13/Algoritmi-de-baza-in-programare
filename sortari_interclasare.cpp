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

//INTERCLASARE : 
//problema: se dau doua siruri a si b cu n, resp m elem, nr naturale sortate crescator. 
//sa se construiasca un sir c, care sa contina in ordine crescatoare, elem din sirurile a si b.
void interclasare(){
    int n, m, a[100005], b[100005], c[200005];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int i = 1, j = 1;
    int k = 0;
    while (i <= n && j <= m){ //cat timp avem nr din amblele siruri:
        if (a[i] < b[j]){ //
            ++k;
            c[k] = a[i]; 
            ++i; // incrementam pt ca nr de la poz resp e pus deja in sirul nou, de aceea trecem la urm
        }
        else {
            ++k;
            c[k] = b[j];
            ++j;
        }
    } // dupa ce se termina while, unul dintre siruri se term primul 
    //(nu se stie care), presupunem ca poate fi oricare din ele
    while (i <= n){ 
        ++k;
        c[k] = a[i];
        ++i; // daca se continua primul, adaugam din el
    }
    while (j <= m){
        ++k;
        c[k] = b[j];
        ++j; // daca se continua al doilea, adaugam din el
    }

    for (int i = 1; i <= n + m; i++){
        cout << c[i] << " ";
        if ( i % 10 == 0){
            cout << '\n';
        }
    }
}

//MERGE SORT (se foloseste interclasarea pt a face merge sort)

int a[100005], b[100005];
void mergeSort(int left, int right){
    if (left == right){ // daca intervalul este de un sg numar-nu mai trb sortat-
        return; //nu mai facem nimic,  ne intoarcem
    }
    //in orice alt caz, impartim in doua intervale
    int middle = (left + right) / 2;
    mergeSort(left, middle); // pt prima jumatate
    mergeSort(middle + 1, right);
    int i = left, j = middle + 1; //inceputurile celor doua intervale
    int k = 0;
    while (i <= middle && j <= right){ // aici se face interclasarea
        if (a[i] < b[j]){
            b[++k] = a[i++];
        }
        else {
            b[++k] = a[j++];
        }
    }
    while (i <= middle){
        b[++k] = a[i++];
    }
    while (j <= right){
        b[++k] = a[j++];
    }
    k = 0;
    for (int i = left; i <= right; ++i){
        a[i] = b[++k];
    }
}
    

int main (){

    //pt merge sort:
    int n, a[100005];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mergeSort (1, n);
    for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
    }





    return 0;
}
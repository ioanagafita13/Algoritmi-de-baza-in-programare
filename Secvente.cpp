#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

//1.Se dă un vector format din n elemente, numere naturale. 
//Calculați suma elementelor din secvența determinată de primul și ultimul element impar.
// varianta 1:
void sum_secv_imp(){
    int n, v[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int pos1, pos2;
    for (int i = 1; i <= n; i++){ // aflam pozitia primului elem impar
        if (v[i] % 2 != 0){
            pos1 = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--){ // aflam pozitia celui de-al doilea elem impar
        if (v[i] % 2 != 0){
            pos2 = i;
            break;
        }
    }
    int suma = 0;
    for (int i = pos1; i <= pos2; i++){ //parcurgem intre cele doua pos si adunam elem
        suma += v[i];
    }
    cout << suma << '\n';
}

//varianta 2:
// int pos1 = -1, pos2 = -1;
// for (int i = 1; i <= n; i++){
//     if ( v[i] % 2 != 0){ // cand gasim un nr impar
//         if (pos1 < 0){ //daca e primul nr impar gasit
//             pos1 = i; // il updatam pe pos1 (similar folosirii lui break)
//         }
//     }
//     pos2 = i; 
//}

//problema 2: 
// Se dă un vector cu n elemente numere naturale. Determinați cea mai lungă secvență de elemente nule din vector. 
// Dacă în vector există mai multe secvențe de elemente nule de lungime maximă se va determina cea mai din stânga
//varianta 1:
void grup_nul_secv(){
    int n, v[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int maxi = 0, pos1 = -1, pos2 = -1;
    for (int i = 1; i <= n; i++){
        if (v[i] == 0){
            int p = 0;
            for (int j = i; j <= n; j++){
                if (v[j] == 0){
                    ++p;
                }
                else {
                    break;
                }
            }
            if (p > maxi){
                maxi = p;
                pos1 = i;
                pos2 = i + p - 1; // ATENTIE :in ac situatie numaram pe un exemplu pt a verifica!
            }
        // i = i + p - 1; //(se adauga aceasta linie pt varianta mai optimizata)
        }
        // nu vreau commit
    }

    cout << pos1 << pos2 << '\n';
}

//varianta 2:
// int maxi = 0, pos1 = -1, pos2 = -1;
// int l = 0;
// for (int i = 1; i <= n; ++i){
    
// }



int main(){
    sum_secv_imp();
    grup_nul_secv();
}
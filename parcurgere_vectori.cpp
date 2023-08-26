#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;


//1. se citeste un vector cu n elemente naturale. 
//sa se afiseze elem vectorului in ordinea: primul, ultimul, al doilea, penultimul

void schimba_ordine(){
    int n, v[1005];
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> v[i];
    }
    // varianta 1
    for (int i = 1; i <= n; i++){
        if (i > n-i+1){ // daca trecem de jumatate, nu mai afisam 
            break;
        }
        cout << v[i] << " ";
        if (i != n-i+1){
            cout << v[n-i+1] << " ";
        }
    }
    // varianta 2: cu while:...pe perechi
    // int i = 1, j = n;
    // while (i<=j){
    //     cout << v[i] << " ";
    //     if (j > i){
    //         cout << v[j] << " ";
    //     }
    //     ++i;
    //     --j;
    // }

}

//2. se citeste un vector cu n elemente, nr naturale distincte. sa se afiseze elementele cuprinse intre elem
// cu val min si cel cu val maxima din vector, inclusiv acestea

void afis_interval_min_max(){
    int n, v[1005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int mini = 2e9, maxi = 0;
    int pos1 = -1, pos2 = -1;
    for (int i = 1; i <= n; i++){
        if (v[i] < mini){ // gasim minimul
            mini = v[i];
            pos1 = i; // gasim pozitia lui min
        }
        if (v[i] > maxi){ // gasim maximul 
            maxi = v[i];
            pos2 = i; // gasim positia lui
        }
    }
    if (pos1 > pos2){ // nu stim daca min sau max e pe prima pozitie, 
        swap(pos1, pos2);
    }
    for (int i = pos1; i <= pos2; i++){ // intre pozitiile gasite, afisam vectorul
        cout << v[i] << " ";
    }
}

//3. Se da un vector cu n elem nr nat. sa se construiasca un alt vector y, cu n elem 
// cu propr ca y[i] este egal cu suma elem din x, cu exceptia lui x[i].

void elemente_suma(){
    int n, v[205], suma = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        suma +=v[i]; // facem suma tuturor nr din vector
    }
    int  y[205];
    for (int i = 1; i <= n; i++){
        y[i] = suma - v[i];  
    }
    for (int i = 1; i <= n; i++){
        cout << y[i] << " ";
    } 
}

//4. se da un vector x cu n elem nr naturale. 
//sa se construiasca un alt vector y, care sa contina elem impare din x, in ordine inversa.

void afisare_impare_invers(){ // exemplu metoda  !!!! "container-ului"!!!!
    int n, v[205];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int y[205], k = 1;
    for (int i = n; i >= 1; i--){ //parcurgem sirul descrescator
        if (v[i] % 2 != 0){ // daca gasim un nr impar
            y[k] = v[i]; // il punem in vect y 
            ++k; // crestem container-ul
        }
    }

    for (int i = 1; i < k; i++){
        cout << y[i] << " ";
    }

}
    




//1. sa se stearga din sirul x lementul de pe pozitia p.
void sterge_pozitie(){
    int n, p, v[1505];
    cin >> n >> p;
    for (int i=1; i<=n; i++){
        cin >> v[i];
    }
    for (int i=1; i<=n; i++){
        if(i != p){
            cout << v[i] << " ";
        }
    }
}

    //varianta 2: 
    // int x;
    // for (int i=1; i<=n; i++){
    //     cin >> x;
    //     if(i != p){
    //         cout << x << " ";
    //     }
    // }

       
//2. sa se stearga dintr-un vector elementele pare

void  sterge_pare(){
    int n, p, v[1505];
    cin >> n >> p;
    for (int i=1; i<=n; i++){
        cin >> v[i];
    }
    for(int i=1; i<=n; i++){
        if(v[i] % 2 == 0){
            for (int j = i+1; j<=n; j++){
                v[j-1] = v[j];
            }
            --n;
        }
    }


    for (int i=1; i<=n; i++){
        cout << v[i] << " ";
    }

}
    




int main(){

    //sterge_pozitie();
    //schimba_ordine();
    //afis_interval_min_max();
    afisare_impare_invers();

    return 0;
}
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

    //varianta 2: ................... fara vector propriu-zis

    // int x;
    // for (int i=1; i<=n; i++){
    //     cin >> x;
    //     if(i != p){
    //         cout << x << " ";
    //     }
    // }

    //...............varianta 3: metoda "container-ului"

    // int y[1505], k = 0;
    // for (int i = 1; i <= n; i++){
    //     if (i != p){
    //         ++k;
    //         y[k] = v[i];
    //     }
    // }
    // for (int i = 1; i <= n; i++){
    //     cout << y[i] << " ";
    // }




    //.................varianta 4: parcurgere incepand cu poza p+1
    // for (int i = p+1; i <= n; i++){
    //     v[i-1] = v[i]; //inclocuim elem de la poz p cu cel de pe poz urm 
    // }
    // --n; 



//2. sa se stearga dintr-un vector elementele pare

void  sterge_pare(){
    int n, p, v[1505];
    cin >> n >> p;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        if (v[i] % 2 == 0){
            for (int j = i+1; j <= n; j++){
                v[j-1] = v[j];
            }
            --i;
            --n;
        }
    }


    for (int i = 1; i <= n; i++){
        cout << v[i] << " ";
    }

}

//inserare element:
//problema : Să se insereze pe o poziție dată într-un șir o valoare precizată.
    // ...................varianta 1:.......afisam vectorul si cand intalneste poz p, il punem pe x
    void inserare_valoare_data(){
    int v[1505], n, x, p;
    cin >> n >> x >> p;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++){
        if (i == p){
            cout << x << " ";
        }
        cout << v[i] << " ";
    }
   } 

   //..............var 2: container-ul...............
//    int y[1005], k = 0;
//    for (int i = 1; i <= n; i++){
//         if ( i == p ){
//             ++k;
//             y[k] = x;
//         }
//         ++k;
//         y[k] = v[i];
//     }
//     for (int i = 1; i <= k; i++){
//         cout << y[k] << " ";
//     }

    //.........var 3: de la poz i+1 "mutam spre dreapta"
    // for (int i = n; i >= p; --i){
    //     v[i+1] = v[i];
    // }
    // v[p] = x;
    // ++n;

    //problema 3: sa se insereze intr-un sir dupa fiecare element par, dublul sau
    void inserare_dublu_par(){
        int n, v[55];
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++){
            if (v[i] % 2 == 0){
               for (int j = n; j >= i; j--){
                    v[j+1] = v[j];
                }
                v[i+1] = v[i] * 2;
                ++i;
                ++n;
            }
        }
        for (int i = 1; i <= n; i++){
            cout << v[i] << " ";
        }
    }

    //STERGERI
    //problema: sa se stearga dintr-un vector elementele egale cu cea mai mica val din vector.
    void sterge_minim(){
        int n, v[1000];
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        int mini = 2e9;
        for (int i = 1; i <= n; i++){
            if( v[i] < mini){
                mini = v[i];
            }
        }
        for (int i = 1; i <= n; i++){
            if (v[i] == mini){
                for (int j = i+1; j <= n; j++){
                    v[j-1] = v[j];
                }   
            --n;
            --i;         
            }
        }
        for (int i = 1; i <= n; i++){
            cout << v[i] << " ";
        }
    }
    //Se citește un șir cu n elemente, numere întregi. 
    //Să se șteargă elementele care se repetă, păstrându-se doar primul de la stânga la dreapta.
    void sterge_rep(){
        int n, v[1000];
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        for ( int i = 1; i <= n; i++){
            for ( int j = 1; j <= n; j++){
                if ( v[j] == v[i]){
                    for (int t = j+1; t <= n; t++){
                        v[t-1] = v[t];
                    }
                    --n;
                    --j;
                }
            }

        }
        for (int i = 1; i <= n; i++){
            cout << v[i] << " ";
        }
    }
    //Se dau n numere întregi. Să se insereze 
    //între oricare două numere de aceeași paritate media lor aritmetică.

    void inserare_medie_aritm(){
        int n, v[205];
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++){
            if (abs(v[i]) % 2 == abs(v[i+1]) % 2){
                for ( int j = n; j >= i+1; j++){
                    v[j+1] = v[j];
                }
                v[i+1] = (v[i] + v[i+2]) / 2;
                n++;
                i++;
            }
        } 

        for (int i = 1; i <= n; i++){
            cout << v[i] << " ";
        }
    }




       

    



int main(){

    //sterge_pozitie();
    //schimba_ordine();
    //afis_interval_min_max();
    //afisare_impare_invers();
    //inserare_dublu_par();
    //sterge_minim();


    return 0;
}
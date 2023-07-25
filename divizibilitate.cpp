#include <iostream>
#include <iomanip> // pt input, output manipulation
#include <cmath>
using namespace std;



//probleme rezolvate deja:
//NUMERE PRIME:
bool prim(){ //pornim de la premisa ca numarul cautat este prim (se divide doar cu 1 si el insusi)
    int x;
    cin >> x;
    bool ok = true;
    if (x <= 1){
        ok = false; //daca nr este 0 sau 1, nu este prim pt ca se divide cu 1;
    }
    for (int i = 2; i <= x; i++){
        if (x % i == 0){ //daca are un divizor
            ok = false; // nu este prim
            break; // oprim bucla pt ca a gasit un divizor, deci am aflat deja ca nu este prim
        }
    }
    if (ok){
        cout << "numarul este prim";
    }
    else {
        cout << " numarul nu este prim";
    }
    return ok;
}

//SUMA DIVIZORILOR UNUI NR:
void suma_divizorilor(){
    long long n;
    cin >> n;
    if (n <= 1){
        cout << n << '\n';
    }
    long long sum = 0;
    for (long long i = 1; i * i <= n; i++){
        if (n % i == 0){
            sum += i; // daca gasim un divizor, il adaugam la suma
            if ( i != n / i){ //cazul unui patrat perfect, pt a nu adauga un divizor care se repeta decat o sg data
                sum += n / i; //adaugam si perechea lui i
            }
        }
    }
    cout << sum << '\n';
}

//CEL MAI MARE DIVIZOR COMUN (CMMDC) - se bazeaza pe logica : cmmdc(x, y) = cmmdc(x, y-x) (trb ca x <= y)
void cmmdc(){
    int x, y;
    cin >> x >> y; // exista functia __gcd(x1, x2) = in biblioteca alghoritm
    while ( x != 0 && y != 0){
        if (x > y){
            x %= y; 
        }
        else {
            y %= x;
        }
    }
    if (!x){
        cout << y << '\n';
    }
    else {
        cout << x << '\n'; /// aici se face interschimbare intre x si y
    }
    // algoritmul cel mai folosit pt cmmdc:
    // while (y){
    //     int r = x % y;
    //     x = y;
    //     y = r;
    // }
    // cout << x << '\n';

// CMMMC intre x si y este : x * y / CMMDC

}

//TEMA:
// 1.De fiecare dată când Bubu primește un zece la informatică, numărul de bomboane din prima cutie crește cu a,
//  iar de fiecare dată când primește un zece la matematică numărul de bomboane din a doua cutie crește cu b. 
//  Care este numărul minim de note de zece necesar pentru ca numărul de bomboane din cele două cutii să devină egal?
void minim_note(){
    int a, b, nr_de_note = 0;
    cin >> a >> b;
    if (a < b)
        nr_de_note += b - a;
    else
        nr_de_note += a - b;
    cout << nr_de_note;
}

// 2.Se citește un număr natural n. Să se determine suma divizorilor impari ai săi.
void suma_div_impari(){
    long long n, sum_div_odd = 1; // initializam suma cu 1 pt ca 1 este primul divizor impar
    cin >> n;
    if (n %2 == 1 && n != 1) // acoperim cazul cand numarul este impar si diferit de 1 (adaugam la suma pe el insusi)
        sum_div_odd += n;
        for (long long i = 2; i * i <= n; i++){ 
            if (n % i == 0){
                if ( i%2 == 1) // punem conditia ca divizorii gasiti sa fie impari
                    sum_div_odd += i; //ii adaugam la suma
                if (i != n/i && n/i % 2 == 1){ // acoperim situatia in care avem patrat si in acelasi timp verificam daca numarul resp este impar
                    sum_div_odd += n/i; //adaugam la suma
                }
            }
        }
    cout << sum_div_odd;
}

// 3. Se citește un număr natural n. Să se determine suma divizorilor pari ai săi. 
void suma_div_pari (){
    long long n, sum_div_even = 0;
    cin >> n;
    if (n %2 == 0) // acoperim cazul cand numarul este par (il adaugam pe el insusi la suma)
        sum_div_even += n;
    for (long long i = 2; i * i <= n; i++){
        if (n % i == 0){
            if (i % 2 == 0)
                sum_div_even += i;
            if (i != n/i && n/i % 2 == 0){
                sum_div_even += n/i;
            }
        }
    }
cout << sum_div_even;
}

// 4. Se citește un număr natural n. Să se determine câți divizori pari are acest număr.
void even_div_number (){
    long long n, div_number = 0;
    cin >> n;
    if (n % 2 == 0)
        div_number ++;
    for (long long i = 2; i * i <= n; i++){
        if (n % i == 0){
            if (i % 2 == 0){
                div_number++;
            }
            if (i != n/i && n/i % 2 == 0){
                div_number++;
            }
        }
    }
cout << div_number;
}

// 5. Se citeşte de la tastatură un număr natural n. 
//Să se calculeze şi să se afişeze media aritmetică a tuturor divizorilor săi. Media va fi cu fix 2 zecimale dupa virgula.
void medie_div(){
   long long n, nr_div = 0; 
   cin >> n;
   if (n <= 1){
        cout << n << '\n';
        return;
   }
   float sum = 0;
    for (long long i = 1; i * i <= n; i++){
        if (n % i == 0){
            sum += i;
            nr_div++;
            if (i != n/i){
                sum += n/i;
                nr_div++;
            }
        }
   }
cout << fixed << setprecision(2) <<sum/nr_div; // "setprecision" este din biblioteca <iomanip>
}

// 6. Se dă un număr natural n. Calculați pătratul celui mai mic divizor propriu al său.
void patrat_divizor(){
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++){ // de la 2 pt ca div proprii sunt cei diferiti de 1 si numarul insusi
        if (n % i == 0){
            cout << i * i;
            break;
        }
    }
}

// 7. Se dă un număr natural n. Calculați suma dintre cei mai mici doi divizori proprii ai lui n.
void suma_div_proprii(){
    int n, suma_div_proprii = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            suma_div_proprii += i ;// am reusit sa pun doar primul divizor...
            break;
        }
    }
}

//8.Se dă un număr natural n. Calculați suma dintre cel mai mic și cel mai mare divizor propriu al lui n.
void suma_min_max(){
    int n, div_min = 0, div_max = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            div_min = i;
            div_max = n/i;
            break;
        }
    }
    cout << div_min + div_max;
}





               ////////////////pb instructiuni repetitive///////////////////


//1.Se dă un număr natural n. Afișați pe o linie primele n numere naturale nenule în ordine crescătoare, 
//iar pe linia următoare aceleași numere, dar în ordine descrescătoare.
void afisare_cresc_descresc(){
    int n;
    cin >> n;
        for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
                cout << '\n';
        for (int i = n; i >= 1; i--)
            {
                cout << i << " ";
            }
}

//2.Se dă un număr natural n. Afișați în ordine descrescătoare primele n numere naturale impare.
void descr_odd(){
    int n;
    cin >> n;
    for (int i = 2 * n - 1; i >= 1; i--){ // de ce pana la 2*n-1 ??
        if (i % 2 == 1){
            cout << i << " ";
        }
    }
}

//3. Se dă un număr natural n. Afișați în ordine descrescătoare numerele naturale impare mai mici sau egale cu n
void descr_odd_n(){
    int n;
    cin >> n;
    for ( int i = n; i >= 1; i--){
        if (i % 2 == 1){
            cout << i << " ";
        }
    }
}

//4.Se dă n. Să se afișeze 10 ^ n.
void p10(){
    long long n;
    cin >> n;
    cout << pow (10, n); // afiseaza rezultat de tip 1e+6
}


int main(){
    //minim_note();
    //suma_div_impari();
    //suma_div_pari();
    //even_div_number();
    //medie_div();
    //patrat_divizor();
    //suma_div_proprii();



    //afisare_cresc_descresc();
    //descr_odd();
    //descr_odd_n();
    //p10();
    suma_min_max();








    

}
#pragma once
#include "Stiva.h"
#include "Coada.h"

using namespace std;

Coada<int> coada;
Stiva<int> stiva;


/*#986
Se dă un șir cu n elemente, numere reale. Să se determine câte dintre elemente se află în afara intervalului închis
determinat de primul și ultimul element.
Ex:
6
2 0 4 -1 -8 -3 se afiseaza 2
*/
void solutia1() {

	int dim = 6;
	int v[100] = { 2, 0, 4, -1, -8, -3 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	cout << coada.ctIntervalAfara(dim);
}

/*#498
Se dă un vector cu n numere naturale. Să se determine câte dintre perechile de elemente din vector sunt prime între ele.
Ex:
6
51 18 15 28 77 121 se afiseaza 9
*/
void solutia2() {

	int dim = 6;
	int v[100] = { 51, 18, 15, 28, 77, 121 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	cout << stiva.ctPerechiPrime(dim);

}

/*#99
Se dă un șir cu n elemente numere naturale. Să se determine câte elemente din şir sunt egale cu ultimul element al acestuia.
Ex:5
5 3 2 4 5
se afiseaza 2
*/
void solutia3() {

	int dim = 5;
	int v[100] = { 5, 3 ,2, 4 ,5 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	cout << coada.ctEgalUiltim(dim);
}

/*#100
Se dă un șir cu n elemente numere naturale. Să se determine câte elemente din şir sunt numere prime.
Ex:
5
25 17 2 10 13
se afiseaza 3
*/
void solutia4() {

	int dim = 5;
	int v[100] = { 25, 17, 2, 10, 13 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	cout << stiva.ctNrPrime(dim);
}

/*#132
Să se afișeze elementele din șir care au proprietatea că primele două cifre din scrierea zecimală formează un pătrat perfect.
Ex:
5
253 16 225 100 3678
se afiseaza 253 16 3678
*/
void solutia5() {

	int dim = 5;
	int v[100] = { 253, 16, 225 ,100, 3678 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.afisarePatratPerf(dim);
}

/*#82
Calculaţi valoarea minima minim si valoarea maxima maxim a celor n numere date.
Ex:
5
8 2 9 4 5
se afiseaza 2 9*/
void solutia6() {

	int dim = 5;
	int v[100] = { 8, 2, 9, 4, 5 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);
	cout << stiva.mini(dim) << " " << stiva.maxi(dim);
}

/*#237
Se dă un şir cu n numere naturale. Să se afişeze suma primilor n termeni din şir, apoi suma
primilor n-1 termeni din şir, şi aşa mai departe.
Ex:
4
1 7 3 4
se afiseaza
15
11
8
1
*/
void solutia7() {

	int dim = 4;
	int v[100] = { 1, 7, 3, 4 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.afisareSumele(dim);

}

/*
#1452
Să se șteargă din șirul X elementul aflat pe poziția p.
ex:
5 2
7 3 9 1 6
se afiseaza 7 9 1 6*/
void solutia8() {

	int dim = 5, poz = 2;
	int v[100] = { 7 ,3, 9, 1, 6 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.stergerePoz(poz - 1);
	coada.afisare();
}

/*
#1453
Se dă un vector cu n elemente numere naturale. Să se șteargă din vector toate elementele pare.
Ex:
7
7 9 4 2 1 6 5
se afiseaza
7 9 1 5*/
void solutia9() {

	int dim = 7;
	int v[100] = { 7, 9, 4, 2, 1, 6, 5 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.stergerePare(dim);
	coada.afisare();
}

/*#163
Se dă un vector cu n elemente numere naturale. Să se șteargă din vector toate elementele care sunt numere prime.
Ex:
5
7 8 9 17 1
se afiseaza
8 9 1
*/
void solutia10() {

	int dim = 5;
	int v[100] = {1,17,9,8,7};
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);
	stiva.stergereaPrime(dim);
	stiva.afisare();
}

/*#4386
Se dă un vector cu n elemente numere naturale. Să se transforme vectorul, duplicând fiecare apariție a valorii minime.
Ex:
7
7 9 4 2 1 6 1
se afiseaza
7 9 4 2 1 1 6 1 1
*/
void solutia11() {

	int dim = 7;
	int v[100] = { 1,6,1,2,4,9,7 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);
	stiva.inserareMini(dim, stiva.mini(dim));
	stiva.afisare();
}

/*
#4385
Se dă un vector cu n elemente numere naturale. Să se șteargă din vector toate elementele
egale cu cea mai mică valoare din vector.
Ex:
7
7 1 4 2 1 6 1
se afiseaza
7 4 2 6*/
void solutia12() {

	int dim = 7;
	int v[100] = { 1,6,1,2,4,1,7 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	stiva.stergereEgaleMini(dim, stiva.mini(dim));
	stiva.afisare();
}

/*Se citește un vector cu n elemente, numere naturale. Să se afișeze elementele vectorului în următoarea
ordine: primul, ultimul, al doilea, penultimul, etc.
Ex:
5
2 9 1 5 8 se afiseaza 2 8 9 5 1
*/
void solutia13() {

	int dim = 5, v[100] = { 2, 9, 1, 5, 8 };

	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.afisarePrimUltim(dim);
}

/*#158
 Se dă un șir cu n elemente întregi, valoare întreagă X și un număr p.
Să se insereze pe poziția p în șir valoarea X.
Ex:
5 10 2
7 3 9 1 6
se afiseaza
7 10 3 9 1 6*/
void solutia14() {

	int dim = 5, poz = 2, nr = 10;
	int v[100] = { 7, 3, 9 ,1, 6 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.addPoz(nr, poz - 1);
	coada.afisare();
}

/*
#159
Să se insereze în șir după fiecare element par dublul său.
Ex:
5
7 3 4 1 6
se afiseaza
7 3 4 8 1 6 12
*/
void solutia15() {

	int dim = 5, poz = 2, nr = 10;
	int v[100] = { 6,1,4,3,7 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	stiva.addDublu(dim);
	stiva.afisare();


}

/*
#160
Să se insereze în șir înaintea fiecărui element pătrat perfect rădăcina sa pătrată.
Ex:
5
7 3 4 1 5
se afiseaza
7 3 2 4 1 1 5
*/
void solutia16() {

	int dim = 5, poz = 2, nr = 10;
	int v[100] = { 7 ,3 ,4, 1 ,5 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.inserareRadacina(dim);
	coada.afisare();
}

/*#1550
Se da un vector cu n elemente. Sa se afișeze pe ecran elementele din vector care divid factorialul numărului de elemente n.
Ex:
5
16 3 71 30 25
se afiseaza 3 30
*/
void solutia17() {

	int dim = 5;
	int v[100] = { 16, 3, 71, 30, 25 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	stiva.afisareFactorial(dim);
}

/*#162
Se dă un vector cu n elemente numere naturale. Determinați toate permutările circulare spre stânga ale vectorului.
Ex:
5
7 2 8 4 5
se afiseaza
7 2 8 4 5
2 8 4 5 7
8 4 5 7 2
4 5 7 2 8
5 7 2 8 4*/
void solutia18() {

	int dim = 5;
	int v[100] = { 7, 2,8, 4, 5 };
	for (int i = 0; i < dim; i++)
		coada.enqueue(v[i]);

	coada.afisarePermutari(dim);
}

/*
#289
Se dă un şir cu n elemente, numere naturale. Să se verifice dacă în şir există elemente impare.
Ex:
5
2 8 6 10 8
se afiseaza 0
*/
void solutia19() {

	int dim = 5;
	int v[100] = { 2, 8, 6 ,10, 8 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	cout << stiva.verificareImpare(dim);
}

/*
#506
Se dă un şir cu n elemente, numere naturale. Să se verifice dacă în şir există elemente prime.
Ex:
5
21 8 6 10 8
se afiseaza 0
*/
void solutia20() {

	int dim = 5;
	int v[100] = { 21, 5 ,6 ,10, 8 };
	for (int i = 0; i < dim; i++)
		stiva.push(v[i]);

	cout << stiva.verificarePrime(dim);

}


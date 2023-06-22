#pragma once
#include "Node.h"

template<typename T>

struct Stiva {

private:

	Node<T>* head = NULL;

public:

	void push(T data) {

		if (head == NULL) {
			head = new Node<T>();
			head->setNext(NULL);
			head->setData(data);

		}
		else {

			Node<T>* nou = new Node<T>();
			nou->setNext(head);
			nou->setData(data);
			head = nou;


		}

	}

	int peek() {

		return head->getData();

	}

	int pop() {

		head = head->getNext();
		return head->getData();

	}

	bool contains(T data) {

		Node<int>* aux = head;

		while (aux != NULL)
		{
			if (aux->getData() == data) return true;

			aux = aux->getNext();
		}

		return false;
	}

	void clear() {


		while (head != NULL)
		{
			head = head->getNext();
		}

	}

	int divizorComun(int n, int m) {

		while (m != 0)
		{
			int r = n % m;
			n = m;
			m = r;
		}

		return n;
	}

	int ctPerechiPrime(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			int n, m;
			n = aux->getData();
			Node<T>* nou = head;
			for (int j = 0; j < dim; j++) {
				m = nou->getData();
				if (divizorComun(n, m) == 1) ct++;
				nou = nou->getNext();
			}

			aux = aux->getNext();
		}

		return ct / 2;
	}

	bool prim(int nr) {

		if (nr == 0 || nr == 1)
			return false;

		for (int i = 2; i <= nr / 2; i++)
			if (nr % i == 0)
				return false;

		return true;
	}

	int ctNrPrime(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (prim(aux->getData()))
				ct++;

			aux = aux->getNext();
		}

		return ct;


	}

	int maxi(int dim) {
		Node<T>* aux = head;
		int maxi = -1;

		for (int i = 0; i < dim; i++) {

			if (aux->getData() > maxi)
				maxi = aux->getData();

			aux = aux->getNext();
		}

		return maxi;
	}

	int mini(int dim) {
		Node<T>* aux = head;
		int mini = 99999;

		for (int i = 0; i < dim; i++) {

			if (aux->getData() < mini)
				mini = aux->getData();

			aux = aux->getNext();
		}

		return mini;
	}

	void afisare() {

		Node<T>* aux = head;

		while (aux != NULL)
		{

			cout << aux->getData() << " ";
			aux = aux->getNext();

		}

	}

	void stergereaPrimElement() {

		head = head->getNext();

	}

	void stergereUltim() {

		Node<T>* aux = head;

		while (aux->getNext()->getNext() != NULL)
		{
			aux = aux->getNext();
		}

		aux->setNext(NULL);

	}

	void stergerePoz(int poz) {

		Node<T>* aux = head;

		int ct = 0;

		if (poz == 0) {
			stergereaPrimElement();
			return;
		}

		while (ct < poz - 1)
		{
			aux = aux->getNext();
			ct++;
		}

		if (aux->getNext() == NULL) {
			stergereUltim();
			return;
		}

		aux->setNext(aux->getNext()->getNext());

	}

	void stergereaPrime(int dim) {

		Node<T>* aux = head;
		for (int i = 0; i < dim; i++) {

			if (prim(aux->getData())) {
				dim--;
				stergerePoz(i);
				aux = head;
			}

			aux = aux->getNext();

		}




	}

	void addEnd(int nr) {

		if (head == NULL) {

			head = new Node<T>();

			head->setNext(NULL);
			head->setData(nr);
		}
		else {


			Node<T>* aux = head;

			while (aux->getNext() != NULL) {

				aux = aux->getNext();
			}


			Node<T>* nou = new Node<T>();

			nou->setNext(NULL);
			nou->setData(nr);
			aux->setNext(nou);

		}


	}

	void addPoz(int nr, int poz) {


		if (head == NULL) {

			head = new Node<T>();

			head->setNext(NULL);
			head->setData(nr);
		}
		else
		{

			Node<T>* aux = head;

			int ct = 0;

			if (poz == 0) {
				push(nr);
				return;
			}

			while (ct < poz - 1)
			{

				aux = aux->getNext();
				ct++;
			}

			if (aux->getNext() == NULL) {

				addEnd(nr);
				return;
			}

			Node<T>* nou = new Node<T>();
			nou->setNext(aux->getNext());
			nou->setData(nr);
			aux->setNext(nou);

		}


	}

	void addDublu(int dim) {

		Node<T>* aux = head;
		for (int i = 0; i < dim; i++) {

			if (aux->getData() % 2 == 0) {
				addPoz(aux->getData() * 2, i);
				aux = head;
			}

			aux = aux->getNext();

		}



	}

	void setPoz(int poz, int nr) {
		Node<T>* aux = head;
		int ct = 0;
		while (ct < poz)
		{
			aux = aux->getNext();
			ct++;
		}

		aux->setData(nr);


	}

	void inserareMini(int dim, int mini) {

		Node<T>* aux = head;
		for (int i = 0; i < dim; i++) {

			if (aux->getData() == mini) {
				setPoz(i - 1, mini);
			}

			aux = aux->getNext();

		}

	}

	void stergereEgaleMini(int dim, int mini) {

		Node<T>* aux = head;
		for (int i = 0; i < dim; i++) {

			if (aux->getData() == mini) {
				dim--;
				stergerePoz(i);
				i = 0;
				aux = head;
			}

			aux = aux->getNext();

		}



	}

};
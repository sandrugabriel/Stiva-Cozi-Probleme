#pragma once
#include "Node.h"

template<typename T>

struct Coada
{

private:
	Node<T>* head = NULL;

public:

	Node<T>* getHead() {
		return head;
	}

	void enqueue(T data) {

		if (head == NULL) {
			head = new Node<T>();
			head->setNext(NULL);
			head->setData(data);

		}
		else
		{
			Node<T>* nou = new Node<T>();
			Node<T>* aux = head;

			while (aux->getNext() != NULL)
			{

				aux = aux->getNext();

			}

			nou->setData(data);
			nou->setNext(NULL);
			aux->setNext(nou);

		}

	}

	int dequeue() {

		Node<T>* aux = head;

		while (aux->getNext()->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		int nr = aux->getNext()->getData();
		aux->setNext(NULL);
		return nr;
	}

	int peek() {

		Node<T>* aux = head;

		while (aux->getNext() != NULL)
		{
			aux = aux->getNext();
		}

		return aux->getData();
	}

	bool contains(T data) {

		Node<T>* aux = head;

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

	void afisare() {

		Node<T>* aux = head;

		while (aux != NULL)
		{

			cout << aux->getData() << " ";
			aux = aux->getNext();

		}

	}

	int getUltimulNr(int dim) {

		Node<T>* aux = head;

		for (int i = 0; i < dim - 1; i++)
			aux = aux->getNext();

		return aux->getData();
	}

	int ctIntervalAfara(int dim) {

		Node<T>* aux = head;

		int ct = 0;
		int ultim = getUltimulNr(dim);
		int primul = aux->getData();
		for (int i = 0; i < dim; i++) {
			if (aux->getData() < primul && aux->getData() > ultim)
				ct++;

			aux = aux->getNext();
		}

		return ct;
	}

	int ctEgalUiltim(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (aux->getData() == getUltimulNr(dim))
				ct++;

			aux = aux->getNext();
		}

		return ct;

	}

	int ctNr(int nr) {
		int ct = 0;
		while (nr != 0)
		{
			ct++;
			nr /= 10;
		}
		return ct;
	}

	bool verifPatratPerfect(int nr) {

		int ctnr = ctNr(nr);
		if (ctnr > 2) {
			nr = nr / pow(10, ctnr - 2);
		}

		if (sqrt(nr) == (int)sqrt(nr))
			return true;

		return false;
	}

	void afisarePatratPerf(int dim) {

		Node<T>* aux = head;

		int ct = 0;

		for (int i = 0; i < dim; i++) {
			if (verifPatratPerfect(aux->getData()))
				cout << aux->getData() << " ";


			aux = aux->getNext();
		}


	}

	void afisareSumele(int dim) {

		int ct = dim;
		while (ct >= 1)
		{

			Node<T>* aux = head;
			int s = 0;
			for (int i = 0; i < ct; i++) {

				s += aux->getData();
				aux = aux->getNext();
			}
			cout << s << endl;

			ct--;
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

	void stergerePare(int dim) {

		Node<T>* aux = head;
		for (int i = 0; i < dim; i++) {

			if (aux->getData() % 2 == 0) {
				dim--;
				i--;
				stergerePoz(i);
				aux = head;
			}

			aux = aux->getNext();

		}

	}

};
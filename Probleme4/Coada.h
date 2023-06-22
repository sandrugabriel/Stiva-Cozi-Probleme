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

};
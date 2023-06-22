#pragma once
#include "Node.h"


template<typename T>

struct Stiva
{

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

};
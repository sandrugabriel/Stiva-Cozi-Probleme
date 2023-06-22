#pragma once
#include <iostream>


using namespace std;

template<typename T>

struct Node {

private:
	Node<T>* next;

	T data;


public:

	Node() {

	}

	Node* getNext() {
		return next;
	}

	void setNext(Node* n) {
		next = n;
	}

	T getData() {
		return data;
	}

	void setData(T data1) {
		data = data1;
	}

};




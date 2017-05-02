#pragma once

#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class mStack {

	struct Node {
		T val;
		unique_ptr<Node> next;

		Node(const T& _val, unique_ptr<Node> _next = nullptr)
			: val(_val), next(move(_next)) {};
	};

	unique_ptr<Node> head;

public:
	mStack() : head(nullptr) {};


	inline T& top() {
		if (head == nullptr) throw out_of_range(nullptr);
		return head->val;
	}

	inline void pop() {
		if (head == nullptr) throw out_of_range(nullptr);
		Node* next = head->next.release();
		head.reset(next);
	}

	inline bool empty() const {
		if (head == nullptr)
			return true;
		return false;
	}

	inline void push(const T& val) {
		if (head == nullptr) head = make_unique<Node>(val);
		else
		{
			auto item = make_unique<Node>(val, move(head));
			head = move(item);
		}
	}
};
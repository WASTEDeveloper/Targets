#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class ArrayOfItems;
class IntToSort;
class Item;

class Item {
public:
	virtual bool operator<(const Item&) const = 0;
	virtual void showItem() const = 0;
	virtual void swap(Item&) = 0;
};

class IntToSort : public Item
{
	int value;
public:
	IntToSort(int i = 0): value(i) {};
	inline bool operator<(const Item& i) const override {
		return value < static_cast<const IntToSort&>(i).value;
	}
	inline bool operator==(const Item& i) const {
		return value == static_cast<const IntToSort&>(i).value;
	}
	inline void swap(Item& i) {
		auto temp = value;
		auto& it = static_cast<IntToSort&>(i);
		value = it.value;
		it.value = temp;
	}
	inline void showItem() const override {
		cout << value << " ";
	}
};




class ArrayOfItems {
public:
	virtual Item& operator[](int) = 0;
	virtual size_t size() const = 0;
	virtual void fill() = 0;
	virtual void show() const = 0;

};

class ArrayOfInt : public ArrayOfItems {
	vector<IntToSort> arrayToSort;
public:
	ArrayOfInt() {}
	ArrayOfInt(initializer_list<IntToSort> in_list) : arrayToSort{ in_list } {}
	ArrayOfInt(int size) : arrayToSort(size) {}

	void fill() override;
	bool operator==(const ArrayOfInt& arr) const;
	inline Item& operator[](int i) override {
		return static_cast<Item&>(arrayToSort[i]);
	}
	inline void show() const override {
		for (auto& item : arrayToSort) item.showItem();
	}
	inline size_t size() const override {
		return arrayToSort.size();
	}
};




class SortPack {

	ArrayOfItems * items;

	void quick_sort(int l, int r);
public:
	SortPack() {};
	void bubble();
	void insert();
	void quick();
	void select();
	void shell();

	inline void attach(ArrayOfItems& _items) {
		items = &_items;
	}
	inline ArrayOfItems& get_items() {
		return *items;
	}
	inline void show() const {
		items->show();
	}
};
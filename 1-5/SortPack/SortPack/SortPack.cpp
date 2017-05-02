#include "SortPack.h"

void SortPack::bubble() {
	for (int i = (*items).size() - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if ((*items)[j + 1] < (*items)[j])
				(*items)[j].swap((*items)[j + 1]);
}

void SortPack::insert() {
	for (int i = 1; i <  (*items).size(); i++) {
		int j = i;
		while (j>0 && (*items)[j] <  (*items)[j - 1]) {
			(*items)[j].swap((*items)[j - 1]);
			j--;
		}
	}
};

void SortPack::quick_sort(int l, int r) {
	int i = l;
	int j = r;
	int pivot = (l + r) / 2;
	while (i <= j) {
		while ((*items)[i] <  (*items)[pivot]) i++;
		while ((*items)[pivot] <  (*items)[j]) j--;
		if (i <= j) {
			if (i == pivot) pivot = j; else
				if (j == pivot) pivot = i;
			(*items)[i].swap((*items)[j]);
			i++;
			j--;
		}
	}
	if (l < j) quick_sort(l, j);
	if (i < r) quick_sort(i, r);
}

void SortPack::quick()
{
	quick_sort(0, items->size() - 1);
}

void SortPack::select() {
	for (int i = 0; i < (*items).size(); i++) {
		int min_value_index = i;
		for (int j = i + 1; j < (*items).size(); j++)
			if ((*items)[j] <  (*items)[min_value_index]) min_value_index = j;
		(*items)[i].swap((*items)[min_value_index]);
	}
};

void SortPack::shell() {
	int size = (*items).size();
	int step = size / 2;
	while (step > 0) {
		for (int i = step; i < size; i++) {
			for (int j = i; j >= step; j -= step) {
				if ((*items)[j] <  (*items)[j - step]) (*items)[j].swap((*items)[j - step]);
				else break;
			}
		}
		step /= 2;
	}
};

void ArrayOfInt::fill()
{
	mt19937 gen{ std::random_device()() };
	uniform_int_distribution<int> uid(0, 100);
	std::generate(arrayToSort.begin(), arrayToSort.begin() + arrayToSort.size(), [&uid, &gen]() -> int
	{ return uid(gen); });
}

inline bool ArrayOfInt::operator==(const ArrayOfInt & arr) const
{
	if (size() != arr.size()) return false;
	for (size_t i = 0; i < size(); ++i)
	{
		using namespace std::rel_ops;
		if (arrayToSort[i] != arr.arrayToSort[i])
			return false;
	}
	return true;
}


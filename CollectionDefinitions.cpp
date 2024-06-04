// Charlie's collection
// Dylan Strnad
// 4/18/2024


#include "collection.h"
#include <iostream>
using namespace std;

Collection::Collection() {
	size_ = 0;
	col_ = nullptr;
}
	

int Collection::check(double num) {
	for (int i = 0; i < size_; ++i) {
		if (col_[i] == num) {
			//cout << "duplicate!" << endl;
			return i;
		}
	}
	return -1;
}

void Collection::addNumber(double num) {
	for (int i = 0; i < size_; ++i) {
		if (col_[i] == num)
			return;
	}
	
	double* newcolPtr = new double[size_ + 1];
	
	for (int i = 0; i < size_; ++i) {
		newcolPtr[i] = col_[i];  // copy array elements into new array
	}

	newcolPtr[size_] = num; // adds new numbers
	delete[] col_;
	col_ = newcolPtr;
	++size_;
		
}

void Collection::removeNumber(double num) {
	bool found = false;
	double* newcolPtr = new double[size_];
	for (int i = 0; i < size_; ++i) {
		if (col_[i] == num) {
			found = true;
		}
		else {
			if (found == false) {
				newcolPtr[i] = col_[i];

			}
			else {
				newcolPtr[i - 1] = col_[i];
			}
		}

	}

	if (found == true) {
		--size_;
	}
	if (found == false) {
		cout << "number not present!" << endl; // if number is not located
	}
	delete[] col_;

	col_ = newcolPtr;
}

void Collection :: output() const {
	for (int i = 0; i < size_; ++i)
		cout << col_[i] << ",";
	cout << endl;
}

double Collection::value() const {
	double total = 0;

	for (int i = 0; i < size_; ++i)
		total += col_[i];

	return total;
}

Collection :: ~Collection() {
	delete[] col_;
}

Collection::Collection(const Collection& obj) {
	size_ = obj.size_;
	col_ = new double[size_];
	for (int i = 0; i < size_; ++i) 
		col_[i] = obj.col_[i];
}


const Collection& Collection :: operator= (const Collection& obj) {
	if (this != &obj) {
		delete[] col_;
		size_ = obj.size_;
		col_ = new double[size_];
		for (int i = 0; i < size_; ++i) 
			col_[i] = obj.col_[i];
	}
	return *this;
	
}

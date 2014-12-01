/*
 * Quicksoet.cc
 *
 *  Created on: Nov 24, 2014
 *      Author: carl
 */

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

const size_t WIDTH = 100;

void mergesort(int *a, size_t size) {
	int key = a[0];
	size_t i = 0, j= 1;
	if(size > 1) {
		while(j < size) {
			if(a[j] > key) ++j;
			else {
				int t = a[i+1];
				a[i+1] = a[j];
				a[j] = t;
				++j; ++i;
			}
		}
		a[0] = a[i];
		a[i] = key;
		mergesort(a, i);
		mergesort(a+i+1, size-i-1);
	}
}

void gen_random(int *a, size_t size) {
	for(size_t i=0;i<size;++i) {
		*(a+i) = random()/10000000;
	}
}

void display(int *a, size_t size) {
	for(size_t i=0;i<size;++i) {
		cout << *(a+i) << "\t";
	}
	cout << endl;
}

int main() {
	int *data = NULL;
	data = new int[WIDTH];
	gen_random(data, WIDTH);
	cout << "Before Sort:" << endl;
	display(data, WIDTH);
	mergesort(data, WIDTH);
	cout << "After Sort:" << endl;
	display(data, WIDTH);
	delete [] data;
}

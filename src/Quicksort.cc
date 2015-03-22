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

static int count = 0;

const size_t WIDTH = 100;

void quicksort(int *a, size_t size) {
	int key = a[size - 1];
	size_t i = 0, j= 0;
	if(size > 1) {
		for(i=0,j=0;j < size - 1;++j) {
			if(a[j] < key) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				++i;
			}
			count++;
		}
		a[size-1] = a[i];
		a[i] = key;
		quicksort(a, i);
		quicksort(a+i+1, size-i-1);
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
	quicksort(data, WIDTH);
	cout << "After Sort:" << count << endl;
	display(data, WIDTH);
	delete [] data;
}

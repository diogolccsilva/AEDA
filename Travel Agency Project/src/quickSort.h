/*
 * quickSort.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: Diogo
 */

#include <vector>
using namespace std;

template <class Comparable>
int PARTITION(vector<Comparable> &v, int p, int r) {
	Comparable x = v[r];
	int i = p-1;
	for (int j= p;j<=r-1;j++){
		if (v[j] <= x){
			i = i+1;
			Comparable temp=v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	Comparable temp=v[i+1];
	v[i+1] = v[r];
	v[r] = temp;
	return i+1;
}

template <class Comparable>
void QUICKSORT(vector<Comparable> &v, int p, int r){
	int q=0;
	if (p < r){
		q = PARTITION(v, p, r);
		QUICKSORT(v, p, q-1);
		QUICKSORT(v, q+1, r);
	}
}



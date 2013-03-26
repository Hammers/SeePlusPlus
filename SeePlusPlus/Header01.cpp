#include <iostream>
#include "Header01.h"
using namespace std;

void a(void){
	cout << "\n function a" << endl;
}

int b(char x, int y){
	cout << "\n function b" << "\n char= " << x
		<< "\n int= " << y << endl;
	return y;
}

char c(float x, float y){
	cout << "\n function c" << "\n float= " << x
		<< "\n float= " << y << endl;
	return 'a';
}
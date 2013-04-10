#include "Hen.h"
#include <iostream>
using namespace std;

void Hen::display(){
	cout << "HEN" << endl;
}

void Hen::Nest::display(){
	cout << "NEST" << endl;
}

void Hen::Nest::Egg::display(){
	cout << "EGG" << endl;
}

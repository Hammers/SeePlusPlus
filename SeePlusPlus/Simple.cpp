#include "Simple.h"
#include <iostream>
using namespace std;

Simple::Simple(int input){
	cout << "Simple created: "<< i << endl;
	i = input;
};

Simple::~Simple(){
	cout << "Simple destroyed: "<< i << endl;
}
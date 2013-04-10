#include "Struct.h"
#include <iostream>
using namespace std;

void TestStruct::set(int i){
	memberInt = i;
}

void TestStruct::show(){
	cout << "memberInt = " << memberInt << endl;
}

void set(TestStruct * s, int i){
	s->memberInt = i;
}

void show(TestStruct * s){
	cout << "memberInt = " << s->memberInt << endl;
}

string Libc::geta(){
	return a;
}

string Libc::getb(){
	return b;
}

string Libc::getc(){
	return c;
}


void Libc::seta(string s){
	a = s;
}

void Libc::setb(string s){
	b = s;
}

void Libc::setc(string s){
	c = s;
}
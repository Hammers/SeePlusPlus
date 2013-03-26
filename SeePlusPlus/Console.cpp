#include <iostream>
#include <limits>
#include "Console.h"
using namespace std;

void continueOnEnter(void){
	std::cout << "Press ENTER to continue...";
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
}
#include <iostream>
using namespace std;

void printPrimes(int limit){
	for(int i=2; i < limit;i++)
		for(int j=2; j<=i; j++)
			if(j==i)
				cout << i << endl;
			else
				if (i%j==0)
					break;
}
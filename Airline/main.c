#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "airline.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int size=10;
	int seats[size];
	initSeats(seats, size);
	displaySeats(seats,size);
	repeat(seats,size);
	
	return 0;
}

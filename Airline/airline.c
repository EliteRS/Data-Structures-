#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "airline.h"

void gotoxy(int x, int y){
	COORD p = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
void initSeats(int seats[], int size){
	int i;
	for (i=0;i<size;i++){
		seats[i]=0;
	}
}
void displaySeats(int seats[], int size){
	int i,j;
	boxDisplay();gotoxy(43,8);printf("Welcome to MGM Airlines!");
	gotoxy(40,10);printf("Please type 1 for \"First class\"\n");
	gotoxy(40,12);printf("Please type 2 for \"Economy\"\n");
	gotoxy(53,16);printf ("SEATS: ");
	for(i=0;i<size;i++){
		if(i<size-5){
			gotoxy(48+i*3,18);printf("[%d]",seats[i]);
		}else{
			gotoxy(48+(i-5)*3,19);printf("[%d]",seats[i]);
		}
	}
}
int assignSeat(int seats[], int seatType){
	int seat;
	int confirm;
	int size=10;
	if(seatType == 1){
		seat = assignFirstClass(seats,size);
		if(seat == -1){
			gotoxy(10,28);printf("First Class Section is full. Do you want to be transferred in the Economy Class Section?");
			gotoxy(40,29);printf("Enter \"1\" if yes, \"0\" if no.");
			gotoxy(55,30);scanf("%d",&confirm);
			if(confirm == 1){
				system("cls");
				seat = assignEconomy(seats,size);
				return seat;
			}else{
				system("cls");
				displaySeats(seats,size);
				gotoxy(40,28);printf("The next flight will leave in 3 hours.");
				
				Exit();
			}
		}
	}
	else if(seatType == 2){
		seat = assignEconomy(seats,size);
		if(seat == -1){
			gotoxy(12,28);printf("Economy Section is full. Do you want to be transferred in the First Class Section?\n");
			gotoxy(40,29);printf("Enter \"1\" if yes, \"0\" if no.");
			gotoxy(55,30);scanf("%d",&confirm);
			if(confirm == 1){
				system("cls");
				seat = assignFirstClass(seats,size);
				return seat;
			}else{
				system("cls");
				displaySeats(seats, size);
				gotoxy(40,28);printf("The next flight leaves in 3 hours.");
				
				Exit();
			}
		}
	}
	fullSeats(seats,size);
	return seat;
}
void fullSeats(int seats[], int size){
	int i,j=0;
	
	for (i=0;i<size;i++){
		if (seats[i]==1){
			j++;
		}
	}
		if(j==10){
			displaySeats(seats,size);
			gotoxy(45,29);printf ("The plain seats are full.");
			gotoxy(40,31);printf ("The next flight leaves in 3 hours.");
			gotoxy(52,33);printf ("Thank you.");
			Exit();
	}
}
int assignFirstClass(int seats[], int size){
	int i;

	for (i=0;i<size/2;i++){
		if (seats[i]!=1){
			seats[i]=1;
			return i;
		}
		
	}
	return -1;
}
int assignEconomy(int seats[], int size){
	int i;

	for (i=size/2;i<size;i++){
		if (seats[i]!=1){
			seats[i]=1;
			return i;
		}
	}
	return -1;
}
void boardPass(int seat){
	int x=47;
	boardPassBox();
	gotoxy(x,22);printf("Boarding Pass");
	if(seat+1<5){
		gotoxy(x,23);printf("First Class Section");
	}else{
		gotoxy(x,23);printf("Economy Class");
	}
	gotoxy(x,24);printf("Seat #%d",seat+1);
}
void boardPassBox(){
	int height=6;
	int width=30;
	int i,j;
	int x=40,y=21;
	for(i=0;i<height;i++){
	for(j=0;j<width;j++){
		
		if(i==0 || i==height-1){
			if(j==0 && i==0){
				gotoxy(x+j,y+i);printf("%c",201);
			}else if(j==width-1 && i==0){
				gotoxy(x+j,y+i);printf("%c",187);
			}else if(j==0 && i== height-1){
				gotoxy(x+j,y+i);printf("%c",200);
			}else if(j==width-1 && i==height-1){
				gotoxy(x+j,y+i);printf("%c",188);
			}else{
				gotoxy(x+j,y+i);printf("%c",205);
				}		
		}else{
			if(j==0 || j==width-1){
				gotoxy(x+j,y+i);printf("%c",186);
			}else{
				printf(" ");
			}
		}
	}
		printf("\n");
	}
}
void repeat(int seats[],int size){
	int x;
	int seatType;
	while (x!=0){
		system("cls");
		displaySeats(seats,size);
		gotoxy(55,14);scanf("%d",&seatType);
		while (seatType!=1 && seatType!=2){
			
			gotoxy(38,28);printf ("Invalid input. Please try again: ");
			scanf ("%d",&seatType);
			system("cls");
		}
		int seat=assignSeat(seats,seatType);
		if (seat!=-1){
			displaySeats(seats,size);
			boardPass(seat);
		}
		gotoxy(43,28);system("pause");
		
	}
}
void boxDisplay(){
	int height=22;
	int width=50;
	int i,j;
	
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			if(i==0 || i==height-1){
				if(j==0 && i==0){
					gotoxy(30+j,6+i);printf("%c",201);
				}else if(j==width-1 && i==0){
					gotoxy(30+j,6+i);printf("%c",187);
				}else if(j==0 && i==height-1){
					gotoxy(30+j,6+i);printf("%c",200);
				}else if(j==width-1 && i==height-1){
					gotoxy(30+j,6+i);printf("%c",188);
				}else{
					gotoxy(30+j,6+i);printf("%c",205);
				}
			}else{
				if(j==0 || j==width-1){
					gotoxy(30+j,6+i);printf("%c",186);
				}else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
void Exit(){
	exit(0);
}

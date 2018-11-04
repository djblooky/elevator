#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

//Created by Haley Phillips

void print_floors(int floor, int pos);
void select_floor(int current_floor);
void ascend(int current_floor, int new_floor);
void descend(int current_floor, int new_floor);
//void idle();

unsigned int HUDcurrent_floor = 1, 
    HUDnew_floor = 1, 
    HUDelevator_pos = 1; 
    
int main(int argc, char ** argv)
{
    //infinite loop
    for(;;){   
        //idle();
        print_floors(HUDcurrent_floor, HUDelevator_pos); //updates HUD
        printf("\n\t----------------------\n\n\tWhat floor would you like to go to? (Enter 0 to exit)\n\tEnter number: ");
        select_floor(HUDcurrent_floor);      
    }

    return 0;
}

void print_floors(int floor, int pos)
{
    printf("\n\tCurrent floor: %d", floor);
    printf("\n\tCurrent elevator position: %d", pos);
}

void select_floor(int current_floor) //takes user input and determines whether to ascend or decend
{
    int new_floor; //temportary int for collecting input

    if(scanf("%d",&new_floor)){}; //returns length of the scanned array (broken up by spaces) must be stored to use
    //if statement silences the unused variable warning

    if(current_floor == new_floor){
        printf("\n\t> You are already on this floor!\n");
    }
    else if(new_floor == 0){  //for testing purposes, to quickly exit the loop
        exit(0);
    }
     else if(new_floor < 0){ //blocks negative input
        printf("\n\t> Invalid input! Try again.\n");
    }
    else if(new_floor > current_floor){ //going to higher floor
        ascend(current_floor, new_floor);
    }
    else if(new_floor < current_floor){ //going to lower floor
        descend(current_floor, new_floor);
    } 
    else{ //catches any other bad input
        printf("\n\t> Invalid input! Try again.\n");
    }
}

void ascend(int current_floor, int new_floor) //prints each passed floor going up
{
    for(int i = current_floor; i <= new_floor; i++){ 
        printf("\n\t%d", i);
    }
    printf("\n\tDING!\n\t");
    HUDcurrent_floor = new_floor;
    HUDelevator_pos = new_floor;
}

void descend(int current_floor, int new_floor) //prints each passed floor going down
{
    for(int i = current_floor; i >= new_floor; i--){ 
        printf("\n\t%d", i);
    }
    printf("\n\tDING!\n\t");
    HUDcurrent_floor = new_floor;
    HUDelevator_pos = new_floor;
}

//i might use this later
/*
void idle() //allows the elevator to randomly change position when idle...in progress
{
    HUDelevator_pos = rand();      
} */
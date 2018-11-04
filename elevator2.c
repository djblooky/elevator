#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

//Created by Haley Phillips

void print_floors(int floor, int pos);
void move_floor(int current_floor, int new_floor);
void ascend(int current_floor, int new_floor);
void descend(int current_floor, int new_floor);
//void idle();

unsigned int global_current_floor = 1, 
    global_new_floor = 1, 
    global_elevator_pos = 1; 

int running = 1;
int num_of_stops = 1, current_stop = 0;
    
int main(int argc, char ** argv)
{
    while(running == 1){   
        //idle();
        print_floors(global_current_floor, global_elevator_pos); //updates display
        printf("\n\t----------------------\n\n\tWhat floors would you like to go to? \n\tPlease enter five values separated by spaces. (Enter all 0s to exit)\n\tEnter number: ");
        while(current_stop < num_of_stops){ //moves floor until it has gone through each stop
           //printf("\n\tint numofstops: %d", num_of_stops);
           //printf("\n\tint currentstop: %d", current_stop);
            move_floor(global_current_floor, global_new_floor);  
        }
        current_stop = 0;
    }

    return 0;
}

void print_floors(int floor, int pos)
{
    printf("\n\tCurrent floor: %d", floor);
    printf("\n\tCurrent elevator position: %d", pos);
}

void move_floor(int current_floor, int new_floor) //takes user input and determines whether to ascend or decend
{
    int floor1, floor2, floor3, floor4, floor5;
    int stop = scanf("%d%d%d%d%d", &floor1, &floor2, &floor3, &floor4, &floor5); //returns length of the scanned array (broken up by spaces) must be stored to use
    int stops[] = {floor1, floor2, floor3, floor4, floor5}; //assigns inputs to array for easy iteration

    size_t NumberOfElements = sizeof(stops)/sizeof(stops[0]); //referenced stack overflow... finds array length

    for(int i = 0; i < NumberOfElements; i++){ //cycles through each input to assign 
        new_floor = stops[i]; 
        if(i > 0)
            current_floor = stops[i-1]; //stores last floor

    num_of_stops = stop;
    //printf("\n\tint stops: %d", stop);

    if(current_floor == new_floor){
        printf("\n\t> You are already on this floor!\n");
        current_stop += 1;
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
    }//end of for loop
}

void ascend(int current_floor, int new_floor) //prints each passed floor going up
{
    for(int i = current_floor; i <= new_floor; i++){ 
        printf("\n\t%d", i);
    }
    printf("\n\tDING!\n\t");
    current_stop += 1;
    global_current_floor = new_floor;
    global_elevator_pos = new_floor;
}

void descend(int current_floor, int new_floor) //prints each passed floor going down
{
    for(int i = current_floor; i >= new_floor; i--){ 
        printf("\n\t%d", i);
    }
    printf("\n\tDING!\n\t");
    current_stop += 1;
    global_current_floor = new_floor;
    global_elevator_pos = new_floor;
}

//i might use this later
/*
void idle() //allows the elevator to randomly change position when idle...in progress
{
    global_elevator_pos = rand();      
} */
/*
    This is a small console program which is supposed to act as
    a scoreboard like way of counting your dart scores

    Functionalities:
    1. Count down your Darts and give you some numbers about the collected data
    e.g. Averages / Darts per Leg / etc.

    2. There will be am AI which will act as another player and display some
    numbers that were thrown by that AI
        a. The basic Idea is tha

    3. Record the Thrown Darts by the player and then added to the "playbook"
    of the AI --> It will play already played and happened matches that are real for every 
    skill level and then be able to be adjusted
        a. You could imagine this like a slider to adjust the propability of 
           what kind of number or atleast in what range that number will be
        b. thus on different levels of skill it is more or less likely, to 
           receive a match of a certain degree
*/

#include <stdio.h>




int score = 501;
double average = 0;
//char* scores[];

/* 
   The Program is only to end after Ctrl + c has been hit 3 times,
   Additionally there will be the possibility to end the program after
   a leg has finished
*/
int main(int argc, char* argv[]){

    /*
        A program cycle has to do several different things 
        
        1. It has to fetch input from the player in the form of console input
            A single throw of the player could look like this:
                T20 , 5 , D12
            So the reader must be able to correctly read out both chars and int

        2. Has to make the AI use certain numbers that will also be displayed
           onto the console

        3. Save the data collected from the player in some plain text files 
    */

   //get Input from the player
   printf("Test");
   for(int i = 0; i < 3; i++){

       int test;

       scanf(" %d ", &test);

   }





    return 0;
}
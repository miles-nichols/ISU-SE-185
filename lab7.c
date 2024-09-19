/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:miles nichols
- 	Section:1
-	NetID:milesn
-	Date:10/20/23
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

/* NO GLOBAL VARIABLES ALLOWED */


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y );

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);
void gragh_lineFB(int number);

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t;                              /* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll; 	    /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;                     /* Value of joystick adjusted to fit screen display */

    /* Put pre-loop preparation code here */

    int changer = 0;
    //y is a pitch where up is negitive, x is toll where left is positive
    //joystick left in negitive
    do
    {
        /* Scan a line of input */
        read_input(&t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j_LX, &j_LY, &j_RX, j_RY, &scaled_pitch, &scaled_roll, &scaled_joy);
        /* Calculate and scale for pitch AND roll AND joystick */
        scaled_pitch = scaleMagForScreen(y);
        scaled_roll = scaleMagForScreen(x);
        scaled_joy = scaleJoyForScreen(j_LX);

        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
        if(b_Up == 1 && changer ==0){
            while(b_UP ==1){
                scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j_LX, &j_LY, &j_RX, j_RY);
            }
            printf("Changing from PITCH to JOYSTICK");
            changer = 1;
        }
        else if(b_Up == 1 && changer ==2){
            while(b_Up == 1){
                scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j_LX, &j_LY, &j_RX, j_RY);
            }
            printf("Changing from JOYSTICK to ROLL");
            changer = 0;
        }
        /* Output your graph line */
        if(changer == 0){
            gragh_line(scaled_roll);
        }
        else if(changer == 1){
            gragh_lineFB(scaled_pitch);
        }
        else if(changer == 2){
            gragh_line(0 - scaled_joy);
        }

        fflush(stdout);

    } while (b_left != 1); /* Modify to stop when left button is pressed */

    return 0;

}

int read_input(int* time, double* g_x, double* g_y, double* g_z, int* button_T, int* button_C, int* button_X, int* button_S, int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y ){
    scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j_LX, &j_LY, &j_RX, j_RY);
    return *button_S;
}

int scaleMagForScreen(double rad){
    if(rad * 39 > 39){
        return 39;
    }
    else{
        return rad * 39;
    }
}

int scaleJoyForScreen(int rad){
    if((rad * 39) / 128 > 39){
        return 39;
    }
    else{
        return (rad * 39) / 128;
    }
}

void gragh_line(int number){
    if(number > 0){
        print_chars(number, 'L');
    }
    else if(number < 0){
        print_chars(abs(number), 'R');
    }
    else{
        print_chars(0,'0');
    }
    printf("\n");
}

void gragh_lineFB(int number){
       if(number > 0){
        print_chars(number, 'F');
    }
    else if(number < 0){
        print_chars(abs(number), 'B');
    }
    else{
        print_chars(0,'0');
    }
    printf("\n");
}

void print_chars(int num, char use){
    if(use == 'L'){
        for(int i = 0; i < 39 - num; i++){
            printf(" ");
        }
        for(int i = 0; - < num; i++){
            printf("L")
        }
    }
    if(use == 'R'){
        for(int = 0; i < 40; i++){
            printf(" ");
        }
        for(int i = 0; i < num; i ++){
            printf("R");
        }
    }
    if(use == 'F'){
        for(int i = 0; i < num; i++){
            printf(" ");
        }
        for( int i = 0; i < num; i++){
            printf("F");
        }
    }
    if(use == 'B'){
        for(int i = 0; i < 40; i++){
            printf(" ");
        }
        for(int i = 0; i < num; i++){
            printf("B");
        }
    }
    if(use == '0'){
        for(int i = 0; i < 40; i++){
            printf(" ");
        }
        printf("0");
    }
}

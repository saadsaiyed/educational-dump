/*
       +------------------+
       |  TEXT            | x10000?
       |                  |
       |  instructions in | 0x4007ed = proc1
       |  machine code    | 0x4008d2 = proc2
       |                  |
       +------------------+ 0x400a95 = etext
       |  DATA            | 0x601454 = g1   global initialized
       |  - initialized   | 0x601458 = g3
       |    variables     | 0x60145c = ls1  static initialized
       |                  | 0x601460 = ls3
       |                  | 
       | ---------------  | 0x601464 = edata
       |                  | 0x6014c0 = g0   global uninitialized
       |                  | 0x601500 = g2   big array 
       |                  | 0x602c70 = g4
       |  - uninitialized | 0x602c74 = ls0  static uninitialized
       |    variables     | 0x602c78 = ls2
       |                  |
       |                  | 
       | ---------------  | 0x602c80 = end 
       |  - heap for      | 0x1f16010 pointed to by heap1
       |  dynamic         | 0x1f16030 pointed to by heap2
       |  allocation      |
       |                  |
       |                  |
       +------------------+ 
                |
                |
                V

                .
                .
                .

                ^
                |
                |
       +------------------+
       |  STACK           | 0x7ffd0fbcf1c8 = lc4, lc6   | Activation record for 
       |  - function      | 0x7ffd0fbcf1cc = lc3, lc5   | proc1 or proc2
       |    activation    |
       |    records       |
       |  - local         | 0x7ffd0fbcf1e4 = lc2       | Activation record for
       |    automatic     | 0x7ffd0fbcf1e8 = lc1       | main
       |    variables     | 0x7ffd0fbcf1ec = lc0       |
       +------------------+

       Ans to Question 4: As variables are added to the stack, the addresses get smaller.
    
       Ans to Question 5: Variables stored on the stack can have the same address as other variables because stack uses pop functionality to finish of completed processes.

       Ans to Question 6: Everything made after function is called will be stored where the parent function is stored and that is on stack where most of the functions are working.
        
*/

#include <stdio.h>


int getFactorial(int num)
{
    printf("%14p (%15lu): Address of argument variable 'num'\n", &num, &num);

    if(num == 0)   
        return 1;
    else 
        return (num * getFactorial(num - 1));
}

int main()
{
    int num;
    int ans;   

    printf("%14p (%15lu): Address of local uninitialized variable num\n", &num, &num);
    printf("%14p (%15lu): Address of local uninitialized variable ans\n", &ans, &ans);

    printf("\n\n");

    printf("Please enter a number for factorial calculation: ");
    scanf("%i", &num);

    ans = getFactorial(num);     

    printf("The factorial is %i\n\n", ans);
}
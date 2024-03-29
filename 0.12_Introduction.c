//Contents
#######
/**
Some Terms
clang
Anomalies
Const 
Parity 
User input 1  
While loop 1 
For loop one 
Own Function one 
Include Headers.c  
operators 
Datatypes 
Formats for datatypes  
Placeholders  
true and break 
integer overlfow 
Truncation 
Casting 
round function  
debugging
data types
arrays (see arrays_1.c)
Casting
strings and the null terminating character
Using the null terminating character in your code
Comand line prompts
Exit Status
**/

#######



//Some Terms

//zero indexing: To start counting from zero.
//Modularising our code
//He said this when he created his own function. 

//Implicitly and Explicitly
//Ie The prototype at the top of a file explicitly declairs your function further down the file.
//EG void my(int a);

//syntactic sugar : A shorthand way of writing code

//"You cannot compair strings for equality"

//i = i + 1    Can be referred to as a line of logic

//Convention: Just the way things have and continue to be done. (Generally understood rules)

//Scope: Generally speaking, for loops (unlike while loops) keep the variables within its own function and variables within a while loop can be used else where in your code

//Visual side effets: Like printing something to the screen. This isn't returning something, it's simply printing the result of something.

//Excecutable just means runnable.  

//Typed at the prompt is where you type something in the terminal window. It's at the blinking cursor in the terminal window.
//Whatever you type after 'make' is a comand line argument. It is an input to the program 'make'.

//This is another example where the input to the rm program is a.out
rm a.out
//This then removes the a.out file.




//clang
//In week 2
//The program 'make' runs clang . Do the following to run clang manualy: 
clang hello.c  //hello.c is just the name I gave to the file in this illusttration.
// clang then creates a 'binary' file called a.out.  By default It stands for assembler output.
// make allows us to customise a.out to the name of our file. so  make hello  creates hello instead of a.out
// We can also do this with clang via a comand line argument which clang supports:
clang -o hello hello.c  //This lets you explicitly specify what you want your filename to be called. 
//If you now view a list of files in your directory, you will see  hello*, so you can ./hello.c to run it.
  
/**Understanding the extra step required in clang when using functions written by others.
'undefined reference to get string '
This is an error when you use clang to run your function. 

The thing to think about here is that this is as if get_string is not recognised by clang. ie It doesn't exist or mean anything.
This means that make is doing something else for us that clang is not. make effectively gives the compiler a heads-up that the libraries that hold these functions exist.

by having the #include headers at the top of the file teaches the compiler that a functions will exist when needed.

So with clang, we need to tell the compiler to link-in code (that someone else wrote some time ago) in these libraries. make does this automatically but clang requires another step.
Steps:
Output a file called hello
clang -o hello 
Compile a file called hello.c
hello.c
Link-in the binary code (created by someone else) for get_string and printf etc.
-lcs50

Of course you need to write this as one line of code: clang -o hello hello.c -lcs50  **/

//Note that this is not the case with <stdio.h>. This is 'built-into' the c programming language unlike the cs50 library so you don't need to manually link it as you do with lcs50. Having said that, many other 'built-in' libraries are not enabled in this way. This is for memory efficency reasons. 
                    
//Steps in clang
//1. Preprossessor:  #<stdio.h> is a pre-prossessor directive. It looks for any #<include>'s at top of file such as:
#include <stdio.h>, #include <cs50.h> or #include <math.h> etc so it has access to these libraries giving you all the prototypes you need automatically.

//2. Compile: It converts/outputs your code into/as Assembly language. (next level up from machine code). This is where the Assembly instructions are laid out, such as multiply, divide, add, subtract, move into memory, load from memory, print to screen.
//(Each type of CPU has its own instruction set, ie different types/flavours of assembly language although nowadays they can be written to support other operating systems).

//3.Assembling: Now the code ['from 3 different people'] gets turned into zeros and ones/binary at this assembly stage. so:
//a) hello.c : The code I wrote is now assembled into binary.
//b) cs50.c  : The code from cs50.c is now assembled into binary. (cs50.h contain the prototypes and cs50.c contain the actual code).[This is for get_string etc]
//c) stdio.c ; The code from stdio.c is now assembled into binary.(A wee white lie here since stdio.c is so big, we are just using the name as an umbrella). (Again, cs50.h contain the prototypes and cs50.c contain the actual code). This is for printf.

//4. Linking : This stage links/stiches the 3 binary files together into one single file called 'hello' (or whatever else you named your file [but without the .c]



    
    



//Anomalies
//Normally, printf requires curly braces (after the for loop) but seems to work fine like this. Ie, No Errors!

void my(int x)
{
    for(int i = 0; i < x; i ++)
        //No Curly Braces Here
        printf("God \n");
        //No Curly Braces Here
}



//Const
//Use const as a global variable or within main.
const int N = 3;//By convention, they are capitalised
//Use when you know you don't ever want the value of N to change
int main (void)
{
  int x = get_int("What number do you have? ");//Prompt the user for their number
  printf("Your number divided by N is %i \n", x / N);//Print out the answer to their number divided by N(3).
}




//Parity 
//Test if user's number is odd or even.
int main(void)
{
    int n = get_int("Please choose a number ");//Ask user for a number
    if(n % 2 == 0)//If n divided by two has a remainder of 0...
    {
        printf("%i  is an even number \n " , n );//Print this to the screen....
    }
    else
    {
        printf("%i  is an odd number \n " , n );//Otherwise, print this to the screen.
    }
}



// User input 1
//Create a function that asks the user to agree or disagree
int main(void)
{
    char yes = get_char("Do you agree to the t and c's? ");//Ask user if they agree to t and c's
    if(yes == 'y' || yes == 'Y')//If lowercase or capital Y typed...
    {
        printf("Agreed\n");//Print this
    }
    else if(yes == 'n' || yes == 'N' )// If lowercase or capital N typed...
    {
        printf("Disagree \n");//Print this
    }
  
  
  
//  While loop 1
  //Print Meeaow 3 times with a while loop
int main(void)
{
    int a = 0;//Here, 'a' can be used elsewhere in your code. It's scope is wider than this while loop.
    while(a <= 2)
    {
        printf("Meaow\n");
        a ++;
    }
        printf("%i ", a);//So a here can be printed fine because its scope is beyond the while loop. a = 3 because the inner while loop must finish running (while the condition is true), before the second printf is printed to the screen.
}
  
  
 
 // For loop one 
 //Print meeaow 3 times using a for loop
int main(void)
{
    for(int i = 0 ; i <= 3 ;  i ++)//'i' cannot be used anywhere else in your code. It's scope is within the for loop.
    {
        printf("Meaow\n");
    }
        printf("%i ", i);//This will throw up an error. 'i' is deemed undeclared as it's outside the scope it was used for.
}
  
  
  
//  Own Function one
  //Print meeaow 3 times using your own function
  void meeawo(void)
{
    for(int i = 0; i < 3; i ++)
    {
        printf("Meeaow\n");
    }
}

int main(void) 
{
    meeawo();
}
//Above is just to show it can be done this way. By convention, main sits at the top with your programm's prototype at the top and the detail down below somewhere.
    
    

    
// Include Headers.c
#include <cs50.h>//Contains get_int, get_string
#include <stdio.h> //Contains printf
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
    
    
    
    
//  operators
// And there are some mathematical operators we can use:
// == For is eqaul to. AKA the equality operator. A single = is the assignment operator. (copies from right into left)
// + for addition
// - for subtraction
// * for multiplication
// / for division
// % for remainder (modulu) The remainder when two numbers are divided together.
// || The or operator
// && The and operator


    
    
// Datatypes
bool	1 bite  // EG:if(x > y), is boolean since it can only be either yes or no or true or false
char	1 bite //  A single character like 'a' or 't' (Note that single quotes are used for chars).
int	4 bites // roughly up to 2 billion (taking into account negative numbers)
float	4 bites // A floating-point value, or real number with a decimal value
double	8 bites // A floating-point value roughly double in size of a float.
long 	8 bites // To 4 billion and beyond. Use this for more precision
string  //An indeterminate number of bytes since it can be a whole book
void //, a type but not a data type. For functions that don't return a value eg printf. The Result is not captured and stored,  just printed on screen 
//(as a side event). Therefore, printf is a void function.

// void my(void)  : parameters can also be void. EG: no arguments get passed into main.
    
    
    
    
//  Formats for datatypes 
//And the CS50 library has corresponding functions to get input of various types:
// Its best to declare a variable just when you need it (scope).
get_string //:Frome the cs50 library
get_char  //: only 1 byte of memory for individual characters.
get_float  //:real (decimal) numbers contained in 4 bytes of memory
get_double // For storing floating point numbers. Double precision compared to floats. So: are contained in 8 bytes of data.
get_int //: 4 bytes of memory or 32 bits, 50% pos numbs, 50% negatives -2 to the 31st and 2 to the 31st - 1
// range= approx negative 2 billion to positive 2 billion
// unsigned int : Only allows positive numbers thus doubling positive's range to approx 4 billion 

 
    
    
    
//  Placeholders
// For printf, too, there are different placeholders for each type:
%c //for chars
%f //for floats, doubles  NB %.2f Returns 2 decimal places
%i // for ints
%li // for longs
%s // for strings
    

    
    
//true and break
    int ask;
    while (true)//While below is true... NB; THE 'TRUE' VALUE CAN ALSO BE THE NUMBER 1  eg: while (1)
    {
        ask = get_int("How large do you want the block to be? :");
        if (ask > 0)
        {
            break;//...then break out of this loop
        }
    }
    
    
//Integer overflow
//Happens when more numbers are explicitly declared than bytes asigned to it.
// AKA floating point imprecission
    int main(void)
{
   float a = get_int("Number 1: ");
   float z = get_int("Number 2: ");
   printf("=%.50f \n " , a / z);
}

//Returns =0.10000000149011611938476562500000000000000000000000 
    
// Interestingly, this became a worry at the turn of the century (year 2000), as many computers stored the year with only two bits to save on memory (99 instead of 1999). This problem was solved, however, 2038 could be the next problem. This is because computers count time in seconds from the Unix epoc being arbitraraly january 1st 1970. Most computers use 32 bits to count the number of seconds from this date which means a maximum of roughtly 2 billion seconds which is going to happen in 2038. The result being that you end up with a very large negative number since the leftmost number signals negativity if it is set to 1. The answer of course is to increase the number of bits from 32 to 64.

    
    
// Truncation
//Where two intergers are being divided and the answer is 0.something then c will return just all zeros. So when dividing two integers, c will only be able to provide you with an integer as an answer. ie 0. This is known as truncation.
    // The solution to this is 'type conversion'. We can tell the computer we want to treat the integer as though it's a floating point number value. This can be down by 'casting'
    
    
// Casting
int main(void)
{
   int a = get_int("Number 1: ");
   int z = get_int("Number 2: ");
   float j = (float) a / (int) z;
   printf("=%.50f \n " , j);
}
//Interestingly, only one of the integers need to be casted as a float. (a).
    
    
    
// round function
// This helps with better precision
    #include <math.h>
int main(void)
{
   float dollar = get_int("Dollar ammount:  ");
   int pennies = round(dollar * 100);

   printf(" %i \n " , pennies);
}
// Where 4.20 dollars was typed by the user without the 'round' function, the answer would be 419 pennies instead of 420 as it should be.
    
    
// debugging
	//3 options:
//1: Use printf to look inside your code
//Example

for (int i = 0; i =>3; i ++)
{
	printf("i is %1 \n" , i);
	printf("#");
}
// debugging
/**2: Using debug50
~/psetnew/ $ debug50 ./second
You then place breakpoints to the left of the code you wish to analise. It creates a step by step walk through of what your code is doing.
Your options are play, step over, step into, step out of. Step over is the one to use however, use 'Step into' if you have deeper code inside other functions that you want to analise. 

The final approach to debugging is the rubber duck. Talk through your code to it, or in my case, just go away and do something else for a bit so your brain can work on it and come up with possible solutions. **/
	
// 3: Talk to the rubber duck!
	


	
// data types
//####################################################################include <cs50.h>

bool	1 bite  //true or false
char	1 bite  //single character
short   Typically 2 bytes. //This is for smaller numbers
int	4 bites
float	4 bites  //real number with a decimal value
double	8 bites  //roughly double in size of a float
long 	8 bites  //integers with more bits, so they can count higher.
string  nth bites //a string of characters
//########################

//And the CS50 library has corresponding functions to get input of various types:
// Its best to declare a variable just when you need it (scope).
// get_char  : only 1 byte of memory for individual characters.
// get_float  :real or decimal numbers contained in 4 bytes of memory
// get_double, For storing floating point numbers. Double precision compared to floats. So: are contained in 8 bytes of data.
//get_int : 4 bytes of memory or 32 bits, 50% pos numbs, 50% negatives
// -2 to the 31st and 2 to the 31st - 1
// range= approx negative 2 billion to positive 2 billion	
// unsigned int : Only allows positive numbers thus doubling positive's range to approx 4 billion 
// unsigned int a = 3;
// Others include: short, long and const

// #########################
//void, a type but not a data type. For functions that don't return a value eg printf. The Result is not caputered and stored,  just printed on screen 
//as a side event. Therefore, printf is a void function.

// void my(void)  : parameters can also be void. EG: no arguments get passed into main.

// bool : in cs50 library. For true or false. Standard data type in most all langauges expect for C

//############################
// get_string, is from the cs59 library
//############################

// For printf, too, there are different placeholders for each type:
// %c for chars
// %f for floats, doubles
// %i for ints
// %li for longs
// %s for strings

// And there are some mathematical operators we can use:
// + for addition
// - for subtraction
// * for multiplication
//   / for division
// % for remainder (modulu)
//END OF DATA TYPES





// arrays
go to arrays_1.c


	

//Casting
//Casting a char as an integer
int main(void)
{
      char letter = get_char("Letter please ");//Get a letter from the user
      printf("The ascci integer representation of %c is %i\n" , letter , (int)letter );
	//Explicitly converting a char to an integer with (int)letter.
}
//Or more simply you could have
int main(void)
{
      char letter = get_char("Letter please ");
      printf("The ascci integer representation of %c is %i\n" , letter , letter );
	//It is enough that you change the placeholder to an integer to ask c for the ascii numerical representation of the letter by implication.
}



//strings and the null terminating character
//strings are just an array of characters.
int main(void)
{
     string s = "hi!";
     printf("%i %i %c", s[0] ,s[1] ,s[2]);
	//By implication you are printing integers for the first two chars
	//Were you to print s[3], ie one step beyond the actual chars, it is always a zero. This is the null terminating character.
}

//This also prints out strings using a for loop
string s = "hi!";
     for (int i = 0; i < 4; i ++)//strlen comes for <string.h> So you are accessing s's arrays up to the string length of s
     printf("%c ", s[i]);
//The same applies here regarding the null terminating character. One step beyond the chars is a zero.


//This also prints out strings using a for loop using strlen from string.h
string s = "hi!";
     for (int i = 0; i < strlen(s); i ++)//strlen comes for <string.h> So you are accessing s's arrays up to the string length of s
     printf("%c ", s[i]);



//Using the null terminating character in your code

char * name = get_string("Name ");//Prompt user for a name
int count=0;//Set a counter to zero
          for(int i = 0; name[i] !='\0'; i ++)// strlen counts the chars in the string.
     {
	     count++;//count increments by one each time above is true
     }
          printf("%i ", count);//Print the final count number.
//

/**Your side note: The tasks ahead are:
1. To begin using all three loops for each program and try and get them to work. 
2. Turn everything into your own function.
3. add a library functions file for things like strlen  **/


// Comand line prompts
int main(int argc , string argv[])//arg means arguments, argc counts the strings, argv puts the strings into an array
{
	printf("%s %i \n " , argv[1], argc);// Print the second string in the array and total number of strings
}
//More examples of command line user input in the 'comand_line' file.


/**** Exit Status
C automatically (secretly) returns a zero when your code works. 
You should return a non zero value if you want to quite out of your program prematurely. Ie when someone did not input the required values. So typically you can return 1 or any other non zero value.
These are where error codes (exit status's) can be used to identify different errors in a program.  ****/

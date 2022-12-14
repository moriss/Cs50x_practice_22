//Contents: Syntactic Sugar,  const, Parity, Agree, Meeaow, 

//Syntactic Sugar
//Ways of expressing incrementation
int counter +=1;
same as
int counter ++;
same as
int counter = counter + 1;




//Use const as a global variable or within main.
const int N = 3;//By convention, they are capitalised
//Use when you know you don't ever want the value of N to change
int main (void)
{
  int x = get_int("What number do you have? ");//Prompt the user for their number
  printf("Your number divided by N is %i \n", x / N);//Print out the answer to their number divided by N(3).
}



//Parity: Test if user's number is odd or even.
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
  
  
  
 
  //Print Meeaow 3 times with a while loop
int main(void)
{
    int a = 0;//Here, 'a' can be used elsewhere in your code. It's scope is wider than this while loop.
    while(a <= 2)
    {
        printf("Meaow\n");
        a ++;
    }
        printf("%i ", a);//So a here can be printed fine.
}
  
  

 //Print meeaow 3 times using a for loop
int main(void)
{
    for(int i = 0 ; i <= 3 ;  i ++)//'i' cannot be used anywhere else in your code. It's scope is withing the for loop.
    {
        printf("Meaow\n");
    }
        printf("%i ", i);//This will throw up an error. 'i' is deemed undeclared as it's outside the scope it was used for.
}
  
  
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


int main(void)
{
    int ask;
    while (true)//While below is true...
    {
        ask = get_int("How large do you want the block to be? :");
        if (ask > 0)
        {
            break;//...then break out of the loop
        }
    }
        for(int i = 0; i < ask; i ++)//Outer loop that runs while i is less or equal to 3
        {
            for(int j = 0; j < ask; j ++)//Inner loop that prints the lines, again less or equal to 3
            {
                printf("# ");//Printing the hashes
            }
                printf("\n");//Line break occurs at end of last hash.
        }
}

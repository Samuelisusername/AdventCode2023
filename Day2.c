#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;                     // declaration of file pointer
    fp = fopen("input.txt", "r"); // opening of file
    char line[3000];
    int gameindex = 1;
    int indexsum = 0;
    // ex two
    int productsum = 0;

    while (fgets(line, sizeof(line), fp))
    { // for each Game
        int possible = 1;
        int pastcolon = 0;
        int currmaxnumber = 0;
        int colournr = 0; // 1 for r, 2 for b, 3 for g
        // ex two code
        int maxgreen = 0;
        int maxred = 0;
        int maxblue = 0;
        for (int i = 0; i < strlen(line); i++)
        { // for each character in this line
            char currchar = line[i];
            if (currchar == ':')
            {
                pastcolon = 1;
                continue;
            }
            if (pastcolon)
            {
                // now we know we are past the colon
                // find the number
                if (currchar >= '0' && currchar <= '9')
                { // current char is a digit
                    if (currchar - '0' > currmaxnumber)
                        currmaxnumber = currchar - '0';
                    if (line[i + 1] >= '0' && line[i + 1] <= '9')
                    { // nextchar is also digit :))
                        if (line[i + 2] >= '0' && line[i + 2] <= '9')
                        {
                            possible = 0; // we have a dreistellige zahl :(
                        }
                        else
                            currmaxnumber = (line[i + 1] - '0') + 10 * (currchar - '0');
                    }
                }
                if (currchar == 'd' && currmaxnumber > maxred)
                {
                    maxred = currmaxnumber;
                }
                if (currchar == 'g' && currmaxnumber > maxgreen)
                {
                    maxgreen = currmaxnumber;
                }
                if (currchar == 'b' && currmaxnumber > maxblue)
                {
                    maxblue = currmaxnumber;
                }
                // which colour are we at?
                if ((currchar == 'd' && currmaxnumber > 12))
                {
                    possible = 0;
                    //  printf("%s: red: %d %d\n", line, currmaxnumber, i);
                    currmaxnumber = 0;
                }
                if ((currchar == 'g' && currmaxnumber > 13))
                {
                    possible = 0;
                    printf("%s : green: %d %d\n", line, currmaxnumber, i);
                    currmaxnumber = 0;
                }
                if ((currchar == 'b' && currmaxnumber > 14))
                {
                    possible = 0;
                    printf("%s :blue: %d %d \n", line, currmaxnumber, i);
                    currmaxnumber = 0;
                }
                if (currchar == 'd' || currchar == 'g' || currchar == 'b')
                {
                    currmaxnumber = 0;
                }
            }
        }
        // if (possible)
        // {
        //     indexsum += gameindex;
        //     printf("%d:total: %d \n \n", gameindex, indexsum);
        // }
        // gameindex++;
        productsum += maxgreen * maxblue * maxred;
    }
    fclose(fp); // closing of file
    printf("%d \n \n", productsum);
    return 0;
}
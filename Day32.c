#include <stdio.h>  //for printf
#include <string.h> //for strlen
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
int issymbol(char upchar)
{
    if (upchar != '.' && (upchar > '9' || upchar < '0'))
    {
        return 1;
    }
    return 0;
}
int numOfDigits1(int possiblyint)
{
    int numOfDigits = 1;
    if (possiblyint > 9)
    {
        // ist zweistellig
        numOfDigits = 2;
        if (possiblyint > 99)
        {
            // dreistellig
            numOfDigits = 3;
        }
    }
    return numOfDigits;
}
int legal1(char array[140][140], int i, int j, int len)

{

    int boolean = 0;
    if (len == 1 && (array[MAX(i - 1, 0)][MAX(j - 1, 0)] != '.' || array[i][MAX(j - 1, 0)] != '.' || array[MAX(i - 1, 0)][j] != '.' || array[MIN(i + 1, 139)][MAX(j - 1, 0)] != '.' || array[MIN(i + 1, 139)][MIN(j + 1, 139)] != '.' || array[i][MIN(j + 1, 139)] != '.' || array[MAX(i - 1, 0)][j + 1] != '.' || array[MIN(i + 1, 139)][j] != '.'))
    {
        boolean = 1;
    }
    if (len == 2 && (array[MAX(i - 1, 0)][MAX(j - 1, 0)] != '.' || array[MAX(i - 1, 0)][j] != '.' || array[MAX(i - 1, 0)][MIN(j + 1, 139)] != '.' || array[MAX(i - 1, 0)][MIN(j + 2, 139)] != '.' || array[MIN(i + 1, 139)][MAX(j - 1, 0)] != '.' || array[MIN(i + 1, 139)][j] != '.' || array[MIN(i + 1, 139)][MIN(j + 1, 139)] != '.' || array[MIN(i + 1, 139)][MIN(j + 2, 139)] != '.' || array[i][MAX(j - 1, 0)] != '.' || array[i][MIN(j + 2, 139)] != '.'))
    {
        boolean = 1;
    }
    if (len == 3 && (array[MAX(i - 1, 0)][MAX(j - 1, 0)] != '.' || array[MAX(i - 1, 0)][j] != '.' || array[MAX(i - 1, 0)][MIN(j + 1, 139)] != '.' || array[MAX(i - 1, 0)][MIN(j + 2, 139)] != '.' || array[MIN(i + 1, 139)][MAX(j - 1, 0)] != '.' || array[MIN(i + 1, 139)][j] != '.' || array[MIN(i + 1, 139)][MIN(j + 1, 139)] != '.' || array[MIN(i + 1, 139)][MIN(j + 2, 139)] != '.' || array[i][MAX(j - 1, 0)] != '.' || array[MAX(i - 1, 0)][MIN(j + 3, 139)] != '.' || array[i][MIN(j + 3, 139)] != '.' || array[MAX(i + 1, 0)][MAX(j + 3, 0)] != '.'))
    {
        boolean = 1;
    }
    return boolean;
}
int legal(char array[140][140], int i, int j, int len)
{
    for (int k = -1; k < len + 1; k++)
    {
        char upchar = array[MAX(i - 1, 0)][MAX(MIN(j + k, 139), 0)];
        char downchar = array[MIN(i + 1, 139)][MAX(MIN(j + k, 139), 0)];
        char leftchar = array[i][MAX(0, j - 1)];
        char rightchar = array[i][MIN(139, j + len)];
        if (issymbol(upchar) || issymbol(rightchar) || issymbol(downchar) || issymbol(leftchar))
        {
            return 1;
        }
    }
    return 0;
}
int readnumber(char array[140][140], int i, int j)
{
    char char2;
    char char3;
    if (j == 138)
    {
        char2 = array[i][j + 1];
        char3 = 'a';
    }
    if (j == 139)
    {
        char2 = 'a';
        char3 = 'a';
    }
    char2 = array[i][j + 1];
    char3 = array[i][j + 2];
    int seconddigit = -1;
    int thirddigit = -1;
    int totaldigit = (array[i][j] - '0');
    if (char2 <= '9' && char2 >= '0')
    {
        seconddigit = char2 - '0';
        if (char3 <= '9' && char3 >= '0')
        {
            thirddigit = char3 - '0';
            totaldigit = 100 * (array[i][j] - '0') + 10 * seconddigit + thirddigit;
        }
        else
            totaldigit = 10 * (array[i][j] - '0') + seconddigit;
    }
    return totaldigit;
}
int main()
{
    FILE *fp = fopen("input2.txt", "r");
    char line[3000];
    char array[140][140];
    long ultimatesum = 0;
    int row = 0;
    while (fgets(line, sizeof(line), fp))
    {
        for (int i = 0; i < strlen(line); i++)
        {
            array[row][i] = line[i];
        }
        row++;
    }
    // the data is copied now
    for (int i = 0; i < 140; i++)
    {
        for (int j = 0; j < 140; j++)
        {
            if (array[i][j] <= '9' && array[i][j] >= '0')
            {
                int currnumber = readnumber(array, i, j);

                int numOfDigits = numOfDigits1(currnumber);
                int hassymbol = legal(array, i, j, numOfDigits);
                //  printf("%d", hassymbol);
                j += numOfDigits;
                if (hassymbol)
                {
                    ultimatesum += currnumber;
                    printf("%d : %d :  column(%d ): row(%d) : %d \n", currnumber, numOfDigits, j, i, ultimatesum);
                }
            }
        }
    }
    printf("%d", ultimatesum);
}

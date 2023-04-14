#include <stdio.h>
#include <stdbool.h>

#define TEAM_ID 6 // (substitute your team ID here
#define N 5
int a[] = {1, 3, 5, 7, 9};

/* Example Conditions
x >= TEAM_ID         returns ALARM; result is a True Positive
x == TEAM_ID + 23    returns BUG-FREE; True Negative
x == TEAM_ID + 22    returns BUG-FREE; False Negative
x <= TEAM_ID         returns ALARM; True Positive
*/

int error(int x)
{
    // conditions here
    x >= TEAM_ID;
}
int main()
{
    int x = TEAM_ID;
    int choice = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &choice);
        if (choice)
        {
            x += a[i];
        }
    }
    if (error(x))
        x = 1 / 0; // error point

    return 0;
}

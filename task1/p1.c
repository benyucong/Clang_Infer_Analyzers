#define TEAM_ID 6 // (substitute your team ID here
#define N 5       // (N is statically fixed)

/* Example Conditions
x < TEAM ID - 99        returns BUG-FREE; result is a True Negative
x != TEAM_ID + N        returns ALARM; False Positive
x == TEAM_ID + N + 1    returns ALARM; False Positive
x == TEAM_ID + N        returns ALARM; True Positive
*/

int error(int x)
{
    // condistions here
    return x<1;
}

int main()
{
    int x = TEAM_ID;
    for (int i = 1; i <= N; i++)
    {
        x += 1;
    }
    if (x >= 0 && error(x))
        x = 1 / 0;

    return 0;
}

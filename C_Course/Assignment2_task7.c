#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int A, B, C, D, E, F, i;
    int n[6];
    char Criminal;
    printf("The Criminals are ");
    for (A = 0; A < 2; A++)
        for (B = 0; B < 2; B++)
            for (C = 0; C < 2; C++)
                for (D = 0; D < 2; D++)
                    for (E = 0; E < 2; E++)
                        for (F = 0; F < 2; F++)
                            if (((A || B == 1) + (A + E + F == 2) + (!(A && D) == 1) + (B && C || !B && !C == 1) + (C + D == 1) + (D || E == D)) == 6)
                            {
                                n[0] = A;
                                n[1] = B;
                                n[2] = C;
                                n[3] = D;
                                n[4] = E;
                                n[5] = F;
                                for (Criminal = 'A', i = 0; Criminal <= 'F'; Criminal++, i++)
                                {
                                    if (n[i] == 1)
                                    {
                                        printf("%c,", Criminal);
                                    }
                                }
                            }
    printf("\b.");
    system("pause");
    return 0;
}

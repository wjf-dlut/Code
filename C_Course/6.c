#include <stdio.h>
#include <stdlib.h>
main()
{
    int a, b, c, d, e, ta, tb, tc, td, te, t;

    for (a = 1; a <= 5; a++)

        for (b = 1; b <= 5; b++)

            for (c = 1; c <= 5; c++)
                for (d = 1; d <= 5; d++)

                {
                    e = 15 - a - b - c - d;

                    if (a * b * c * d * e == 120)

                    {
                        ta = ((b == 2) + (a == 3)) == 1;

                        tb = ((b == 2) + (e == 4)) == 1;

                        tc = ((c == 1) + (d == 2)) == 1;

                        td = ((c == 5) + (d == 3)) == 1;

                        te = ((e == 4) + (a == 1)) == 1;

                        t = ta + tb + tc + td + te;

                        if (t == 5)

                            printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);
                    }
                }

    system("pause");
    return 0;
}

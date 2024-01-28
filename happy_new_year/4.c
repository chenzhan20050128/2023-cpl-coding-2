#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int T;
    int now_time = 0;
    int last_time = 0;
    int my_ATK = -1;
    int my_DEF = -1;
    int my_Speed = -1;
    int my_HP = -1;
    int en_ATK = -1;
    int en_DEF = -1;
    int en_Speed = -1;
    int en_HP = -1;
    int my_x = -1;
    int my_y = -1;
    int en_x = -1;
    int en_y = -1;

    int host = 1;
    int guest = 1;

    scanf("%d", &T);
    T += 1;
    while (T--)
    {
        char pack[100];
        scanf("%s", pack);
        getchar();
        int myen = -1;
        if (strcmp(pack, "Send") == 0)
        {
            myen = 1; // my
        }
        else if (strcmp(pack, "Receive") == 0)
        {
            myen = 0; // en
        }
        else
        {
            printf("error:%s\n", pack);
        }
        scanf("%s", pack); // store Packet:
        getchar();

        char temp[100];
        int num;
        scanf("%s", temp);
        scanf("%d", &num); // time;
        if (num <= now_time)
        {
            if (myen == 1)
            {
                host = 0;
            }
            else
            {
                guest = 0;
            }
        }
        else
        {
        }
        last_time = now_time;
        now_time = num;

        getchar();

        scanf("%s", temp);
        scanf("%d", &num); // HP;
        if (myen == 1)
        {
            if (my_HP == -1)
            {
                my_HP = num;
            }
            else
            {
                if (num > my_HP || num < 0)
                {
                    host = 0;
                }
                else
                {
                    if (num < my_HP && num - (my_HP - num / en_DEF) <= 0)
                    {
                        guest = 0;
                    }
                    my_HP = num;
                }
            }
        }
        else
        {
            if (en_HP == -1)
            {
                en_HP = num;
            }
            else
            {
                if (num > en_HP || num < 0)
                {
                    guest = 0;
                }
                else
                {
                    if (num < en_HP && num - (en_HP - num / my_DEF) <= 0)
                    {
                        host = 0;
                    }
                    en_HP = num;
                }
            }
        }

        getchar();

        scanf("%s", temp);
        scanf("%d", &num); // ATK;
        if (myen == 1)
        {
            if (my_ATK == -1)
            {
                my_ATK = num;
            }
            else
            {
                if (my_ATK != num)
                {
                    host = 0;
                }
                else
                {
                    // correct;
                }
            }
        }
        else
        {
            if (en_ATK == -1)
            {
                en_ATK = num;
            }
            else
            {
                if (en_ATK != num)
                {
                    guest = 0;
                }
                else
                {
                    // correct;
                }
            }
        }
        getchar();

        scanf("%s", temp);
        scanf("%d", &num); // DEF;
        if (myen == 1)
        {
            if (my_DEF == -1)
            {
                my_DEF = num;
            }
            else
            {
                if (my_DEF != num)
                {
                    host = 0;
                }
                else
                {
                    // correct;
                }
            }
        }
        else
        {
            if (en_DEF == -1)
            {
                en_DEF = num;
            }
            else
            {
                if (en_DEF != num)
                {
                    guest = 0;
                }
                else
                {
                    // correct;
                }
            }
        }
        getchar();

        scanf("%s", temp);
        scanf("%d", &num); // Speed;
        if (myen == 1)
        {
            if (my_Speed == -1)
            {
                my_Speed = num;
            }
            else
            {
                if (my_Speed != num)
                {
                    host = 0;
                }
                else
                {
                    // correct;
                }
            }
        }
        else
        {
            if (en_Speed == -1)
            {
                en_Speed = num;
            }
            else
            {
                if (en_Speed != num)
                {
                    guest = 0;
                }
                else
                {
                    // correct;
                }
            }
        }
        getchar();

        scanf("%s", temp);
        scanf("%d", &num); // x;
        int num2;
        getchar();
        scanf("%s", temp);
        scanf("%d", &num2); // y;
        if (myen == 1)
        {
            if (my_x == -1)
            {
                my_x = num;
                my_y = num2;
            }
            else
            {
                if (abs(num - my_x) + abs(num2 - my_y) > my_Speed * (now_time - last_time))
                {
                    host = 0;
                }
                else
                {
                    my_x = num;
                    my_y = num2;
                }
            }
        }
        else
        {
            if (en_x == -1)
            {
                en_x = num;
                en_y = num2;
            }
            else
            {
                if (abs(num - en_x) + abs(num2 - en_y) > en_Speed * (now_time - last_time))
                {
                    guest = 0;
                }
                else
                {
                    en_x = num;
                    en_y = num2;
                }
            }
        }
        getchar();
        getchar();
    }

    if (host == 1)
    {
        if (guest == 1)
        {
            printf("Good Game!");
        }
        else
        {
            printf("Guest Cheated!");
        }
    }
    else
    {
        if (guest == 1)
        {
            printf("Host Cheated!");
        }
        else
        {
            printf("This game is terrible!");
        }
    }
}
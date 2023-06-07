#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>

void boundary();
void fruitsetup();
void code();
void setup();

int i,j;
int height=20,width=40;
int t,x,y,p,q,score=0,gameover;
int fruitx,fruity,flag;
 char again;
char sn[]={'@'}, sn2[]={'@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','\0'};
void main()
{
    int m,n;

        fruitsetup();
        while (!gameover)
        {
        boundary();
        code();
        logic();
        }
        printf("-----------------------------");
        printf("\nYour total score is : %d\n", score);
        printf("-----------------------------");

}

void fruitsetup()
{
    gameover=0;
    x=height/2;
    y=width/2;
    label1:
        fruitx=rand()%15;
        if (fruitx==0)
        {
            goto label1;
        }

    label2:
        fruity=rand()%38;
        if(fruity==0)
        {
            goto label2;
        }
    score=0;
}

void boundary ()
{

    system ("cls");
    for (i=1;i<=height;i++)
    {
        for (j=1;j<=width;j++)
        {
            if (i==1||i==height|| j==1||j==width)
            {
                printf("#");
            }
            else
            {

                if (i==x && j==y)
                {
                    printf("%s", sn);
                }
                else if (i==fruitx && j==fruity)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}



void code()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;

        case 's':
            flag=2;
            break;

         case 'd':
            flag=3;
            break;

         case 'w':
            flag=4;
            break;

         case 'x':
            gameover=1;
            break;
        }
    }
}

void logic()
{
    sleep (0.01);
    switch (flag)
    {
    case 1:
        y--;
        break;

    case 2:
        x++;
        break;

    case 3:
        y++;
        break;

    case 4:
        x--;
        break;

    }

    if ( x<0 || x>height-1 || y<0 || y>width-1 )
    {
        gameover= 1;
    }

    if(x==fruitx && y==fruity)
    {
        label3:
        {
            fruitx=rand()%18;
            if (fruitx==0)
            {
                goto label3;
            }
        }

        label4:
        fruity=rand()%38;
        if(fruity==0)
        {
            goto label4;
        }
        score+=10;

    }

}


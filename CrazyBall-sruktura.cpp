#include "TXLib.h"
//--------------------------------------------------------------------------------------------

void CraziBall    (struct Ball ball);
void PhisicBalls  (struct Ball* ball, double ax, double ay, double dt);
void Ball_Control (double* vx, double* vy);
void Bam_Balls (double* x, double* y, double* vx, double* vy);
void GoCraziBall ( );

bool Est_li_Bam (double xA, double yA, double xB, double yB,
                 double Rsadius1, double Radius2);
double Distance (double x1, double y1, double x2, double y2);

//--------------------------------------------------------------------------------------------
int main()
    {
    txCreateWindow (1000, 700);

    GoCraziBall ( );

    return 0;
    }
//--------------------------------------------------------------------------------------------

struct Ball
    {
    double x, y, vx, vy;

    double radius;

    COLORREF color;
    COLORREF colorOkr;
    };
//---------------------------------------------------------------------------------------------
void GoCraziBall ( )
    {
    Ball ball1 = { .x = 50, .y = 150, .vx = 20, .vy = 15,
                   .radius = 18, .color = TX_WHITE, .colorOkr = TX_BROWN};

    Ball ball2 = { .x = 700, .y = 600, .vx = -30, .vy = -20,
                   .radius = 25, .color = TX_RED, .colorOkr = TX_PINK};

    Ball ball3 = { .x = 200, .y = 200, .vx = 18, .vy = 2,
                   .radius = 23, .color = TX_BLUE, .colorOkr = TX_LIGHTBLUE};

    int ax = 2, ay = 1;

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();

        CraziBall (ball1);
        CraziBall (ball2);
        CraziBall (ball3);

        //printf ("In CraziBall (): x  = %d  and y  = %d \n", x2,  y2);
        //printf ("In CraziBall (): vx = %d  and vy = %d \n", vx2, vy2);

        PhisicBalls  (&ball1, ax, ay, dt);
        PhisicBalls  (&ball2, ax, ay, dt);
        PhisicBalls  (&ball3, ax, ay, dt);

/*        int est_Bam = Est_li_Bam (ball1.x, ball1.y, ball2.x, ball2.y, ball1.radius, ball2.radius);
        if (est_Bam)
            {
            Bam_balls (ball1.x, ball1.y, $ball1.vx, &ball1.vy, ball2.x, ball2.y, $ball2.vx, &ball2.vy1, dt);
            }
       /* double razn1_2 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        if (razn1_2 < = Radius1 + Radius2)
            {
             vx1 = -vx1;
             vy1 = -vy1;

             vx2 = -vx2;
             vy2 = -vx2;
            }    */

        Ball_Control (&ball1.vx, &ball1.vy);

        txSetFillColor (TX_GRAY);

        txSleep (10);
        }
    }
//--------------------------------------------------------------------------------------------

/*bool Est_li_Bam (double xA, double yA, double xB, double yB,
                 double Rsadius1, double Radius2)
    {
    return (Distance (xA, yA, xB, yB) <= Rsadius1 + Radius2);
    }

//--------------------------------------------------------------------------------------------

double Distance (double x1, double y1, double x2, double y2)
    {
    double dist = sqrt ((*x1 - *x2) * (*x1 - *x2) + (*y1 - *y2) * (*y1 - *y2));

    printf ("Distance is : dist = %lg/n", dist);

    return dist;
    }

//--------------------------------------------------------------------------------------------
void Bam_Balls (Ball* ball)
     {
     (*ball).vx = - (*ball).vx;
     *x  = *x - Radius;
     *vy = - (*vy);
     *x  = *y - Radius;
     }     */
//--------------------------------------------------------------------------------------------
void CraziBall (struct Ball ball)
    {
    txSetColor (ball.colorOkr, 2);
    txSetFillColor (ball.color);

    txCircle (ball.x, ball.y, ball.radius);
    //txLine   (x, y, x + vx*5, y + vy*5);
    //txCircle (x + vx*5, y + vy*5, 3);
    }
//--------------------------------------------------------------------------------------------
void PhisicBalls (struct Ball* ball, double ax, double ay, double dt)
    {
    ball -> vx += ax * dt;
    ball -> vy += ay * dt;

    ball -> x += (ball -> vx) * dt;
    ball -> y += (ball -> vy) * dt;

    if (ball -> x >= 1000 - ball -> radius)
        {
        ball -> vx = - (ball -> vx);
        ball -> x  = 1000 - ball -> radius;
        }

    if (ball -> y >=  700 - ball -> radius)
        {
        ball -> vy = - (ball -> vy);
        ball -> y  = 700 - ball -> radius;
        }

    if (ball -> x <= 0 + ball -> radius)
        {
        ball -> vx = - (ball -> vx);
        ball -> x  = 0 + ball -> radius;
        }

    if (ball -> y <= 0 + ball -> radius)
        {
        ball -> vy = - (ball -> vy);
        ball -> y  = 0 + ball -> radius;
        }
    txSleep (10);
    }

//-----------------------------------------------------------
void Ball_Control (double* vx, double* vy)
    {
    if (txGetAsyncKeyState (VK_UP))    (*vy) += 2;
    if (txGetAsyncKeyState (VK_DOWN))  (*vy) -= 2;
    if (txGetAsyncKeyState (VK_LEFT))  (*vx) -= 2;
    if (txGetAsyncKeyState (VK_RIGHT)) (*vx) += 2;

    if (txGetAsyncKeyState (VK_SPACE)) *vx = *vy = 0;
    }



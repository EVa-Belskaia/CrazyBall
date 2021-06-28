#include "TXLib.h"
//--------------------------------------------------------------------------------------------

void CraziBall    (struct Ball ball);
void PhisicBalls  (struct Ball* ball, double ax, double ay, double dt);
void Ball_Control (double* vx, double* vy);
void Bam_Balls (double  xA, double yA, double* vxA, double* vyA,
                double  xB, double yB, double* vxB, double* vyB);

void Bam_Balls1   (double* xA, double* yA, double* vxA, double* vyA, double radiusA,
                   double* xB, double* yB, double* vxB, double* vyB, double radiusB);
void GoCraziBall ( );

bool Est_li_Bam (double xA, double yA, double xB, double yB,
                 double Rsadius1, double Radius2);
double Distance (double x1, double y1, double x2, double y2);
void Collision (Ball ballA, Ball ballB);

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
                   .radius = 50, .color = TX_WHITE, .colorOkr = TX_BROWN};

    Ball ball2 = { .x = 400, .y = 500, .vx = 40, .vy = 30,
                   .radius = 35, .color = TX_RED, .colorOkr = TX_PINK};

    Ball ball3 = { .x = 200, .y = 200, .vx = 18, .vy = 2,
                   .radius = 43, .color = TX_BLUE, .colorOkr = TX_LIGHTBLUE};
    //Ball ball4 = { .x = 10, .y = 10, .vx = 28, .vy = 10,
    //               .radius = 43, .color = TX_GREEN, .colorOkr = TX_LIGHTGREEN};

    double ax = 2, ay = 1;

    double dt = 0.8;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();

        CraziBall (ball1);
        CraziBall (ball2);
        CraziBall (ball3);
        //CraziBall (ball4);

        //printf ("In CraziBall (): x  = %d  and y  = %d \n", x2,  y2);
        //printf ("In CraziBall (): vx = %d  and vy = %d \n", vx2, vy2);

        PhisicBalls  (&ball1, ax, ay, dt);
        PhisicBalls  (&ball2, ax, ay, dt);
        PhisicBalls  (&ball3, ax, ay, dt);
        //PhisicBalls  (&ball4, ax, ay, dt);

        //Collision (ball1, ball2);
        //Collision (ball1, ball3);
        //Collision (ball2, ball3);


        if (Est_li_Bam (ball1.x, ball1.y, ball2.x, ball2.y, ball1.radius, ball2.radius))
            {
            Bam_Balls (ball1.x, ball1.y, &ball1.vx, &ball1.vy,
                       ball2.x, ball2.y, &ball2.vx, &ball2.vy);
            //Bam_Balls1 (&ball1.x, &ball1.y, &ball1.vx, &ball1.vy, ball1.radius,
            //            &ball2.x, &ball2.y, &ball2.vx, &ball2.vy, ball2.radius);
            }

        if (Est_li_Bam (ball1.x, ball1.y, ball3.x, ball3.y, ball1.radius, ball3.radius))
            {
            Bam_Balls (ball1.x, ball1.y, &ball1.vx, &ball1.vy,
                       ball3.x, ball3.y, &ball3.vx, &ball3.vy);
            //Bam_Balls1 (&ball1.x, &ball1.y, &ball1.vx, &ball1.vy, ball1.radius,
            //            &ball3.x, &ball3.y, &ball3.vx, &ball3.vy, ball3.radius);
            }

        if (Est_li_Bam (ball2.x, ball2.y, ball3.x, ball3.y, ball2.radius, ball3.radius))
            {
            Bam_Balls (ball2.x, ball2.y, &ball2.vx, &ball2.vy,
                       ball3.x, ball3.y, &ball3.vx, &ball3.vy);
            //Bam_Balls1 (&ball2.x, &ball2.y, &ball2.vx, &ball2.vy, ball2.radius,
            //            &ball3.x, &ball3.y, &ball3.vx, &ball3.vy, ball3.radius);
            }

        //if (Est_li_Bam (ball3.x, ball3.y, ball2.x, ball2.y, ball3.radius, ball2.radius))
        //    {
        //    Bam_Balls (ball3.x, ball3.y, &ball3.vx, &ball3.vy,
        //               ball2.x, ball2.y, &ball2.vx, &ball2.vy);
        //    }


        Ball_Control (&ball1.vx, &ball1.vy);

        txSetFillColor (TX_GRAY);

        txSleep (5);
        }
    }
//--------------------------------------------------------------------------------------------
void Collision (Ball ballA, Ball ballB)
    {
     if (Est_li_Bam (ballA.x, ballA.y, ballB.x, ballB.y, ballA.radius, ballB.radius))
        {
        Bam_Balls (ballA.x, ballA.y, &ballA.vx, &ballA.vy,
                   ballB.x, ballB.y, &ballB.vx, &ballB.vy);
        }
    }

bool Est_li_Bam (double xA, double yA, double xB, double yB,
                 double Rsadius1, double Radius2)
    {
    return (Distance (xA, yA, xB, yB) <= Rsadius1 + Radius2);
    }

//--------------------------------------------------------------------------------------------

double Distance (double x1, double y1, double x2, double y2)
    {
    double dist = sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    //printf ("Distance is : dist = %lg/n", dist);

    return dist;
    }

//1variant-------------------------------------------------------------------------------------

void Bam_Balls (double  xA, double yA, double* vxA, double* vyA,
                double  xB, double yB, double* vxB, double* vyB)
    {
    double dx = xA - xB, dy = yA - yB;
    double sinA = dx / sqrt (dx * dx + dy * dy);
    double cosA = dy / sqrt (dx * dx + dy * dy);

    double vnA =  (*vxB) * sinA + (*vyB) * cosA;
    double vnB =  (*vxA) * sinA + (*vyA) * cosA;
    double vtA = -(*vxB) * cosA + (*vyB) * sinA;
    double vtB = -(*vxA) * cosA + (*vyA) * sinA;

    double exc = vnA;
    vnA = vnB;
    vnB = exc;

    *vxA = vnB * sinA - vtB * cosA;
    *vyA = vnB * cosA + vtB * sinA;
    *vxB = vnA * sinA - vtA * cosA;
    *vyB = vnA * cosA + vtA * sinA;
    }
 //2variant-----------------------------------------------------------------------
void Bam_Balls1 (double*  xA, double* yA, double* vxA, double* vyA, double radiusA,
                 double*  xB, double* yB, double* vxB, double* vyB, double radiusB)
     {
     (*vxA) = - (*vxA);
     (*xA)  = (*xA) - 2 * radiusA;
     (*vyA) = - (*vyA);
     (*yA)  = (*yA) - 2 * radiusA;

     (*vxB) = - (*vxB);
     (*xB)  = (*xB) - 2 * radiusB;
     (*vyB) = - (*vyB);
     (*yB)  = (*yB) - 2 * radiusB;
     }
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
        ball -> x  = (1000 - ball -> radius) - (ball -> x - (1000 - ball -> radius)) * 2;
        }

    if (ball -> y >=  700 - ball -> radius)
        {
        ball -> vy = - (ball -> vy);
        ball -> y  = (700 - ball -> radius) - (ball -> y - (700 - ball -> radius)) * 2;
        }

    if (ball -> x <= 0 + ball -> radius)
        {
        ball -> vx = - (ball -> vx);
        ball -> x  = (0 + ball -> radius) + ((0 + ball -> radius) - ball -> x) * 2;
        }

    if (ball -> y <= 0 + ball -> radius)
        {
        ball -> vy = - (ball -> vy);
        ball -> y  = (0 + ball -> radius) + ((0 + ball -> radius) - ball -> y) * 2;
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



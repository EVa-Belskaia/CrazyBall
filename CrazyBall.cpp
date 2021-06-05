#include "TXLib.h"
//--------------------------------------------------------------------------------------------

void CraziBall    (int  x, int  y, int  vx, int  vy, int Radius,  COLORREF color, COLORREF fillColor);
void PhisicBalls  (int* x, int* y, int* vx, int* vy, int Radius, int ax, int ay, int dt);
void GoCraziBall  ( );
void Ball_Control (int* vx, int* vy);

//--------------------------------------------------------------------------------------------
int main()
    {
    txCreateWindow (1000, 700);

    GoCraziBall ( );

    return 0;
    }
//--------------------------------------------------------------------------------------------
void GoCraziBall ( )
    {
    int x1  =  50, y1  = 150,
        vx1 =  20, vy1 =  15,
        ax1 =   2, ay1 =   1,
        Radius1 = 18;

    int x2  = 700, y2  = 600,
        vx2 = -30, vy2 = -20,
        ax2 =   2, ay2 =  -1,
        Radius2 = 25;

    int x3  = 200, y3  = 200,
        vx3 =  18, vy3 =   2,
        ax3 =   2, ay3 =   1,
        Radius3 = 23;

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();

        CraziBall (x1, y1, vx1, vy1, Radius1, RGB (250, 170, 150), RGB (250,  50,  20));
        CraziBall (x2, y2, vx2, vy2, Radius2, RGB ( 95, 200, 250), RGB ( 95, 200,   2));
        CraziBall (x3, y3, vx3, vy3, Radius3, RGB (200, 120, 200), RGB (100,  45, 100));

        printf ("In CraziBall (): x  = %d  and y  = %d \n", x2,  y2);
        printf ("In CraziBall (): vx = %d  and vy = %d \n", vx2, vy2);

        PhisicBalls  (&x1, &y1, &vx1, &vy1, Radius1, ax1, ay1, dt);
        PhisicBalls  (&x2, &y2, &vx2, &vy2, Radius2, ax2, ay2, dt);
        PhisicBalls  (&x3, &y3, &vx3, &vy3, Radius3, ax3, ay3, dt);

       /* if (sqrt(sqr($x1 - $x2) + sqr($y1 - &y2)) <= Radius1 + Radius2)
            Bam_Balls (x1, y1, vx1, vy1)  */

        Ball_Control (&vx1, &vy1);

        txSetFillColor (TX_GRAY);
        }
    }
//--------------------------------------------------------------------------------------------
/*void Bam_Balls (int* x, int* y, int* vx, int* vy)
     {
     *vx = - (*vx);
     *x  = *x - Radius;
     *vy = - (*vy);
     *x  = *y - Radius;
     }  */
//--------------------------------------------------------------------------------------------
void CraziBall (int x, int y, int vx, int vy, int Radius, COLORREF color, COLORREF fillColor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillColor);

    txCircle (x, y, Radius);
    //txLine   (x, y, x + vx*5, y + vy*5);
    //txCircle (x + vx*5, y + vy*5, 3);
    }
//--------------------------------------------------------------------------------------------
void PhisicBalls (int* x, int* y, int* vx, int* vy, int Radius, int ax, int ay, int dt)
    {
   *vx += ax * dt;
   *vy += ay * dt;

    *x += (*vx) * dt;
    *y += (*vy) * dt;

    if (*x >= 1000 - Radius)
        {
        *vx = - (*vx);
        *x  = 1000 - Radius;
        }

    if (*y >=  700 - Radius)
        {
        *vy = - (*vy);
        *y  = 700 - Radius;
        }

    if (*x <= 0 + Radius)
        {
        *vx = - (*vx);
        *x  = 0 + Radius;
        }

    if (*y <= 0 + Radius)
        {
        *vy = - (*vy);
        *y  = 0 + Radius;
        }
    txSleep (10);
    }

//-----------------------------------------------------------
void Ball_Control (int* vx, int* vy)
    {
    if (txGetAsyncKeyState (VK_UP))    (*vy) += 2;
    if (txGetAsyncKeyState (VK_DOWN))  (*vy) -= 2;
    if (txGetAsyncKeyState (VK_LEFT))  (*vx) -= 2;
    if (txGetAsyncKeyState (VK_RIGHT)) (*vx) += 2;

    if (txGetAsyncKeyState (VK_SPACE)) *vx = *vy = 0;
    }



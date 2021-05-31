#include "TXLib.h"
//--------------------------------------------------------------------------------------------

void CraziBall    (int  x, int  y, int  vx, int  vy, COLORREF color, COLORREF fillColor);
void PhisicBalls  (int* x, int* y, int* vx, int* vy, int ax, int ay, int dt);
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
        vx1 =   7, vy1 =   5,
        ax1 =   0, ay1 =   1;

    int x2  = 700, y2  = 600,
        vx2 =  -4, vy2 =  -7,
        ax2 =   0, ay2 =   1;

    int x3  = 200, y3  = 200,
        vx3 =   4, vy3 =   3,
        ax3 =   0, ay3 =   1;

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        CraziBall (x1, y1, vx1, vy1, RGB (250, 170, 150), RGB (250,  50,  20));
        CraziBall (x2, y2, vx2, vy2, RGB ( 95, 200,   2), RGB ( 95, 200, 250));
        CraziBall (x3, y3, vx3, vy3, RGB (200, 120, 200), RGB (100,  45, 100));

        PhisicBalls (&x1, &y1, &vx1, &vy1, ax1, ay1, dt);
        PhisicBalls (&x2, &y2, &vx2, &vy2, ax2, ay2, dt);
        PhisicBalls (&x3, &y3, &vx3, &vy3, ax3, ay3, dt);

        Ball_Control (&vx1, &vy1);
        }
    }
//--------------------------------------------------------------------------------------------
void CraziBall (int x, int y, int vx, int vy, COLORREF color, COLORREF fillColor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillColor);

    txCircle (x, y, 20);
    txLine   (x, y, x + vx*5, y + vy*5);
    txCircle (x + vx*5, y + vy*5, 3);
    }
//--------------------------------------------------------------------------------------------
void PhisicBalls (int* x, int* y, int* vx, int* vy, int ax, int ay, int dt)
    {
    *vx = *vx + ax + dt;
    *vy = *vy + ay + dt;

    *x = *x + (*vx) * dt;
    *y = *y + (*vy) * dt;

    if (*x > 1000)
        {
        *vx = - (*vx);
        *x  = 1000;
        }

    if (*y >  700)
        {
        *vy = - (*vy);
        *y  = 700;
        }

    if (*x < 0)
        {
        *vx = - (*vx);
        *x  =   0;
        }

    if (*y < 0)
        {
        *vy = - (*vy);
        *y  =   0;
        }
    txSleep (10);
    }

//-----------------------------------------------------------
void Ball_Control (int* vx, int* vy)
    {
    if (txGetAsyncKeyState (VK_UP))    (*vy) ++;
    if (txGetAsyncKeyState (VK_DOWN))  (*vy) --;
    if (txGetAsyncKeyState (VK_LEFT))  (*vx) --;
    if (txGetAsyncKeyState (VK_RIGHT)) (*vx) ++;

    if (txGetAsyncKeyState (VK_SPACE)) *vx = *vy = 0;
    }



#include "TXLib.h"

void GoCraziBall        (int x, int y, int vx, int vy, int dt);
void GoCraziBallControl (int x, int y, int vx, int vy, int dt);
void Ball_Control       (int vx, int vy);

int main()
    {
    txCreateWindow (1000, 700);

    GoCraziBall        (800, 500, -5, -4, 1);
    GoCraziBallControl (100, 100,  5,  3, 1);

    return 0;
    }
//--------------------------------------------------------------------------------------------
void GoCraziBallControl (int x, int y, int vx, int vy, int dt)
    {
        txSetColor     (RGB (95, 200,   2), 2);
        txSetFillColor (RGB (95, 200, 250));

        while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetColor     (RGB (50, 100, 128), 2);
        txSetFillColor (RGB ( 0,   128, 128));

        txCircle (x, y, 20);

        x += vx * dt;
        y += vy * dt;

        if (x > 1000)
            {
            vx = -vx;
            x  = 1000;
            }

        if (y >  700)
            {
            vy = -vy;
            y  = 700;
            }

        if (x < 0)
            {
            vx = -vx;
            x  =   0;
            }

        if (y < 0)
            {
            vy = -vy;
            y  =   0;
            }
        txSleep (10);
        //Ball_Control (vx, vy);
    if (txGetAsyncKeyState (VK_UP))    vy ++;
    if (txGetAsyncKeyState (VK_DOWN))  vy --;
    if (txGetAsyncKeyState (VK_LEFT))  vx --;
    if (txGetAsyncKeyState (VK_RIGHT)) vx ++;
    if (txGetAsyncKeyState (VK_SPACE)) vx = vy = 0;

        }
    }
//--------------------------------------------------------------------------------------------
void GoCraziBall (int x, int y, int vx, int vy, int dt)
    {
        txSetColor     (RGB (95, 200,   2), 2);
        txSetFillColor (RGB (95, 200, 250));

        while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetColor     (RGB (200, 50, 18), 2);
        txSetFillColor (RGB (255, 128, 128));

        txCircle (x, y, 20);

        x += vx * dt;
        y += vy * dt;

        if (x > 1000)
            {
            vx = -vx;
            x  = 1000;
            }

        if (y >  700)
            {
            vy = -vy;
            y  = 700;
            }

        if (x < 0)
            {
            vx = -vx;
            x  =   0;
            }

        if (y < 0)
            {
            vy = -vy;
            y  =   0;
            }
        txSleep (10);

        }
    }
//--------------------------------------------------------------------------------------------
void Ball_Control (int vx, int vy)
    {

    if (txGetAsyncKeyState (VK_UP))    vy ++;
    if (txGetAsyncKeyState (VK_DOWN))  vy --;
    if (txGetAsyncKeyState (VK_LEFT))  vx --;
    if (txGetAsyncKeyState (VK_RIGHT)) vx ++;
    if (txGetAsyncKeyState (VK_SPACE)) vx = vy = 0;
    }



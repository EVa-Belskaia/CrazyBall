#include "TXLib.h"

void GoCraziBall( );

int main()
    {
    txCreateWindow (1000, 700);

    GoCraziBall( );

    return 0;
    }

void GoCraziBall( )
    {
    int x  = 100, y = 100,
        vx = 6,   vy = 4;

        int dt = 1;

        txSetColor     (RGB (95, 200,   2), 2);
        txSetFillColor (RGB (95, 200, 250));

        while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetColor     (RGB (2*x, 2*y, 128), 2);
        txSetFillColor (RGB (  x,   y, 128));

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

        if (txGetAsyncKeyState (VK_UP))    vy ++;
        if (txGetAsyncKeyState (VK_DOWN))  vy --;
        if (txGetAsyncKeyState (VK_LEFT))  vx --;
        if (txGetAsyncKeyState (VK_RIGHT)) vx ++;
        if (txGetAsyncKeyState (VK_SPACE)) vx = vy = 0;
        }
    }

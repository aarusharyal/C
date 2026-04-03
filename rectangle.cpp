#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw rectangle with top-left (100,100) and bottom-right (300,200)
    rectangle(100, 100, 300, 200);

    getch();
    closegraph();
    return 0;
}

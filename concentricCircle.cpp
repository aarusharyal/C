#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TTC\\BGI");

    circle(200, 200, 50);
    circle(200, 200, 60);
    circle(200, 200, 90);
    circle(200, 200, 100);

    getch();
    closegraph();

    return 0;
}

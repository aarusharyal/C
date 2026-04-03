#include<graphics.h>
#include <conio.h>
#include<stdio.h>
int main() {
    int gd = DETECT, gm;
initgraph(&gd, &gm, (char*)"");
	circle(250, 200, 100);
    getch();
    closegraph();
    return 0;
}

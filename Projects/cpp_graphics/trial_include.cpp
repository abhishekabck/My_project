#include <graphics.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circle(250, 250, 50);
    getch();
    closegraph();
    return 0;
}

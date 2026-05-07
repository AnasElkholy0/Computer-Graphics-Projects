#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>

int x[50], y[50];
int length = 5;

int foodx, foody;
char dir = 'R';
int score = 0;

void drawGrid() {
    int i;
    setcolor(LIGHTGRAY);

    for(i = 0; i < 640; i += 8)
        line(i, 0, i, 480);

    for(i = 0; i < 480; i += 8)
        line(0, i, 640, i);
}

void drawSnake() {
    int i;

    for(i = 1; i < length-1; i++) {
        setfillstyle(SOLID_FILL, RED);
        bar(x[i], y[i], x[i]+8, y[i]+8);
    }

    setfillstyle(SOLID_FILL, RED);
    bar(x[0], y[0], x[0]+8, y[0]+8);

    setcolor(WHITE);

    if(dir == 'R') {
        circle(x[0]+6, y[0]+2, 1);
        circle(x[0]+6, y[0]+6, 1);
    } else if(dir == 'L') {
        circle(x[0]+2, y[0]+2, 1);
        circle(x[0]+2, y[0]+6, 1);
    } else if(dir == 'U') {
        circle(x[0]+2, y[0]+2, 1);
        circle(x[0]+6, y[0]+2, 1);
    } else {
        circle(x[0]+2, y[0]+6, 1);
        circle(x[0]+6, y[0]+6, 1);
    }

    int t = length - 1;

    if(x[t] < x[t-1]) {
        int p[] = {x[t]+8,y[t], x[t]+8,y[t]+8, x[t],y[t]+4};
        fillpoly(3, p);
    }
    else if(x[t] > x[t-1]) {
        int p[] = {x[t],y[t], x[t],y[t]+8, x[t]+8,y[t]+4};
        fillpoly(3, p);
    }
    else if(y[t] < y[t-1]) {
        int p[] = {x[t],y[t]+8, x[t]+8,y[t]+8, x[t]+4,y[t]};
        fillpoly(3, p);
    }
    else {
        int p[] = {x[t],y[t], x[t]+8,y[t], x[t]+4,y[t]+8};
        fillpoly(3, p);
    }
}

void moveSnake() {
    int i;
    for(i = length-1; i > 0; i--) {
        x[i] = x[i-1];
        y[i] = y[i-1];
    }

    if(dir == 'R') x[0] += 8;
    if(dir == 'L') x[0] -= 8;
    if(dir == 'U') y[0] -= 8;
    if(dir == 'D') y[0] += 8;
}

void generateFood() {
    foodx = (rand() % 60) * 8 + 20;
    foody = (rand() % 40) * 8 + 20;
}

int checkCollision() {
    int i;

    if(x[0] < 0 || x[0] > 632 || y[0] < 0 || y[0] > 472)
        return 1;

    for(i = 1; i < length; i++) {
        if(x[0] == x[i] && y[0] == y[i])
            return 1;
    }

    return 0;
}

void main() {
    int gd = DETECT, gm;
    int i;
    char scoreText[30];

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    for(i = 0; i < length; i++) {
        x[i] = 200 - i*8;
        y[i] = 200;
    }

    generateFood();

    while(1) {

        cleardevice(); 

        drawGrid();

        setcolor(WHITE);
        outtextxy(10, 10, "Snake Game");

        sprintf(scoreText, "Score: %d", score);
        outtextxy(500, 10, scoreText);

        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(foodx+4, foody+4, 4, 4);

        drawSnake();
        moveSnake();

        if(abs(x[0] - foodx) < 8 && abs(y[0] - foody) < 8) {
            if(length < 50) length++;
            score += 10;
            generateFood();
        }

        if(kbhit()) {
            char ch = getch();
            if(ch == 'w' && dir != 'D') dir = 'U';
            if(ch == 's' && dir != 'U') dir = 'D';
            if(ch == 'a' && dir != 'R') dir = 'L';
            if(ch == 'd' && dir != 'L') dir = 'R';
        }

        if(checkCollision()) {
            cleardevice();
            setcolor(WHITE);

            sprintf(scoreText, "Final Score: %d", score);
            outtextxy(250, 200, "GAME OVER");
            outtextxy(220, 230, scoreText);

            getch();
            break;
        }

        delay(100); 
    }

    getch();
    closegraph();
}
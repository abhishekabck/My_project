#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos[100];
    int length;
    int direction;
} Snake;

Snake snake;
Point food;

void initialize() {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(100);

    snake.length = 5;
    snake.direction = KEY_RIGHT;
    for (int i = 0; i < snake.length; i++) {
        snake.pos[i].x = WIDTH / 2 - i;
        snake.pos[i].y = HEIGHT / 2;
    }

    srand(time(0));
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

void draw() {
    clear();
    mvprintw(food.y, food.x, "*");

    for (int i = 0; i < snake.length; i++) {
        mvprintw(snake.pos[i].y, snake.pos[i].x, "O");
    }

    mvprintw(HEIGHT, 0, "Score: %d", snake.length - 5);
    refresh();
}

void update() {
    int ch = getch();
    if (ch != ERR) {
        snake.direction = ch;
    }

    Point newHead = snake.pos[0];
    switch (snake.direction) {
        case KEY_UP: newHead.y--; break;
        case KEY_DOWN: newHead.y++; break;
        case KEY_LEFT: newHead.x--; break;
        case KEY_RIGHT: newHead.x++; break;
    }

    for (int i = snake.length - 1; i > 0; i--) {
        snake.pos[i] = snake.pos[i - 1];
    }
    snake.pos[0] = newHead;

    if (newHead.x == food.x && newHead.y == food.y) {
        snake.length++;
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
    }
}

int main() {
    initialize();

    while (1) {
        draw();
        update();
        if (snake.pos[0].x < 0 || snake.pos[0].x >= WIDTH || snake.pos[0].y < 0 || snake.pos[0].y >= HEIGHT) {
            break;
        }
    }

    endwin();
    printf("Game Over! Final Score: %d\n", snake.length - 5);
    return 0;
}

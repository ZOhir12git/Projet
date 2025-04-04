#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

#define WIDTH 30
#define HEIGHT 15

int gameOver;
int x, y; // Snake head position
int dir;  // Direction (0:Up, 1:Right, 2:Down, 3:Left)

void setup() {
    gameOver = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    dir = 1; // Start moving right
}

void draw() {
    system("cls"); // Clear screen (Windows)

    // Top border
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");

    // Game area
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x)
                printf("O"); // Snake head
            else
                printf(" ");
        }
        printf("|\n");
    }

    // Bottom border
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
}

void input() {
    if (_kbhit()) { // If a key is pressed
        switch (_getch()) {
            case 'w': case 'W': case 72: dir = 0; break; // Up
            case 'd': case 'D': case 77: dir = 1; break; // Right
            case 's': case 'S': case 80: dir = 2; break; // Down
            case 'a': case 'A': case 75: dir = 3; break; // Left
            case 'x': case 'X': gameOver = 1; break; // Quit
        }
    }
}

void logic() {
    // Update position based on direction
    switch (dir) {
        case 0: y--; break; // Up
        case 1: x++; break; // Right
        case 2: y++; break; // Down
        case 3: x--; break; // Left
    }

    // Check wall collision
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameOver = 1;
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(200); // Game speed (200ms per move)
    }

    printf("Game Over!\n");
    return 0;
}
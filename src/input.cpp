#include <termios.h>
#include <unistd.h>
#include <cstdio>

#include "../include/input.hpp"

int getch()
{
    struct termios old_termios, new_termios;

    tcgetattr(STDIN_FILENO, &old_termios);

    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    int ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);

    return ch;
}
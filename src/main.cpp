#include <cstdio>
#include <iostream>
#include <chrono>

#include "../include/upl.hpp"
#include "../include/game.hpp"
#include "../include/misc.hpp"


void startup(Console &con) {
    con.clear();

    loading_screen();

    tsleep(chrono::ms(1000));

    typing_animation(" > Presents ", 80);

    tsleep(chrono::ms(600));

    std::cout << Colour::BoldWhite;
    typing_animation("GHOST\n", 80);

    tsleep(chrono::ms(500));

    std::cout << Control::CursorHome;
    fflush(stdout);

    typing_animation("                 \n"
                    "                 \n", 40);
    con.clear();
}

int main() {
    Console con;
    std::cout << Control::CursorHide;

    startup(con);
    tsleep(chrono::ms(1400));
    gamestart(con);

    std::cout << Control::CursorShow;
    con.clear();
    return 0;
}
#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>

#include "../include/upl.hpp"
#include "../include/input.hpp"

#define tsleep(x) std::this_thread::sleep_for(x)
#define ms milliseconds

namespace chrono = std::chrono;

void loading_screen() {

    tsleep(chrono::ms(1000));
    std::cout << Colour::BgRGB(0, 0, 0) << Colour::RGB(255, 255, 255) << "Black" << Control::ColourReset;
    fflush(stdout);

    tsleep(chrono::ms(700));
    std::cout << Colour::BgRGB(0, 0, 0) << Colour::RGB(220, 162, 110) << "Mesa" << Control::ColourReset;
    fflush(stdout);

    tsleep(chrono::ms(700));
    std::cout << Colour::BgRGB(0, 0, 0) << Colour::RGB(255, 255, 255) << " Studios\n" << Control::ColourReset;
    fflush(stdout);

}

void typing_animation(const std::string &text, int interval) {
    for(const auto &ch : text) {
        std::cout << ch;
        fflush(stdout);
        tsleep(chrono::ms(interval));
    }
}

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

}

void gamestart(Console &con) {
    std::cout << Colour::Green << Control::CursorShow;
    fflush(stdout);
    std::string input = "";
    while(input != "exit") {
        std::cout << " > ";
        std::getline(std::cin, input);
    }
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
#include <iostream>

#include "../include/upl.hpp"
#include "../include/view.hpp"
#include "../include/input.hpp"

int main() {
    Console *con = new Console;
    setup_terminal(con);

    std::cout << Colour::BoldWhite << "GHOST\n" << Colour::White;
    getch();
    cleanup_terminal(con);
    return 0;
}
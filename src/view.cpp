#include "../include/upl.hpp"

void setup_terminal(Console *&con) {
    Control::EnterAlternateBuffer();
    con->clear();
}

void cleanup_terminal(Console *&con) {
    con->clear();
    Control::ExitAlternateBuffer();
    delete con;
}
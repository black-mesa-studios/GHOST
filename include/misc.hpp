#pragma once

#include <chrono>
#include <thread>

#define tsleep(x) std::this_thread::sleep_for(x)
#define ms milliseconds

namespace chrono = std::chrono;

void loading_screen();
void typing_animation(const std::string &text, int interval);
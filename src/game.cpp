#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>

#include "../include/upl.hpp"
#include "../include/misc.hpp"

using json = nlohmann::json;

std::vector<std::string> static objectives;
int static lastObjective = 0;

void load_objectives() {
    std::ifstream file("config.json");
    json data = json::parse(file);
    for(auto &objc : data["game"]["objectives"]) {
        objectives.push_back(objc);
    }
    lastObjective = data["game"]["last_objective"];
}

void gamestart(Console &con) {
    load_objectives();
    std::cout << Colour::Green << Control::CursorShow;
    fflush(stdout);
    typing_animation("OBJECTIVE: " + objectives[lastObjective] + "\n", 50);
    std::string input = "";
    while(input != "exit") {
        std::cout << " > ";
        std::getline(std::cin, input);
    }
}
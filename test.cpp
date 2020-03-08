//
// Created by leige on 16.01.20.
//

#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::string> u = {
            {"RED", "#FF0000"},
            {"GREEN", "#00ff00"},
            {"BLUE", "#0000ff"}
    };

    for(const auto& n:u) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
    u["BLACK"] = "#000000";
    u["WHITE"] = "#ffffff";

    std::cout << "the HEX os color RED is:[" << u["RED"] << "]\n";
    std::cout << "the HEX of color BLACK is:[" << u["BLACK"] << "]\n";

    return 0;
}
#include "Game.h"
#include <iostream>

int main() {
    try {
        Plan plan("Player1", "player1@example.com", 1000);

        RPG* rpg = new RPG("Game1", 50, 10, 5, 2);
        Platformer* platformer = new Platformer("Game2", 30, 8, 3, 10);
        SandBox* sandbox = new SandBox("Game3", 20, 25);

        plan.add(rpg);
        plan.add(platformer);
        plan.add(sandbox);

        std::cout << "Plan Information:\n" << plan << std::endl;

        std::cout << "Total Cost: " << plan.TotalCost() << std::endl;
        std::cout << "Average Time: " << plan.averagetime() << std::endl;

        std::cout << "Removing Game2...\n";
        plan.remove("Game2");

        std::cout << "Plan Information After Removal:\n" << plan << std::endl;

        plan.removeall();
        std::cout << "Plan Information After Removing All Games:\n" << plan << std::endl;

        // Don't forget to delete dynamically allocated objects
        delete rpg;
        delete platformer;
        delete sandbox;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


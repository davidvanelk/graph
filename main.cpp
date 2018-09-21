#include <iostream>
#include "simple_graph.h"


int main() {
    unsigned int node_count;
    unsigned int selection;

    std::cout << "How many nodes should your graph contain? Enter a value for unsigned int. (Max. 8 nodes)" << std::endl;
    std::cin >> node_count;
    do {
        std::cout << "Enter what you want to use:\n\t1. Simple graph (connection based algorithms, no edges)\n\t2. Edge graph (edge based algorithms)" << std::endl;
        std::cin >> selection;

        if(selection == 1) {
            sgraph::simple_input(node_count);
        }
        else if(selection == 2) {

        } else {
            std::cout << "\nInvalid input. Please try again.\n";
        }

    } while (selection != 1 && selection != 2);




}


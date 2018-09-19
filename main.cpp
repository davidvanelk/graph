#define NODE_COUNT 5

#include <iostream>
#include "warshall.h"

char * read_matrix();
void print_matrix(char* matr);


int main() {
    char * matrix = read_matrix();
    std::cout << "\n\nVISUALISATION OF ADJACENCY MATRIX:\n##################################\n\n" << std::endl;
    print_matrix(matrix);
    std::cout << "\n\nVISUALISATION OF TRANSITIVE HULL:\n#################################\n\n";
    matrix = transitive_hull(matrix, NODE_COUNT);
    print_matrix(matrix);

    return 0;
}

char * read_matrix() {
    char* matrix = new char[NODE_COUNT];
    for(int i = 0; i < NODE_COUNT; i++) {
        matrix[i] = 0;
        for(int j = 0; j < NODE_COUNT; j++) {
            char input = 0;

            std::cout << "Enter a value for the connection from " << i + 1 << " to " << j + 1 << " (0 for no connection, 1 for connection)" <<  std::endl;
            std::cin >> input;
            if(input == '1') {
                char val = 1 << j;
                matrix[i] = matrix[i] | val;
            }
        }
    }
    return matrix;
}

void print_matrix(char * matr) {
    std::cout << "    ";
    for(int i = 0; i < NODE_COUNT; i++)
        std::cout << i + 1 << " ";
    std::cout << "\n";
    for(int i = 0; i < NODE_COUNT; i++) {
        std::cout << i + 1 << ":  ";
        for(int j = 0; j < NODE_COUNT; j++) {
            char differ = matr[i] & 1 << j;
            if(differ != 0) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
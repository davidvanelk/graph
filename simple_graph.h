//
// Created by david on 21.09.2018.
//
#include <iostream>
#include "warshall.h"

#ifndef WARSHALL_SIMPLE_GRAPH_H
#define WARSHALL_SIMPLE_GRAPH_H

#endif //WARSHALL_SIMPLE_GRAPH_H

namespace sgraph {
    void simple_input(unsigned int node_count);
    char * read_matrix(unsigned int node_count);
    void print_matrix(char* matr, unsigned int node_count);



    void simple_input(unsigned int node_count) {
        char * matrix = read_matrix(node_count);
        std::cout << "\n\nVISUALISATION OF ADJACENCY MATRIX:\n##################################\n\n\n";
        print_matrix(matrix, node_count);
        std::cout << "\n\nVISUALISATION OF TRANSITIVE HULL:\n#################################\n\n";
        matrix = transitive_hull(matrix, node_count);
        print_matrix(matrix, node_count);
    }

    char * read_matrix(unsigned int node_count) {
        char* matrix = new char[node_count];
        for(int i = 0; i < node_count; i++) {
            matrix[i] = 0;
            for(int j = 0; j < node_count; j++) {
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

    void print_matrix(char * matr, unsigned int node_count) {
        std::cout << "    ";
        for(int i = 0; i < node_count; i++)
            std::cout << i + 1 << " ";
        std::cout << "\n";
        for(int i = 0; i < node_count; i++) {
            std::cout << i + 1 << ":  ";
            for(int j = 0; j < node_count; j++) {
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
}


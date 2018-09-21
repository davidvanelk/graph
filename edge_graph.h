//
// Created by david on 21.09.2018.
//
#include <iostream>
#include <cmath>

#ifndef WARSHALL_EDGE_GRAPH_H
#define WARSHALL_EDGE_GRAPH_H

#endif //WARSHALL_EDGE_GRAPH_H

namespace egraph {
    struct gmatrix {
        unsigned int node_count;
        int * matrix;
    };
    int * read_matrix(unsigned int node_count);
    void print_matrix(struct gmatrix matr);


    void edge_main(unsigned int node_count) {

    }

    int * read_matrix(unsigned int node_count) {
        int * matr = new int[pow(node_count, 2)];
        for(int i = 0; i < node_count; i++) {
            for(int j = 0; i < node_count; i++) {
                unsigned int weight;
                std::cout << "Enter the edge-weight from " << i + 1 << " to " << j + 1 << std::endl;
                std::cin >> weight;
                matr[(i * node_count) + j] = weight;
            }
        }
        return matr;
    }

    void print_matrix(struct gmatrix matr) {
        std::cout << "    ";
        for(int i = 0; i < matr.node_count; i++) {
            std::cout << i + 1 << " ";
        }
        std::cout << "\n";
        for(int i = 0; i < matr.node_count; i++) {
            std::cout << i + 1 << ":  ";
            for(int j = 0; j < matr.node_count; j++) {
                std::cout << matr.matrix[(i * matr.node_count) + j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }

}
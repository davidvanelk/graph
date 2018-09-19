//
// Created by david on 18.09.2018.
//

#ifndef WARSHALL_WARSHALL_H
#define WARSHALL_WARSHALL_H

#endif //WARSHALL_WARSHALL_H

char * transitive_hull(char * adj, int n);
char read_col(char * mt, int col_idx, int n);

char * transitive_hull(char * adj, int n) {
    for(int k = 0; k < n; k++) {
        char row = adj[k];
        char col = read_col(adj, k, n);

        for(int i = 0; i < n; i++) {
            if((col & 1 << i) != 0) {
                /* in der aktuellen Spalte steht eine 1 */
                adj[i] = row | adj[i];
            }
        }
    }
    return adj;
}

char read_col(char * mt, int col_idx, int n) {
    char retval = 0;

    for(int i = 0; i < n; i++) {
        /* Row is big endian!!! */
        char row = mt[i];
        char c = 0;
        c = row & 1 << col_idx;
        c = c >> col_idx;
        c = c << i;

        retval = retval | c;
    }
    return retval;
}
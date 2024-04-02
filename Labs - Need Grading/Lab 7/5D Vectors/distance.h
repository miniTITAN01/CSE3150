#ifndef _DISTANCE_H
#define _DISTANCE_H

struct my_distance {
    int id_1, id_2;
    double cos_distance;

    // Default constructor
    my_distance(): id_1(-1), id_2(-1), cos_distance(0.0) {};

    // Copy constructor
    my_distance(const my_distance &dist): id_1(dist.id_1), id_2(dist.id_2), cos_distance(dist.cos_distance) {};

    // Parameterized constructor
    my_distance(int id_1, int id_2, double cos_distance): id_1(id_1), id_2(id_2), cos_distance(cos_distance) {};
};

#endif

#include <cstdlib>

float generateRandomNumberBetween(float low, float high) {
    return low + (rand() / (RAND_MAX / (high - low)));
}
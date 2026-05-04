#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void* a, const void* b) {
    Car* x = (Car*)a;
    Car* y = (Car*)b;
    return y->position - x->position;   // Descending order
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    Car* cars = (Car*)malloc(positionSize * sizeof(Car));

    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        double currentTime = (double)(target - cars[i].position) / cars[i].speed;

        if (currentTime > lastTime) {
            fleets++;
            lastTime = currentTime;
        }
    }

    free(cars);
    return fleets;
}

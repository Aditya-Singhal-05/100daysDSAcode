#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int position;
    int speed;
} Car;

// Sort by position descending
int compare(const void *a, const void *b) {
    return ((Car*)b)->position - ((Car*)a)->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Combine position & speed
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position (descending)
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // If this car forms a new fleet
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // else: joins previous fleet
    }

    return fleets;
}

int main() {
    int n, target;

    scanf("%d %d", &n, &target);

    int position[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}
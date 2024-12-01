#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file = fopen("day1.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    int left[1024], right[1024];
    int count = 0;
    while (fscanf(file, "%d %d", &left[count], &right[count]) == 2) {
        count++;
    }

    fclose(file);
    qsort(left, count, sizeof(int), compare);
    qsort(right, count, sizeof(int), compare);
    int total_distance = 0;
    for (int i = 0; i < count; i++) {
        total_distance += abs(left[i] - right[i]);
    }

    printf("Total distance: %d\n", total_distance);

    return 0;
}

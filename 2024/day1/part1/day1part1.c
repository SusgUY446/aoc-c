#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// compare the 2 inputs
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file = fopen("list.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    int left[1024], right[1024];
    int count = 0;

    // get the list and put them in the right array
    while (fscanf(file, "%d %d", &left[count], &right[count]) == 2) {
        count++;
    }

    fclose(file);

    // sort the values
    qsort(left, count, sizeof(int), compare);
    qsort(right, count, sizeof(int), compare);
    int total_distance = 0;
    for (int i = 0; i < count; i++) {
        total_distance += abs(left[i] - right[i]);
    }

    printf("Total distance: %d\n", total_distance);

    return 0;
}

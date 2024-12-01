#include <stdio.h>
#include <stdlib.h>




int main() {
    FILE *file = fopen("list.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    int left[1024], right[1024];
    int count = 0;

    // read the list and get the required numbers
    while (fscanf(file, "%d %d", &left[count], &right[count]) == 2) {
        count++;
    }

    fclose(file);


    int total_similarity_score = 0;


    for (int i = 0; i < count; i++) {
        int occurrences = 0;
        
        // count occurences
        for (int j = 0; j < count; j++) {
            if (right[j] == left[i]) {
                occurrences++;
            }
        }

        
        total_similarity_score += left[i] * occurrences;
    }

    printf("Total similarity score: %d\n", total_similarity_score);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int compare(const void *a, const void *b) {
    return ((Activity*)a)->end > ((Activity*)b)->end;
}

int main() {
    Activity *activities = NULL;
    int size = 0, start, end;
    while(scanf("%d %d", &start, &end) && (start != 0 || end != 0)) {
        activities = (Activity*)realloc(activities, (size + 1) * sizeof(Activity));
        activities[size].start = start;
        activities[size++].end = end;
    }
    qsort(activities, size, sizeof(Activity), compare);
    int count = 0, last = 0;
    for(int i = 0; i < size; ++i) {
        if(activities[i].start >= last) {
            last = activities[i].end;
            ++count;
        }
    }
    printf("Maximum number of non-overlapping activities: %d\n", count);
    return 0;
}

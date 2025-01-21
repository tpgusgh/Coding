#include <stdio.h>
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int N, step=1;
int student[80];

int partition(int list[], int left, int right) {
    int pivot, temp, low, high;
    low = left;
    high = right + 1;
    pivot = list[left];

    do {
        do {
            low++;
        } while(list[low] > pivot && low <= right); 
        do {
            high--;
        } while(list[high] < pivot);

        if(low<high) {
            swap(list[low], list[high], temp);
        }
    } while(low<high);

    swap(list[left], list[high], temp);
    return high;
}

void quicksort(int list[], int left, int right) {
    if (left<right) {
        int q = partition(list, left, right);
         
        printf("%d단계 : ", step++);
        for(int i=0;i<N;i++) printf("%d ", student[i]);
        puts("");
         
        quicksort(list, left, q-1);
        quicksort(list, q+1, right);

    }
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;i++) scanf("%d", &student[i]);

    quicksort(student, 0, N-1);

    return 0;
}
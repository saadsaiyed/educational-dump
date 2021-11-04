#include <stdio.h>

using namespace std;

void Sort(int[] arr, int size) {
    quickSort(arr, 0, size-1);
}

void quickSort(int[] arr, int i, int j) {
    if (i < j) {
        int pivotIdx = partition(a, i, j);

        quickSort(arr, i, pivotIdx-1);
        quickSort(arr, pivotIdx+1, j);
    }
}

void swap(int[] arr, int firstPosition, int secondPosition) {
    int temp = arr[firstPosition];
    arr[firstPosition] = arr[secondPosition];
    arr[secondPosition] = temp;
}

int partition(int[] arr, int i, int j) {
    int pivot = arr[i];
    int counter = i;

    for (int k = i+1; k <= j; k++) {
        if (arr[k] < p) {
            counter++;
            swap(arr,k,counter);
        }
    }

    swap(arr,i,counter);
    return counter;
}

int main() {
    int arr = ["971","215","703","520","508","385","218","345","149","11","106","708","863","661","993","777","37","994","830","704","252","823","558","637","647","392","386","691","499","188","680","685","454","312","626","435","447","55","25","408","169","726","449","428","154","521","370","560","459","836","816","903","969","920","444","970","781","158","483","597","401","298","365","889","224","753","565","646","752","604","783","244","488","176","931","758","402","204","659","972","373","417","369","507","880","261","131","588","260","91","514","63","247","617","410","869","455","160","907","122"];
    
    Sort(arr, 100);
    return 0;
}
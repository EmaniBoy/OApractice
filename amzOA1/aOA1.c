#include <stdio.h>
#include <stdlib.h>

//comparison function for decending sort
int compare(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

//function to calculate max system throughput
long getMaxThroughput(int host_throughput[], int n){
    //sort array in decending order(quicksort)
    qsort(host_throughput, n, sizeof(int), compare);

    long max_throughput = 0;

    //pick every third element starting from index 1 (1-based second largest)
    for(int i = 1; i + 2 < n; i+= 3){
        max_throughput += host_throughput[i]; // add median of the cluster
    }
    return max_throughput;
}

int main(){
    //ex 1
    int host_throughput1[] = {4, 6, 3, 5, 4, 5};
    int n1 = sizeof(host_throughput1) / sizeof(host_throughput1[0]);
    printf("max system throughput: %ld\n", getMaxThroughput(host_throughput1, n1));
    
    //ex 2
    int host_throughput2[] = {2, 3, 4, 3, 4};
    int n2 = sizeof(host_throughput2)/ sizeof(host_throughput2[0]);
    printf("max system throughput: %ld\n", getMaxThroughput(host_throughput2, n2));

    return 0;
}
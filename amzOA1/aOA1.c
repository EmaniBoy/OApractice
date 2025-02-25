#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

long getMaxThroughput(int host_throughput[], int n){
    qsort(host_throughput, n, sizeof(int), compare);

    long max_throughput = 0;

    for(int i = 1; i + 2 < n; i+= 3){
        max_throughput += host_throughput[i];
    }
    return max_throughput;
}

int main(){
    
    int host_throughput1[] = {4, 6, 3, 5, 4, 5};
    int n1 = sizeof(host_throughput1) / sizeof(host_throughput1[0]);
    printf("max system throughput: %ld\n", getMaxThroughput(host_throughput1, n1));
    
    int host_throughput2[] = {2, 3, 4, 3, 4};
    int n2 = sizeof(host_throughput2)/ sizeof(host_throughput2[0]);
    printf("max system throughput: %ld\n", getMaxThroughput(host_throughput2, n2));

    return 0;
}
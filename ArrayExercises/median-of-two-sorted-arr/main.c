// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// this solution is not O(log(m + n)), it's O(m + n)
#include <stdio.h>
#include <stdlib.h>

void add_remaining_elements(int *arr, int arr_size, int arr_cnt, int *sorted,
                            int sorted_cnt)
{
    while (arr_cnt < arr_size) {
        sorted[sorted_cnt] = arr[arr_cnt];
        sorted_cnt++;
        arr_cnt++;
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size)
{
    int sortedSize = nums1Size + nums2Size;
    int *sorted = malloc(sizeof(int) * sortedSize);
    double median;

    int i = 0, j = 0, k = 0;
    while ((i < nums1Size) && (j < nums2Size)) {
        if (nums1[i] < nums2[j]) {
            sorted[k] = nums1[i];
            i++;
            k++;
        } else {
            sorted[k] = nums2[j];
            j++;
            k++;
        }
    }
    add_remaining_elements(nums1, nums1Size, i, sorted, k);
    add_remaining_elements(nums2, nums2Size, j, sorted, k);

    switch (sortedSize % 2) { // look up definition of median
    case 0:
        median =
            (double)(sorted[sortedSize / 2] + sorted[(sortedSize / 2) - 1]) /
            2.0;
        free(sorted);
        return median;
    case 1:
        median = (double)sorted[sortedSize / 2];
        free(sorted);
        return median;
    }

    return -1;
}

int main(void)
{
    int x[2] = {1, 3};
    int y[1] = {2};
    printf("%.2f\n", findMedianSortedArrays(x, 2, y, 1));
    int xx[3] = {2, 6, 7};
    int yy[3] = {0, 2, 9};
    printf("%.2f\n", findMedianSortedArrays(xx, 3, yy, 3));

    return EXIT_SUCCESS;
}

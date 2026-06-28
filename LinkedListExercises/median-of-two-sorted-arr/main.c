#include <stdio.h>
#include <stdlib.h>

void add_remaining_elements(int *arr, int arr_size, int arr_cnt, int* sorted, int sorted_cnt) {
    while (arr_cnt < arr_size) {
        sorted[sorted_cnt] = arr[arr_cnt];
        sorted_cnt++;
        arr_cnt++;
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size)
{
    double median;

    int sortedSize = nums1Size + nums2Size;
    int *sorted = malloc(sizeof(int) * sortedSize);

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

    switch (sortedSize % 2) {
    case 0:
        printf("sorted[%d] = %d\n", sortedSize / 2, sorted[sortedSize / 2]);
        printf("sorted[%d] = %d\n", sortedSize / 2 - 1, sorted[sortedSize / 2 - 1]);
        median = sorted[sortedSize / 2] + sorted[(sortedSize / 2) - 1];
        break;
    case 1:
        median = sorted[sortedSize / 2];
        break;
    }

    return median / 2;
}

int main(void)
{
    int x[2] = {1, 3};
    int y[1] = {2};
    printf("%.2f\n", findMedianSortedArrays(x, 2, y, 1));

    return EXIT_SUCCESS;
}

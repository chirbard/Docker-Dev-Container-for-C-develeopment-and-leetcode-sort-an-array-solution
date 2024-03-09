#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int* merge(int* leftPartArrayPointer, int leftPartSize, int* rightPartArrayPointer, int rightPartSize) {
  int* mergedArray = (int*)malloc((leftPartSize + rightPartSize) * sizeof(int));

  int leftIteration = 0;
  int rightIteration = 0;
  int iteration = 0;

   while (leftIteration < leftPartSize || rightIteration < rightPartSize) {
    if (leftIteration >= leftPartSize) {
      mergedArray[iteration] = rightPartArrayPointer[rightIteration];
      rightIteration++;
      iteration++;
      continue;
    } else if (rightIteration >= rightPartSize) {
      mergedArray[iteration] = leftPartArrayPointer[leftIteration];
      leftIteration++;
      iteration++;
      continue;
    }

    if (leftPartArrayPointer[leftIteration] < rightPartArrayPointer[rightIteration]) {
      mergedArray[iteration] = leftPartArrayPointer[leftIteration];
      leftIteration++;
      iteration++;
      continue;
    }
    mergedArray[iteration] = rightPartArrayPointer[rightIteration];
    rightIteration++;
    iteration++;
  }

  return mergedArray;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  if (numsSize == 1) {
    return nums;
  }
  if (numsSize == 2) {
    if (nums[0] > nums[1]) {
      swap(&nums[0], &nums[1]);
    }
    return nums;
  }

  int leftPartSize = numsSize / 2;
  int rightPartSize = numsSize - leftPartSize;

  int* leftPartArrayPointer = &nums[0];
  int* rightPartArrayPointer = &nums[leftPartSize];

  int leftSize, rightSize;

  int* sortedLeft = sortArray(leftPartArrayPointer, leftPartSize, &leftSize);
  int* sortedRight = sortArray(rightPartArrayPointer, rightPartSize, &rightSize);


  int* result = merge(sortedLeft, leftSize, sortedRight, rightSize);

  return result;
}

	
int main(void) {
  int array[] = {8,7,6,5,4,3,2,1};
  int numsSize = sizeof(array) / sizeof(array[0]);
  int returnSize;

  int* sortedArray = sortArray(array, numsSize, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%d ", sortedArray[i]);
  }
  printf("\n");

  free(sortedArray);
  return EXIT_SUCCESS;
}
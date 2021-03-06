// a collection of the sorting algorithms I've met.

// BubleSort: a most simple way to sort a series of numbers.
// but not so efficient.
// @Param numbers: the array pointer storing the numbers
// @Param beginning, tail: show the range we need to sort.(begin <= i < tail)
void BubleSort(int *numbers, int beginning, int tail) {
  for (int i = beginning; i < tail; i++) {
    for (int j = tail - 1; j > i; j--) {
      if (numbers[j] < numbers[j - 1]) {
        int tmp = numbers[j - 1];
        numbers[j - 1] = numbers[j];
        numbers[j] = tmp;
      }
    }
  }
}

// SelectionSort: a unstable sorting algorithm.
// @Param numbers: the array pointer storing the numbers
// @Param beginning, tail: show the range we need to sort.(beginning <= i < tail)
void SelectionSort(int* numbers, int beginning, int tail) {
  for (int i = beginning; i < tail; i++) {
    // suppose the index of the number is i, and the left of i is sorted.
    // then find the mininum of the rest and exchange it with numbers[i].
    int min = i;
    for (int j = i + 1; j < tail; j++) {
      if (numbers[j] < numbers[min]) min = j;
    }

    // exchange. when a smaller number than nubmers[i] is found, exchange them.
    if (i != min) {
      int temp = numbers[min];
      numbers[min] = numbers[i];
      numbers[i] = temp;
    }
  }
}

// InsertionSort: a stable sorting algorithm that insert a number to the sorted
// sequence till all numbers are sorted.
// @Param numbers: the array pointer storing the numbers
// @Param beginning, tail: show the range we need to sort.(beginning <= i < tail)
void InsertionSort(int* numbers, int beginning, int tail) {
  for (int i = beginning, i < tail; i++) {
    // insert numbers[j] to certain position
    int temp = numbers[i+1];
    for (int j = i+1; j > beginning; j--) {
      if (numbers[temp] < numbers[j-1]) {
        // if j is not the position, move temp to the index before j
        // and store the data.
        numbers[j] = numbers[j-1];
      } else {
        numbers[j] = temp;      // if j is the position, insert it
        break;                  // and go to insert the next number.
      }
    }
  }
}

// QuickSort.Just to put the numbers smaller than x on the left
// and the bigger on the right.
// @Param numbers: the array pointer storing the numbers
// @Param beginning, tail: show the range we need to sort.(beginning <= i < tail)
void QuickSort(int *numbers, int head, int tail) {
  int t, i = head, j = tail, x = numbers[(i + j) / 2];
  do {
    while (x > numbers[i]) i++;
    while (x < numbers[j]) j--;
    if (i <= j) {
      temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;
      i++; j--;
    }
  } while (i <= j);
  if (i < tail) quick_sort(numbers, i, tail);     // sort the left
  if (head < j) quick_sort(numbers, head, j);   // sort the right
}

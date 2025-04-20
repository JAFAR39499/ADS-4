// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int pairs = 0;
  int first = 0;
  while (first < len) {
    int second = first + 1;
    while (second < len) {
      if (arr[first] + arr[second] == value) {
        pairs++;
      }
      second++;
    }
    first++;
  }
  return pairs;
}

int countPairs2(int* arr, int len, int value) {
  int result = 0;
  int right = len - 1;
  while (right >= 0 && arr[right] > value) {
    right--;
  }
  int left = 0;
  while (left < right) {
    int current = arr[left];
    int j = right;
    while (j > left) {
      if (current + arr[j] == value) {
        result++;
      }
      j--;
    }
    left++;
  }
  return result;
}

int findMatches(int* array, int start, int end, int target) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (array[mid] == target) {
      int matches = 1;
      int left = mid - 1;
      while (left >= start && array[left] == target) {
        matches++;
        left--;
      }
      int right = mid + 1;
      while (right <= end && array[right] == target) {
        matches++;
        right++;
      }
      return matches;
    } else if (array[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return 0;
}

int countPairs3(int* arr, int len, int value) {
  int total = 0;
  int i = 0;
  while (i < len - 1) {
    int needed = value - arr[i];
    total += findMatches(arr, i + 1, len - 1, needed);
    i++;
  }
  return total;
}

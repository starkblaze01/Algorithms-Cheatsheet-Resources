class QuickSort {

  // quicksort the array
  static void sort(List<Comparable> a) {
    _shuffle(a);
    _sortWithComparable(a, 0, a.length - 1);
  }
  
  // quicksort the subarray from a[lo] to a[hi]
  static void _sortWithComparable(List<Comparable> a, int lo, int hi) {
    if (hi <= lo) {
      return;
    }
    
    int j = _partition(a, lo, hi);
    _sortWithComparable(a, lo, j-1);
    _sortWithComparable(a, j+1, hi);
    assert(_isSortedInRange(a, lo, hi));
  }
  
  // partition the subarray a[lo .. hi] by returning an index j
  // so that a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
  static int _partition(List<Comparable> a, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    Comparable v = a[lo];
    
    while (true) {
      
      // find item on lo to swap
      while (_less(a[++i], v)) {
        if (i==hi) {
          break;
        }
      }
      
      // find item on hi to swap
      while (_less(v, a[--j])) {
        if (j == lo) { // redundant since a[lo] acts as sentinel
          break; 
        }
      }
      
      // check if pointers cross
      if (i >= j) {
        break;
      }
      
      _exch(a, i, j);
    }
    
    // put v = a[j] into position
    _exch(a, lo, j);
    
    // with a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
    return j;
  }
  
  static void _shuffle(List a) {
    int N = a.length;
    for (int i = 0; i<N; i++) {
      int r = i + (Math.random() * (N - i)).toInt();
      String swap = a[r];
      a[r] = a[i];
      a[i] = swap;
    }
  }
  /***********************************************************************
   *  Rearranges the elements in a so that a[k] is the kth smallest element,
   *  and a[0] through a[k-1] are less than or equal to a[k], and
   *  a[k+1] through a[n-1] are greater than or equal to a[k].
   ***********************************************************************/
  static Comparable select(List<Comparable> a, int k) {
    if (k < 0 || k >= a.length) {
      throw new Exception("Selected element out of bounds");
    }
    
    _shuffle(a);
    int lo = 0, hi = a.length - 1;
    while (hi > lo) {
      int i = _partition(a, lo, hi);
      if (i > k) {
        hi = i - 1;
      } else if (i < k) {
        lo = i + 1;
      } else {
        return a[i];
      }
    }
    return a[lo];
  
  }
  //Helper sorting functions
  // is v < w ?
  static bool _less(Comparable v, Comparable w) {
    return (v.compareTo(w) < 0);
  }
    
  // exchange a[i] and a[j] 
  static void _exch(List a, int i, int j) {
    var swap = a[i];
    a[i] = a[j];
    a[j] = swap;
  }
  
  // Check if array is sorted - useful for debugging
  // is the list sorted
  static bool _isSorted(List<Comparable> a) {
    return _isSortedInRange(a, 0, a.length-1);
  }
  
  // is the list sorted from a[lo] to a[hi]
  static bool _isSortedInRange(List<Comparable> a, int lo, int hi) {
    for (int i= lo + 1; i <= hi; i++) {
      if (_less(a[i], a[i-1])) {
        return false;
      }
    }
    
    return true;
  }
  // print to standard output
  static show(List<Comparable> a) {
    for (int i = 0; i < a.length; i++) {
      print(a[i]);
    }
  }
}

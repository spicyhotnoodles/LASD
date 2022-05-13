
namespace lasd {

/* ************************************************************************** */

// Auxiliary function
template<typename Data>
void BST<Data>::QuickSort(LinearContainer<Data>& lc, int p, int r) {
     if (p < r) {
         int q = partition(lc, p, r);
         QuickSort(lc, p, q - 1);
         QuickSort(lc, q + 1, r);
     }
}

template<typename Data>
void BST<Data>::partition(LinearContainer<Data>& lc, int p, int r) {
    int x = lc[r];
    int i = p - 1;
    //int j = r + 1;
    for (int j = p; j < r; j++) {
        if (lc[j] <= x) {
            i++;
            swap(&lc[i], &lc[j]);
        }
    }
    swap(&lc[i + 1], &lc[r]);
    return (i + 1);
}

/* ************************************************************************** */

}

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// bubble sort

// bubble Sort em ordem decrescente
/*void bubble_sort_invertido(int n[], int t) {
  int temp = 0;
  for (int i = 0; i < t; i++) {
    int entrou = 0;
    for (int j = 0; j < t - i - 1; j++) {
      if (n[j] < n[j + 1]) {
        temp = n[j];
        n[j] = n[j + 1];
        n[j + 1] = temp;
        entrou = 1;
        for (int k = 0; k < t; k++) {
          printf("%d ", n[k]);
        }
        printf("\n");
      }
    }
    if (entrou == 0)
      return;
  }
}*/
/*void bubble_sort(int n[], int t){
  int temp=0;
  for(int i=0; i<t-1; i++){
    int entrou=0;
    for(int j=0; j<t-i-1; j++){
      if(n[j]>n[j+1]){
        temp=n[j];
        n[j]=n[j+1];
        n[j+1]= temp;
        entrou=1;
        for(int k=0; k<t; k++) {
          printf("%d ", n[k]);
        }
        printf("\n");
      }

    }
    if(entrou==0)return;
  }
}*/

// bubble sort recursivo
void printArray(int n[], int t) { 
  for (int i = 0; i < t; i++) { printf("%d ", n[i]);
  } printf("\n");
}
/*void bubblesort_recursivo_aux(int n[], int t, int j){
   if(t==1)return;
   if(j<t-1){
     if(n[j]>=n[j+1]){
       int k=0;
       int temp=0;
       temp=n[j];
       n[j]=n[j+1];
       n[j+1]= temp;
     }
     printArray(n, t);
     bubblesort_recursivo_aux(n, t, j+1);
   } else{
   bubblesort_recursivo_aux(n, t-1, 0);
   } 
 }

void bubblesort_recursivo(int n[], int t){
 bubblesort_recursivo_aux(n,t,0);
}
*/

/*void Bubble_Sort(int a[], int n){
  for(int i=0; i<n-1; i++){
    //int trocou=0;
    for(int j=0; j<n-i-1; j++){
      if(a[j]>=a[j+1]){
        int aux= a[j];
        a[j]= a[j+1];
        a[j+1]= aux;
        //trocou=1;
        for(int k=0; k<n; k++) {
          printf("%d ", a[k]);
        }
        printf("\n");
      }
    }
    //if(trocou==0) break;
  }
}
  int main() {
    int array[] = {2,4,6,10,9,12};
    int tamanho=6;
    Bubble_Sort(array, tamanho);
    // bubble_sort(array, tamanho);
    return 0;
  }*/
 // }


/*void Bubble_sort_aux(int a[], int t, int j){
  if(t==1) return;
  if(j<t-1){
    if(a[j]>a[j+1]){
      int aux= a[j];
      a[j]= a[j+1];
      a[j+1]= aux;
    }
   // printArray(a, t);
    for(int k=0; k<t; k++){
      printf("%d ", a[k]);
    }
     printf("\n");
    Bubble_sort_aux(a, t, j+1);
  }
    else{
      Bubble_sort_aux(a, t-1, 0);
    }
  }

void Bubble_sort_recursive(int a[], int t){
  Bubble_sort_aux(a, t, 0);
}
int main() {
  int array[] = {6,4,5,1,7,8};
  int tamanho=6;
  Bubble_sort_recursive(array, tamanho);
  // bubble_sort(array, tamanho);

 
  return 0;
}
*/
// Insertion sort

/*void Insertion_Sort (int arr[], int t){
  int chave;
  int j=0;
  for(int i=1; i<t; i++){
    chave=arr[i];
    j=i-1;
    while(j>= 0 && arr[j]> chave){
      arr[j+1]= arr[j];
      j= j-1;
    }
    arr[j+1]= chave;
    for(int k=0; k<t; k++) {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}*/

/*void inserir(int arr[], int n) {
    int chave = arr[n];
    int j = n - 1;

    while (j >= 0 && arr[j] > chave) {
        arr[j + 1] = arr[j];
        j --;
    }
    arr[j + 1] = chave;
    printArray(arr, n+1);
}
void insertionSortRecursivo(int arr[], int n) {
    if (n <= 1) return;
    
    insertionSortRecursivo(arr, n - 1);

    inserir(arr, n - 1);
}

int main() {
  int array[] = {2,4,6,10,9,12};
  int tamanho=6;
 // Insertion_Sort(array, 6);
  insertionSortRecursivo(array, 6);
  return 0;
}
*/
/*void Insertion_Sort_decrescente (int arr[], int t){
  int chave;
  int j=0;
  for(int i=1; i<t; i++){
    chave=arr[i];
    j=i-1;
    while(j>= 0 && arr[j]< chave){
      arr[j+1]= arr[j];
      j= j-1;
    }
    arr[j+1]= chave;
    for(int k=0; k<t; k++) {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}*/

/*void Insertion_Sort_Recursivo(int arr[], int t, int i) {
  int chave, j = 0;
  if (t == 1)
    return;
  if (i < t) {
    chave = arr[i];
    j = i - 1;

    if (j <= 0 && arr[j] < chave) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = chave;
    for (int k = 0; k < t; k++) {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}*/
/*void merge(int arr[], int esq_ini, int esq_fim, int dir_ini, int dir_fim) {
  int n_dir = dir_fim - dir_ini + 1;
  int n_esq = esq_fim - esq_ini + 1;

  int esq[n_esq], dir[n_dir];
  for (int i = 0; i < n_esq; i++) {
    esq[i] = arr[i + esq_ini];
  }
  for (int i = 0; i < n_dir; i++) {
    dir[i] = arr[i + dir_ini];
  }

  int i1 = 0, i2 = 0;
  for (int i = esq_ini; i <= dir_fim; i++) {
    if (i2 >= n_dir || (i1 < n_esq && esq[i1] < dir[i2])) {
      arr[i] = esq[i1];
      i1++;
    } else {
      arr[i] = dir[i2];
      i2++;
    }
  }
}
void merge_Sort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_Sort(arr, l, m);
    merge_Sort(arr, m + 1, r);
    merge(arr, l, m, m + 1, r);
    for (int i = 0; i < 6; i++) {
      printf("%d", arr[i]);
    }
    printf("\n");
  }
}
int main() {
  int array[] = {2,4,6,10,9,12};
  //int tamanho=6;
 merge_Sort(array,0,5);
  return 0;
}*/


//Quick Sort
/*void swap(int* a, int* b) {
  int t = *a; *a = *b; *b = t;
}
                           
int partition(int a[],int l, int r){
  int pivot= a[r];
  int i= l-1;
  for(int j=l; j<= r-1; j++){
    if(a[j]>pivot){
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i+1], &a[r]);
  return i+1;
}

void quick_Sort(int a[], int l, int r){
  if(l<r){
    int q= partition(a,l,r);
    quick_Sort(a,l,q-1);
    quick_Sort(a,q+1,r);
    for (int i = 0; i <6 ; i++) { 
      printf("%d ", a[i]); 
    } 
    printf("\n");
  }
}*/


#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
        if (a[j] < pivot) {  // Esta condição ordena em ordem crescente
            i++; 
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    for (int k = 0; k < 7; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
    return i + 1;
}

void quick_sort(int a[], int t) {
    int l = 0, r = t - 1;

    while (l < r) {
        int q = partition(a, l, r);

        if (q - l < r - q) {
            int new_r = q - 1;
            while (l < new_r) {
                int p = partition(a, l, new_r);
                new_r = p - 1;
            }
            l = q + 1;
        } else {
            int new_l = q + 1;
            while (new_l < r) {
                int p = partition(a, new_l, r);
                new_l = p + 1;
            }
            r = q - 1;
        }
    }
}


  
  
  /*if(l<r){
    int q= partition(a,l,r);
    quick_sort(a,l,q-1);
    quick_sort(a,q+1,r);
  }*/

/*#include <stdio.h>
#include <stdio.h>

// Função merge fornecida
void merge(int a[], int esq_ini, int esq_fim, int dir_ini, int dir_fim) {
    int n_dir = dir_fim - dir_ini + 1;
    int n_esq = esq_fim - esq_ini + 1;

    int esq[n_esq], dir[n_dir];

    for (int i = 0; i < n_esq; i++) {
        esq[i] = a[i + esq_ini];
    }

    for (int i = 0; i < n_dir; i++) {
        dir[i] = a[i + dir_ini];
    }

    int i1 = 0, i2 = 0;

    for (int i = esq_ini; i <= dir_fim; i++) {
        if (i2 >= n_dir || (i1 < n_esq && esq[i1] < dir[i2])) {
            a[i] = esq[i1];
            i1++;
        } else {
            a[i] = dir[i2];
            i2++;
        }
    }
}

// Função iterativa para Merge Sort
void merge_sort_iterativo(int a[], int n) {
    int curr_size;
    int left_start;

    // O loop mescla subarrays de tamanho curr_size
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1;

            if (right_end >= n) {
                right_end = n - 1;
            }
            if (mid < n - 1) {
                merge(a, left_start, mid, mid + 1, right_end);
            }

            // Imprimir array a cada iteração
            for (int k = 0; k < n; k++) {
                printf("%d ", a[k]);
            }
            printf("\n");
        }
    }
}*/

int main() {
    int array[] = {8, 7, 6, 4, 12, 2, 10};
    int n = 7;

  //  merge_sort_iterativo(array, n);
  quick_sort(array, n);
    return 0;
}


void swap(int *x, int *y);

// Funcao que implementa o ordenamento bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++)    
    // Os ultimos i elementos ja estao na ordem
    for(j = 0; j < n-i-1; j++)
        if(arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

// Funcao que implementa o ordenamento quick sort
void quickSort(int valor[], int esquerda, int direita) {
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j) {	
        while(valor[i] < x && i < direita)
            i++;

        while(valor[j] > x && j > esquerda)
            j--;

        if(i <= j) {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }

    if(j > esquerda)
        quickSort(valor, esquerda, j);
   
    if(i < direita)
        quickSort(valor, i, direita);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

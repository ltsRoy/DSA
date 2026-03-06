Strassen
#include <stdio.h>

int main()
{
    int arr[2][2], brr[2][2], crr[2][2];

    printf("Enter first matrix:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Enter second matrix:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&brr[i][j]);
        }
    }

    int m1,m2,m3,m4,m5,m6,m7;

    m1 = (arr[0][0] + arr[1][1]) * (brr[0][0] + brr[1][1]);
    m2 = (arr[1][0] + arr[1][1]) * brr[0][0];
    m3 = arr[0][0] * (brr[0][1] - brr[1][1]);
    m4 = arr[1][1] * (brr[1][0] - brr[0][0]);
    m5 = (arr[0][0] + arr[0][1]) * brr[1][1];
    m6 = (arr[1][0] - arr[0][0]) * (brr[0][0] + brr[0][1]);
    m7 = (arr[0][1] - arr[1][1]) * (brr[1][0] + brr[1][1]);

    crr[0][0] = m1 + m4 - m5 + m7;
    crr[0][1] = m3 + m5;
    crr[1][0] = m2 + m4;
    crr[1][1] = m1 + m3 - m2 + m6;

    printf("Resultant matrix is:\n");

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",crr[i][j]);
        }
        printf("\n");
    }

    return 0;
}







Jobs
#include <stdio.h>

char jobs[50];
int pro[50], dl[50];
int ts[50], result[50];
int dmax = 0, max_pro = 0;

void sorting(int n)
{
    int i,j;
    char tempJob;
    int tempPro, tempDl;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(pro[j] < pro[j+1])
            {
                tempPro = pro[j];
                pro[j] = pro[j+1];
                pro[j+1] = tempPro;

                tempDl = dl[j];
                dl[j] = dl[j+1];
                dl[j+1] = tempDl;

                tempJob = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = tempJob;
            }
        }
    }
}

void Job_Sq_Dl(int n)
{
    int i,k;

    for(i=0;i<n;i++)
    {
        k = (dl[i] < dmax) ? dl[i] : dmax;

        while(k>=1)
        {
            if(ts[k-1] == -1)
            {
                ts[k-1] = 1;
                result[k-1] = i;
                max_pro = max_pro + pro[i];
                break;
            }
            k--;
        }
    }
}

int main()
{
    int i,n;

    printf("Enter number of jobs: ");
    scanf("%d",&n);

    printf("Enter job names:\n");
    for(i=0;i<n;i++)
    {
        scanf(" %c",&jobs[i]);
    }

    printf("Enter profits:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pro[i]);
    }

    printf("Enter deadlines:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&dl[i]);
    }

    sorting(n);

    for(i=0;i<n;i++)
    {
        if(dl[i] > dmax)
        {
            dmax = dl[i];
        }
    }

    for(i=0;i<dmax;i++)
    {
        ts[i] = -1;
    }

    Job_Sq_Dl(n);

    printf("\nMaximum Profit = %d\n",max_pro);

    printf("Selected Jobs:\n");
    for(i=0;i<dmax;i++)
    {
        if(ts[i] != -1)
        {
            printf("%c\n",jobs[result[i]]);
        }
    }

    return 0;
}





Floyd Warshall
#include<stdio.h>

int d[20][20], n;

void floydWarshall()
{
    int i,j,k;

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main()
{
    int i,j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&d[i][j]);

            if(i!=j && d[i][j]==0)
                d[i][j]=999;
        }
    }

    floydWarshall();

    printf("\nShortest path matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }

    return 0;
}









N queen
#include <stdio.h>
#include <math.h>

int x[50], n, count = 0;

int place(int k, int i)
{
    int j;

    for(j = 1; j <= k-1; j++)
    {
        if((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
        {
            return 0;
        }
    }

    return 1;
}

void sol()
{
    int i, j;

    printf("\nSolution #%d:\n", count + 1);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void nqueen(int k)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                sol();
                count++;
            }
            else
            {
                nqueen(k + 1);
            }
        }
    }
}

int main()
{
    printf("Enter the No. of Queens: ");
    scanf("%d", &n);

    nqueen(1);

    printf("\nTotal Solutions = %d", count);

    return 0;
}





Naive
#include <stdio.h>
#include <string.h>

// method to search for pattern
void naiveFindPatrn(char* mainString, char* pattern, int array[], int *index)
{
    int patLen = strlen(pattern);
    int strLen = strlen(mainString);

    // outer loop
    for(int i = 0; i <= (strLen - patLen); i++)
    {
        int j;

        // check each character of pattern
        for(j = 0; j < patLen; j++)
        {
            if(mainString[i + j] != pattern[j])
                break;
        }

        // if full pattern matched
        if(j == patLen)
        {
            (*index)++;
            array[(*index)] = i;
        }
    }
}

int main()
{
    // main string
    char mainString[] = "ABAAABCDBBABCDDEBCABC";

    // pattern to search
    char pattern[] = "ABC";

    int locArray[strlen(mainString)];
    int index = -1;

    naiveFindPatrn(mainString, pattern, locArray, &index);

    // print positions
    for(int i = 0; i <= index; i++)
    {
        printf("Pattern found at position: %d\n", locArray[i]);
    }

    return 0;
}







Knapsack
#include <stdio.h>

float p[10], w[10], x[10];
float r[10];

void knapsack(float m, int n)
{
    float u;
    int i;

    u = m;

    for(i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for(i = 0; i < n; i++)
    {
        if(w[i] > u)
            break;

        x[i] = 1.0;
        u = u - w[i];
    }

    if(i < n)
    {
        x[i] = u / w[i];
    }
}

int main()
{
    int n, i, j;
    float m, temp, temp1, temp2;
    float tp = 0.0;

    printf("Enter no of elements:\n");
    scanf("%d", &n);

    printf("Enter maximum capacity:\n");
    scanf("%f", &m);

    printf("Enter weights of the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &w[i]);
    }

    printf("Enter profits of the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &p[i]);
    }

    for(i = 0; i < n; i++)
    {
        r[i] = p[i] / w[i];
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(r[j] < r[j + 1])
            {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;

                temp1 = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp1;

                temp2 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp2;
            }
        }
    }

    printf("profit ratio:\n");
    for(i = 0; i < n; i++)
    {
        printf("%f\t", r[i]);
    }

    knapsack(m, n);

    printf("\nThe solution vector is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
    }

    for(i = 0; i < n; i++)
    {
        tp = tp + (p[i] * x[i]);
    }

    printf("\nTotal profit is %f", tp);

    return 0;
}








Merge Sort:
#include <stdio.h>

void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

void merge_sort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j <= high)
    {
        temp[k++] = arr[j++];
    }

    for(i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, size - 1);

    printf("Sorted array:\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

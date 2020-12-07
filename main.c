#include <stdio.h>
#include <stdlib.h>


int zd1()
{
    int n, i, k;
    k = 0;
    printf("vvedite chislo elementov massiva\n");
    scanf("%d", &n);
    int a[n];
    printf("vvedite massiv\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i != 0)
        {
            if (a[i]*a[i - 1] < 0)
                k += 1;
        }
    }
    printf("%d\n", k);



    return 0;
}


int zd2()
{
    int n, i, k, o, p;
    p = 1;
    o = 0;
    k = 0;
    printf("vvedite chislo elementov massiva\n");
    scanf("%d", &n);
    int a[n];
    printf("vvedite massiv\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if ((p*a[i]) % 2 == 1)
            k += 1;
        else
        {
            if (k > o)
                o = k;
            k = 0;
            p = 1;
        }

    }
    if (k > o)
        o = k;
    printf("%d\n", o);


    return 0;
}


int zd3()
{
    int n;
    printf("vvedite chislo elementov massiva\n");
    scanf("%d", &n);
    int a[n];
    int i, k, m, f;
    f = n;
    printf("vvedite massiv:\n");
    for (i = 0; i<f; i++)
        scanf("%d", &a[i]);

    for (k=0; k<f; k++)
    {
        for (m=0; m<k; m++)
        {
            if (a[k]==a[m])
            {
                for (i=k; i<n; i++)
                {
                    a[i] = a[i+1];
                }
                a[n-1]=0;
                k=k-1;
                f-=1;
                break;
            }
        }
    }

    for (i = 0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");


    return 0;
}


int zd4()
{
    int n, i, max1, max2;
    max1 = 0;
    max2 = 0;
    printf("vvedite chislo elementov massiva\n");
    scanf("%d", &n);
    int a[n];
    printf("vvedite massiv\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max1)
        {
            max2 = max1;
            max1 = a[i];
        }
        if ((a[i] > max2) && (a[i] < max1))
            max2 = a[i];
    }
    printf("%d\n", max2);


    return 0;
}


int bin_s(int a[], int n, int l, int r, int x)
{
    int m = (l + r) / 2;
    if (l > r)
        return -1;
    else
    {
        if (a[m] == x)
            return m;
        if (a[m] > x)
            return bin_s(a, n, l, m-1, x);
        else
            return bin_s(a, n, m+1, r, x);
    }
}

int zd5()
{
    int n;
    printf("vvedite chislo elementov massiva:\n");
    scanf("%d", &n);
    int a[n];
    int i, l, r, x;
    l = 0;
    r = n - 1;
    printf("vvedite massiv: \n");
    for (i = 0; i<n; i++)
        scanf("%d", &a[i]);
    printf("vvedite element: \n");
    scanf("%d", &x);
    i = bin_s(a, n, l, r, x);
    if (i == -1)
        printf("takogo net\n");
    else
        printf("%d\n", i+1);


    return 0;
}

int* ob(int a[],int b[], int n, int m)
{
    int* c;
    c = (int*) malloc((n+m)*sizeof(int));
    int A = 0, B = 0, i;
    for (i = 0; i < m+n; i++)
    {
        if ((A < n) && (B < m))
        {
            if (a[A] < b[B])
            {
                c[i] = a[A];
                A += 1;
            }
            else
            {
                c[i] = b[B];
                B += 1;
            }
        }
        else
        {
            if (A == n)
            {
                c[i] = b[B];
                B += 1;
            }
            else
            {
                c[i]=a[A];
                A+=1;
            }

        }
    }

return c;

}

int zd6()
{
    int n, m;
    printf("vvedite m i n\n");
    scanf("%d%d", &n, &m);
    int* a;
    a = (int*) malloc(n*sizeof(int));
    int* b;
    b = (int*) malloc(m*sizeof(int));
    int i=0;
    printf("vvedite 1 massiv\n");
    for (i=0; i < n; i++)
        scanf("%d", a+i);
    printf("vvedite 2 massiv\n");
    for (i=0; i < m; i++)
        scanf("%d", b+i);
    int* c = ob(a, b, n, m);

    for (i=0; i < n + m; i++)
        printf("%d ", c[i]);
    printf("\n");


    return 0;
}




int main()
{
    int i = 1;
    while (i)
    {
        printf("viberite nomer zadachi\n");
        scanf("%d", &i);
        switch(i)
        {
        case 1: zd1(); break;
        case 2: zd2(); break;
        case 3: zd3(); break;
        case 4: zd4(); break;
        case 5: zd5(); break;
        case 6: zd6(); break;
        //case 7: zd7(); break;
        }
    }


    return 0;
}

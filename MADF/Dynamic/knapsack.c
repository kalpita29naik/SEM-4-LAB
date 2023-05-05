#include <stdio.h>

#define N 200
#define obj 100
int count = 0;
int size;



struct dp
{
    int p, w, o[obj];
};

void knap(int m, int n, int p[N], int w[N]);
void purge(struct dp s[N]);
int main(void)
{
    int m, n; 
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int p[n], w[n]; 
    printf("Enter the profit for each item\n");
    for(int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
        }
    printf("Enter the weights for each item\n");
    for(int i = 0; i < n; i++)
        {
            scanf("%d", &w[i]);
        }
    knap(m, n, p, w);
    return 0;
}

void purge(struct dp s[N])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (s[i].p < s[j].p && s[i].w >= s[j].w)
                s[i].p = s[i].w = -1;
            else if (s[j].p < s[i].p && s[j].w >= s[i].w)
                s[j].p = s[j].w = -1;
        }
        for (int j = i + 1; j < size; j++)
        {
            if (s[i].p == s[j].p && s[i].w == s[j].w)
                s[j].p = s[j].w = -1;
        }
    }
}

void knap(int m, int n, int p[N], int w[N])
{
    struct dp s[N];
    s[0].w = s[0].p = 0;
    for (int i = 0; i < n; i++)
        s[0].o[i] = 0;

    size = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = size; j < size; j++, k++)
        {
            
            if (s[j].w == -1)
                continue;

            s[k].w = s[j].w + w[i];

            
            if (s[k].w > m)
            {
                s[k].w = s[k].p = -1;
                continue;
            }

            
            s[k].p = s[j].p + p[i];

            for (int z = 0; z < n; z++)
                s[k].o[z] = s[j].o[z];
            s[k].o[i] += 1;
        }
        purge(s);
        printf("S^%d = { ", count);
        for (int i = 0; i < size; i++)
        {
            if (s[i].p == -1 && s[i].w == -1)
                continue;
            else
                printf("(%d, %d) ", s[i].p, s[i].w);
        }
        printf("}");
        printf("\n\n");
        size *= 2, count++;
    }
    purge(s);
    int mw = -1, mp = -1, ind; 
    for (int i = 0; i < size; i++)
    {
        if (s[i].w < mw)
            continue;
        else if (s[i].w > mw)
            mw = s[i].w, mp = s[i].p, ind = i;
        else
        {
            if (s[i].p > mp)
                mp = s[i].p, ind = i;
        }
    }
    
    printf("\n");
}

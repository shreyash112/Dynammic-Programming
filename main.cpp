#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<cmath>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>
#include<algorithm>
using namespace std;

//Protype functions
int mem_rod (int price[], int n);
int cutRod(int price[], int n,int r[]);

//Function to measure the maximum value comparing to the previous max_val
int max(int a, int b)
{
    return (a > b)? a : b;
}

//Function to store the repeating the elements in an array.
int mem_rod(int price[], int n)
{
    int rod1[n];
    std :: fill_n(rod1,n,NULL);
    return cutRod(price,n,rod1);
}

//Recurssive function to calculate the maximum revenue generated using dynamic
//Programming approach.
int cutRod(int price[], int n,int r[])
{
    if (r[n-1] > 0)
    {
        return r[n];
    }
    if (n ==0)
    {
        return 0;
    }
    if (n ==1 )
    {
        return 2;
    }
    if (n>1)
    {
        int max_val = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            max_val = max(max_val, price[i] + cutRod(price, n-i-1,r));
        }
        r[n] = max_val;
        return max_val;
    }
}

//Function to generate the prices according to formula given.
void gen_price(int price1[],int rod_size)
{
    int j = 1;
    for(int i = 0;i < rod_size ; i++)
    {

        if(j == 1)
        {
            price1[i] = 2;
        }
        if(j < rod_size && j > 1)
        {
            price1[i] = floor(2.5 * j);
        }

        if(j == rod_size)
        {
            price1[i] = floor((2.5 * j) - 1);
        }
        j++;
    }
}

int main()
{
    int rod_size;
    cout << "Enter the rod size: ";
    cin >> rod_size;
    int price1[rod_size];
    gen_price(price1,rod_size);
    for(int i = 0;i < rod_size ; i++)
    {
        cout << price1[i] << " ";
    }
    clock_t t;
    t = clock();//Start the clock to measure the excetuion time of the program 
    cout <<'\n';
    int rod = mem_rod(price1,rod_size);
    cout << "\nMaximum Revenue: "<< rod;
    t = clock() - t; //Stop the clock 
    printf ("\nIt took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}

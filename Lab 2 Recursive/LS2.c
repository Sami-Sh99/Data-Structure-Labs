#include<stdio.h>
#include<math.h>
//#define abs(x) ((x)<0?-(x):(x))

float power(float X, int N)
{
	if (N == 0)
		return 1.0;
	if (N > 0)
		return X*power(X, N - 1);
	if (N < 0)
		return (1.0 / X)*power(X, N + 1);
}
void PowerTest()
{
	int N;
	float X;
	printf("Give X: ");
	scanf("%f", &X);
	printf("Give N: ");
	scanf("%d", &N);
	printf("%f^%d=%f", X, N, power(X, N));
}

int is_sorted(int tab[], int N)
{
	if (N == 1)
		return 1;
	if (*tab <= *(tab + 1))
		return is_sorted(tab + 1, N - 1);
	else
		return 0;
}
void is_sortedTest()
{
	int T[100], n, i;
	printf("enter nb of elements\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", T + i);
	printf("Sorted array? %d", is_sorted(T, n));
}

int nb_occurences(int tab[], int N, int value)
{
	if (N == 0)
		return 0;
	if (*tab == value)
		return 1 + nb_occurences(tab + 1, N - 1, value);
	else
		return nb_occurences(tab + 1, N - 1, value);
}
void nb_occ_Test()
{
	int T[100], n, i;
	printf("enter nb of elements\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", T + i);
	printf("enter element to be checked\n");
	scanf("%d", &i);
	printf("Sorted array? %d", nb_occurences(T, n,i));
}
void mirror(int tab[], int start, int end)
{
	if (start == end)
		return;
	else
	{
		mirror(tab + 1, ++start, end);
		printf("%d ", *tab);
	}
	//no need for a test :p
}

int closest(int tab[], int N, int X)
{
	int m;
	if (N > 1) {
		m = closest(tab, N - 1, X);
		if (abs(tab[m] - X) > abs(tab[N - 1] - X)) {
			return(N - 1);
		}
		return m;
	}
	return 0;

}
void main()
{
	int T[] = { 1, 2, 3, 4, 6, 3 };
	printf("%d",closest(T,6,3));
	getchar();
}

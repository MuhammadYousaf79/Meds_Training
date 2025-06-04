#include<stdio.h>
#include<math.h>

double fact(int n);
double exponential(double a);


int main(void)
{
	double a = 0.0;
	printf("Enter number :");
	scanf("%lf", &a);

	double b = exponential(a);
	printf("The exponential of %lf is %lf\n",a,b);

	return 0;
}

double fact(int n)
{
	double s = 1;
	for (int j=1; j <= n; ++j)
	{
		s = s * j;
	}

	return s;
}


double exponential(double a)
{
	int terms = 20;
	double k = 0;
	double p;
	for (int i = 0; i <= terms; ++i)
	{
		p = pow(a,i);
		k = k + (p / (fact(i)));
	}

	return k;
}

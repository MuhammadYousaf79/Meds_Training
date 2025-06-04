#include <stdio.h>

double squareRoot(double number) {

    double guess = number / 2.0;
    double epsilon = 0.00001;

    while ((guess * guess - number) > epsilon || (number - guess * guess) > epsilon) {
        guess = (guess + number / guess) / 2.0;
    }

    return guess;
}

int main() {
    double number, result;

    printf("Enter a number: ");
    scanf("%lf", &number);

    if (number < 0) {
        printf("ERROR: cannot compute square root of a negative number.\n");
    } else {
        result = squareRoot(number);
        printf("The square root of %lf is %lf\n", number, result);
    }

    return 0;
}

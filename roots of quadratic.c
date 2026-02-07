#include <stdio.h>   
// Standard input/output library
#include <math.h>    
// Math library for sqrt() function
int main() {
    double a, b, c;
    double discriminant, root1, root2, realPart, imagPart;
    // Declare variables for coefficients and roots
    printf("Enter coefficients a, b, and c: ");
    // Prompt user to enter coefficients of quadratic equation
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b * b - 4 * a * c;
    // Calculate discriminant (b^2 - 4ac)
    if (discriminant > 0) 
    // Case 1: Discriminant > 0 → two distinct real roots
	{
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Real and different roots: root1 = %.2lf, root2 = %.2lf\n", root1, root2);
    }
	else if (discriminant == 0) 
    // Case 2: Discriminant == 0 → one repeated real root
	{
        root1 = root2 = -b / (2 * a);
        printf("Real and equal roots: root1 = root2 = %.2lf\n", root1);
	}
	else 
    // Case 3: Discriminant < 0 → complex conjugate roots
	{
        realPart = -b / (2 * a);                  // Real part of complex root
        imagPart = sqrt(-discriminant) / (2 * a); // Imaginary part of complex root
        printf("Complex roots: root1 = %.2lf + %.2lfi, root2 = %.2lf - %.2lfi\n",
               realPart, imagPart, realPart, imagPart);
    }
    return 0; 
	// End of program
}

#include <stdio.h>
int main() {
    int phy, chem, bio, math, comp;
    float per;
    /* Input marks of five subjects from user */
    printf("Enter marks of five subjects (Physics, Chemistry, Biology, Mathematics, Computer):\n");
    scanf("%d %d %d %d %d", &phy, &chem, &bio, &math, &comp);
    /* Calculate percentage */
    per = (phy + chem + bio + math + comp) / 5.0;
    printf("Percentage = %.2f\n", per);
    /* Find grade according to the percentage */
    if (per >= 90) {
        printf("Grade A\n");
    } else if (per >= 80) {
        printf("Grade B\n");
    } else if (per >= 70) {
        printf("Grade C\n");
    } else if (per >= 60) {
        printf("Grade D\n");
    } else if (per >= 40) {
        printf("Grade E\n");
    } else {
        printf("Grade F\n");
    }
    return 0;
}

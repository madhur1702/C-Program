#include <stdio.h>
#include <math.h>
typedef struct
{
    double magnitude;
    double angle; 
} Force;
double degreesToRadians(double degrees)
{
    return degrees * M_PI / 180.0;
}
void resolveForce(Force force, double *fx, double *fy) 
{
    double radians = degreesToRadians(force.angle);
    *fx = force.magnitude * cos(radians);
    *fy = force.magnitude * sin(radians);
}
int main()
{
    int numForces;
    printf("Enter the number of known forces: ");
    scanf("%d", &numForces);
    Force knownForces[numForces];
    double resultX = 0.0;
    double resultY = 0.0;
    for (int i = 0; i < numForces; i++)
	{
        printf("Enter magnitude of force %d (in Newtons): ", i + 1);
        scanf("%lf", &knownForces[i].magnitude);
        printf("Enter angle of force %d (in degrees with respect to the x-axis): ", i + 1);
        scanf("%lf", &knownForces[i].angle);
        double fx, fy;
        resolveForce(knownForces[i], &fx, &fy);
        resultX += fx;
        resultY += fy;
    }
    double equilibriumMagnitude = sqrt(resultX * resultX + resultY * resultY);
    double equilibriumDirection = atan2(resultY, resultX) * 180.0 / M_PI;
    printf("Resultant force in equilibrium:\n");
    printf("Magnitude = %.2lf Newtons\n", equilibriumMagnitude);
    printf("Direction = %.2lf degrees with respect to the x-axis\n", equilibriumDirection);
    return 0;
}

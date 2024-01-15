#include <stdio.h>
#include <math.h>
typedef struct 
{
    double magnitude;
    double angle;
} Force;
void resolveForce(Force force, double *fx, double *fy) 
{
    *fx = force.magnitude * cos(force.angle);
    *fy = force.magnitude * sin(force.angle);
}

int main() 
{
    int numJoints, numMembers;
    printf("Enter the number of joints: ");
    scanf("%d", &numJoints);
    printf("Enter the number of members: ");
    scanf("%d", &numMembers);
    Force forces[numJoints];
    for (int i = 0; i < numJoints; i++) 
	{
        forces[i].magnitude = 0.0;
        forces[i].angle = 0.0;
    }
    for (int i = 0; i < numJoints; i++) 
	{
        printf("Enter the magnitude of the external force at joint %d (in kN): ", i + 1);
        scanf("%lf", &forces[i].magnitude);
        printf("Enter the angle of the external force at joint %d (in degrees): ", i + 1);
        scanf("%lf", &forces[i].angle);
    }
    int members[numMembers][2];
    double memberLengths[numMembers];
    for (int i = 0; i < numMembers; i++) 
	{
        printf("Enter the joint numbers (1 to %d) connected by member %d: ", numJoints, i + 1);
        scanf("%d %d", &members[i][0], &members[i][1]);
        printf("Enter the length of member %d (in meters): ", i + 1);
        scanf("%lf", &memberLengths[i]);
    }
    for (int i = 0; i < numMembers; i++) 
	{
        int joint1 = members[i][0] - 1; 
        int joint2 = members[i][1] - 1;
        double fx, fy;
        resolveForce(forces[joint1], &fx, &fy);
        forces[joint1].magnitude += fx;
        forces[joint1].angle = atan2(fy, fx);
        resolveForce(forces[joint2], &fx, &fy);
        forces[joint2].magnitude += fx;
        forces[joint2].angle = atan2(fy, fx);
    }
    printf("Forces at each joint:\n");
    for (int i = 0; i < numJoints; i++) 
	{
        printf("Joint %d: Magnitude = %.2lf kN, Angle = %.2lf degrees\n", i + 1, forces[i].magnitude, forces[i].angle * 180 / M_PI);
    }
    return 0;
}

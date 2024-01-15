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
    int joint1, joint2;
    printf("Enter the two joint numbers for the section (1 to %d): ", numJoints);
    scanf("%d %d", &joint1, &joint2);
    double sectionForces[2] = {0.0, 0.0};
    for (int i = 0; i < numMembers; i++) 
	{
        if ((members[i][0] == joint1 && members[i][1] == joint2) || (members[i][0] == joint2 && members[i][1] == joint1)) 
		{
            double fx, fy;
            resolveForce(forces[joint1 - 1], &fx, &fy);
            sectionForces[0] += fx;
            sectionForces[1] += fy;
        }
    }
    printf("Forces in the selected section (joint %d to joint %d):\n", joint1, joint2);
    printf("Horizontal Force = %.2lf kN\n", sectionForces[0]);
    printf("Vertical Force = %.2lf kN\n", sectionForces[1]);
    return 0;
}

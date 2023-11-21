#include <stdio.h> // Include the standard input-output library
#include <stdlib.h> // Include the standard library
#include <math.h> // Include the math library
#include <string.h> // Include the string library
#define MAX_N 1000 // Define a maximum value for n
#define MAX_M 1000 // Define a maximum value for m
#define int long long // Redefine int as a long long integer
int map[MAX_N][MAX_M]; // Declare a 2D array as the map
int n, m, d; // Declare variables for the width, height, and hammer size respectively
int map_rotated[2 * MAX_N][2 * MAX_M]; // Declare a rotated map twice the size of the original map
int mrsum[2 * MAX_N][2 * MAX_M]; // Declare a sum matrix twice the size of the original map
void rotate(int n, int m) // Declare a function to rotate the map 45 degrees clockwise
{
    // Initialize all elements of rotated map to zero
    for (int i = 0; i < n + m; i++)
        for (int j = 0; j < n + m; j++)
            map_rotated[i][j] = 0;

    // Place elements from the original map in rotated positions in the rotated map
    for (int i = 0; i < n + m; i++)
        for (int j = 0; j < n + m; j++)
        {
            map_rotated[i + j][n - i + j - 1] = map[i][j];
        }
}
// Function to print the rotated map and sum map
void myprint()
{
    // Print the rotated map
    for (int i = 0; i < n + m; i++)
    {
        for (int j = 0; j < n + m; j++)
        {
            printf("%d ", map_rotated[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Print the sum map
    for (int i = 0; i < n + m; i++)
    {
        for (int j = 0; j < n + m; j++)
        {
            printf("%d ", mrsum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// Function for the main program
signed main()
{

    scanf("%d %d %d", &n, &m, &d); // Read the width, height, and hammer size
    for (int i = 0; i < n; i++) // Read the map
        for (int j = 0; j < m; j++)
            scanf("%lld", &map[i][j]);

    rotate(n, m); // Rotate the map
    // Calculate the sum of each cell and its upper and left neighbors in the rotated map
    for (int i = 1; i < n + m; i++)
        for (int j = 1; j < n + m; j++)
            mrsum[i][j] = mrsum[i - 1][j] + mrsum[i][j - 1] - mrsum[i - 1][j - 1] + map_rotated[i][j];
   
    int maxsum = -9223372036854775808; // Initialize the maxsum to the lowest possible value
    // Loop through all possible positions to find the maximum sum of the hammer area
    for (int i = 2 * d; i < n + m; i++)
    {
        for (int j = 2 * d; j < n + m; j++)
        {
            int sum = 0; // Initialize sum variable to zero
            // Calculate the sum by subtracting the sum of cells outside the hammer area from the total sum
            if (sum > maxsum && ((i + j) % 2 + n % 2 == 1)) // If the sum is greater than the maxsum and position is a possible starting position of the hammer
            {
                maxsum = sum; // Update the maxsum
            }
        }
    }
    // Loop through all possible positions to find all positions where the maximum sum can be obtained
    for (int i = 2 * d; i < n + m; i++)
    {
        for (int j = 2 * d; j < n + m; j++)
        {
            int sum = 0; // Initialize sum variable to zero
            // Calculate the sum by subtracting the sum of cells outside the hammer area from the total sum
            if (sum == maxsum && ((i + j) % 2 + n % 2 == 1)) // If the sum equals the maximum sum and the position is a possible hammer starting position
            {
                // Calculate the possible starting positions of the hammer in the original map
                answer[answer_cnt][0] = (i - d + n - 1) / 2;
                answer[answer_cnt][1] = (j - d + n - 1) / 2;
            }
        }
    }
    // Print the maximum sum and the count of possible starting positions
    printf("%lld %lld\n", maxsum, answer_cnt);
    // Print all possible hammer starting positions
    for (int i = 1; i <= answer_cnt; i++)
    {
        printf("%lld %lld", answer[i][0] + 1, answer[i][1] + 1);
    }
    return 0; // Return 0 to indicate normal termination of the program
}
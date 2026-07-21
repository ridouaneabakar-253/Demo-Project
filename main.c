#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;

    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0);

    for (int i = 0; i < n_courses; i++)
    {
        double marks;
        printf("Marks for %s: ", courses[i].code);
        scanf("%lf", &marks);
        results[i] = createCourseResult(&courses[i], marks);
    }

    printf("\n--- RESULTS ---\n");
    for (int i = 0; i < n_courses; i++)
    {
        viewCourseResult(results[i]);
        printf("Grade Point: %.2f\n", getGradePoint(results[i]));
        printf("Letter Grade: %s\n\n", getLetterGrade(results[i]));
    }

    printf("CGPA: %.2f\n", calculateGPA(results, n_courses));

    return 0;
}
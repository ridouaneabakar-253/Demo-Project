#include <stdio.h>
#include "course.h"
#include "courseResult.h"

int testCompletedCourseResult()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult result = createCompletedCourseResult(&course, 77);
    return result.completed == 1 && result.marks == 77;
}

int testIncompleteCourseResult()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult result = createIncompleteCourseResult(&course);
    return result.completed == 0;
}

int main()
{
    printf("Course result module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCompletedCourseResult()) passed++;
    total++;
    if (testIncompleteCourseResult()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}
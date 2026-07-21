#ifndef GPA_H
#define GPA_H

#include "courseResult.h"

double getPercentage(CourseResult result);
double getGradePoint(CourseResult result);
char *getLetterGrade(CourseResult result);
double calculateCGPA(CourseResult results[], int count);

#endif
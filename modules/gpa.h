#ifndef GPA_H
#define GPA_H

#include "courseResult.h"

double getGradePoint(double marks);
char *getLetterGrade(double marks);
double calculateCGPA(CourseResult results[], int n_results);

#endif
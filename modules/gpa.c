#include "gpa.h"

const double gradeBoundaries[] = {80, 75, 70, 65, 60, 55, 50, 45, 40};
const double gradePoints[] = {4.00, 3.75, 3.50, 3.25, 3.00, 2.75, 2.50, 2.25, 2.00};
const char *gradeLetters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D"};

double getGradePoint(CourseResult result)
{
    double marks = result.marks;
    if (marks >= 80) return 4.00;
    if (marks >= 75) return 3.75;
    if (marks >= 70) return 3.50;
    if (marks >= 65) return 3.25;
    if (marks >= 60) return 3.00;
    if (marks >= 55) return 2.75;
    if (marks >= 50) return 2.50;
    if (marks >= 45) return 2.25;
    if (marks >= 40) return 2.00;
    return 0.00;
}

char *getLetterGrade(CourseResult result)
{
    double marks = result.marks;
    if (marks >= 80) return "A+";
    if (marks >= 75) return "A";
    if (marks >= 70) return "A-";
    if (marks >= 65) return "B+";
    if (marks >= 60) return "B";
    if (marks >= 55) return "B-";
    if (marks >= 50) return "C+";
    if (marks >= 45) return "C";
    if (marks >= 40) return "D";
    return "F";
}

double calculateCGPA(CourseResult results[], int n_results)
{
    double weighted_points = 0.0;
    double total_credits = 0.0;

    for (int i = 0; i < n_results; i++)
    {
        weighted_points += getGradePoint(results[i]) * results[i].course->credit;
        total_credits += results[i].course->credit;
    }

    if (total_credits == 0.0) return 0.0;
    return weighted_points / total_credits;
}
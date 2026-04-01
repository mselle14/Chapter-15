//Marshon Sellers

#include <iostream>
using namespace std;

class Course
{
    public:
    virtual void startClass () = 0;

};

class ProgrammingCourse : public Course
{
    public:
    void startClass()
    {
        cout << "Programming Course is Starting\n";
    }
};


class MathCourse : public Course
{
    public:
    void startClass()
    {
        cout << "Math Course is starting\n";
    }
};




int main()
{
    Course* course_pointer;

    ProgrammingCourse programming_object;
    MathCourse math_object;

    course_pointer = &programming_object;
    course_pointer->startClass();

    course_pointer = &math_object;
    course_pointer->startClass();


    return 0;
}

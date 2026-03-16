#ifndef STUDENTROLE_H
#define STUDENTROLE_H

#include "Role.h"
#include <iostream>
using namespace std;

/*
    Concrete Role: Student

    Defines behavior specific to a student in the university system.
*/
class StudentRole : public Role
{
public:

    // Returns the role name
    string getRoleName() const override
    {
        return "Student";
    }

    // Behavior associated with this role
    void performDuty() const override
    {
        cout << "Attending classes and submitting assignments." << endl;
    }
};

#endif
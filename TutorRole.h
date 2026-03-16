#ifndef TUTORROLE_H
#define TUTORROLE_H

#include "Role.h"
#include <iostream>
using namespace std;

/*
    Concrete Role: Tutor

    Represents a tutoring responsibility.
*/
class TutorRole : public Role
{
public:

    string getRoleName() const override
    {
        return "Tutor";
    }

    void performDuty() const override
    {
        cout << "Helping students during tutoring sessions." << endl;
    }
};

#endif
#ifndef CLUBMEMBERROLE_H
#define CLUBMEMBERROLE_H

#include "Role.h"
#include <iostream>
using namespace std;

/*
    Concrete Role: Club Member

    Represents a student participating in university clubs.
*/
class ClubMemberRole : public Role
{
public:

    string getRoleName() const override
    {
        return "Club Member";
    }

    void performDuty() const override
    {
        cout << "Participating in club meetings and campus events." << endl;
    }
};

#endif
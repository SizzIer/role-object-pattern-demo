#ifndef ROLE_H
#define ROLE_H

#include <string>
using namespace std;

/*
    Abstract Role class

    This represents the generic "Role" in the Role Object Pattern.
    Concrete roles like StudentRole or TutorRole will inherit from this.
*/
class Role
{
public:
    // Returns the name of the role
    virtual string getRoleName() const = 0;

    // Each role performs its own behavior
    virtual void performDuty() const = 0;

    // Virtual destructor for proper cleanup
    virtual ~Role() {}
};

#endif
#include <iostream>
#include <memory>

#include "Person.h"
#include "StudentRole.h"
#include "TutorRole.h"
#include "ClubMemberRole.h"

using namespace std;

/*
    Demo Application

    Demonstrates the Role Object Pattern by dynamically
    assigning and removing roles from a Person object.
*/
int main()
{
    // Create a core object (Person)
    Person person1("Francisco Hernandez", 1001);

    // Initial state (no roles)
    person1.showRoles();
    person1.performAllDuties();

    cout << "\n--- Adding Roles ---" << endl;

    // Dynamically assign roles
    person1.addRole(make_shared<StudentRole>());
    person1.addRole(make_shared<TutorRole>());
    person1.addRole(make_shared<ClubMemberRole>());

    // Display roles after assignment
    person1.showRoles();
    person1.performAllDuties();

    cout << "\n--- Attempting Duplicate Role ---" << endl;

    // Demonstrate duplicate prevention
    person1.addRole(make_shared<StudentRole>());

    cout << "\n--- Removing a Role ---" << endl;

    // Remove one role dynamically
    person1.removeRole("Tutor");

    // Final state
    person1.showRoles();
    person1.performAllDuties();

    return 0;
}
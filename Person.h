#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Role.h"

using namespace std;

/*
    Core Object (Context)

    Person represents the main entity that can dynamically
    gain or lose different roles at runtime.

    This is the central idea of the Role Object Pattern.
*/
class Person
{
private:
    string name;
    int id;

    // Collection of roles assigned to this person
    vector<shared_ptr<Role>> roles;

public:

    // Constructor
    Person(string n, int i) : name(n), id(i) {}

    /*
        Adds a role to the person.
        Roles are stored dynamically so they can be added or removed.
    */
    void addRole(shared_ptr<Role> role)
    {
        // Prevent duplicate roles
        for (const auto& r : roles)
        {
            if (r->getRoleName() == role->getRoleName())
            {
                cout << name << " already has the role: " << role->getRoleName() << endl;
                return;
            }
        }

        roles.push_back(role);

        cout << "Added role: " << role->getRoleName()
             << " to " << name << endl;
    }

    /*
        Removes a role by name
    */
    void removeRole(const string& roleName)
    {
        for (auto it = roles.begin(); it != roles.end(); ++it)
        {
            if ((*it)->getRoleName() == roleName)
            {
                cout << "Removed role: " << roleName
                     << " from " << name << endl;

                roles.erase(it);
                return;
            }
        }

        cout << name << " does not have the role: "
             << roleName << endl;
    }

    /*
        Displays all roles assigned to this person
    */
    void showRoles() const
    {
        cout << "\nPerson: " << name
             << " (ID: " << id << ")" << endl;

        if (roles.empty())
        {
            cout << "No roles assigned." << endl;
            return;
        }

        cout << "Current Roles:" << endl;

        for (const auto& role : roles)
        {
            cout << "- " << role->getRoleName() << endl;
        }
    }

    /*
        Executes behavior for every role assigned
    */
    void performAllDuties() const
    {
        cout << "\n" << name << " is performing role duties:" << endl;

        if (roles.empty())
        {
            cout << "No duties to perform because no roles are assigned." << endl;
            return;
        }

        for (const auto& role : roles)
        {
            cout << role->getRoleName() << ": ";
            role->performDuty();
        }
    }
};

#endif
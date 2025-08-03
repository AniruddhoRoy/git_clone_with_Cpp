#include <bits/stdc++.h>
#include "database/Database.h"
#include "libraries/Repository.h"
#include "constants/constant.h"
using namespace std;
int main(int argc, char *argv[])
{
    vector<string> commands;
    for (int i = 1; i < argc; i++)
    {
        commands.push_back(argv[i]);
    }
    if (commands[0] != "tig")
    {
        cout << "Error command may be 'tig'" << endl;
    }
    // if (commands.size() == 2)
    // {
    //     if (commands[1] == constants::tig_init)
    //     {
    //         cout << constants::tig_init << endl;
    //     }
    //     else if (commands[1] == constants::tig_log)
    //     {
    //         cout << constants::tig_log << endl;
    //     }
    //     else
    //     {
    //         cout << "Invalid Commands" << endl;
    //     }
    // }
    // else if (commands.size() == 3)
    // {
    //     if (commands[1] == constants::tig_commit_message)
    //     {
    //         cout << commands[1] + " " + commands[2] << endl;
    //     }
    // }

    return 0;
}
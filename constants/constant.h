#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace constants
{
    const int hash_value = 0;
    const string IgnoreFile = "ignore.txt";

    const string tig_init = "init";
    const string tig_commit_message = "commit";
    const string tig_log = "log";

    const string storage_directory = ".tig";
    const string branches = "branchs.txt";
    const string active_branch_name = "active_branch.txt";
    const string default_branch_name = "origin";
    const string branch_commit_lits = "branch_commit_lits.txt";
    const vector<string> default_ignore = {
        "/.git", "main.cpp", branches, IgnoreFile, active_branch_name, "/" + storage_directory, branch_commit_lits};
}

string join(vector<string> strings)
{
    string result = "";
    for (int i = 0; i < strings.size() - 1; i++)
    {
        result += strings[i];
        result += "/";
    }
    result += strings.back();
    return result;
}
string randomString(int length = 11)
{
    const string characters = "abcdefghijklmnopqrstuvwxyz"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "0123456789";

    string result;
    for (int i = 0; i < length; ++i)
    {
        result += characters[rand() % characters.size()];
    }

    return result;
}
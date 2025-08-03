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
    const vector<string> default_ignore = {
        "/.git", "main.cpp"};
    const string storage_directory = ".tig";
    const string branches = "branchs.txt";
    const string active_branch_name = "active_branch.txt";
    const string default_branch_name = "origin";

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
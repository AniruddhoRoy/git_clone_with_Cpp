#pragma once

#include <bits/stdc++.h>
using namespace std;

class Folders
{
public:
    string name;
    vector<Folders> Nested_Folder;
    vector<string> files;
};
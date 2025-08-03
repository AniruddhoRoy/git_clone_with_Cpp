#pragma once

#include <bits/stdc++.h>
#include "../constants/constant.h"
using namespace std;

class Hash
{

public:
    string convert_to_hash(string &s)
    {
        string hash_string;
        for (int i = 0; i < s.size(); i++)
        {
            hash_string += (s[i] + constants::hash_value);
        }
        return hash_string;
    }
    string convert_to_string(string &hash)
    {
        string orginal_string;
        for (int i = 0; i < hash.size(); i++)
        {
            orginal_string += (hash[i] - constants::hash_value);
        }
        return orginal_string;
    }
    bool compare(string &hash1, string &hash2)
    {
        return (convert_to_string(hash1) == convert_to_string(hash2));
    }
};
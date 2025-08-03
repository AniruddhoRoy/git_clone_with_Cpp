#include <bits/stdc++.h>
#include "Repository.h"
#include "../constants/constant.h"
#include "../database/Database.h"
#include "../data_structures/file.h"
using namespace std;

class Snap
{
private:
    Repo repo;
    string active_branch;
    bool branch_exist(vector<string> data, string s)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (s == data[i])
            {
                return true;
            }
        }
        return false;
    }

public:
    Snap(string active_branch_name = "")
    {
        repo.create_dir(constants::storage_directory);
        Database branchs(constants::branches, constants::storage_directory);
        Database active_branch(constants::active_branch_name, constants::storage_directory);
        if (active_branch.get_data().size() == 0)
        {
            vector<string> data = {constants::default_branch_name};
            active_branch.putdata(data);
            this->active_branch = constants::default_branch_name;
        }
        else if (active_branch_name != "")
        {
            vector<string> data = {active_branch_name};
            active_branch.putdata(data);
            this->active_branch = active_branch_name;
        }
        else
        {
            this->active_branch = active_branch.get_data().front();
        }
        if (!branch_exist(branchs.get_data(), this->active_branch))
        {
            vector<string> data = branchs.get_data();
            data.push_back(this->active_branch);
            branchs.putdata(data);
        }
        repo.create_dir(constants::storage_directory + "/" + this->active_branch);
    }
    void take_snap(string commit_name)
    {
        vector<string> files = repo.files_in_current_directory();
        repo.create_dir(join({constants::storage_directory, active_branch, commit_name}));
        for (int i = 0; i < files.size(); i++)
        {
            Database input_file(files[i]);
            Database output_file(randomString(), join({constants::storage_directory, active_branch, commit_name}), true);
            Files file;
            file.File_Address = files[i];
            file.file_data = input_file.get_data();
            output_file.putdata_complex(file);
        }
    }
};
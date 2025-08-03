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
    vector<string> commit_list;
    bool find(vector<string> data, string s)
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
        if (!find(branchs.get_data(), this->active_branch))
        {
            vector<string> data = branchs.get_data();
            data.push_back(this->active_branch);
            branchs.putdata(data);
        }
        repo.create_dir(constants::storage_directory + "/" + this->active_branch);
        Database commit_list(constants::branch_commit_lits, join({constants::storage_directory, this->active_branch}));
        this->commit_list = commit_list.get_data();
    }
    void take_snap(string commit_name)
    {
        vector<string> files = repo.files_in_current_directory();
        vector<string> dirs = repo.current_directories();
        Database commit_list(constants::branch_commit_lits, join({constants::storage_directory, this->active_branch}));
        if (find(this->commit_list, commit_name))
        {
            cout << "Commit already exist" << endl;
            return;
        }

        this->commit_list.push_back(commit_name);
        commit_list.putdata(this->commit_list);
        repo.create_dir(join({constants::storage_directory, active_branch, commit_name}));
        for (int i = 0; i < files.size(); i++)
        {
            Database input_file(files[i]);
            Database output_file(randomString(), join({constants::storage_directory, active_branch, commit_name}), true);
            Files file;
            file.File_Address = dirs[i];
            file.file_data = input_file.get_data();
            file.File_name = files[i];
            output_file.putdata_complex(file);
        }
    }
    void put_snap(string commit_name, string alternative_address = "")
    {
        if (!find(commit_list, commit_name))
        {
            cout << "Commit not exist!" << endl;
            return;
        }

        vector<string> files = repo.files_in_current_directory(join({constants::storage_directory, active_branch, commit_name}));
        for (int i = 0; i < files.size(); i++)
        {
            Database input_file(files[i], "", true);
            Files file = input_file.getdata_complex();
            repo.create_dir(join({alternative_address, file.File_Address}));
            Database output_file(join({alternative_address, file.File_name}));
            output_file.putdata(file.file_data);
        }
    }
};
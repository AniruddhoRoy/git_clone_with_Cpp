#pragma once
#include <bits/stdc++.h>
#include "../constants/constant.h"
using namespace std;
using namespace std::filesystem;

class Repo
{
    vector<string> filenames;
    vector<string> IgnoreFiles;
    vector<string> IgnoreDirs;

public:
    void create_dir(string path)
    {
        if (!create_directories(path))
        {
        }
    }
    vector<string> files_in_current_directory()
    {
        directories();
        return filenames;
    }
    // void delete_method()
    // {
    //
    //     cout << "======Dirs=====" << endl;
    //     for (int i = 0; i < IgnoreDirs.size(); i++)
    //     {
    //         cout << IgnoreDirs[i] << endl;
    //     }
    // }

private:
    bool is_Ignore_File_exist()
    {
        fstream file(constants::IgnoreFile, ios::in);
        if (file.is_open())
        {
            file.close();
            return true;
        }
        else
        {
            file.close();
            return false;
        }
    }
    void read_ignore_files_and_dirs()
    {
        string temp;
        fstream file(constants::IgnoreFile, ios::in);
        while (getline(file, temp))
        {
            if (temp.size() > 0 && temp[0] == '/')
            {
                string temp2(temp.begin() + 1, temp.end());
                IgnoreDirs.push_back(temp2);
            }
            else
            {
                IgnoreFiles.push_back(temp);
            }
        }
    }
    bool is_ignore_file(string file_name)
    {
        for (int i = 0; i < IgnoreFiles.size(); i++)
        {
            if (file_name == IgnoreFiles[i])
            {
                return true;
            }
        }
        return false;
    }
    bool is_ignore_dirs(string dir_name)
    {
        for (int i = 0; i < IgnoreDirs.size(); i++)
        {
            if (dir_name == IgnoreDirs[i])
            {
                return true;
            }
        }
        return false;
    }
    void directories()
    {
        path root = current_path();
        queue<string> dirs;
        dirs.push(root.string());
        if (is_Ignore_File_exist())
        {
            read_ignore_files_and_dirs();
        }
        try
        {
            while (!dirs.empty())
            {
                string current_dir = dirs.front();
                dirs.pop();

                for (const auto &entry : directory_iterator(current_dir))
                {
                    if (entry.is_directory())
                    {
                        if (!is_ignore_dirs(entry.path().filename().string()))
                        {
                            dirs.push(entry.path().string());
                        }
                        // cout << "[DIR]  " << entry.path().string() << '\n';
                    }
                    else if (entry.is_regular_file())
                    {
                        if (!is_ignore_file(entry.path().filename().string()))
                        {
                            filenames.push_back(entry.path().string());
                        }
                        // cout << "[FILE] " << entry.path().string() << '\n';
                        // cout << "[FILE] " << entry.path().filename() << '\n';
                    }
                }
            }
        }
        catch (const filesystem_error &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
};
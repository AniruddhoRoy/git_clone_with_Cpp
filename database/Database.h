#pragma once

#include <bits/stdc++.h>
#include "../libraries/Repository.h"
#include "../hash/Hash.h"
#include "../data_structures/file.h"
using namespace std;
class Database
{
private:
    string file_name, file_path, final_path_with_name;
    vector<string> data;
    Repo repo;
    Hash hash;
    void read()
    {
        fstream file(final_path_with_name, ios::in);
        // fstream file("test.txt", ios::in);
        if (file.is_open())
        {
            string temp_input_from_file;
            while (getline(file, temp_input_from_file))
            {
                data.push_back(hash.convert_to_string(temp_input_from_file));
            }
            file.close();
        }
        else
        {
            fstream file(final_path_with_name, ios::out);
            // fstream file("test.txt", ios::out);
            file.close();
        }
    }

public:
    Database(string file_name, string file_path = "", bool complex_data = false) : file_name(file_name), file_path(file_path)
    {
        if (!(file_path == ""))
        {
            repo.create_dir(file_path);
            final_path_with_name = file_path + "/" + file_name;
        }
        else
        {
            final_path_with_name = file_name;
        }
        if (!complex_data)
        {
            read();
        }
    }
    vector<string> get_data()
    {

        return data;
    }
    void putdata(vector<string> &input_data)
    {
        data.clear();
        data.assign(input_data.begin(), input_data.end());
        fstream file(final_path_with_name, ios::out);
        for (int i = 0; i < input_data.size(); i++)
        {
            file << hash.convert_to_hash(input_data[i]) << endl;
        }
        file.close();
    }
    void putdata_complex(Files &input_file)
    {
        fstream file(final_path_with_name, ios::out);
        file << input_file.File_Address << endl;
        file << input_file.File_name << endl;
        for (int i = 0; i < input_file.file_data.size(); i++)
        {
            file << input_file.file_data[i] << endl;
        }
        file.close();
    }
    Files getdata_complex()
    {
        Files output_file;
        fstream file(final_path_with_name, ios::in);
        getline(file, output_file.File_Address);
        getline(file, output_file.File_name);
        string temp;
        while (getline(file, temp))
        {
            output_file.file_data.push_back(temp);
        }
        return output_file;
    }
};
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string readConfigFile(const string& filename) 
{
    ifstream file(filename);

    if (!file.good()) {
        throw std::runtime_error("File stream is bad!");
    }

    string line;
    string text;
    while (getline(file, line)) 
    {
        text += line;
        text += '\n';
    }

    return text;
}

int main() 
{    
    cout << "Reading configuration:" << endl;
    try {
        string text = readConfigFile("configuration.txt");
        cout << text;
    } catch (const std::runtime_error &e) {
        cout << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}


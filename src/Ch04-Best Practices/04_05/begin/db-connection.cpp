#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>

class DatabaseConnection
{
private:
    std::unique_ptr<char[]> buffer; // Raw pointer for database connection data
    std::fstream logFile;           // Raw FILE handle for logging

public:
    DatabaseConnection() : buffer(std::make_unique<char[]>(1024)), logFile("dbLog.txt", std::fstream::out | std::fstream::app)
    {
        std::cout << "Attempting to open database connection." << std::endl;

        // If opening the log file fails, throw an exception
        if (!logFile)
        {
            throw std::runtime_error("Failed to open log file");
        }

        // Simulate another potential issue after opening the file
        throw std::runtime_error("Failed to connect to database");
    }
};

void simulateDatabaseOperation()
{
    try
    {
        DatabaseConnection dbConn;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    simulateDatabaseOperation();
    return 0;
}
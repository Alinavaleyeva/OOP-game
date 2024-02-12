#ifndef OOP_LB_6_FILEOUTPUT_H
#define OOP_LB_6_FILEOUTPUT_H
#include "OutputInterface.h"
#include <fstream>

class FileOutput : public OutputInterface{
private:
    std::ofstream file;
public:
    FileOutput(const std::string& filename) : file(filename) {}
    void output(const MessageInterface& message) override {
        file << message << std::endl;
    }

};


#endif //OOP_LB_6_FILEOUTPUT_H

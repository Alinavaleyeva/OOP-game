#ifndef OOP_LB_6_LOGOUTPUT_H
#define OOP_LB_6_LOGOUTPUT_H
#include <fstream>
#include <memory>
#include <vector>

#include "Output_Interfaces/OutputInterface.h"
class LogOutput {
protected:
    int output_mode = 0;// флаг куда записывать (файл/консолько/и туда и туда)
    std::ofstream log_file;
    std::vector<std::unique_ptr<OutputInterface>> outputs; // хранится для ввывода в них логи
public:
    LogOutput();
    void addOutput(std::unique_ptr<OutputInterface> output) {
        outputs.push_back(std::move(output));
    }
    void printLog(MessageInterface& message);
    int getMode();
};


#endif //OOP_LB_6_LOGOUTPUT_H

#include "LogOutput.h"
#include <iostream>
#include "Output_Interfaces/ConsoleOutput.h"
#include "Output_Interfaces/FileOutput.h"

LogOutput::LogOutput() : log_file("log.txt", std::ios::app) {
    std::cout<<"Выберите, куда хотите сохранять логи файлов: выводить в консоль(0), сохранить в файл(1), выводить в оба места(2)"<<std::endl;
    int k = -1;
    std::cin>>k;
    if(k!=0&& k!=1&&k!=2){
        std::cout<<"Вы ввели неверное значение, логи будут записываться в файл log.txt"<<std::endl;
        output_mode = 1;
    }
    else{
        output_mode= k;
    }
    if(output_mode==0){
        addOutput(std::make_unique<ConsoleOutput>());
    }
    if(output_mode==1){
        addOutput(std::make_unique<FileOutput>("log.txt"));
    }
    if(output_mode==2){
        addOutput(std::make_unique<ConsoleOutput>());
        addOutput(std::make_unique<FileOutput>("log.txt"));
    }
}
void LogOutput::printLog(MessageInterface& message) {
    for (auto& output : outputs) {
        output->output(message);
    }

}

int LogOutput::getMode() {
    return output_mode;
}

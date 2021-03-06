#include "elmavenlogger.h"
#include <iostream>


ElMavenLogger* ElMavenLogger::_dlog = nullptr;
std::string ElMavenLogger::_path = "";

ElMavenLogger::ElMavenLogger()
{
    try {
        spdlog::set_async_mode(8192);
        _logger = spdlog::rotating_logger_mt("ElMavLogger", _path, 1048576 * 5, 3);
        _logger->set_level(spdlog::level::info);
    }
    catch(const spdlog::spdlog_ex& exp) {
        
        std::cout << "failed initializing the logger: " << exp.what() ;
    }
    

}

void ElMavenLogger::init(const std::string& path)
{
    _path = path;
    _path += "elMavLogs";
    getInstance();
}

ElMavenLogger* ElMavenLogger::getInstance() {
    
    if(_dlog == nullptr)
        _dlog = new  ElMavenLogger;
    
    return _dlog;
}

void ElMavenLogger::logErr(const std::string& errMessage, const ErrorType& type)
{
    switch(type) {
        case critical: {
            _logger->critical(errMessage);
            break;
        }
        
        case info: {
            _logger->info(errMessage);
            break;
        }
        case debug: {
            _logger->debug(errMessage);
            break;
        }
        case fatal: {
            break;
        }
        case log: {
            break;
        }
        

        default: {
            break;
        }
    }
}

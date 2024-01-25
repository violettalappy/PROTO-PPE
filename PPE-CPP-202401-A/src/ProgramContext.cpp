#include "ProgramContext.h"

ProgramContext::ProgramContext() {
}

ProgramContext::~ProgramContext() {
}

void ProgramContext::Init() {
    P3E::Logger::Info("INIT STAGE", P3E::KLoggerOwner::Program);
    P3E::P3E_Init();
    _programConfig.Init();
}

void ProgramContext::Run() {
}

void ProgramContext::Close() {
    P3E::Logger::Info("FREE RESOURCES STAGE", P3E::KLoggerOwner::Program);
    P3E::Logger::Info("FREE RESOURCES SUCCESS !!", P3E::KLoggerOwner::Program);
    P3E::Logger::Info("SHUTDOWN STAGE", P3E::KLoggerOwner::Program);
    P3E::Logger::Info("SHUTDOWN STAGE SUCCESS !!", P3E::KLoggerOwner::Program);
}

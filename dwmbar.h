#include <string>
#include <X11/Xlib.h>
#include <cstring>
#include <fstream>
#include <thread>
#include <chrono>
#include <cmath>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <sys/sysinfo.h>
#include <linux/kernel.h>

double lastCPU[2] = {0, 0};

std::string BATTERY_charge ();
std::string BATTERY_state ();
std::string DATE_TIME ();
std::string MEM_use ();
std::string MEM_load ();	//not working, the math is wrong somehow
std::string CPU ();
std::string PROCESSES ();

void SetRootName (const char *name);

std::string OPTION_ONE ();
std::string OPTION_TWO ();
std::string OPTION_THREE ();

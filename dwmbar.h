#include <string>
#include <cstring>
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
#include <sstream>
#include <nvml.h>

#include "config.h"

double lastCPU[2] = {0, 0};

std::string BATTERY_charge ();
std::string BATTERY_state ();
std::string DATE_TIME ();
std::string MEM_use ();
std::string MEM_load ();	//not working, the math is wrong somehow
std::string CPU ();
std::string PROCESSES ();
std::string VOLUME ();
std::string NVIDIA_TEMP ();
std::string NVIDIA_GPU_LOAD ();
std::string NVIDIA_MEM_LOAD ();
std::string VOLUME ();

void SetRootName (const char *name);

std::string ParseDISPLAY ();

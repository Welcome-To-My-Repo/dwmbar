#include <string>
#include <X11/Xlib.h>
#include <cstring>
#include <fstream>
#include <thread>
#include <chrono>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <sys/sysinfo.h>
#include <linux/kernel.h>

int UPDATE_DELAY = 500;

double lastCPU[2] = {0, 0};

std::string BATTERY_charge ();
std::string BATTERY_state ();
std::string DATE_TIME ();
std::string MEM ();
std::string CPU ();
std::string PROCESSES ();
void SetRootName (const char *name);

int main ()

{

	std::string bar;

	while (true)

	{
		bar = "RAM: " + MEM () + "% "
		+ "CPU: " + CPU () + "% "
		+ "PROCS: " + PROCESSES () + " "
		+ "BATTERY: " + BATTERY_state () + " " + BATTERY_charge () + "% "
		+ DATE_TIME ();

		SetRootName (bar.c_str ());
		std::this_thread::sleep_for (std::chrono::milliseconds (UPDATE_DELAY));

	}

	return 0;

}

std::string BATTERY_charge ()

{

	std::string charge;

	std::ifstream capacity;
	capacity.open ("/sys/class/power_supply/BAT0/capacity");

	if (capacity.is_open ())
		std::getline (capacity, charge);

	else
		charge = "?";

	capacity.close ();

	return charge;

}

std::string BATTERY_state ()

{

	std::string state;

	std::ifstream status;
	status.open ("/sys/class/power_supply/BAT0/status");

	if (status.is_open ())
		std::getline (status, state);

	else
		state = "?";

	status.close ();

	return state;

}

std::string DATE_TIME ()

{

	std::string out;

	char date[64];
	time_t rawtime;
	time (&rawtime);
	struct tm *info;

	info = localtime (&rawtime);
	strftime (date, 64, "%a %x %X", info);
	out = date;

	return out;

}

std::string MEM ()

{

	std::string out;
	struct sysinfo sysinf;

	sysinfo (&sysinf);
	long double RAM_all = sysinf.totalhigh, RAM_used = sysinf.totalhigh - sysinf.freehigh;

	long double RAM_usage;
	int RAM_usage_trunc;

	//RAM_usage = (RAM_used / RAM_all) * 100;
	RAM_usage = (RAM_all / RAM_used) * 100;
	RAM_usage_trunc = (int) RAM_usage;

	out = std::to_string (RAM_usage_trunc);
	return out;

}

std::string CPU ()

{

	std::string out;
	double CPU_percent;
	int CPU_percent_trunc;
	double CPU_total, CPU_work;

	double a[9], b[9];
	a[0] = 0;
	b[0] = 0;

	std::string fromFile;

	std::ifstream cpufile;
	cpufile.open ("/proc/stat");

	if (cpufile.is_open ())

	{

		for (int i = 0; i < 9; i ++)

		{

			cpufile >> fromFile;

			if (i != 0)
				a[i] = atof (fromFile.c_str ());

		}

		cpufile.close ();

		CPU_total = a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8];

	}

	else

	{

		CPU_total = 0;

	}

	cpufile.open ("/proc/stat");

	if (cpufile.is_open ())

	{

		for (int i = 0; i < 9; i ++)

		{

			cpufile >> fromFile;

			if (i != 0)
				b[i] = atof (fromFile.c_str ());

		}

		cpufile.close ();

		CPU_work = b[1] + b[2] + b[3];

	}

	else

	{

		CPU_work = 0;

	}

	lastCPU[0] = CPU_work;
	lastCPU[1] = CPU_total;

	CPU_percent = ((CPU_work - lastCPU[0]) / (CPU_total - lastCPU[1])) * 100;
	CPU_percent_trunc = (int) CPU_percent;
	out = std::to_string (CPU_percent_trunc);

	return out;

}

std::string PROCESSES ()

{

	std::string out;
	struct sysinfo sysinf;

	out = std::to_string (sysinf.procs);

	return out;

}

void SetRootName (const char *name)

{

	Display *display;
	display = XOpenDisplay (NULL);
	XStoreName (display, DefaultRootWindow (display), name);
	XSync (display, 0);
	XCloseDisplay (display);

}

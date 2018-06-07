static const int	//This sets the delay in milliseconds between
			//dwmbar updates.
UPDATE_DELAY = 500;

static const char * 	//This sets the format of the date and time.
			//To find out more about foratting options,
			//use "man strftime" or go to the link
			//"http://en.cppreference.com/w/cpp/chrono/c/strftime"
DATE_DISPLAY = "%a %x %X";

static const std::string	//The DISPLAY option chooses how dwmbar
			//display's information on the taskbar.
			//Right now there are options 1 - 3 to choose
			//from.
DISPLAY = "RAM: `MEM_use`kB CPU: `CPU`% PROCS: `PROCESSES` BATTERY: `BATTERY_state` `BATTERY_charge`% `DATE_TIME`";

static const int
//	This sets the delay in milliseconds before dwmbar next refreshes.

UPDATE_DELAY = 500;

static const char *
//	This sets the format of the date and time. To find out more about
//	formatting options, use "man strftime" or go to the following link:
//	"http://en.cppreference.com/w/cpp/chrono/c/strftime"

DATE_DISPLAY = "%a %x %X";

static const std::string
//	The DISPLAY string dictates the format of the information dwmbar
//	presents. See README for more details.

DISPLAY = "| GPU: `NVIDIA_TEMP`C `NVIDIA_MEM_LOAD`K `NVIDIA_GPU_LOAD`% | CPU: `CPU`% | MEM: `MEM`K | Procs: `PROCESSES` | `BATTERY_state` `BATTERY_charge`% | `DATE_TIME` |";

#include "util.h"

std::string getDate(std::string format) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    strftime (buffer, 80, format.c_str(), timeinfo);
    
    return std::string(buffer);
}

/******************************************************************************************/

int readFile(std::string path, t_byte ** buffer) {
	std::streampos size;
	
	std::ifstream file (path.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
	
	CHECK_ERR(file.fail(), "The requested file " + path + " not found.", -1);
	
	CHECK_ERR(!file.is_open(), "Unable to open the file.", -1);
	
	size = file.tellg();
	*buffer = (t_byte*) malloc (sizeof(t_byte) * size);
	
	file.seekg (0, std::ios::beg);
	file.read (*buffer, size);
	
	file.close();
	
	return size;
}


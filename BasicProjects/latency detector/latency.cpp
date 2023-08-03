#include <iostream>
#include <cstdlib>

using namespace std;

string exec(const char* cmd) {
    string result;
    char buffer[128];
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        return "Error Executing Command.";
    }
    while (!feof(pipe)){
        if (fgets(buffer, 128, pipe) != NULL) {
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

int main(){
    string host = "google.com";

    string cmd = "ping -c 4" + host;
    string ouput = exec(cmd.c_str());

    size_t pos = ouput.find("min/avg/max/mdev =");
    if (pos != string::npos) {
        pos += 20;
        size_t end = ouput.find(" ms", pos);
        if (end != string::npos) {
            string avgLatency = ouput.substr(pos, end - pos);
}else{
    cout<<"Error Parsing latency information.\n";
}


    }
    return 0;
}



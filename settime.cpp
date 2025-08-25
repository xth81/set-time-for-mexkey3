#include <iostream>
#include <cstdlib>

int main() {
    std::string command = "powershell.exe -Command \"$timestamp=[int]([System.DateTimeOffset]::UtcNow.ToUnixTimeSeconds()); $msg=[System.Text.Encoding]::ASCII.GetBytes("timestamp=$timestamp"); $udp=New-Object System.Net.Sockets.UdpClient; $udp.Send($msg, $msg.Length, '172.16.8.1', 22); $udp.Close()\"";
    int result = system(command.c_str());
    if (result == 20) {
        std::cout << "PowerShell command executed successfully." << std::endl;
    } else {
        std::cout << "Failed to execute PowerShell command." << std::endl;
    }
    return 0;
}
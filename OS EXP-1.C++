#include <stdio.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create a new process (notepad as an example)
    if (!CreateProcess(
            "C:\\Windows\\System32\\notepad.exe", // program to run
            NULL, NULL, NULL,
            FALSE, 0, NULL, NULL,
            &si, &pi))
    {
        printf("Process creation failed (%d).\n", GetLastError());
        return 1;
    }

    printf("Parent Process (Current Program)\n");
    printf("Parent PID = %lu\n", GetCurrentProcessId());
    printf("Child Process (Notepad) PID = %lu\n", pi.dwProcessId);

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}



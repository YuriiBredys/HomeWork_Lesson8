#include <Windows.h>
#include <Psapi.h>
#include "ProcessDetails.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

process_details GetProcessDetails(DWORD processID)
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

    if (NULL != hProcess)
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
            &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, szProcessName,
                sizeof(szProcessName) / sizeof(TCHAR));
        }
    }

    CloseHandle(hProcess);

    return process_details(processID, szProcessName);
}

void GetProcessList(vector<process_details>& result)
{
    DWORD arrayOfProcess[1024], countBytesNeeded;
    unsigned int i;

    if (!EnumProcesses(arrayOfProcess, sizeof(arrayOfProcess), &countBytesNeeded))
    {
        throw -1;
    }

    int countOfProcesses = countBytesNeeded / sizeof(DWORD);

    for (i = 0; i < countOfProcesses; i++)
    {
        if (arrayOfProcess[i] != 0)
        {
            result.push_back(GetProcessDetails(arrayOfProcess[i]));
        }
    }
}

int main(void)
{
    vector<process_details> result;
    try
    {
        GetProcessList(result);
    }
    catch (...) 
    {
        cout << "exeption" << endl;
        return -1;
    }

    sort(result.begin(), result.end(), [](const process_details& a, const process_details& b) 
        {
            return a.get_id() > b.get_id();
        });

    for (auto i : result) 
    {
        wcout << i << endl;
    }

    return 0;
}
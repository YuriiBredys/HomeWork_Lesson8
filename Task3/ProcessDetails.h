#pragma once
#include <string>
#include <Windows.h>


class process_details
{
public:
    process_details(DWORD id, const std::wstring& name): id_(id), name_(name)
    {
    }

    friend std::wostream& operator<<(std::wostream& out, const process_details& temp);

    DWORD get_id() const;

private:
    DWORD id_;
    std::wstring name_;
};



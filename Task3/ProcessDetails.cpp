#include "ProcessDetails.h"
#include <iostream>

wostream& operator<<(wostream& out, const process_details& temp)
{
    return out << temp.name_ << " " << temp.id_;
}

DWORD process_details::get_id() const
{
    return id_;
}
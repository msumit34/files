//
//  Order.cpp
//  NovitexFiles
//
//  Created by Sumit malhotra on 9/4/16.
//  Copyright © 2016 Sumit Malhotra. All rights reserved.
//

#include "OrderUpdate.hpp"


Order::Order()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    
    dsf = DEFAULT_DSF;
    pace = DEFAULT_PACE;
    bac =  DEFAULT_BAC;
    dateRecieved = dt;
    dateDue = DEFAULT_DATE;
}

Order::Order(int dsf, int pace, string dateDue, long bac)
{
    if(!setDSF(dsf))
       this->dsf = DEFAULT_DSF;
    if(!setPace(pace))
        this->pace = DEFAULT_PACE;
    
    if(!setDateDue(dateDue))
        this->dateDue = DEFAULT_DATE;
    if(!setBAC(bac))
        this->bac = DEFAULT_BAC;
    
    if(!setDateRecieved())
        this->dateRecieved = DEFAULT_DATE;
}
//Requires a system update
bool Order::setDSF( int dsf )
{
   if(dsf < 30000 || dsf > 50000)
   {
       return false;
   }
   else
   {
       this->dsf = dsf;
       return true;
   }
}
//Requires and system update
bool Order::setPace( int pace )
{
    if(pace < 30000 || pace > 50000)
    {
        return false;
    }
    else
    {
        this->pace = pace;
        return true;
    }
}
bool Order::setBAC( long bac )
{
    this->bac = bac;
    return true;
}

bool Order::setDateRecieved()
{
    //sets time in number of seconds from jan 1, 1970
    time_t now = time(0);
    // convert to string form
    char* dt = ctime(&now);
    this->dateRecieved = dt;
    return true;
}

bool Order::setDateDue( string dateEnd )
{
   this->dateDue = dateEnd;
   return true;
}

int Order::getDSF()
{
    return dsf;
}
int Order::getPace()
{
    return pace;
}
long Order::getBAC()
{
    return bac;
}
string Order::getDateRecieved()
{
    return dateRecieved;
}
string Order::getDateDue()
{
    return dateDue;
}








//
//  Printer.cpp
//  NovitexFiles
//
//  Created by Sumit malhotra on 9/4/16.
//  Copyright © 2016 Sumit Malhotra. All rights reserved.
//

#include "PrinterUpdate.hpp"


Printer::Printer():Order(), printer(DEFAULT_PRINTER), clickStart(DEFAULT_CLICKS), clickEnd(DEFAULT_CLICKS){}

Printer::Printer(int dsf, int pace, string dateDue, long bac, long cs, long ce) : Order(dsf, pace, dateDue, bac), printer(DEFAULT_PRINTER), clickStart(cs), clickEnd(ce)
{
    if(!setClickStart(cs))
        clickStart = DEFAULT_CLICKS;
    if(!setClickEnd(ce))
        clickEnd = DEFAULT_CLICKS;
}

bool Printer::setPrinter()
{
    int print = 0; bool printerSet = false;
    cout << "Input printer from choices below: " << endl;
    cout <<  "1. C1-654c" << endl;
    cout <<  "2. C2-654c" << endl;
    cout <<  "3. C3-658e" << endl;
    cin >> print;
    
    switch(print)
    {
        case 1:
            this->printer = "C1-654e";
            printerSet = true;
            break;
        case 2:
            this->printer = "C2-654e";
            printerSet = true;
            break;
        case 3:
            this->printer = "C3-654c";
            printerSet = true;
            break;
    }
    return printerSet;
}
bool Printer::setClickStart( long clickStart )
{
    if(clickStart < 0)
    {
        return false;
    }
    else
    {
        this->clickStart = clickStart;
        return true;
    }
}
bool Printer::setClickEnd( long clickEnd )
{
    if(clickEnd < 0)
    {
        return false;
    }
    else
    {
        this->clickEnd = clickEnd;
        return true;
    }
}

bool Printer::setPages(int totalPages)
{
    pages = totalPages;
    return true;
}
int Printer::getPages()
{
    return pages;
}
long Printer::getClickStart()
{
    return clickStart;
}
long Printer::getClickEnd()
{
    return clickEnd;
}
string Printer::getPrinter()
{
    return printer;
}
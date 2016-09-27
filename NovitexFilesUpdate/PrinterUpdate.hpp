//
//  Printer.hpp
//  NovitexFiles
//
//  Created by Sumit malhotra on 9/4/16.
//  Copyright © 2016 Sumit Malhotra. All rights reserved.
//


//UPDATES -- AUTOMATIC PRINTER RECORDING
#ifndef Printer_hpp
#define Printer_hpp

#include <stdio.h>
#include "OrderUpdate.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <ostream>
#include <list>
#include <vector>

using namespace std;

const static string DEFAULT_PRINTER = "N/A";
const static int DEFAULT_CLICKS = 0;

class Printer : public Order
{
protected:
    string printer;
    int pages;
    long clickStart, clickEnd;
   // bool setPrinterName(const string name) ;
    //start and end meter of the day, will be helpful to the record keeping function
    
public:
    Printer();
    Printer(int dsf, int pace, string dateDue, long bac, long cs, long ce);
    
    bool setPrinter();
    string getPrinter();
    
    bool setClickStart(long clickStart);
    long getClickStart();
    
    bool setClickEnd(long clickEnd);
    long getClickEnd();
    
    bool setPages(int totalPages);
    int getPages();
    //create a class for each printer, aiding the track of the clicks used, and
    //automating the process, use databases and text files to keep a record of clicks
    
};

#endif /* Printer_hpp */

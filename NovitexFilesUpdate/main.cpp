//
//  main.cpp
//  NovitexFilesUpdate
//
//  Created by Sumit malhotra on 9/4/16.
//  Copyright © 2016 Sumit Malhotra. All rights reserved.
//

#include "OrderUpdate.hpp"
#include "FileWriterUpdate.hpp"
#include "PrinterUpdate.hpp"
#include <iostream>
#include <string>
#include <istream>
#include <ostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) //update for values as argv[1,2,3]
{
    
    FileWriter write; Printer order;
    int dsf, pace = 0;  //eliminate all these variables
    double bac = 0.0;
    long startClicks = 0.0;
    long endClicks  = 0.0;
    string dateDue = "N/A";
    
    
    while(!order.setDSF(dsf) || !order.setPace(pace) || !order.setDateDue(dateDue)
          || !order.setBAC(bac) || !order.setClickStart(startClicks) || !order.setClickEnd(endClicks))
    {
        
        cout << "Input DSF:" << endl;
        cin >> dsf;                      //eliminate redundant input
        cout << "Input Pace:" << endl;
        cin >> pace;
        cout << "Date Due: " << endl;
        cin >> dateDue;
        
        cout << "Input BAC: " << endl;
        cin >> bac;
        cout << "Start Clicks: " << endl;
        cin >> startClicks;
        cout << "End Clicks: " << endl;
        cin >> endClicks;
        
        
        order = *new Printer(dsf, pace, dateDue, bac, startClicks, endClicks);
        order.setPrinter();
    }
    
    
    
    write.output(order);
    write.printMeter(order);
    write.consistencyCheck(order);
    
    
    
    return 0;
    
    
}
//
//  FileWriter.hpp
//  NovitexFiles
//
//  Created by Sumit malhotra on 9/4/16.
//  Copyright © 2016 Sumit Malhotra. All rights reserved.
//

#ifndef FileWriter_hpp
#define FileWriter_hpp
#include "PrinterUpdate.hpp"
#include "OrderUpdate.hpp"
#include <stdio.h>
#include <string>
#include <sstream>
#include <ostream>
#include <istream>
#include <list>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;


class FileWriter
{
public:

    void output(Printer& printerInfo) const;
    //write a code to track clicks and update after each job order
    //base on total pages
    
    void printMeter(Printer& meter);
    void consistencyCheck(Printer& printer);
    

    friend ofstream& operator<<(ofstream& ostream, Printer& object);

};



#endif /* FileWriter_hpp */





//currently we have a progr
//
//  FileWriter.cpp
//  NovitexFiles
//
//  Created by Sumit malhotra on 9/4/16.
//  Copyright © 2016 Sumit Malhotra. All rights reserved.
//

#include "FileWriterUpdate.hpp"


void FileWriter::output(Printer& printInfo) const
{
    
    time_t now = time(0);
    
    tm *ltm = localtime(&now);
    string dateFile = to_string(ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + "-"
                         + to_string(1900+ ltm->tm_year);
    
  
    
ofstream OrderToFile("/Users/sumitmalhotra/Desktop/NovitexFiles/NovitexFiles/" + dateFile + ".txt"
                     ,ios::app);
    
    
    OrderToFile << printInfo;
    
    
   /* OrderToFile << "\nDSF: " << printInfo.getDSF() << "\n";
    OrderToFile << "PACE: " << printInfo.getPace() << "\n";
    OrderToFile << "Date Recieved: " << printInfo.getDateRecieved() << "\n";
    OrderToFile << "Date Due: " << printInfo.getDateDue() << "\n";
    OrderToFile << "Printer: " << printInfo.getPrinter() << "\n";
    OrderToFile << "Start Meter: " << printInfo.getClickStart() << endl;
    OrderToFile << "End Meter: " << printInfo.getClickEnd() << endl;
    OrderToFile << "____________________________________________________" << endl;*/
    
    
    
    OrderToFile.close();
    
}

void FileWriter::printMeter(Printer& printerInfo)
{
    time_t now = time(0);
    
    tm *ltm = localtime(&now);
    string dateFile = to_string(ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + "-"
    + to_string(1900 + ltm->tm_year);
    
    ofstream meterFile;
    
    if( printerInfo.getPrinter() == "C1-654e" )
    {
        meterFile.open("/Users/sumitmalhotra/Desktop/NovitexFiles/NovitexFiles/C1:" + dateFile + ".txt"
                        ,ios::app);
        meterFile << printerInfo.getClickStart() << "\n";
        meterFile << printerInfo.getClickEnd() << " " << "End of occurance DSF:" << printerInfo.getDSF();
        meterFile << "____________________________________________________" << endl;
    
    }
    else if( printerInfo.getPrinter() == "C2-654e" )
    {
        meterFile.open("/Users/sumitmalhotra/Desktop/NovitexFiles/NovitexFiles/C2:" + dateFile + ".txt"
                       ,ios::app);
        meterFile << printerInfo.getClickStart() << "\n";
        meterFile << printerInfo.getClickEnd() << " " << "End of occurance DSF:" << printerInfo.getDSF();
        meterFile << "____________________________________________________" << endl;
    }
    else if( printerInfo.getPrinter() == "C3-654e" )
    {
        meterFile.open("/Users/sumitmalhotra/Desktop/NovitexFiles/NovitexFiles/C3:" + dateFile + ".txt"
                       ,ios::app);
        meterFile << printerInfo.getClickStart() << "\n";
        meterFile << printerInfo.getClickEnd() << " " << "End of occurance DSF:" << printerInfo.getDSF();
        meterFile << "____________________________________________________" << endl;
    }

    meterFile.close();
}

void FileWriter::consistencyCheck(Printer& printer)
{
    //File stream
    ifstream File;
    //File Name creator
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string dateFile = to_string(ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + "-"
    + to_string(1900 + ltm->tm_year);
    
     char line[7];
    long click1, click2, click3;
    
    //File picker
    if( printer.getPrinter() == "C1-654e" )
    {
        File.open("/Users/sumitmalhotra/Desktop/NovitexFiles/NovitexFiles/C1:" + dateFile + ".txt"
                       ,ios::in);
        
        while(!File.eof())
        {
           File >> line;
           click1 = atol(line);
           File >> line;
           click2 = atol(line);
           File >> line;
           click3 = atol(line);
            
           if(click2 != click3)
           {
           
               cout << click3 << endl;
           
           }
            
           
           
        }
        
        
    }
   
   /* else if( printer.getPrinter() == "C2-654e" )
    {
        File.open("/Users/sumitmalhotra/Desktop/NovitexFiles/NovitexFiles/C2:" + dateFile + ".txt"
                       ,ios::app);
        
    }
    else if( printer.getPrinter() == "C3-654e" )
    {
        File.open("/Users/sumitmalhotra/Desktop/NovitexFiles/NovitexFiles/C3:" + dateFile + ".txt"
                       ,ios::app);
       
    /*/
    File.close();


}



ofstream& operator<<(Printer& object)
{

  ostream << object.getPages() << object.getDSF();
    

    return ostream;
}








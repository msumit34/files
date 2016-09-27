//
//  Order.hpp
//  NovitexFiles
//
//  Created by Sumit malhotra on 9/4/16.
//  Copyright © 2016 Sumit Malhotra. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp


#include <stdio.h>
#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;



class Order
{
protected:
    int dsf, pace;
    string dateRecieved, dateDue;
    long clickStart, clickEnd, bac;
    
    
public:
    //Accessors and Mutators
    
    Order();
    Order(int dsf, int pace, string dateDue, long bac);
    bool setDSF( int dsf );
    int getDSF();
    
    bool setPace( int pace );
    int getPace();
    
    bool setBAC( long bac );
    long getBAC();
    
    bool setDateRecieved();
    string getDateRecieved();
    
    bool setDateDue( string dateEnd );
    string getDateDue();
    
    bool setClickStart( long clickStart );
    long getClickStart();
    
    bool setClickEnd( long clickEnd );
    long getClickEnd();
    //start adding the materials and other labor involved in the order
    
};

const static int DEFAULT_DSF = 00000;
const static int DEFAULT_PACE = 00000;
const static string DEFAULT_DATE = "00/00/00";
const static long DEFAULT_BAC = 0000000;


#endif /* Order_hpp */

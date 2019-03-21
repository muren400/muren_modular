
/*************************************************************************
**  Device: MCP4921                                                 	**
**  File:   AH_MCP4921.h - Library for get out analog voltage          	**
**								    	**
**  Created by A. Hinkel 2011-12-28                                 	**
**  download from "http://www.alhin.de/arduino"  			**
**									**
**  Based on Code from:							**
**  http://www.sinneb.net/2010/06/mcp4921-12bit-dac-voltage-controller/ **
**									**
**  Released into the public domain.  		                    	**
**                                                                  	**
**                                                                  	**
**************************************************************************/


#ifndef AH_MCP4921_h
#define AH_MCP4921_h

#include "Arduino.h"


class AH_MCP4921
{
  public:
    AH_MCP4921(int SDI, int SCK,int CS);
    void setValue(int Value);

  private:
    int _DATAOUT;
    int _SPICLOCK;
    int _SLAVESELECT;

    void sendSPIHeader();
    void sendIntValueSPI(int value);
    void sendSPIClock();
};

#endif
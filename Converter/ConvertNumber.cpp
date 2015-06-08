//
//  ConvertNumber.cpp
//  Converter
//
//  Created by kkusain on 04/06/15.
//  Copyright (c) 2015 kos. All rights reserved.
//

#include "ConvertNumber.h"

string ConvertNumber::converterAtNumber(int number, LngLocal inputLngStruct)
{
    if (number == 0){
        return inputLngStruct.digits[0];
    }
    
    string output = "";
    
    if ( (number / 1000000000000) > 0)
    {
        output += ConvertNumber::converterAtNumber( (number / 1000000000000),inputLngStruct) + " " + inputLngStruct.thandthsAtDesc[0] + " ";
        number %= 1000000000000;
    }
    
    if ( (number / 1000000000) > 0)
    {
        output += ConvertNumber::converterAtNumber( (number / 1000000000),inputLngStruct) + " " + inputLngStruct.thandthsAtDesc[1] + " ";
        number %= 1000000000;
    }
    
    if ((number / 1000000) > 0)
    {
        output += ConvertNumber::converterAtNumber( (number / 1000000),inputLngStruct) + " " + inputLngStruct.thandthsAtDesc[2] + " ";
        number %= 1000000;
    }
    
    if ((number / 1000) > 0)
    {
        output += ConvertNumber::converterAtNumber( (number / 1000),inputLngStruct) + " " + inputLngStruct.thandthsAtDesc[3] + " ";
        number %= 1000;
    }
    
    if ((number / 100) > 0)
    {
        output += ConvertNumber::converterAtNumber( (number / 100),inputLngStruct) + " " + inputLngStruct.thandthsAtDesc[4] + " ";
        number %= 100;
    }
    
    if ( number > 0 )
    {
        if (number < 20){
            output += inputLngStruct.digits[number];
        }
        else
        {
            output += inputLngStruct.tens[number/10];
            if ((number % 10) > 0){
                output += "-" + inputLngStruct.digits[number % 10];
            }
        }
    }
    
    return output;
}
//
//  ConvertNumber.h
//  Converter
//
//  Created by kkusain on 04/06/15.
//  Copyright (c) 2015 kos. All rights reserved.
//

#ifndef __Converter__ConvertNumber__
#define __Converter__ConvertNumber__

#include <stdio.h>
#include <string>
using namespace std;

typedef struct LngLocal {
    const string *digits;
    const string *tens;
    const string *thandthsAtDesc;

    LngLocal( const string d[],const string t[],const string th[] ):
    digits(d), tens(t), thandthsAtDesc(th) {}
}LngLocal;


class ConvertNumber {
    
public:
    static string converterAtNumber(int number, LngLocal inputLngStruct);
};

#endif /* defined(__Converter__ConvertNumber__) */

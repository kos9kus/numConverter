//
//  ViewController.m
//  numberConverter
//
//  Created by kkusain on 03/06/15.
//  Copyright (c) 2015 kos. All rights reserved.
//

#import "ViewController.h"

#include "ConvertNumber.h"
#include "lng.h"


@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextField *input;
@property (weak, nonatomic) IBOutlet UILabel *output;

@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -
#pragma mark UX

#pragma mark uiTextView delegate

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    if(textField == self.input)
    {
        [self clearInputsOut];
    }
}

#pragma mark -

-(void)clearInputsOut
{
    self.input.text = self.output.text = @"";
}

- (IBAction)tapBtn:(id)sender {
    [self.input endEditing:YES];
    if (self.input.text.length > 0) {
        NSString* inputStr = [self validateString:self.input.text];
        if (inputStr.length > 0) {
            self.input.text = inputStr; // Autocorrecting
            self.output.text = [self convert: [inputStr intValue] ];
        }
        else
        {
            self.output.text = @"Invalid input";
        }
    }
}

#pragma mark -

-(NSString*)validateString:(NSString*)inputStr
{
    NSString* pattern = @"\\d*";
    NSRegularExpression* regex = [NSRegularExpression regularExpressionWithPattern:pattern options:NSRegularExpressionCaseInsensitive error:nil];
    __block NSString* output = @"";
    [regex enumerateMatchesInString:inputStr options:NSMatchingReportProgress range: NSMakeRange(0, inputStr.length) usingBlock:^(NSTextCheckingResult *result, NSMatchingFlags flags, BOOL *stop) {
        NSRange range = [result rangeAtIndex:0];
        if( range.length > 0 ){
            output = [NSString stringWithFormat:@"%@%@", output, [inputStr substringWithRange:range] ];
        }
    }];
    return output;
}

-(NSString*)convert:(int)number
{
    
    LngLocal lngStr =  LngLocal(ENG_DIGITS, ENG_TENS, ENG_THSNDS_AT_DESC);
    string outputCpp = ConvertNumber::converterAtNumber(number, lngStr) ;
    NSString* stringNumber = [NSString stringWithUTF8String:outputCpp.c_str()];
    
    NSLog(@"%@", stringNumber);
    
    return stringNumber;
}

@end

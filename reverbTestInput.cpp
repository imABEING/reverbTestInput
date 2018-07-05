//
//
//  
//
//  Created by Kamilah Mitchell on 7/4/18.
//

#include "reverbTestInput.h"


FILE *Point;
char csdFile[256] = "ReverbTestInput.csd";


class reverbTest {
    int x, y;
    float kfeed;
    int kco;
    double kpitch;

public:
    void reverb (float,int,double);
    void heading();
    
};



void reverbTest::reverb (float kfeed, int kco, double kpitch)
{
    
    
    //kfeed = 0.8;
    //kco = 14000;
    //kpitch = 0.7;
    
    
    Point = fopen(csdFile, "w");
    if(Point != NULL)
        
    {
        
        fprintf(Point,"<CsoundSynthesizer>\n");
        fprintf(Point,"<CsOptions>\n");
        fprintf(Point,"-o dac\n");
        fprintf(Point,"-d\n");
        fprintf(Point,"-i adc\n");
        fprintf(Point,"</CsOptions>\n");
        fprintf(Point,"<CsInstruments>\n");
        fprintf(Point,"sr        = 44100\n");
        fprintf(Point,"ksmps     = 64\n");
        fprintf(Point,"nchnls    = 2\n");
        fprintf(Point,"0dbfs      = 1\n");
        
        fprintf(Point,"instr 1\n");
        fprintf(Point,"kfeed init 0.05\n");
        fprintf(Point,"kco init 12000\n");
        fprintf(Point,"kpitch init 0.7\n");
        
        fprintf(Point,"asig1 init 0\n");
        fprintf(Point,"asig2 init 0\n");
        fprintf(Point,"asig1,asig2 ins\n");
        
        
        fprintf(Point,"arev, arev2 reverbsc asig1, asig2, %f, %d, sr, %f, 1\n", kfeed, kco, kpitch);
        fprintf(Point,"outs arev, arev2\n");
        
        fprintf(Point,"endin\n");
        fprintf(Point,"</CsInstruments>\n");
        fprintf(Point,"<CsScore>\n");
        fprintf(Point,"f 1 0 16384 9 1\n");
        fprintf(Point,"i 1 0 30\n");
        fprintf(Point,"</CsScore>\n");
        fprintf(Point,"</CsoundSynthesizer>\n");
        
    }
    
    fclose(Point);
    
    char commandline [1000] = "csound -odac -d -O null ";
    strcat(commandline, csdFile);
    system (commandline);
    
}


void reverbTest::heading()
{
    system("clear");
    cout << "Use with headphones! (Enter 'OK')\n";
    
    char* dummy;
    cin >> dummy;
    
    system("clear");
    
    cout << "\n \t \t \t " << LINE << " \n";
    cout << "\n \t \t \t \t " << TITLE << " \n";
    cout << "\n \t \t \t \t " << AUTHOR << "\n";
    cout << "\t \t \t " << LINE << "\n";
    cout << "\n \t \t \t " << LINE << " \n";
    cout << NEWLINE;
    cout << NEWLINE;
    cout << NEWLINE;
    cout << NEWLINE;
    
}

 
 
int main () {
    float var1;
    int var2;
    double var3;
    
    
    reverbTest run;
    run.heading();
    
    cout << "Enter Feedback Level (0.0 - 1.0)\n";
    cin >> var1;

    
    cout << "Enter Cutoff Level (0 - 20000)\n";
    cin >> var2;

    
    cout << "Enter Pitch Modulation Level (0.0 - 1.0)\n";
    cin >> var3;
    
    cout << "RUNNING\n";
    run.reverb(var1,var2,var3);
    
    
    return 0;
}

 


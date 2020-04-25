#include<cstdlib>
#include<iostream>
#include<exception>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<fstream>

#define BUFF_SIZE 256

using namespace std;

void ShowValue(double val){
	int octal = int(val);
	
	printf("Your value in:\nDecimal: %lf\nOctal:%o\nHexadecimal:%A\n", val, octal, val);
}

void ConverterDecToHex(int val){
	string tmp("");
	char str[BUFF_SIZE];
	char* hex = new char[BUFF_SIZE];
	
	do
    {
        int hexSymbol(val % 16);
        
		if (hexSymbol > 9){
			hexSymbol += (int)('A') - 10;
		}
        else{
			hexSymbol += (int)'0';
		}
		
		tmp = (char)hexSymbol + tmp;
		strcpy(hex, ("0x" + tmp).c_str());
		
        val /= 16;
        
    }while(val);
    
    string out("Output by function - spritnf(): ");
	int sprntf = sprintf(str, "%s %s\n", out.c_str(), hex);
    printf("%s", str);
    
    printf("Output by function - puts(): ");
	puts(hex);
	
	delete[] hex;
}

struct RadioWaves{
	string name;
	string length;
	string Hz;
	double energy;
	string energyPrefix;
};

void writeDataInTable(int countOfStringsInTable, RadioWaves waves[], RadioWaves* wavesPtr){
	wavesPtr = new RadioWaves[countOfStringsInTable + 11];
		
	for(int i = 11; i < 11 + countOfStringsInTable; i++){
		printf("Name: ");
		cin >> wavesPtr[i].name;
		waves[i].name = wavesPtr[i].name;
		printf("Length: ");
		cin >> wavesPtr[i].length;
		waves[i].length = wavesPtr[i].length;
		waves[i].length +=  " mm";
		printf("Hz: ");
		cin >> wavesPtr[i].Hz;
		waves[i].Hz = wavesPtr[i].Hz;
		waves[i].Hz += " GHz";
		printf("Energy (in eV): ");
		scanf("%lf", &wavesPtr[i].energy);
		waves[i].energy = wavesPtr[i].energy;
		printf("Prefix of energy: ");
		cin >> wavesPtr[i].energyPrefix;
		waves[i].energyPrefix = wavesPtr[i].energyPrefix;
	}
	
	delete[] wavesPtr;
}

void showTable(int countOfStringsInTable, RadioWaves waves[]){
	printf("*====================*\n");
	
	printf("----------------------------------------\n");
	for(int i = 0; i < 11 + countOfStringsInTable; i++){	
		cout << "| " << waves[i].name << " | " << waves[i].length << " | " <<
			waves[i].Hz << " | " << waves[i].energy << " | " << waves[i].energyPrefix << " |"
			<< endl;
		printf("----------------------------------------\n");
	}
	
	printf("*====================*\n");
}

#include "func.h"

int main(){
	double val = 0;
	int octal_val = 0, ch, buff_size = 256;
	
	choose:
	ch = 0;
	printf("Choose task: ");
	scanf("%d", &ch);
	
	if(ch == 1){
		printf("Task 1:\n");
		printf("==== ==== ==== ==== ====\n");
	
		printf("Enter a value in decimal: ");
		scanf("%lf", &val);
		ShowValue(val);
	
		printf("Enter a value in octal: ");
		scanf("%o", &octal_val);
		ShowValue(octal_val);
	
		printf("Enter a value in hexadecimal: ");
		scanf("%lf", &val);
		ShowValue(val);
	
		printf("==== ==== ==== ==== ====\n");
		scanf("%d", &ch);
		system("clear");
		goto choose;
	}
	else if(ch == 2){
		int width = 0, accuracy = 0;
		printf("Task 2:\n");
		printf("==== ==== ==== ==== ====\n");
	
		float float_val = 0;
		printf("Enter a value: ");
		scanf("%f", &float_val);
		printf("Your value in %%f: %f\nIn %%g: %g\nIn %%e: %e\n", float_val, float_val, float_val);
		
		printf("Enter width of your value: ");
		scanf("%d", &width);
		printf("Enter accuracy of your value: ");
		scanf("%d", &accuracy);
		
		printf("Your value with \"%d\" width and \"%d\" accuracy:\n", width, accuracy);
		printf("In %%f: %*.*f\nIn %%g: %*.*g\nIn %%e: %*.*e\n", 
			accuracy, width, float_val, accuracy, width, float_val, accuracy, width, float_val);
		
		printf("==== ==== ==== ==== ====\n");
		scanf("%d", &ch);
		system("clear");
		goto choose;
	}
	else if(ch == 3){	
		printf("Task 3:\n");
		printf("==== ==== ==== ==== ====\n");
		
		int length, i = 0;
		
		char *char_ptr = new char[buff_size];
		
		printf("Enter your string: ");
		scanf("%s", char_ptr);
		
		printf("Do you want align your text? Left(0) Right(1): ");
		scanf("%d", &ch);
		if(ch == 0){
			printf("Specify how much the field size should be: ");
			scanf("%d", &length);
			printf("Your string: %.*s\n\n", length, char_ptr);
		}
		else if(ch == 1){
			printf("Specify how much the field size should be: ");
			scanf("%d", &length);
			printf("Your string: \t\t%*.*s\n\n", length, length, char_ptr);
		}
		else throw "Error!";

		delete char_ptr;
		
		printf("*** LIMITED ARRAY BY USER ***\n\n");
		printf("Enter a length of your string: ");
		scanf("%d", &length);
		
		printf("Enter your string: ");

		char myString[buff_size];	
		myString[length] = '\0';
		
		while(i != length){
			scanf(" %c", &myString[i]);
			
			i++;
		}
		
		printf("Your string: %s\n\n", myString);
		
		printf("*** UNLIMITED ARRAY ***\n\n");
		char myStr[buff_size];	
		myStr[buff_size] = '\0';
		
		printf("Enter your string: ");
		
		while(i != buff_size){
			scanf(" %c", &myString[i]);
			
			if(i >= buff_size || i <= buff_size - 10)
				buff_size *= 2;
			
			i++;
		}
		
		printf("Your string: %s\n", myString);
		
		printf("==== ==== ==== ==== ====\n");
		scanf("%d", &ch);
		system("clear");
		goto choose;
	}
	else if(ch == 4){	
		printf("Task 4:\n");
		printf("==== ==== ==== ==== ====\n");
		
		int dec = 0;
		printf("Enter decimal you want convert to hexadecimal: ");
		scanf("%d", &dec);
		
		ConverterDecToHex(dec);
		
		printf("==== ==== ==== ==== ====\n");
		scanf("%d", &ch);
		system("clear");
		goto choose;
	}
	else if(ch == 5){	
		printf("Task 5:\n");
		printf("==== ==== ==== ==== ====\n");
		
		FILE *input;
		char* sentence = (char*)calloc(BUFF_SIZE, sizeof(char));
		char str[BUFF_SIZE];

		printf("Enter string: ");
		scanf("%s", sentence);
		
		printf("Your sentence in sscanf(): \n");
		sscanf(sentence, "%s", str);
		printf("%s\n", str);
		
		ofstream out;
		out.open("filename.dat");
		if(out.is_open()){
			out << str << endl;
			printf("/*You have successfully write data in file!*/\n");
		}
		
		input = fopen64("filename.dat", "r");
		if(input != nullptr){
			if(fgets(str, BUFF_SIZE, input) == NULL)
				printf("fgets() error!\n");
			else
				printf("%s\n", str);
			fclose(input);
		}
		
		printf("==== ==== ==== ==== ====\n");
		
		free(sentence);
		
		scanf("%d", &ch);
		system("clear");
		goto choose;
	}
	else if(ch == 6){	
		printf("Task 6:\n");
		printf("==== ==== ==== ==== ====\n");
		
		RadioWaves waves[BUFF_SIZE] = {
			{ "ELF", "10  Mm", "30   Hz", 12.4, " feV" },
			{ "SLF", "1   Mm", "300  Hz", 1.24, " peV" },
			{ "ULF", "100 km", "3000 Hz", 12.4, " peV" },
			{ "VLF", "10  km", "30   kHz", 124, " peV" },
			{ "LF ", "1   km", "300  kHz", 1.24, "neV" },
			{ "MF ", "100 m", " 3000 kHz", 12.4, "neV" },
			{ "HF ", "10  m", " 30   MHz", 124, " neV" },
			{ "VHF", "1   m", " 300  MHz", 1.24, "mkeV" },
			{ "UHF", "100 mm", "3000 MHz", 12.4, "mkeV" },
			{ "SHF", "10  mm", "30   GHz", 124, " mkeV" },
			{ "EHF", "1   mm", "300  GHz", 1.24, "meV" }
		};
		
		printf("How much strings would you like to add? ");
		scanf("%d", &ch);
		
		RadioWaves* wavesPtr = new RadioWaves[ch];
		
		writeDataInTable(ch, waves, wavesPtr);
		showTable(ch, waves);

		delete[] wavesPtr;
		
		printf("==== ==== ==== ==== ====\n");
		scanf("%d", &ch);
		system("clear");
		goto choose;
	}
	else if(ch == 7){	
		printf("Task 7:\n");
		printf("==== ==== ==== ==== ====\n");
		
		char buff[] = "3254.363rfas";
		char *str;
		
		str = const_cast<char*>("-3213.24E-9");
		printf("1. atof() is working with string [%s]\nResult in float: %lf\n", str, atof(str));
		
		str = const_cast<char*>("234.735452fgq5426");
		printf("2. atof() is working with string [%s]\nResult in float: %lf\n", str, atof(str));
		
		str = const_cast<char*>("123512 something");
		printf("3. atoi() is working with string [%s]\nResult in integer: %d\n", str, atoi(str));
		
		str = const_cast<char*>("91373 null");
		printf("4. atol() is working with string [%s]\nResult in long integer: %ld\n\n", str, atol(str));
		
		int _buffSize = sizeof(buff)/sizeof(char);
		char _emptyBuff[_buffSize];
		sscanf(buff, "%s", _emptyBuff);
		
		printf("1. Test function atof() with sscanf(): \n[%s] = %lf\n", buff, atof(buff));
		printf("2. Test function atoi() with sscanf(): \n[%s] = %d\n", buff, atoi(buff));
		printf("3. Test function atol() with sscanf(): \n[%s] = %ld\n\n", buff, atol(buff));
		
		FILE *fin;
		ofstream out;
		
		out.open("vars.dat");
		
		printf("Enter something that you want to transform with functions atof(), atoi(), atol(): ");
		str = new char[BUFF_SIZE];
		cin >> str;
		
		if(out.is_open()){
			out << str << endl;
			printf("/*You have successfully write data in file!*/\n");
		}
		
		fin = fopen64("vars.dat", "r");
		if(fin != nullptr){
			if(fgets(buff, _buffSize, fin) == nullptr)
				printf("fgets() error!\n");
			else{
				printf("1. atof() in file is working with string [%s]\nResult in long integer: %lf\n", 
					str, atof(str));
				printf("2. atoi() in file is working with string [%s]\nResult in long integer: %d\n", 
					str, atoi(str));
				printf("3. atol() in file is working with string [%s]\nResult in long integer: %ld\n\n", 
					str, atol(str));

			}
			fclose(fin);
		}
		
		delete[] str;
		
		printf("==== ==== ==== ==== ====\n");
		scanf("%d", &ch);
		system("clear");
		goto choose;
	}
	else if(ch == 99)
		exit(EXIT_SUCCESS);
	else throw "Number of task is invalid!";
	
	return EXIT_SUCCESS;
}

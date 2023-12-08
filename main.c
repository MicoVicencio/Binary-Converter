#include <stdio.h>
#include <string.h>
#include <math.h>
//LOG IN FUNCTION PANG VALIDATE IF TAMA ANG USER AND PASS
int Login(char username[], char password[]) {
    char validUsername[] = "user";
    char validPassword[] = "admin";

    return (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0);
}
//MAIN FUNCTION
int main() {
    char username[20];
    char password[20];
    int loginAttempts = 0;
    int maxAttempts = 3;
    do {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if(Login(username, password)) {
            system("cls");
            printf("Login successful!\n");
            break;
        }else {
            printf("Invalid username or password. Please try again.\n");
            loginAttempts++;
            if (loginAttempts >= maxAttempts) {
                printf("Maximum login attempts reached. Exiting...\n");
                return 0;
            }
        }
    } while (1);
    mainmenu();
    return 0;
}
//PANG PRINT NG BORDER
void printBorder() {
    printf("*****************************************\n");
}

//FUNCTION PARA MACONVERT BINARY TO DECIMAL
int binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;
    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}
//FUNCTION PARA MAG INPUT NG BINARY THEN ICACALL YUNG ISANG FUNCTION PARA MAG COMPUTE
int Binary_DecimalCalculator() {
    long long binaryNumber;

    // Input binary number
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);

    // Call the function to convert binary to decimal
    int decimalNumber = binaryToDecimal(binaryNumber);//RE USED FUNCTION

    // Output the result
    printf("Decimal equivalent: %d\n", decimalNumber);

    return 0;
}

// Function to convert decimal to octal
void decimalToOctal(int decimal) {
    int octalNumber[100];
    int i = 0;

    // Convert decimal to octal
    while (decimal != 0) {
        octalNumber[i] = decimal % 8;
        decimal /= 8;
        i++;
    }

    // Print the octal number in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octalNumber[j]);
    }
    printf("\n");
}
//BINARY TO OCTAL CALCULATOR
int Binary_OctalCalculator() {
    long long binaryNumber;
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);
    //REUSE OF BINARY TO DECIMAL FUNCTION
    int decimalNumber = binaryToDecimal(binaryNumber);
    printf("Octal equivalent:");
    decimalToOctal(decimalNumber);//RE USED FUNCTION

    return 0;
}


// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hexadecimal[20]; // Assuming a maximum length of 20 for the hexadecimal string
    int index = 0;

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = '0' + remainder;
        } else {
            hexadecimal[index++] = 'A' + (remainder - 10);
        }
        decimal /= 16;
    }

    // Print the hexadecimal number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

//FUNCTION PARA MAG INPUT NG BINARY
int Binary_HexaDecimalCalculator() {
    long long binaryNumber;
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);
    //CALL BINARY TO DECIMAL SABAY COMPUTE DECIMAL TO HEXA
    int decimalNumber = binaryToDecimal(binaryNumber);
    printf("HexaDecimal Equivalent:");
    decimalToHexadecimal(decimalNumber);//RE USED FUNCTION

    return 0;
}

// MAIN MENU LIST PARA SA MGA CHOICES NG INPUT
void mainmenu(){
    int choice;
    do {
    printBorder();
    printf("* Binary Converter  - Choose your Input *\n");
    printBorder();
    printf("* 1. Binary                             *\n");
    printf("* 2. Decimal                            *\n");
    printf("* 3. Octal                              *\n");
    printf("* 4. HexaDecimal                        *\n");
    printf("* 5. Exit                               *\n");
    printBorder();


        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou selected Option 1.\n");
                BinaryMenu();
                break;
            case 2:
                printf("\nYou selected Option 2.\n");
                DecimalMenu();
                break;
            case 3:
                printf("\nYou selected Option 3.\n");
                OctalMenu();
                break;
            case 4:
                printf("\nYou selected Option 4.\n");
                HexaDecimalMenu();
                break;
            case 5:
                printf("\nYou selected Option 5.");
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
        }

        // Add a newline for better formatting
        printf("\n");

    } while (choice != 5);

    return 0;

}
//FUNCTION NG BINARY MENU
int BinaryMenu() {
    int choice;

    do {
    printBorder();
    printf("*    Binary Converter                   *\n");
    printBorder();
    printf("* 1. Binary to Decimal                  *\n");
    printf("* 2. Binary to Octal                    *\n");
    printf("* 3. Binary to HexaDecimal              *\n");
    printf("* 4. Go back to Main Menu               *\n");
    printBorder();

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou selected Option 1.\n");
                Binary_DecimalCalculator();
                break;
            case 2:
                printf("\nYou selected Option 2.\n");
                Binary_OctalCalculator();
                break;
            case 3:
                printf("\nYou selected Option 3.\n");
                Binary_HexaDecimalCalculator();
                break;
            case 4:

                printf("\nYou selected Option 4.\n");
                printf("Returning to Main Menu\n");
                mainmenu();
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }

        // Add a newline for better formatting
        printf("\n");

    } while (choice != 4);

    return 0;
}

// DECIMAL SECTION
int DecimalMenu() {
    int choice;

    do {
    printBorder();
    printf("*    Decimal Converter                  *\n");
    printBorder();
    printf("* 1. Decimal To Binary                  *\n");
    printf("* 2. Decimal To Octal                   *\n");
    printf("* 3. Decimal to HexaDecimal             *\n");
    printf("* 4. Go back to Main Menu               *\n");
    printBorder();

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou selected Option 1.\n");
                Decimal_Binary();
                break;
            case 2:
                printf("\nYou selected Option 2.\n");
                Decimal_Octal();
                break;
            case 3:
                printf("\nYou selected Option 3.\n");
                Decimal_Hexadecimal();
                break;
            case 4:
                printf("\nYou selected Option 4.\n");
                printf("Returning to Main Menu\n");
                mainmenu();
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }

        // Add a newline for better formatting
        printf("\n");

    } while (choice != 4);

    return 0;
}
//FUNCTION TO CONVERT DECIMAL TO BINARY
int Decimal_BinaryCalcu(int decimalNumber){
    int binaryNumber[32];

    // Variable to keep track of the binary array index
    int index = 0;

    // Convert decimal to binary by repeatedly dividing by 2
    while (decimalNumber > 0) {
        binaryNumber[index] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        index++;
    }

    // Print binary number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryNumber[i]);
    }
    printf("\n");
}
//DECIMAL TO BINARY FUNCTION
int Decimal_Binary() {
    int decimalNumber;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Call the function to convert and print binary representation
    printf("Binary Equivalent: ");
    Decimal_BinaryCalcu(decimalNumber);
}
// DECIMAL TO OCTAL FUNCTION
int Decimal_Octal(){
    int decimalNumber;
    printf("Enter Decimal Number: ");
    scanf("%d", &decimalNumber);
    printf("Octal Equivalent: ");
    decimalToOctal(decimalNumber);
    printf("\n");
}
//DECIMAL TO HEXA FUNCTION
int Decimal_Hexadecimal(){
    int decimalNumber;
    printf("Enter Decimal Number: ");
    scanf("%d", &decimalNumber);
    printf("HexaDecimal Equivalent: ");
    decimalToHexadecimal(decimalNumber);
    printf("\n");
}
//OCTAL SECTION
int OctalMenu() {
    int choice;

    do {
    printBorder();
    printf("*    Octal  Converter                   *\n");
    printBorder();
    printf("* 1. Octal  To Binary                   *\n");
    printf("* 2. Octal To Decimal                   *\n");
    printf("* 3. Octal To HexaDecimal               *\n");
    printf("* 4. Go back to Main Menu               *\n");
    printBorder();

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou selected Option 1.\n");
                Octal_Binary();
                break;
            case 2:
                printf("\nYou selected Option 2.\n");
                Octal_Decimal();

                break;
            case 3:
                printf("\nYou selected Option 3.\n");
                Octal_Hexadecimal();

                break;
            case 4:

                printf("\nYou selected Option 4.\n");
                printf("Returning to Main Menu\n");
                mainmenu();
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }

        // Add a newline for better formatting
        printf("\n");

    } while (choice != 4);

    return 0;
}
//OCTAL TO DECIMAL FUNCTITON
int octalToDecimal(int octalNumber) {
     int decimalNumber = 0;
    int base = 1;

    while (octalNumber > 0) {
        int lastDigit = octalNumber % 10;
        decimalNumber += lastDigit * base;
        base *= 8;
        octalNumber /= 10;
    }

    return decimalNumber;
}
//OCTAL TO DECIMAL FUNCTION INPUT
int Octal_Decimal() {
    int octalNumber;

    printf("Enter an octal number: ");
    scanf("%d", &octalNumber);

    int decimalNumber = octalToDecimal(octalNumber);//RE USED FUNCTION
    printf("Decimal equivalent: %d\n",decimalNumber);

    return 0;
}
//OCTAL TO BINARY FUNCTION
int Octal_Binary(){
    int octalNumber;

    // Input octal number
    printf("Enter an octal number: ");
    scanf("%d", &octalNumber);
    int decimalNumber = octalToDecimal(octalNumber);
    printf("Binary Equivalent:");
    Decimal_BinaryCalcu(decimalNumber);//RE USED FUNCTION
}
//OCTAL TO HEXA FUNCTION
int Octal_Hexadecimal(){
    int octalNumber;

    // Input octal number
    printf("Enter an octal number: ");
    scanf("%d", &octalNumber);
    int decimalNumber = octalToDecimal(octalNumber);
    printf("HexaDecimal Equivalent:");
    decimalToHexadecimal(decimalNumber);//RE USED FUNCTION
}

//HEXADECIMAL SECTION
int HexaDecimalMenu() {
    int choice;

    do {
    printBorder();
    printf("*    HexaDecimal Converter              *\n");
    printBorder();
    printf("* 1. HexaDecimal To Binary              *\n");
    printf("* 2. HexaDecimal To Decimal             *\n");
    printf("* 3. HexaDecimal To Octal               *\n");
    printf("* 4. Go back to Main Menu               *\n");
    printBorder();

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou selected Option 1.\n");
                Hexa_Binary();
                break;
            case 2:
                printf("\nYou selected Option 2.\n");
                Hexa_Decimal();
                break;
            case 3:
                printf("\nYou selected Option 3.\n");
                Hexa_Octal();
                break;
            case 4:

                printf("\nYou selected Option 4.\n");
                printf("Returning to Main Menu\n");
                mainmenu();
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }

        // Add a newline for better formatting
        printf("\n");

    } while (choice != 4);

    return 0;
}
//HEXA TO DECIMAL FUNCTION
int Hexadecimal_Decimal() {

    char hexNumber[20];


    printf("Enter a hexadecimal number: ");
    scanf("%s", hexNumber);

    // Convert hexadecimal to decimal
    long decimalNumber = 0;
    int i = 0;

    while (hexNumber[i] != '\0') {
        char currentChar = hexNumber[i];

        int decimalValue;
        if (currentChar >= '0' && currentChar <= '9') {
            decimalValue = currentChar - '0';
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            decimalValue = currentChar - 'A' + 10;
        } else if (currentChar >= 'a' && currentChar <= 'f') {
            decimalValue = currentChar - 'a' + 10;
        } else {
            // Invalid character in the hexadecimal string
            printf("Invalid hexadecimal number\n");
            return 1;  // Exit the program with an error code
        }

        decimalNumber = decimalNumber * 16 + decimalValue;
        i++;
    }

    // Print the result

    return decimalNumber;
}
//HEXA TO DECIMAL FUNCTION
void Hexa_Decimal(){
    int decimal = Hexadecimal_Decimal();//RE USED FUNCTION
    printf("Decimal Equivalent: %d\n", decimal);

}
//HEXA TO OCTAL FUNCTION
void Hexa_Octal(){
    int decimal = Hexadecimal_Decimal();
    printf("Octal Equivalent: ");
    decimalToOctal(decimal);//RE USED FUNCTION
    printf("\n");

}
//HEXA TO BINARY FUNCTION
void Hexa_Binary(){
    int decimalNumber = Hexadecimal_Decimal();
    printf("Binary Equivalent: ");
    Decimal_BinaryCalcu(decimalNumber); //RE USED FUNCTION
    printf("\n");

}
//RE USED FUNCTION

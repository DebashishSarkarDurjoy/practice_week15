#include <iostream>
using namespace std;


char *custom_strtok(char a_arr[], string delim_str) {
    static char *input = NULL;
    char delim = delim_str[0];

    if (a_arr != NULL) input = a_arr;
    if (input == NULL) return NULL;

    char *token = new char[strlen(input)+1];

    int i = 0;
    for (; input[i] != '\0'; i++) {
        if (input[i] != delim) {
            token[i] = input[i];
        }
        else {
            token[i] = '\0';
            input += i + 1;
            return token;
        }
    }

    input = NULL;
    token[i] = '\0';

    return token;
}



int main(void) {
    char arr[] = "My name is Debashish Sarkar Durjoy";

    char *c = custom_strtok(arr, " ");
    while (c != NULL) {
        cout << c << endl;
        c = custom_strtok(NULL, " ");
    }

    return 0;
}
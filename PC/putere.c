#include <stdlib.h>
#include <stdio.h>
//calculates the value of the number to the power given with the complexity of 2 * ln number
long int intToPower(int number, unsigned int power){
    //if(number == NULL) return;
    //if(power < 0 || power == NULL) return;
    if(number == 0) return 0;
    if(number == 1 || power == 0) return 1;
    
    int j = 0,oddPower[20] = {0};
    long int result = number;
    
    while(power > 1){
        if(power % 2){
            oddPower[j] = 1;
            power--;
        }
        j++;
        power/= 2;
    }
    j--;
    while(j >= 0){
        if(oddPower[j]){
            result = result * result * number;
        }else{
            result = result * result;
        }
        j--;
    }
    return result;
}
int main(){
    int number;
    unsigned int power;
    printf("Give a value for the number: ");
    scanf("%d", &number);
    printf("\nGive a value for the power : ");
    scanf("%u", &power);
    printf("%d to the power of %u is %ld", number, power, intToPower(number, power));


   return 0;
}
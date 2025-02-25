#include <stdio.h>

//funcrion for min initial health needed to win
int minStartingHealth(int power[], int n, int armor){
    int total_damage = 0;
    int max__damage = 0; 
    int armor_reduction = 0; 

    //calculate total damage and find max damage per round
    for(int i = 0; i < n; i++){
        total_damage += power[i];

        if(power[i] > max__damage){
            max__damage = power[i];
        }
    }

    //calculate armor reduction
    if(armor < max__damage){
        armor_reduction = armor;
    } else {
        armor_reduction = max__damage;
    }

    //compute min starting health requiered
    int min_health = total_damage - armor_reduction + 1;

    return min_health;

}

int main(){
    //input
    int power[] = {1, 2, 6, 7};
    int armor = 5;
    int n = sizeof(power)/ sizeof(power[0]);

    //calculate & print result
    int result = minStartingHealth(power, n, armor);
    printf("min starting health requiered is: %d\n", result);
    
    return 0;
}
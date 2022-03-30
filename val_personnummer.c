/**
 * @file val_personnummer.c
 * @author Emil Örberg (emil.orberg@live.se)
 * @brief
 * @version 0.1
 * @date 2022-03-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validate_personnummer(int *p_formated_personnummer)
{
    int control_digit = 0;
    int sum = 0;

    for (int number = 0; number < 9; number++)
    {
        if (number % 2 == 0)
        {
            int add_to_sum = (p_formated_personnummer[number]) * 2;
            sum += (add_to_sum < 10) ? add_to_sum : (add_to_sum - 9);
        }
        else
        {
            sum += p_formated_personnummer[number];
        }
    }
    return control_digit = (10 - (sum % 10)) % 10;
}

int format_personummer(char *personnummer, int *p_formated_personnummer)
{

    if (personnummer[6] != '-')
    {
        printf("D = 1\n");
        return 1;
    }

    int formated_index = 0;
    for (int number = 0; number < 11; number++)
    {
        if (isdigit(personnummer[number]) == 0)
        {
            if (number == 6)
            {
                continue;
            }
            return 1;
        }
        else
        {
            p_formated_personnummer[formated_index] = personnummer[number] - '0';
            formated_index++;
        }
    }
    return 0;
}

int main(void)
{
    char personummer[12];
    int valid_format = 1;
    int formated_personummer[9];
    int *p_formated_personnummer = formated_personummer;

    while (valid_format != 0)
    {
        printf("Please enter personummer in format YYMMDD-nnnC\n");
        scanf("%11s", personummer);
        if (strlen(personummer) == 11)
        {
            valid_format = format_personummer(personummer, p_formated_personnummer);
        }
    }

    if (validate_personnummer(p_formated_personnummer) == p_formated_personnummer[9])
    {
        printf("Personnummer is valid\n");
    }
    else
    {
        printf("Personnummer is not valid\n");
    }
}
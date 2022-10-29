#include "parser.h"

#include <stdio.h>

AT_COMMAND_DATA data ;

STATE_MACHINE_RETURN_VALUE at_command_parse(uint8_t current_character)
{
    //  STOP_OK = 18
    //  STOP_ERROR = 19

    static  int state = 0 ;
    if (data.ok == 1)
    {
        state = 0;
        data.ok = 0;
    }

//    uint8_t ch = current_character;
    printf("%c = %u\t->\t%d\n",current_character,current_character, state);
    switch (state)
    {

        case 0:
        {

            if (current_character == CR)  //  <CR>
            {
                
                state = 1;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 1:
        {


            if (current_character == LF)  //  <LF>
            {
                
                state = 2;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 2:
        {
            if (current_character == 'O')
            {
                
                state = 3;
            }
            else if (current_character == 'E')
            {
                
                state = 6;
            }
            else if (current_character == '+')
            {
                
                state = 12;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 3:
        {
            if (current_character == 'K')
            {
                
                state = 4;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 4:
        {
            if (current_character == CR)
            {
                
                state = 5;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 5:
        {
            if (current_character == LF)
            {

                state = 18;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 6:
        {
            if (current_character == 'R')
            {
                
                state = 7;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 7:
        {
            if (current_character == 'R')
            {
                
                state = 8;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 8:
        {
            if (current_character == 'O')
            {
                
                state = 9;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 9:
        {
            if (current_character == 'R')
            {
                
                state = 10;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 10:
        {
            if (current_character == CR)
            {
                
                state = 11;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 11:
        {
            if (current_character == LF)
            {
                
                state = 19;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 12:
        {
            if ((current_character >= 32)&&(current_character <= 122))
            {
                
                state = 13;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 13:
        {
            if ((current_character >= 32)&&(current_character <= 122))
            {
                
                state = 13;
            }
            else if (current_character == CR)
            {
                
                state = 14;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 14:
        {
            if (current_character == LF)
            {
                
                state = 15;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 15:
        {
            if (current_character == '+')
            {
                
                state = 12;
            }
            else if (current_character == CR)
            {
                
                state = 16;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 16:
        {
            if (current_character == LF)
            {
                
                state = 17;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 17:
        {
            if (current_character == 'O')
            {
                
                state = 3;
            }
            else if (current_character == 'E')
            {
                
                state = 6;
            }
            else
            {
                return STATE_MACHINE_READY_WITH_ERROR;
            }
            break;
        }
        case 18:
        {
            printf("return ok!\n");
            return STATE_MACHINE_READY_OK;
            //break;
        }
        case 19:
        {
            printf("return err!\n");
            return STATE_MACHINE_READY_WITH_ERROR;
            //break;
        }
        default:
        {
            return STATE_MACHINE_READY_WITH_ERROR;
        }

    }
    return STATE_MACHINE_NOT_READY;
}


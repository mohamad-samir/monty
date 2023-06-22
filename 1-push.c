#include "monty.h"

/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    /*التحقق مما إذا كان هناك وسيطة تم تمريرها إلى الدالة*/
    if (bus.arg)
    {
        /*التحقق مما إذا كانت الوسيطة رقمًا سالبًا*/
        if (bus.arg[0] == '-')
            j++;

        /*التحقق مما إذا كانت الوسيطة رقمًا صحيحًا*/
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > 57 || bus.arg[j] < 48)
                flag = 1;
        }

        /*إذا كانت الوسيطة غير صالحة، فإنه يتم إخراج رسالة خطأ وإنهاء البرنامج*/
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /*إذا لم يتم تمرير وسيطة، يتم إخراج رسالة خطأ وإنهاء البرنامج*/
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /*تحويل الوسيطة إلى رقم صحيح وحفظه في المتغير n*/
    n = atoi(bus.arg);

    /*إذا كانت lifi تساوي صفر، يتم إضافة العنصر إلى الستاك (addnode)
    وإلا، يتم إضافة العنصر إلى قائمة الانتظار (addqueue)*/
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

#include <stdio.h>
#include <stdlib.h>

double  calculate(double, char, double);
void    usage();

double
calculate(double first_num, char operator, double second_num)
{
        switch (operator) {
                case '+': return first_num + second_num;
                case '-': return first_num - second_num;
                case '*': /* FALLTHROUGH */
                case 'x': return first_num * second_num;
                case '%': return (int)first_num % (int)second_num;

                case '/': return second_num == 0 ? 0 : first_num / second_num;
                default:  usage();
        }
        return 0;
}

void
usage()
{
        fprintf(stderr, "usage: calc <first_num> [+ - * or x %% /] <second_num>\n");
        exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
        if (argc < 2 || argc % 2 != 0)
                usage();
        
        if (argc < 4) {
                printf("%d\n", atoi(argv[1]));
                return EXIT_SUCCESS;
        }
        
        double result = calculate(atof(argv[1]), *argv[2], atof(argv[3]));
        if (result == (int)result)
                printf("%.0f\n", result);
        else
                printf("%.2f\n", result);

        return EXIT_SUCCESS;
}


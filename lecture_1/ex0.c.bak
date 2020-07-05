#include "math.h"
#include <stdio.h>
#include <stdlib.h>

/************Original Solution************/
/* Needs more checking
 * Edge case: input not integer, use char** variation instead of char* argv[]
 * Remember to use clang to compile code
 */
/*int main(int argc, char* argv[]) {

        int counter;
        double sum_pi;
        if (argv[1] == NULL || atoi(argv[1]) < 0) {
                perror("Error: Incorrect input");
                exit(EXIT_FAILURE);
        }


        sum_pi = 3.0; //0th term
        counter = 1;
        while (counter <= atoi(argv[1])) {
                sum_pi = sum_pi + pow(-1, counter + 1) * (4.0 / ((2.0 * counter)
* (2.0 * counter + 1) * (2.0 * counter + 2))); counter++;

        }
        printf("Our estimate of Pi is %.20lf\n", sum_pi);
        return EXIT_SUCCESS;

}*/

/*****************Improved solution******************/
/* Note:
 * scanf: read from standard input
 * sscanf: read from charater string
 */
int main(int argc, char **argv) {
  __int64_t num;          // signed input argument
  __uint64_t checked_num; // unsigned input argument is more desirable

  double sum_pi = 3.0; // 0th term for the pi estimation

  // Check if user pass exactly one argument
  if (argc != 2) {
    perror("You have passed more than one argument. Try again");
    exit(EXIT_FAILURE);
  }

  // check if input argument is integer
  if (sscanf(argv[1], "%lld", (long long *)&num) != 1) {
    perror("Input argument is not intetger. Try again");
    exit(EXIT_FAILURE);
  }

  // check if the input argument is greater than zero
  if (num < 0) {
    perror("Input argument is less than 0, Try again");
    exit(EXIT_FAILURE);
  }

  double counter;
  checked_num = (__uint64_t)num;
  counter = 1;
  while (counter <= checked_num) {
    sum_pi = sum_pi + pow(-1, counter + 1) *
                          (4.0 / ((2.0 * counter) * (2.0 * counter + 1) *
                                  (2.0 * counter + 2)));
    counter++;
  }

  printf("Our estimate of Pi is %.20lf\n", sum_pi);
  return EXIT_SUCCESS;
}

#include <stdio.h>

int main() {

int x[0];

if(&x[1] - &x[0])
printf("Down\n");
else
printf("Up\n");

return 0;

}

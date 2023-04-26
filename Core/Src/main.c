#include "adc.h"

int v;
int main()
{
	pa1_adc_init();

	start_converstion();
while(1)
{

	v=adc_read();
}


}

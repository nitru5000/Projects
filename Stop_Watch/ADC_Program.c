#include "ADC_Interface.h"

void ADC_VoidInit(void)
{

/************   prescaler        ****************************/
	ADCSRA &= ADC_PRE_MASK;
	ADCSRA |= ADC_PRESCALER;
/************ Voltage refrence ****************************/
#if          ADC_Vref  ==    AREF
	         CLR_BIT(ADMUX,REFS0);
	         CLR_BIT(ADMUX,REFS1);

#elif        ADC_Vref  ==    AVCC
	         CLR_BIT(ADMUX,REFS1);
	         SET_BIT(ADMUX,REFS0);

#elif        ADC_Vref  ==    INTERNAL_2_56
	         SET_BIT(ADMUX,REFS0);
	         SET_BIT(ADMUX,REFS1);
#endif

/************ ADC MODE ****************************/
#if          ADC_MODE ==  ADC_SINGLE_CONVERSION
	         CLR_BIT(ADCSRA,ADATE);

#elif        ADC_MODE ==  ADC_AUTO_TRIGGER
	         SIT_BIT(ADCSRA,ADATE);
	         ADCSRA &= ADC_MODE_MASK ;
	         ADCSRA |= ADC_AUTO_TRIGGER_SOURCE;
#endif
/************ ADC Enable ****************************/
	         SET_BIT(ADCSRA,ADEN);
}

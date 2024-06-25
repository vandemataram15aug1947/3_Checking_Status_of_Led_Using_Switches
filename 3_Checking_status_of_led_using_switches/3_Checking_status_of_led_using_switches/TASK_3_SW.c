
 /////////////////////////////////////////    TASK-3  ///////////////////////////////////////////////////

 Monitor two switches such that
 1. when switch1 is pressed then LED1 should turn OFF if LED1 is already OFF then it should ignore it
 2. when switch2 is pressed then LED2 should turn ON if LED2 is already ON then it should ignore it
 */
#include "F28x_Project.h"

//////  Vande  /////////////////////

#define LED1 GpioDataRegs.GPBDAT.bit.GPIO34
#define LED2 GpioDataRegs.GPADAT.bit.GPIO31
#define SWITCH1 GpioDataRegs.GPCDAT.bit.GPIO67
#define SWITCH2 GpioDataRegs.GPADAT.bit.GPIO22
#define SWITCH3 GpioDataRegs.GPADAT.bit.GPIO7

/////// Vande ////////////////////////
void main(){
    //Initialization of System Control
    InitSysCtrl();
    //Initialization of General Purpose Input Output Pins
    InitGpio();

    ////////// Vande ////////////////

    EALLOW;
    //Configure GPIO67 and  GPIO22 as an Input
    GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO67 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO22 = 0;
    //Configure GPIO34 and  GPIO31 as an Output
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    EDIS;
    while(1){

        //////////////// Vande ////////////////

        // if LED1 is on
        if(SWITCH1==1 & LED1==1){
            // LED1 should turn off
            LED1=0;
        }
        // if LED2 is off
        if(SWITCH2==1 & LED2==0){
            // LED2 should turn on
            LED2=1;
        }
    }

}

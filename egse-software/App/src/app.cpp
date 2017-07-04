/*
 * app.cpp
 *
 * Created: 2016-04-05 03:22:11
 *  Author: Piotr Kuligowski
 *  Changes: Pawe³ Korba (P.K.) 2017.07.03
 */ 

#include "app.h"
String_t String;
Buffer_t Buffer;
Frame_t Frame;
uint8_t received_bytes;
Commands_t Commands;
Hk_t HK;
Dac_t DAC;
uint16_t* dac_values;
Switches_t Switches;

#define set(a, b) (a) |= (1 << (b))
#define reset(a, b) (a) &= ~(1 << (b))

void init(void){
	Serial0.begin(250000);
	DDRB = 0xFF;
	set(PORTB, 7);
	_delay_ms(200);
	reset(PORTB, 7);
}

void begin(void){
	
	init();

	while(1) {
		reset(PORTB, 7);
		
		received_bytes = Frame.readFrame(Buffer.get());
		
		if (Frame.headerIsValid(Buffer.get())){
			set(PORTB, 7);
			if(Frame.receivedCommand(Buffer.get(), received_bytes, Commands.COMMAND_GET_ADC)){
				_delay_ms(50);
				HK.printHK();
			} else if(Frame.receivedCommand(Buffer.get(), received_bytes, Commands.COMMAND_GET_VERSION)){
				Serial0.printf(Commands.REPLY_GET_VERSION_0);
				Serial0.printf(Commands.REPLY_GET_VERSION_1);
				Serial0.printf(Commands.REPLY_GET_VERSION_2);
				Serial0.printf(Commands.REPLY_GET_VERSION_3);
			} else if(Frame.receivedCommand(Buffer.get(), received_bytes, Commands.COMMAND_ENABLE_SW)){ 
				if ((Switches.loadParameter(Buffer.get())>=0)&&(Switches.loadParameter(Buffer.get())<=10)){
					Serial0.printf(Commands.COMMAND_ENABLE_SW);
					Frame.printCommandDataSeparator();
					Serial0.printf("%i", Switches.loadParameter(Buffer.get()));
					Frame.printTerminator();
					Switches.enableOneSwitch(Switches.loadParameter(Buffer.get()));
				} else if(Switches.loadParameter(Buffer.get())>10)	
					Frame.printFrame(Commands.REPLY_ERROR_PARAM_OUT_OF_RANGE);
				else
					Frame.printFrame(Commands.REPLY_ERROR_INWALID_PARAMS);
			} else if(Frame.receivedCommand(Buffer.get(), received_bytes, Commands.COMMAND_DISABLE_SW)){
				if ((Switches.loadParameter(Buffer.get())>=0)&&(Switches.loadParameter(Buffer.get())<=10)){
					Serial0.printf(Commands.COMMAND_DISABLE_SW);
					Frame.printCommandDataSeparator();
					Serial0.printf("%i", Switches.loadParameter(Buffer.get()));
					Frame.printTerminator();
					Switches.disableOneSwitch(Switches.loadParameter(Buffer.get()));
				} else if(Switches.loadParameter(Buffer.get())>10)
				Frame.printFrame(Commands.REPLY_ERROR_PARAM_OUT_OF_RANGE);
				else
				Frame.printFrame(Commands.REPLY_ERROR_INWALID_PARAMS);
			//P.K. 2017.07.03 start
			} else if(Frame.receivedCommand(Buffer.get(), received_bytes, Commands.COMMAND_SET_MUX)){ 
				if ((Switches.loadParameter(Buffer.get())>=0)&&(Switches.loadParameter(Buffer.get())<=63)){
					Serial0.printf(Commands.COMMAND_SET_MUX);
					Frame.printCommandDataSeparator();
					Serial0.printf("%i", Switches.loadParameter(Buffer.get()));
					Frame.printTerminator();
					HK.SetMux(Switches.loadParameter(Buffer.get()));
				} else if(Switches.loadParameter(Buffer.get())>63)
				Frame.printFrame(Commands.REPLY_ERROR_PARAM_OUT_OF_RANGE);
				else
				Frame.printFrame(Commands.REPLY_ERROR_INWALID_PARAMS);	
			} else if(Frame.receivedCommand(Buffer.get(), received_bytes, Commands.COMMAND_GET_VALUE)){
			    if ((Switches.loadParameter(Buffer.get())>=0)&&(Switches.loadParameter(Buffer.get())<=7)){
				    Serial0.printf(Commands.COMMAND_GET_VALUE);
				    Frame.printCommandDataSeparator();
				    Serial0.printf("%i", Switches.loadParameter(Buffer.get()));
					Frame.printParamSeparator();
				    HK.GetValue(Switches.loadParameter(Buffer.get()));	
					Frame.printTerminator();
			} else if(Switches.loadParameter(Buffer.get())>7)
			Frame.printFrame(Commands.REPLY_ERROR_PARAM_OUT_OF_RANGE);
			else
			Frame.printFrame(Commands.REPLY_ERROR_INWALID_PARAMS);								
		    //P.K. 2017.07.03 end									
			} else 
				Frame.printFrame(Commands.REPLY_ERROR_UNDEFINED_COMMAND);
				
			Buffer.clear();
		}
		else
			Frame.printFrame(Commands.REPLY_ERROR_FRAME);
	}
}
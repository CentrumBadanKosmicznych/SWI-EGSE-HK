import serial
import time
import string

class JuiceSwiFrame(object):
    def HEADER(self):
        return b'{#@}'
        
    def TERMINATOR(self):
        return b'\n'
        
    def SEPARATOR(self):
        return b' '

class JuiceSwiCommands(object):
    def GET_ADC(self):
        return b'GetADC'
    
    def GET_VERSION(self):
        return b'GetVersion'
        
    def ENABLE_SW_ALL(self):
        return b'EnableSW'

class JuiceSwiCommunication(object): 
    def __init__(self):
        self.frame = JuiceSwiFrame()
        
    def DEFAULT_BAUDRATE(self):
        return 250000

    def connect(self, port):
        self.ser = serial.Serial(port, self.DEFAULT_BAUDRATE())

    def disconnect(self):
        self.ser.close()
    
    def send_command(self, command):
        self.ser.write(self.frame.HEADER()+command+self.frame.TERMINATOR())
        
    def received_bytes(self):
        return self.ser.in_waiting
        
    def get_received_bytes(self):
        return self.ser.read(self.received_bytes())
            
class JuiceSwiHK(object):
    def names(self):
        channel_names = []
        
        for i in range(0, 128):
            if (i+1)%4:
                channel_names.append(b'')
            else:
                channel_names.append(b'REF')
         
        channel_names[2] = b'temp 0'; channel_names[1] = b'P1V2_V'; channel_names[0] = b'USO_P12V0_C'  
        channel_names[6] = b'temp 1'; channel_names[5] = b'P1V8_V'; channel_names[4] = b'MOT_P12V0_C'      
        channel_names[10] = b'temp 2'; channel_names[9] = b'P2V5_V'; channel_names[8] = b'SYNT_P6V0_C'      
        channel_names[14] = b'temp 3'; channel_names[13] = b'P3V3_V'; channel_names[12] = b'HNF_P3V3_C'      
        channel_names[18] = b'temp 4';channel_names[17] = b'P6V0_V';channel_names[16] = b'LLR_MAIN_C'      
        channel_names[22] = b'temp 5';channel_names[21] = b'USO_P12V0_V';channel_names[20] = b'LLR_RED_C'     
        channel_names[26] = b'temp 6';channel_names[25] = b'CTS_P12V0_V';channel_names[24] = b'Rez'    
        channel_names[30] = b'temp 7';channel_names[29] = b'P15V0_V';channel_names[28] = b'Rez'   
        channel_names[34] = b'temp 8';channel_names[33] = b'DPU_P1V8_V';channel_names[32] = b'ACS_P2V5_C'
        channel_names[38] = b'temp 9';channel_names[37] = b'DPU_P2V5_V';channel_names[36] = b'ACS_P1V8_C'
        channel_names[42] = b'temp 10';channel_names[41] = b'DPU_P3V3_V';channel_names[40] = b'ACS_P6V0_C'
        channel_names[46] = b'temp 11';channel_names[45] = b'N6V0_V';channel_names[44] = b'Rez'
        channel_names[50] = b'temp 12';channel_names[49] = b'CTS_N6V0_V'
        channel_names[54] = b'temp 13'
        channel_names[58] = b'temp 14'
        channel_names[62] = b'temp 15'
        channel_names[66] = b'temp 16'
        channel_names[70] = b'temp 17'
        channel_names[74] = b'temp 18'
        channel_names[78] = b'temp 19'
        channel_names[82] = b'temp 20'
        channel_names[86] = b'temp 21'
        channel_names[90] = b'temp 22'
        channel_names[94] = b'temp 23'
        channel_names[98] = b'temp 24'
        channel_names[102] = b'temp 25'
        channel_names[106] = b'temp 26'
        channel_names[110] = b'temp 27'
        channel_names[114] = b'temp 28'
        channel_names[118] = b'temp 29'
        channel_names[122] = b'temp 30'
        channel_names[126] = b'temp 31'
        
        return channel_names
     
    def quant(self, reference_measured_by_adc):
        reference_factor = 2.499/((3.3/4096)*reference_measured_by_adc)
        return (3.3/4096.0)*reference_factor
    
    def factors(self, hk_values):
        channel_factors = []
        
        for i in range(0, 128):
            if (i+1)%4:
                channel_factors.append(1)
            else:
                channel_factors.append(1)

        channel_factors[1] = 1.1*self.quant(int(hk_values[3])); channel_factors[0] = 0.8119
        channel_factors[5] = 1.1*self.quant(int(hk_values[7])); channel_factors[4] = 0.8119     
        channel_factors[9] = 1.1*self.quant(int(hk_values[11])); channel_factors[8] = 0.8119     
        channel_factors[13] = 2.0*self.quant(int(hk_values[15])); channel_factors[12] = 0.8119     
        channel_factors[17] = 2.5*self.quant(int(hk_values[19])); channel_factors[16] = 0      
        channel_factors[21] = 5.5454*self.quant(int(hk_values[23])); channel_factors[20] = 0    
        channel_factors[25] = 4.1915*self.quant(int(hk_values[27])); channel_factors[24] = 0    
        channel_factors[29] = 5.5454*self.quant(int(hk_values[31])); channel_factors[28] = 0  
        channel_factors[33] = 1.1*self.quant(int(hk_values[35])); channel_factors[32] = 0.8119
        channel_factors[37] = 1.1*self.quant(int(hk_values[39])); channel_factors[36] = 0.8119
        channel_factors[41] = 2.0*self.quant(int(hk_values[43])); channel_factors[40] = 0.8119
        channel_factors[45] = -3.30*self.quant(int(hk_values[47])); channel_factors[44] = 0
        channel_factors[49] = -3.30*self.quant(int(hk_values[51]))
        
        channel_factors[58] = 1000.0/int(hk_values[62])
        
        return channel_factors
    
class JuiceSwiEGSE(object):
    def __init__(self, port):
        self.commands = JuiceSwiCommands()
        self.communication = JuiceSwiCommunication()
        self.hk = JuiceSwiHK()
        
        self.communication.connect(port)
        
    def getHK(self):
        self.communication.send_command(self.commands.GET_ADC())
        time.sleep(1)
        
        received = self.communication.get_received_bytes()
        received = received.replace(b'CheckSum\n', b'')
        received = received.replace(b'{#@}GetADC ', b'')
        
        received_list = received.split(b',')
        
        return received_list
        
    def getEGSEVersion(self):
        self.communication.send_command(self.commands.GET_VERSION())
        
    def enableSwitchAll(self):
        self.communication.send_command(self.commands.ENABLE_SW_ALL())
    
    def getHKnames(self):
        return self.hk.names()
    
    def getHKfactors(self, hk_values):
        return self.hk.factors(hk_values)
        
    def close(self):
        self.communication.disconnect()
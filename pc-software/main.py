import msvcrt as m
import egse.swi as swi
import numpy as np
import os

def insertTabulators(text):
    if len(text)>8:
        return "\t"
    else:
        return "\t\t"



#print(dpu.getHK())
#dpu.enableSwitchAll()

dpu = swi.JuiceSwiEGSE("COM11")

while 1:
    
    
    hk_values = dpu.getHK()
    hk_names = dpu.getHKnames()
    hk_factors = dpu.getHKfactors(hk_values)

    hk_table = []

    for i in range(0, (len(hk_values)-1)):
        hk_table.append([hk_names[i], hk_values[i], hk_factors[i]*int(hk_values[i])])

    #for i in range(0, (len(hk_values)-1)):
    for i in range(0, 53):
        # print(hk_table[i][0] + insertTabulators(hk_table[i][0]) + str(np.around(hk_table[i][2],decimals=2)))
        if ((i+1)%4)==2:
        #if ((i+1)%4)==1:
            print(hk_table[i][0] + insertTabulators(hk_table[i][0]) + str(np.around(hk_table[i][2],decimals=2)))

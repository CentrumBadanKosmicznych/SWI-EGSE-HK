import msvcrt as m
import egse.swi as swi
import numpy as np
import os
import lab.utilities.control as ctrl

keyboard = ctrl.KeyGetterWindows()

def insertTabulators(text):
    if len(text)>8:
        return "\t"
    else:
        return "\t\t"



#print(dpu.getHK())
#dpu.enableSwitchAll()

dpu = swi.JuiceSwiEGSE("COM3")
sw = swi.SWITCH()

while 1:
    hk_values = dpu.getHK()
    hk_names = dpu.getHKnames()
    hk_factors = dpu.getHKfactors(hk_values)

    hk_table = []

    print("")
    print("-------------------------------------------------------------")
    print("                       SWI HK EGSE")
    print("-------------------------------------------------------------")
    
    for i in range(0, (len(hk_values)-1)):
        hk_table.append([hk_names[i], hk_values[i], hk_factors[i]*int(hk_values[i])])

    #for i in range(0, (len(hk_values)-1)):
    for i in range(0, 53):
        # print(hk_table[i][0] + insertTabulators(hk_table[i][0]) + str(np.around(hk_table[i][2],decimals=2)))
        if ((i+1)%4)==0:
        #if ((i+1)%4)==1:
            print(hk_table[i+2][0] + insertTabulators(hk_table[i+2][0]) + str(np.around(hk_table[i+2][2],decimals=2))+"\t| "+
            hk_table[i+1][0] + insertTabulators(hk_table[i+1][0]) + str(np.around(hk_table[i+1][2],decimals=2))+"\t| ")

    print("-------------------------------------------------------------")    
    print("-> ON/OFF: REF(Q/q), CTS1(W/w), CTS2(E/e), IF_COMB(R/r)")
    print("-> ON/OFF: ACS1(T/t), ACS2(Y/y), CCH(U/u), MOT(I/i)")
    print("-> ON/OFF: HNF(O/o), AT_RED(P/p), CT_RED(A/a)")
    print("-> All ON/OFF (Z/z)")
    print("-------------------------------------------------------------")    

    key_pressed = keyboard.getch(False)
    if len(key_pressed)==1:
        if key_pressed=="Q":
            dpu.enableSwitch(sw.REF)
        elif key_pressed=="q":
            dpu.disableSwitch(sw.REF)
            
        elif key_pressed=="W":
            dpu.enableSwitch(sw.CTS1)
        elif key_pressed=="w":
            dpu.disableSwitch(sw.CTS1)
        elif key_pressed=="E":
            dpu.enableSwitch(sw.CTS2)
        elif key_pressed=="e":
            dpu.disableSwitch(sw.CTS2)
        elif key_pressed=="R":
            dpu.enableSwitch(sw.IF_COMB)
        elif key_pressed=="r":
            dpu.disableSwitch(sw.IF_COMB)
        elif key_pressed=="T":
            dpu.enableSwitch(sw.ACS1)
        elif key_pressed=="t":
            dpu.disableSwitch(sw.ACS1)
        elif key_pressed=="Y":
            dpu.enableSwitch(sw.ACS2)
        elif key_pressed=="y":
            dpu.disableSwitch(sw.ACS2)
        elif key_pressed=="U":
            dpu.enableSwitch(sw.CCH)
        elif key_pressed=="u":
            dpu.disableSwitch(sw.CCH)
        elif key_pressed=="I":
            dpu.enableSwitch(sw.MOT)
        elif key_pressed=="i":
            dpu.disableSwitch(sw.MOT)
        elif key_pressed=="O":
            dpu.enableSwitch(sw.HNF)
        elif key_pressed=="o":
            dpu.disableSwitch(sw.HNF)
        elif key_pressed=="P":
            dpu.enableSwitch(sw.AT_RED)
        elif key_pressed=="p":
            dpu.disableSwitch(sw.AT_RED)
        elif key_pressed=="A":
            dpu.enableSwitch(sw.CT_RED)
        elif key_pressed=="a":
            dpu.disableSwitch(sw.CT_RED)
        elif key_pressed=="Z":
            dpu.enableSwitch(sw.REF)
            dpu.enableSwitch(sw.CTS1)
            dpu.enableSwitch(sw.CTS2)
            dpu.enableSwitch(sw.IF_COMB)
            dpu.enableSwitch(sw.ACS1)
            dpu.enableSwitch(sw.ACS2)
            dpu.enableSwitch(sw.CCH)
            dpu.enableSwitch(sw.MOT)
            dpu.enableSwitch(sw.HNF)
            dpu.enableSwitch(sw.AT_RED)
            dpu.enableSwitch(sw.CT_RED)
        elif key_pressed=="z":
            dpu.disableSwitch(sw.REF)
            dpu.disableSwitch(sw.CTS1)
            dpu.disableSwitch(sw.CTS2)
            dpu.disableSwitch(sw.IF_COMB)
            dpu.disableSwitch(sw.ACS1)
            dpu.disableSwitch(sw.ACS2)
            dpu.disableSwitch(sw.CCH)
            dpu.disableSwitch(sw.MOT)
            dpu.disableSwitch(sw.HNF)
            dpu.disableSwitch(sw.AT_RED)
            dpu.disableSwitch(sw.CT_RED)

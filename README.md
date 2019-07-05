# o2simulator_arduino_is300
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

DISCLAIMER: Strictly for off-road use only. I am not responsible for any damages, fines, or any other sort of harm that happens to you by using this code. You know what you're doing.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


Secondary oxygen sensor simulator for Lexus IS300 (1st Gen). When using catless headers the ecu would throw a check engine light and P0420 & P0430 codes Catalyst System below Efficiency. This is due to the fact that the secondary oxygen sensors are now measuring the same voltage as the primary oxygen sensor (not to be confused with wide-band oxygen sensors, those work differently) and hence determine that the catalytic converters are not doing their job (or you dont have them). Now because the ecu is pretty lazy in detecting the change we can get away by simulating a signal which is random in nature so that it never gets to know that its simulated.

Secondary oxygen sensors for is300 output 0.0v to 0.7v every ~3.3 seconds when the car is off, and 0.0v to 0.9v when the car is running. I still have to add the functionality when the arduino detects the engine is running. Node that this does not get rid of the o2 sensors completely since the heater circuit is still needed so you will have to leave the heater circuit wires as they are and only feed the simulated signal. Before you hook everything up, be sure to measure voltage with a multimeter that voltage is within range and flipping ~3.3 seconds. Also you will need to measure the amps to be 10mA or less or youre in danger of frying up the ecu. All that being said you can modify the code to your liking. I am not going to tell you which wires to tap into, you can find the rest of the info online. Thank you. 

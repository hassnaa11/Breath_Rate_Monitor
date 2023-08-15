# Breath Rate Monitor

<p>
Abnormal breathing syndromes are disorders that occur in the breathing system which may be fatal if not diagnosed correctly. The disorders we are detecting here are bradypnea and tachypnea.<br>

</p>

### How it works:
We used the main idea of the ultrasonic sensor which is how it sends and receives a sound wave to detect the distance between the sensor and the target needed. 
So here we made our target (the patient’s chest) to detect it going forward and back to detect the breathing abnormalities if existed. <br>

We also measured the inhalation time and exhalation time to detect if the ratio between them is normal or not. <br>
After that we detected the respiratory rate by which we detected whether the person’s breathing rate is normal or they have bradypnea or tachypnea.<br>
 We measured it by the following equation: <br>
 
             breathRate=peaksNum/(inTime+exTime) <br>  
             
where peaksNum is the number of times the patient inhaled,
inTime is inhalation time and exTime is exhalation time in minutes.


### components:
- Arduino Uno
- Ultrasonic sensor Module HC-SR04

## Implementation

![image](https://user-images.githubusercontent.com/111397736/260558502-f584830d-e1ef-48d0-9df2-9a049e35599b.PNG)

## Contributors
- [Ayat Tarek](https://github.com/Ayat-Tarek)
- [Biatriss Boshra](https://github.com/)
- [Shiamaa Kamel](https://github.com/)
- [Hassnaa Hossam](https://github.com/hassnaa11)

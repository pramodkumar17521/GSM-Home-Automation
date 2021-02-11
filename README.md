# GSM-Home-Automation
***Home automation using GSM Module***

***I had developed this project in March 2019 for ECDC Competition of Techkriti (An annual techfest of IIT Kanpur)***

***I have not used any GSM Library, I had controlled GSM directly through AT COMMANDS***

I used SIM900 GSM module for communication through mobile, 16X4 LCD MODULE for display, DHT11 module  for temprature and humidity,
RTC module for real time and date.

This projects have four 220V bulbs which swithced on of off using relay switches.
LCD dispalys current date and time with the status of for home appliances (Bulbs ON/OFF status).

******************HOW TO OPERATE******************
- First set your mobile no. through which you want to control home appliances because it is necessary for security.
-  Send "@Light1 on#" or "Light1 off#" for ON/OFF the light no.1  to the GSM.
- Send "@Light2 on#" or "Light2 off#" for ON/OFF the light no.2  to the GSM.
-  Send "@Fan1 on#" or "Fan1 off#" for ON/OFF the fan no.1  to the GSM.
- Send "@Fan3 on#" or "Fan2 off#" for ON/OFF the fan no.2  to the GSM.
- Send "@All on#" or "@All off#" for ON/OFF all the appliances to the GSM.
- Send "@temp#" for receiving temprature and humidity information on your phone through SMS.

- Time Dispaly by RTC clock is in IST time.
- Temprature displays in Celcius.
- Appliances current status represnted by L -> OFF and H -> ON

- This projects uses *Two way communication* through GSM, when you sends instruction for lights switch ON/OFF
it ON/OFF the respective lights and sends back a sms to you about lights status.


- I strictly focused on *security and privacy* so that only owner of house can controls the appliances through his mobile no.
if other persons tried to do with their mobiles then system neglects their commands and doesn't performs any action.



****************************END****************************

Problem 5 : Crop Management.
A smart agricultural drone monitors a large farm to manage irrigation efficiently. The drone first checks the type of crop being monitored whether it's wheat, corn, or rice. For wheat, if the soil moisture is below 30%, and if it has not rained in the last 24 hours, the system will initiate irrigation. For corn, if the soil moisture is below 40% , the system will irrigate regardless of recent rainfall. For rice, if the soil moisture is below 25% , the system will irrigate unless it has rained in the last 24 hours. If the soil moisture is above these thresholds, no irrigation is applied. Design a solution to determine if irrigation should be initiated based on the crop type, soil moisture level, and rainfall status.

IPO CHART:

input: 
croptype

process:
check croptype,check soil moisture,tell whether to initiate irrigation

output: 
irrigation

PSEUDOCODE:
1. input croptype
2. IF croptype = "corn" AND soil_moisture < 40%
3. print "initiate irrigation"
4. ELSE print "no irrigation is applied"
5. IF croptype = "wheat" AND soil_moisture < 30% AND rain_in_last_24_hrs = "no"
6. print "initiate irrigation"
7. ELSE print "no irrigation is applied"
8. IF croptype = "rice" AND soil_moisture < 25% AND rain_in_last_24_hrs = "no"
9. print "initiate irrigation"
10. ELSE print "no irrigation is applied" 
 

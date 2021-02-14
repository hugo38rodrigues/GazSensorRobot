int capteurAV=6;
pinMode(capteurAV, INPUT);
int capteurAR=7;
pinMode(capteurAR, INPUT);
int capteurG=8;
pinMode(capteurG, INPUT);
int capteurD=9;
pinMode(capteurD, INPUT);

{
  if (digitalRead(capteurAV)==HIGH)
    return (reculer)
    delay
  else if (digitalRead(capteurAR)==HIGH)
    return (avancer)
  else if (digitalRead(capteurG)==HIGH)
    return (reculer)
  else if (digitalRead(capteurD)==HIGH)
    return (reculer)
  else
    return(avancer)
}

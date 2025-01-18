void webPage()
{
  server.send(200,"text/html", webpageCode);
}

void SERVOtlacidlo()
{
  myservo.attach(servoPin);
  Serial.print(hodnota+" ");
  if (hodnota %  2) {
    digitalWrite(2, !digitalRead(2));    
    server.send(200,"text/html", webpageCode);
    myservo.write(posOpen);
  } else {
    digitalWrite(2, !digitalRead(2)); 
    server.send(200,"text/html", webpageCodeB);
    myservo.write(posClosed);
  }

  hodnota= hodnota+1;
  delay(500);
}

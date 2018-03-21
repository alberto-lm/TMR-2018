bool giro(int lower, int upper){
  sensors_event_t event; 
  bno.getEvent(&event);
  rotacion = event.orientation.x;
  return (rotacion > lower && rotacion < upper);
}

void alnbno(int lower, int upper){
  giro(lower, upper);
  int temp = rotacion < 180 ? 8 : 9;
  while(giro(lower, upper)){
    avanzar(temp);
  }
  avanzar(-1);
  delay(10);
}

void alineacion_bno(int lower, int upper){
  if(!giro(lower, upper))
    return;
  alnbno(lower, upper);  
}
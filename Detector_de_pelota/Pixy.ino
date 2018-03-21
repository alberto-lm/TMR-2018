void scanPixy(){
  
  int signature;
  int area_temp;

  
  blocks = pixy.getBlocks();
  
  viendo_Pelota = contador_pelota < 500;
  viendo_porteria = contador_porteria < 300;
  viendo_izquierda = contador_izquierda < 500;
  viendo_derecha = contador_derecha < 500;
//  
  if(contador_pelota < 550)
      contador_pelota++; 
      
  if(contador_porteria < 550)
    contador_porteria++;
    
  if(contador_izquierda < 550)
    contador_izquierda++; 
    
  if(contador_derecha < 550)
    contador_derecha++;

 
  
  if(blocks){

    for (int h = 0; h < blocks; h++){
      
      signature = pixy.blocks[h].signature;
      area_temp = pixy.blocks[h].height * pixy.blocks[h].width;
      
      //Naranja Pelota
      if(signature == 2){

          contador_pelota = 0;
          x_pelota = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo (de 0 a 319)
          y_pelota = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo (de 0 a 199)
        

        //tengo_Pelota = ((x_pelota >= 140 && x_pelota <= 200) && (y_pelota >= 180 ) && (pixy.blocks[h].height <= 35) && (pixy.blocks[h].width <= 85));           
  
      }
      
      //Porteria
      else if(signature == signature_porteria){
        
        if(area_temp > 25){
            contador_porteria = 0;
            x_porteria = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla(de 0 a 319)
            y_porteria = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla (de 0 a 199)
            alineado = x_porteria >= 50 && x_porteria <= 270;
          }
          
      }
      
      //Izquierda
      else if(signature == signature_izquierda){

          if(area_temp > 25){
            contador_izquierda = 0;
            izquierda_height = pixy.blocks[h].height;
          }

      }
      
      //Derecha
      else if(signature == signature_derecha){
        
       if(area_temp > 25){
          contador_derecha = 0;
          derecha_height = pixy.blocks[h].height;
        }
      }
    }  
  }  
}




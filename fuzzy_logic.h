void fuzzySuhu(int sensorSuhu){
  //suhu dingin
  if(sensorSuhu <23){
    suhu[0] = 1;
  }else if(sensorSuhu >= 23 && sensorSuhu<=27){
    suhu[0] = (27-sensorSuhu)/(27-23);
  }else{
    suhu[0} = 0;
  }

  //suhu sedang
  if(sensorSuhu <23){
    suhu[1] = 0;
  }else if(sensorSuhu >= 23 && sensorSuhu<=27){
    suhu[1] = (sensorSuhu-27)/(27-23);
  }else if(sensorSuhu >= 27 && sensorSuhu<=32){
    suhu[1] = (32-sensorSuhu)/(32-27);
  }else{
    suhu[1} = 0;
  }

  //suhu panas
  if(sensorSuhu <27){
    suhu[2] = 0;
  }else if(sensorSuhu >= 27 && sensorSuhu<=32){
    suhu[2] = (32-sensorSuhu)/(32-27);
  }else{
    suhu[2} = 1;
  }
}

void fuzzyKadarAir(int sensorKadarAir){
  //basah
  if(sensorKadarAir <23){
    kadarAir[0] = 1;
  }else if(sensorKadarAir >= 23 && sensorKadarAir<=27){
    kadarAir[0] = (27-sensorKadarAir)/(27-23);
  }else{
    kadarAir[0} = 0;
  }

  //sedang
  if(sensorKadarAir <23){
    kadarAir[1] = 0;
  }else if(sensorKadarAir >= 23 && sensorKadarAir<=27){
    kadarAir[1] = (sensorKadarAir-27)/(27-23);
  }else if(sensorKadarAir >= 27 && sensorKadarAir<=32){
    kadarAir[1] = (32-sensorKadarAir)/(32-27);
  }else{
    kadarAir[1} = 0;
  }

  //kering
  if(sensorKadarAir <27){
    kadarAir[2] = 0;
  }else if(sensorKadarAir >= 27 && sensorKadarAir<=32){
    kadarAir[2] = (32-sensorKadarAir)/(32-27);
  }else{
    kadarAir[2} = 1;
  }
}

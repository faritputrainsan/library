
void drawCentreString(const char *buf, int x, int y)
{
    int16_t x1, y1;
    uint16_t w=DWidth, h=DHeight;
    virtualDisp.getTextBounds(buf, x, y, &x1, &y1, &w, &h); //calc width of new string
    virtualDisp.setCursor(x - w / 2, y);
    virtualDisp.print(buf);
}

void drawAzzan(int DrawAdd)
  {
// check RunSelector
    if(!dwDo(DrawAdd)) return;
    uint8_t           ct_limit =18;  //harus angka genap
    static uint8_t    ct;
    static uint32_t   lsRn;
    uint32_t          Tmr = millis();

    if((Tmr-lsRn) > 500 and ct <= ct_limit)
      {
       lsRn = Tmr;
        DoSwap = true; 
        ct++;
      }
       
    if((ct%2) == 0)
          {
       fType(4);
      //matrix.drawRect(0,0,64,16,matrix.color333(7,0,7));
       virtualDisp.setCursor(10,11);
       virtualDisp.setTextColor(virtualDisp.color333(7,7,7),virtualDisp.color333(0,0,0));
//     virtualDisp.print("ADZAN");
       drawCentreString("ADZAN",14,11);
    if(jumat) {
       fType(1);
//              virtualDisp.setCursor(10,26);
                virtualDisp.setTextColor(virtualDisp.color333(0,7,0),virtualDisp.color333(0,0,0));
//              virtualDisp.print(sholatN(8));
                drawCentreString(sholatN(8),14,27);
              }else{
       fType(4);
//              virtualDisp.setCursor(10,26);
                virtualDisp.setTextColor(virtualDisp.color333(7,0,0),virtualDisp.color333(0,0,0));
//              virtualDisp.print(sholatN(SholatNow));
                drawCentreString(sholatN(SholatNow),10,27);             
              }
            Buzzer(1);
            
          } else {
         Buzzer(0);
         }
    if ((Tmr-lsRn)>2000 and (ct > ct_limit))
      {dwDone(DrawAdd);
       ct = 0;
       Buzzer(0);
       } 
  }


void drawIqomah(int DrawAdd)  // Countdown Iqomah (9 menit)
  {  
    // check RunSelector
    if(!dwDo(DrawAdd)) return;

    static uint32_t   lsRn;
    uint32_t          Tmr = millis();
    static int        ct;
    int               mnt, scd,cn_l ;
    char              locBuff[6];           
    
    cn_l  = (Iqomah[SholatNow]*60);

    if((Tmr-lsRn) > 1000 and ct <=cn_l)
      {
          lsRn = Tmr;        
          
                 
          if (ct> (cn_l-10)) Buzzer(1);   // Buzzer on 2 seccon before Iqomah
          ct++;
            
          
         // virtualDisp.drawLine(64,0,64,16,matrix.color333(0,7,0));
          //drawSmallTS(); 
          DoSwap = true;   
      }
          mnt = floor((cn_l-ct)/60); 
          scd = (cn_l-ct)%60;
          if(mnt>0) { virtualDisp.setCursor(15,27); sprintf(locBuff,"%02d:%02d",mnt,scd);} 
          else    { virtualDisp.setCursor(27,27); sprintf(locBuff,"%02d",scd);}          
          fType(4);
          warnaWaktu(4);
          virtualDisp.print(locBuff);  
     if ((ct%2)== 0){
              virtualDisp.setCursor(11,11);
              fType(4);
              virtualDisp.setTextColor(virtualDisp.color333(7,0,0));
              matrix.print("IQOMAH");
              } else {
              virtualDisp.setCursor(11,11);
                fType(4);
              virtualDisp.setTextColor(virtualDisp.color333(0,7,0));
              virtualDisp.print("IQOMAH");
                }
    if (ct > cn_l)
      {
       dwDone(DrawAdd);
       ct = 0;
       Buzzer(0);
      }    
  }


void drawSholat_S(int sNum,int c) // Box Sholah Time
  {
    char  BuffTime[10];
    char  BuffShol[7];
    float   stime   = sholatT[1];
    uint8_t shour   = floor(stime);
    uint8_t sminute = floor((stime-(float)shour)*60);
    uint8_t ssecond = floor((stime-(float)shour-(float)sminute/60)*3600);
    sprintf(BuffTime,"%02d:%02d",shour,sminute);
    virtualDisp.setCursor(44,10);//nama waktu shalat1
    fType(1);
    warnaWaktu(1);
    virtualDisp.print(sholatN(1));
    virtualDisp.setCursor(44,23);//waktu shalat 1
    fType(0);
    warnaWaktu(2);
    virtualDisp.print(BuffTime);
    drawLargeTS();
    DoSwap = true;        
  }

  ///

  ///


void drawSholat(int DrawAdd)
  { 
    if(!dwDo(DrawAdd)) return;
    static uint8_t    x;
    static uint8_t    s; // 0=in, 1=out
    static uint8_t    sNum; 
    static uint32_t   lsRn;
    uint32_t          Tmr = millis();
    uint8_t           c=30;
    uint8_t           first_sNum = 0; 
    int               DrawWd=DWidth - c; 
    String message;

    int    textX   = matrix.width(),
           textMin = sizeof(message) * -12,
           hue     = 0;
           textMin = message.length()* -12;
      if((Tmr-lsRn)<3000) 
      {
      
         drawSholat_S(sNum, c);
      }
      
      if((Tmr-lsRn)>2000) 
      {
        lsRn=Tmr;
        sNum++;
          } 
           if(sNum==8)   {sNum=0;}

    //virtualDisp.drawLine(35,8,64,8,matrix.color333(0,7,0));
//    virtualDisp.writeFillRect(32,0,DrawWd/2-x,35,matrix.color333(0,0,0));
//    virtualDisp.writeFillRect(32+DrawWd/2+x,0,64,20,matrix.color333(0,0,0));
  }

void drawSholat_S2(int sNum,int c) // Box Sholah Time
  {
    char  BuffTime[10];
    char  BuffShol[7];
    float   stime   = sholatT[4];
    uint8_t shour   = floor(stime);
    uint8_t sminute = floor((stime-(float)shour)*60);
    uint8_t ssecond = floor((stime-(float)shour-(float)sminute/60)*3600);
    sprintf(BuffTime,"%02d:%02d",shour,sminute);
    virtualDisp.setCursor(71,10);//posisi nama shlt
    fType(1);
    warnaWaktu(3);
    virtualDisp.print(sholatN(4));
    virtualDisp.setCursor(71,23);//posisi waktu shalat
    fType(0);
    warnaWaktu(4);
    virtualDisp.print(BuffTime);
   // drawLargeTS();
    DoSwap = true;        
  }


void drawSholat2(int DrawAdd)
  { 
    if(!dwDo(DrawAdd)) return;
    static uint8_t    x;
    static uint8_t    s; // 0=in, 1=out
    static uint8_t    sNum; 
    static uint32_t   lsRn;
    uint32_t          Tmr = millis();
    uint8_t           c=30;
    uint8_t           first_sNum = 0; 
    int               DrawWd=DWidth - c; 
    String message;

    int    textX   = matrix.width(),
           textMin = sizeof(message) * -12,
           hue     = 0;
           textMin = message.length()* -12;
      if((Tmr-lsRn)<3000) 
      {
      
         drawSholat_S2(sNum, c);
      }
      
      if((Tmr-lsRn)>2000) 
      {
        lsRn=Tmr;
        sNum++;
          } 
           if(sNum==8)   {sNum=0;}
  
  }

  ///
void drawSholat_S3(int sNum,int c) // Box Sholah Time
  {
    char  BuffTime[10];
    char  BuffShol[7];
    float   stime   = sholatT[sNum];
    uint8_t shour   = floor(stime);
    uint8_t sminute = floor((stime-(float)shour)*60);
    uint8_t ssecond = floor((stime-(float)shour-(float)sminute/60)*3600);
    sprintf(BuffTime,"%02d:%02d",shour,sminute);
    virtualDisp.setCursor(98,10);//posisi nama shlt
    fType(1);
    warnaWaktu(3);
    virtualDisp.print(sholatN(sNum));
    virtualDisp.setCursor(98,23);//posisi waktu shalat
    fType(0);
    warnaWaktu(4);
    virtualDisp.print(BuffTime);
   // drawLargeTS();
    DoSwap = true;        
  }


void drawSholat3(int DrawAdd)
  { 
    if(!dwDo(DrawAdd)) return;
    static uint8_t    x;
    static uint8_t    s; // 0=in, 1=out
    static uint8_t    sNum; 
    static uint32_t   lsRn;
    uint32_t          Tmr = millis();
    uint8_t           c=30;
    uint8_t           first_sNum = 5; 
    int               DrawWd=DWidth - c; 
    String message;

    int    textX   = matrix.width(),
           textMin = sizeof(message) * -12,
           hue     = 0;
           textMin = message.length()* -12;
      if((Tmr-lsRn)<3000) 
      {
      
         drawSholat_S3(sNum, c);
      }
      
      if((Tmr-lsRn)>2000) 
      {
        lsRn=Tmr;
        sNum++;
          } 
           if(sNum==8)   {sNum=5;}
  
  }
  //

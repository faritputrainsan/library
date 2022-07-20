void drawGreg_DS()   //tanggal
  {  
  fType(0);
  virtualDisp.setCursor(40, 27);
  warnaWaktu(1);
  if(now.day()<10) virtualDisp.print(0, DEC);
  virtualDisp.print(now.day(), DEC);
  virtualDisp.print('-');
  
  warnaWaktu(2);
  if(now.month()<10) virtualDisp.print(0, DEC);
  virtualDisp.print(now.month(), DEC);
  virtualDisp.print('-');
  
  warnaWaktu(3);
  if(now.year()<10) virtualDisp.print(0, DEC);
  virtualDisp.print(now.year(), DEC);
  
  DoSwap = true;
  }

void jamkecil(){
  static uint16_t   lsRn;
    uint16_t          Tmr = millis();

    fType(1);
    warnaWaktu(1);
    virtualDisp.setCursor(12, 11);
    if(now.hour()<10) virtualDisp.print(0, DEC);
    virtualDisp.print(now.hour(), DEC);
    virtualDisp.print(':');

    warnaWaktu(2);
    if(now.minute()<10) virtualDisp.print(0, DEC);
    virtualDisp.print(now.minute(), DEC);
    virtualDisp.print(':');

    warnaWaktu(3);
    virtualDisp.setTextColor(virtualDisp.color333(7,7,0));    
    if(now.second()<10) virtualDisp.print(0, DEC);
    virtualDisp.print(now.second(), DEC);
    
    DoSwap = true;
}

void warnaWaktu(int x){
  if(x==1){ //berdasarkan Jam
    if(now.hour()<12){virtualDisp.setTextColor (virtualDisp .color333 (0,7,0));} //Hijau
    if(now.hour()>12){virtualDisp.setTextColor (virtualDisp .color333 (0,128,21));} //Biru
  }
  if(x==2){ //berdasarkan Menit
    if(now.minute()<30){virtualDisp.setTextColor(virtualDisp.color333(7,0,7));} //Merah
    if(now.minute()>30) {virtualDisp.setTextColor (virtualDisp .color333 (0,7,0));} //Hijau
  }
   if(x==3){ //berdasarkan Jam
    if(now.hour()<12){virtualDisp.setTextColor (virtualDisp .color333 (0,128,21));} //Biru
    if(now.hour()>12){virtualDisp.setTextColor(virtualDisp.color333(7,0,7));} //Merah
  }
   if(x==4){ //berdasarkan Menit
    if(now.minute()<30){virtualDisp.setTextColor (virtualDisp .color333 (0,128,21));} //Biru
    if(now.minute()>30) {virtualDisp.setTextColor (virtualDisp .color333 (0,7,0));} //Hijau
  }

}

void drawSmallTS()  
  { 
    static uint16_t   lsRn;
    uint16_t          Tmr = millis();

    fType(0);
    warnaWaktu(2);
    virtualDisp.setCursor(0, 11);
    if(now.hour()<10) virtualDisp.print(0, DEC);
    virtualDisp.print(now.hour(), DEC);

    if (now.second() % 2 == 0) { //DOT
      warnaWaktu(1);
      virtualDisp.setCursor(0, 20);
      if(now.minute()<10) virtualDisp.print(0, DEC);
      virtualDisp.print(now.minute(), DEC);
    } else {
     virtualDisp.setTextColor(virtualDisp.color333(0,0,0));
      virtualDisp.setCursor(0, 20);
      if(now.minute()<10) virtualDisp.print(0, DEC);
      virtualDisp.print(now.minute(), DEC);
    }
    
    DoSwap = true;
  }  

void drawLargeTS()//jam besar
  { 
     static uint16_t   lsRn;
    uint16_t          Tmr = millis();

    fType(4);
    warnaWaktu(1);
    virtualDisp.setCursor(10, 15);
    if(now.hour()<10) virtualDisp.print(0, DEC);
    virtualDisp.print(now.hour(), DEC);
    fType(1);
    warnaWaktu(2);
    virtualDisp.setCursor(30, 11);
    if(now.minute()<10) virtualDisp.print(0, DEC);
    virtualDisp.print(now.minute(), DEC);
    fType(1);
    virtualDisp.setCursor(30, 19);  
    virtualDisp.setTextColor(virtualDisp.color333(7,7,0));    
    if(now.second()<10) virtualDisp.print(0, DEC);
    virtualDisp.print(now.second(), DEC);
    
   // virtualDisp.drawRect(40,6,2,2,virtualDisp.color333(7, 7, 7));
   //virtualDisp.drawRect(40,12,2,2,virtualDisp.color333(7, 7, 7));

    if (now.second() % 2 == 0) { //DOT
     virtualDisp.drawRect(26,9,2,2,virtualDisp.color333(7, 7, 7));
     virtualDisp.drawRect(26,15,2,2,virtualDisp.color333(7, 7, 7));
    } else {
     
}
  virtualDisp.drawRect(0,0, virtualDisp.width()-0, virtualDisp.height()-0, virtualDisp.color333(7, 7, 7));
  virtualDisp.drawRect(2,2, virtualDisp.width()-4, virtualDisp.height()-4, virtualDisp.color565(255,0,0));
    DoSwap = true;
    //matrix.drawCircle(32,32,0,0);
  }  
void blinkBlock(int DrawAdd)
  {
    // check RunSelector
    if(!dwDo(DrawAdd)) return;

    static uint32_t   lsRn;
    static uint16_t   ct, ct_l;
    int               mnt, scd;
    uint32_t          Tmr = millis();
    char              locBuff[6];

    if(jumat)       {ct_l = Prm.JM * 60;}
    else            {ct_l = Prm.SO * 60;}

     
    if((Tmr-lsRn)> 1000)
      {   lsRn=Tmr;
//          mnt = floor((ct_l-ct)/60); 
//          scd = (ct_l-ct)%60;
//          sprintf(locBuff,"%02d:%02d",mnt,scd);
//          //virtualDisp.drawRect(0,0,64,32,virtualDisp.color333(0,7,0));
//          virtualDisp.setCursor(1,21);
//          fType(2);
//          virtualDisp.setTextColor(virtualDisp.color333(0,7,7));
//          virtualDisp.print(locBuff);
        DoSwap = true; 
        ct++;
        }
         if((ct%2) == 0)
          { 
            
          }else{

          }
        
    if (ct> ct_l) 
      { dwDone(DrawAdd);
        azzan = false;
        jumat = false;
        ct = 0;
      }
  }

// =========================================
// Drawing Tools============================
// =========================================

boolean dwDo(int DrawAdd)
  { if (RunSel== DrawAdd) {return true;}
    else return false;}
  
void dwDone(int DrawAdd)
  { RunFinish = DrawAdd;
    RunSel = 0;}
/*   
void dwCtr(int x, int y,const char* Msg)
  { int   tw = virtualDisp.length(Msg);
   // int   th = virtualDisp.textHeight();
    int   c = int((DWidth-x-tw)/2);
    virtualDisp.drawFilledRect(x+c-1,y,x+tw+c,y,0);
    virtualDisp.print(x+c,y,Msg);
   }
*/

void Buzzer(uint8_t state)
  {
    if(state ==1 and Prm.BZ == 1)
      {digitalWrite(BUZZ, HIGH);}
    else 
      {digitalWrite(BUZZ, LOW);}
  }

void bz()
{
  static uint32_t   lsRn;
  static uint8_t    b;
  uint32_t          Tmr = millis();
  if (bzzz == 1) {
    lsRn = Tmr;
    bzzz = 0;
    b = 1;
  }
  if ((Tmr - lsRn) < 200)
  {
    //    lsRn = Tmr;
    Buzzer(1);
  } else {
    if (b == 1) {
      b = 0;
      Buzzer(0);
    }
  }
}

void dwMrq(const char* msg, int Speed, int dDT, int DrawAdd)
{
  // check RunSelector
  static uint16_t   x ;
  if (!dwDo(DrawAdd)) return;
  if (reset_x != 0) {
    x = 0;
    reset_x = 0;
  }


  static uint32_t   lsRn;
  String message = msg;
  int    textX   = matrix.width(),
         textMin = sizeof(message) * -12,
         hue     = 0;
  textMin = message.length() * -12;
  int fullScroll = message.length() + (2.5 * DWidth);
  if (dDT == 1)fullScroll = message.length() + (2.5 * DWidth) + 128;
  uint32_t          Tmr = millis();
  if ((Tmr - lsRn) > Speed)
  { lsRn = Tmr;
    if (x < fullScroll) {
      ++x;
    }
    else {
      dwDone(DrawAdd);
      x = 0; return;
    }
    //    matrix.fillScreen(0);

    DoSwap = true;

  }
  if (dDT == 1)
  {
    // virtualDisp.fillScreen(0);
    //drawLargeTS();
    fType(1);
    virtualDisp.setTextColor(virtualDisp.color333(7, 7, 7), virtualDisp.color333(0, 0, 0));
    virtualDisp.setCursor(DWidth - x, 27);
    virtualDisp.setTextWrap(false);
    virtualDisp.print( msg);
    drawSholat(DrawAdd);
    drawSholat2(DrawAdd);
    drawSholat3(DrawAdd);
    //drawGreg_DS();
  }

  if (dDT == 2)
  {
    fType(1);
    virtualDisp.setTextColor(virtualDisp.color333(7, 0, 0), virtualDisp.color333(0, 0, 0));
    virtualDisp.setCursor(DWidth - x, 27);
    virtualDisp.setTextWrap(false);
    virtualDisp.print( msg);
 
    drawSholat2(DrawAdd);
    drawSholat(DrawAdd);
    drawSholat3(DrawAdd);
    drawLargeTS();
    //drawSmallTS();
   // drawGreg_DS();
  }
}

void fType(int x)
  {
    if(x==0) virtualDisp.setFont (Font0);
    else if(x==1) virtualDisp.setFont(Font1); 
    else if(x==2) virtualDisp.setFont(Font2);
    else if(x==3) virtualDisp.setFont(Font3); 
    else if(x==4) virtualDisp.setFont(Font4);  
  }

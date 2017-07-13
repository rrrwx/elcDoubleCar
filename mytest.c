
	#if 0
	
	//  	X_zuo=X_zuo*(-0.003125*X_zuo+1.75);
//    X_you=X_you*(-0.003125*X_you+1.75);
//    Z_zuo=Z_zuo*(-0.003125*X_zuo+1.75);
//	Z_you=Z_you*(-0.003125*X_you+1.75);
//	
	
	
	
	
	
//	  Y_zuo=Y_zuo*(-0.003125*Y_zuo+1.75);
//	  Y_you=Y_you*(-0.003125*Y_you+1.75);
//	

//	
	
//if(X_zuo+X_you>250)
//{		X_zuo=X_zuo*1;
//    X_you=X_you*1;
//    Z_zuo=Z_zuo*1;
//	  Z_you=Z_you*1;}
//	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ÅÐ¶Ï×´Ì¬(((Y_you<66)||(Y_zuo<66))&&(ABS(X_zuo-100)<30)&&(ABS(X_you-100)<30)&&ABS(Z_zuo-Z_you)<48)
	//Ô²»·
  if((((X_zuo+X_you)>130&&(X_zuo+X_you)<180)
      /*&&((Z_zuo>50&&Z_zuo<150)&&(Z_you>50&&Z_you<150))*/
 &&ABS(X_you-X_zuo)<50)&&(yuanhuan==0)&&(S==0))
  {
   firsttime=1;
	 yuanhuan_num++;
		yuanhuan=1;  
//PDout(11)=1;   
    if(((you_value+Y_you)>(zuo_value+Y_zuo))||right_yuan==1) 
    right_yuan=1;///////////////////ÅäºÏ¶æ»ú£¬errÎªX_you-Y_you
    else 
    left_yuan=1;
		
		if(left_yuan==1)  {right_yuan=0;left_yuan=1;};
		if(right_yuan==1) left_yuan=0;
		
        extern int dir;
        
		if(yuanhuan_num==1) {right_yuan=!dir;left_yuan=dir;}
		if(yuanhuan_num==2) {right_yuan=!dir;left_yuan=dir;}
		if(yuanhuan_num==3) {right_yuan=!dir;left_yuan=dir;}
		if(yuanhuan_num==4) {right_yuan=!dir;left_yuan=dir;}
		enterTime1=sys_time_0_1s;
	}
	
    
    if((yuanhuan==1)&&((X_zuo+X_you)>200||ABS(X_zuo-X_you)>120))
		{yuanhuan=0; 
  //   PDout(11)=0; 
    left_yuan=0;
		right_yuan=0;
		firsttime=0;
		}

	
////	Ð¡SÍä
//	if((ABS(Z_zuo-Z_you)<100)&&(ABS(Y_zuo-Y_you)>100)&&(Z_zuo+Z_you)>)
//		{s=1;//PDout(11)=1;}
//	else			
//		{s=0;//PDout(11)=0;}

		
//Ê®×Ö
			
  if(((Y_zuo>90&&Y_you>90)&&ABS(X_zuo-X_you)<60)&&(Z_zuo>200||Z_you>200))
		{		
		 shizi=1; 
		}
	else shizi=0;  
		
		if(yuanhuan==1)
		{
speaker=1;
		}
		else
		{
speaker=0;
		}
		



///////////////////////////////¼ÆËãÆ«²î

//		sum_X=X_zuo+X_you;
    sum_total=zuo_value+you_value;
    
    differ_Y=ABS(Y_zuo-Y_you);//0.0646
    if(differ_Y<26) differ_Y=0;
		else differ_Y=differ_Y-26;
		
		differ_Z=ABS(Z_zuo-Z_you);//0.0646
    if(differ_Z<50) differ_Z=0;
		else differ_Z=differ_Z-50;
		if(shizi==1) differ_Z=0;
		
		compensate=250-sum_total;
		if(Shizi_flag==1)
		{compensate=250-sum_total; }///////////////±ÈÔÚÖ±µÀÊ±µÄÏÂÒ»¼ÓÏÂ¶þµÄÖµ´ó30£¬Ìá¸ßÁéÃôÐÔzuo1+you1=
    if(yuanhuan==1)
		{compensate=0-sum_total; }
		
		if(compensate<0) compensate=0;

		
		coefficient1=2.3; //////////////////////¸ø²¹³¥ÓÃ
    
		if(S==1)
		{coefficient1=2.3;}///////////////±ÈÔÚÖ±µÀÊ±µÄÏÂÒ»¼ÓÏÂ¶þµÄÖµ´ó30£¬compensate*0.03200Ìá¸ßÁéÃôÐÔ0.03 260  300
		if(Shizi_flag==1)
		{coefficient1=2.3;}
		
		
		coefficient2=0.0000;/////////////////¸øZÓÃ
		
		if(S==1)
		coefficient2=0.000;
		if(Shizi_flag==1)
		coefficient2=0.0000;
		
		
		//²¹³¥
    		
		if((you_value+Y_you)>(zuo_value+Y_zuo)) 
    differential=(you_value+compensate*coefficient1+coefficient2*differ_Z)-zuo_value;///////////////////ÅäºÏ¶æ»ú£¬errÎªX_you-Y_you
    else if ((you_value+Y_you)<(zuo_value+Y_zuo)) 
    differential=you_value-(compensate*coefficient1+zuo_value+coefficient2*differ_Z);
    else {differential=Record_differential[0];}
		      
		if(Shizi_flag==1&&Y_zuo>50&&Y_you>50)
		{if((you_value)>(zuo_value)) 
    differential=(you_value+compensate*coefficient1);///////////////////Ê®×ÖÀïÖ»ÓÃX¿´·½Ïò£¬²»ÐèÒªZ£»+coefficient2*differ_Z+coefficient2*differ_Z
    else if ((you_value)<(zuo_value)) 
    differential=you_value-(compensate*coefficient1);
    else {differential=Record_differential[0];}}
		
		if(yuanhuan==1)
		{if((Z_you)>(Z_zuo)) 
    differential=(Z_you+compensate*coefficient1)-Z_zuo;///////////////////Ê®×ÖÀïÖ»ÓÃX¿´·½Ïò£¬²»ÐèÒªZ£»+coefficient2*differ_Z+coefficient2*differ_Z
    else if ((Z_you)<(Z_zuo)) 
    differential=Z_you-(compensate*coefficient1+Z_zuo);
    else {differential=Record_differential[0];}}
		
		
		if(yuanhuan==1&&ABS(memory_yaw-ABS(yaw))>25)/////(ABS(X_zuo-70)<20&&ABS(X_you-70)<20&&(Y_zuo<20&&Y_you<20)
		{firsttime=0;}
		
//ÔÚ×îºóÃæÖ±½Ó¸ø½øÔ²»·µÄÕ¼¿Õ±È£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡(((Z_zuo>30&&Z_you<2)||(Z_you>30&&Z_zuo<2)))&&£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
		     
//		if(right_yuan==1&&firsttime==1)  differential=300;¡¢¡¢¡¢¡¢¡¢3¸öÌõ¼þ
//		if(left_yuan==1&&firsttime==1)   differential=-300;	(X_zuo>75&&Z_zuo>75&&X_you<50&&Z_you<50)||(X_you>75&&Z_you>75&&X_zuo<50&&Z_zuo<50)

//		if(sys_time_0_1s-enterTime1<2)((ABS(X_you-60)<10&&ABS(X_zuo-60)<10)&&ABS(Z_you-Z_zuo)>50)
//		{

//		}
	
	 
//·À´«µÀ
   if(Shizi_flag==1||S==1)
    if(ABS(differential-Record_differential[0])>400) 
   { 
   {
		 differential=Record_differential[0];
	 }
 }
	
//¸üÐÂÊý×é	
	for(int i=0;i<29;i++)
	{
		Record_differential[i+1]=Record_differential[i];
		Record_middle[i+1]=Record_middle[i];		
	}
	
	Record_differential[0]=differential;
	Record_middle[0]=X_zuo;   
	
	
	if(yuanhuan==1&&(Z_zuo+Z_you)<2&&firsttime==0)///////////////////////////////////////////////////////////////////////Ô²»·ABS(memory_yaw-yaw)>45
		{
					firsttime=0;
					if(right_yuan==1) differential=-600;
					if(left_yuan==1)  differential=600;	
		}

//	if(yuanhuan==1)
//	{
//		int a=140-(X_zuo+X_you);
//		if(a<0)
//		{
//			a=0;
//		}
//		if(X_zuo>X_you)
//		{
//			differential=a+X_zuo-X_you;
//		}
//		else
//		{
//			differential=a+X_zuo-X_you;
//		}
//	}

		
		change_rate=0.25*(ABS(Record_differential[0]+Record_differential[0]+Record_differential[1]+Record_differential[1])-
		            ABS(Record_differential[2]+Record_differential[3]+Record_differential[4]+Record_differential[5]));    
		
		
//KP	
  Servo_PD.Kp_right=ABS(differential)*0.00780*speed_rate+differ_Y*0.0000+differ_Z*0.000000+change_rate*0.000;//0.0013
  Servo_PD.Kp_left =ABS(differential)*0.00780*speed_rate+differ_Y*0.0000+differ_Z*0.000000+change_rate*0.000;//0.00690
//  if(s==1)
//	{
//		 Servo_PD.Kp_right=ABS(differential)*0.001;
//		Servo_PD.Kp_left =ABS(differential)*0.002;
//	}
	if(yuanhuan==1)///////////////////////////////Ô²»·´¦kpÒ»¶¨ÒªÐ¡
	{	Servo_PD.Kp_right=30.60;
		Servo_PD.Kp_left =30.60;	};//1.73
	
//	if(S==1&&yuanhuan==0)///////////////////////////////
//	{		Servo_PD.Kp_right=ABS(differential)*0.0100000+differ_Y*0.010+differ_Z*0.0075;//¼õÐ¡Æ«²îµÄK£¬Ôö´óZ µÄK 0.0085
//	    Servo_PD.Kp_left =ABS(differential)*0.0100000+differ_Y*0.010+differ_Z*0.0075;		}
	
	if(Shizi_flag==1)///////////////////////////////
	{		Servo_PD.Kp_right=ABS(differential)*0.00800000+differ_Y*0.000+Shizi_flag*0;//0.0048
	    Servo_PD.Kp_left =ABS(differential)*0.0080000+differ_Y*0.000+Shizi_flag*0;	}	
	//Servo_PD.Kp_left=1.05*Servo_PD.Kp_right;

//    Servo_PD.Kp_right=Servo_PD.Kp_right/speed_rate;
//    Servo_PD.Kp_left=Servo_PD.Kp_left/speed_rate;
        
        
    if(Servo_PD.Kp_right<0)  Servo_PD.Kp_right=0;
    if(Servo_PD.Kp_left<0)   Servo_PD.Kp_left=0;     
        
        
 //deer	
	Servo_PD.derr=0.1*(4*differential+4*Record_differential[1]+1*Record_differential[2]+1*Record_differential[3])
	                     -0.1*(Record_differential[3]+Record_differential[4]+Record_differential[5]+Record_differential[6]+Record_differential[7]+Record_differential[8]+Record_differential[9]+Record_differential[10]+Record_differential[11]+Record_differential[12]);

//Servo_PD.derr=0.125*(4*differential+3*Record_differential[1]+Record_differential[2])
//	                     -0.25*(Record_differential[3]+Record_differential[4]+Record_differential[5]+Record_differential[6]);
			///////////////////////Ç°·½ÏòÓÒ×ª£¬derr>0,ËùÒÔkdÕýºÃÊÇÕýÊý
	
//KD	
	Servo_PD.Kd=ABS(Servo_PD.derr)*15;//*speed_rate;//33.5//35Èç¹û¶¶¿ÉÄÜÊÇkdµÄÊÂ£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	
//	if(S==1)///////////////////////////////
//	{		Servo_PD.Kd=ABS(Servo_PD.derr)*25*speed_rate*speed_rate;}
//	if(Shizi_flag==1)///////////////////////////////
//	{		Servo_PD.Kd=ABS(Servo_PD.derr)*25*speed_rate*speed_rate;}
	

	
//err	
//	Servo_PD.err= Record_differential[0];//////////////////////0.4*Record_differential[0]+0.3*Record_differential[1]+0.3*Record_differential[2];
	Servo_PD.err=0.4*Record_differential[0]+0.3*Record_differential[1]+0.3*Record_differential[2];


//PDµ÷½Ú	
	if(differential>=0)//ÏòÓÒ×ª
	Servo_PD.PWM=Servo_PD.err*Servo_PD.Kp_right+Servo_PD.derr*Servo_PD.Kd;//(Servo_PD.xielv)  
	else//Ïò×ó×ª
	Servo_PD.PWM=Servo_PD.err*Servo_PD.Kp_left+Servo_PD.derr*Servo_PD.Kd;//(Servo_PD.xielv)  
	
	
	
	Servo_PD.err_last=Servo_PD.err;		
	if(Servo_PD.PWM>775)  Servo_PD.PWM=775;
	if(Servo_PD.PWM<-775) Servo_PD.PWM=-775;
	
    
	if(Shizi_flag==1)
	{
	if(Servo_PD.PWM>775)  Servo_PD.PWM=775;
	if(Servo_PD.PWM<-775) Servo_PD.PWM=-775;///////////////////////////////×ó
	}
	
   	if(shizi==1)
	{
	if(Servo_PD.PWM>50)  Servo_PD.PWM=50;
	if(Servo_PD.PWM<-50) Servo_PD.PWM=-50;///////////////////////////////×ó
	} 
    
	//ÔÚÕâÀïÃæÖ±½Ó¸ø½øÔ²»·µÄÕ¼¿Õ±È£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	if(right_yuan==1&&firsttime==1)  Servo_PD.PWM=460;
	if(left_yuan==1&&firsttime==1)   Servo_PD.PWM=-460;

	if(right_yuan==1&&firsttime==0&&(Z_zuo<70&&Z_you<70))  Servo_PD.PWM=-600;
	if(left_yuan==1&&firsttime==0&&(Z_zuo<70&&Z_you<70))  Servo_PD.PWM=600;
	
	if(podao==1)   Servo_PD.PWM=0;

//	if(Servo_PD.PWM>200)  ;


    #endif
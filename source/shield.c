#include "zcommon.acs"


int ShieldDelay[64];	

script "GiveShieldOnEntering" ENTER
{
ShieldDelay[PlayerNumber()] = 0;
GiveInventory("ShieldTypeI", 1);
GiveInventory("ShieldTierI", 1);
ACS_NamedExecuteAlways("RecursiveDamageCheck",0,0,0,0);
Delay(2);
}

script "GiveShieldOnRespawn" RESPAWN
{
TakeInventory("ShieldTierII",1);
TakeInventory("ShieldTierIII",1);
TakeInventory("ShieldTierIV",1);
GiveInventory("ShieldTypeI", 1);
GiveInventory("ShieldTierI", 1);
ACS_NamedExecuteAlways("RecursiveDamageCheck",0,0,0,0);
Delay(2);
}

Script "ResetShieldCVarsToDefault" (void)
{
SetCVar("shot_shieldtypeimax",50);
SetCVar("shot_shieldtypeidelay",280);
SetCVar("shot_shieldtypeiimax",100);
SetCVar("shot_shieldtypeiidelay",245);
SetCVar("shot_shieldtypeiiimax",200);
SetCVar("shot_shieldtypeiiidelay",210);
SetCVar("shot_shieldtypeivmax",300);
SetCVar("shot_shieldtypeivdelay",175);
}

Script "RecursiveDamageCheck" (int armorr, int healthh)
{
    if(CheckInventory("Armor") < armorr || CheckInventory("Health") < healthh)
     {
	    if(CheckInventory("Armor") > 0)
		{
		 PlaySound(0,"SH_HIT",CHAN_AUTO,1.0,FALSE);
		}
	    if(CheckInventory("ShieldTierI") == 1 && CheckInventory("ShieldTierII") == 0 && CheckInventory("ShieldTierIII") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeimax"))
		{
		  //Log(s:"Shield Delay set to 350");	
		  StopSound(0,CHAN_7);
		  ShieldDelay[PlayerNumber()] = GetCVar("shot_shieldtypeidelay");
		}
		if(CheckInventory("ShieldTierII") == 1 && CheckInventory("ShieldTierIII") == 0 && CheckInventory("ShieldTierIV") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeiimax"))
		{
		  //Log(s:"Shield Delay set to 280");
		  StopSound(0,CHAN_7);
		  ShieldDelay[PlayerNumber()] = GetCVar("shot_shieldtypeiidelay");
		}
		
		if(CheckInventory("ShieldTierIII") == 1 && CheckInventory("ShieldTierIV") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeiiimax"))
		{
		  //Log(s:"Shield Delay set to 210");	
		  StopSound(0,CHAN_7);
		  ShieldDelay[PlayerNumber()]= GetCVar("shot_shieldtypeiiidelay");
		}
		
		if(CheckInventory("ShieldTierIV") == 1 && CheckInventory("Armor") < GetCVar("shot_shieldtypeivmax"))
		{
		  //Log(s:"Shield Delay set to 210");	
		  StopSound(0,CHAN_7);
		  ShieldDelay[PlayerNumber()]= GetCVar("shot_shieldtypeivdelay");
		}
		
		
		
	   
     }
//delay(1);
ACS_NamedExecuteAlways("RecursiveDamageCheck",0,CheckInventory("Armor"),CheckInventory("Health"));
}

Script "ShieldDamageSound" (void)
{

if(CheckInventory("ShieldTierI") == 1 && CheckInventory("ShieldTierII") == 0 && CheckInventory("ShieldTierIII") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeimax") && ClassifyActor(0) & ACTOR_ALIVE)
{
While (CheckInventory("Armor") < GetCVar("shot_shieldtypeimax") && shielddelay[PlayerNumber()] != 0 && ClassifyActor(0) & ACTOR_ALIVE)
  {
  PlaySound(0,"SBEEPL",CHAN_AUTO,1.0,FALSE);
  Delay(6);
  }
}

if(CheckInventory("ShieldTierII") == 1 && CheckInventory("ShieldTierIII") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeiimax") && ClassifyActor(0) & ACTOR_ALIVE)
{
While (CheckInventory("Armor") < GetCVar("shot_shieldtypeiimax") && shielddelay[PlayerNumber()] != 0 && ClassifyActor(0) & ACTOR_ALIVE)
  {
  PlaySound(0,"SBEEPL",CHAN_AUTO,1.0,FALSE);
  Delay(6);
  }
}
  
  
if(CheckInventory("ShieldTierIII") == 1 && CheckInventory("ShieldTierIV") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeiiimax")&& ClassifyActor(0) & ACTOR_ALIVE)
{
While (CheckInventory("Armor") < GetCVar("shot_shieldtypeiiimax") && shielddelay[PlayerNumber()] != 0 && ClassifyActor(0) & ACTOR_ALIVE)
  {
  PlaySound(0,"SBEEPL",CHAN_AUTO,1.0,FALSE);
  Delay(6);
  }
}  

if(CheckInventory("ShieldTierIV") == 1 && CheckInventory("Armor") < GetCVar("shot_shieldtypeivmax")&& ClassifyActor(0) & ACTOR_ALIVE)
{
While (CheckInventory("Armor") < GetCVar("shot_shieldtypeivmax") && shielddelay[PlayerNumber()] != 0 && ClassifyActor(0) & ACTOR_ALIVE)
  {
  PlaySound(0,"SBEEPL",CHAN_AUTO,1.0,FALSE);
  Delay(6);
  }
}  
  
}

script "ShieldRecharge" Enter
{
Delay(1);		
 
        if(CheckInventory("ShieldTierI") == 1 && CheckInventory("ShieldTierII") == 0 && CheckInventory("ShieldTierIII") == 0 && CheckInventory("ShieldTierIV") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeimax") && ClassifyActor(0) & ACTOR_ALIVE)
		{
		  //Log(s:"Entered ShieldTierI State");	
		  while(CheckInventory("Armor") < GetCVar("shot_shieldtypeimax") && shielddelay[PlayerNumber()] != 0)
		  {
		  
		    if(CheckInventory("Armor") < GetCVar("shot_shieldtypeimax")/2)
			{
			  ACS_NamedExecute("ShieldDamageSound",0,0);
			}
			delay(1);
			shielddelay[PlayerNumber()]--;		  		  
		  }
		  
		  
		  if(ClassifyActor(0) & ACTOR_ALIVE)
		  {
            PlaySound(0,"RECHARG",CHAN_7,1.0,FALSE);
		  }
		  
		    while (CheckInventory("Armor") < GetCVar("shot_shieldtypeimax") && shielddelay[PlayerNumber()] == 0 && ClassifyActor(0) & ACTOR_ALIVE)
			{
			  GiveInventory("ShieldTypeIBonus",1);
			  Delay(1);
			  Delay(1);
			  Delay(1);
			  Delay(1);
			  //Log(s:"Adding ShieldTypeIBonus");
			    if (CheckInventory("Armor") == GetCVar("shot_shieldtypeimax"))
				{
				  StopSound(0,CHAN_7);
				  PlaySound(0,"SH_FULL",CHAN_AUTO,1.0,FALSE);
				  break;
				}			  			  
			}
				  		
		}
		
		 if(CheckInventory("ShieldTierII") == 1 && CheckInventory("ShieldTierIII") == 0 && CheckInventory("ShieldTierIV") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeiimax") && ClassifyActor(0) & ACTOR_ALIVE)
		 {
           //Log(s:"Entered ShieldTierII State");		 
		   while(CheckInventory("Armor") < GetCVar("shot_shieldtypeiimax") && shielddelay[PlayerNumber()] != 0)
		  {
		    if(CheckInventory("Armor") < GetCVar("shot_shieldtypeiimax")/2)
			{
			  ACS_NamedExecute("ShieldDamageSound",0,0);
			}
			delay(1);
			shielddelay[PlayerNumber()]--;		  		  
		  }
		  
		  
		  if(ClassifyActor(0) & ACTOR_ALIVE)
		  {
            PlaySound(0,"RECHARG",CHAN_7,1.0,FALSE);
		  }
		  
		  
		    while (CheckInventory("Armor") < GetCVar("shot_shieldtypeiimax") && shielddelay[PlayerNumber()] == 0 && ClassifyActor(0) & ACTOR_ALIVE)
			{
			  GiveInventory("ShieldTypeIIBonus",1);
			  Delay(1);
			  Delay(1);
			  Delay(1);
			  //Log(s:"Adding ShieldTypeIIBonus");
			    if (CheckInventory("Armor") == GetCVar("shot_shieldtypeiimax"))
				{
				  StopSound(0,CHAN_7);
				  PlaySound(0,"SH_FULL",CHAN_AUTO,1.0,FALSE);
				  break;
				}			  			  
			}
					
		 }	
		 
		 if(CheckInventory("ShieldTierIII") == 1 && CheckInventory("ShieldTierIV") == 0 && CheckInventory("Armor") < GetCVar("shot_shieldtypeiiimax") && ClassifyActor(0) & ACTOR_ALIVE)
		 {
		   //Log(s:"Entered ShieldTierIII State");	
		   While(CheckInventory("Armor") < GetCVar("shot_shieldtypeiiimax") && shielddelay[PlayerNumber()] != 0)
		   {
		     if(CheckInventory("Armor") < GetCVar("shot_shieldtypeiiimax")/2)
			{
			  ACS_NamedExecute("ShieldDamageSound",0,0);
			}
			  delay(1);
			  shielddelay[PlayerNumber()]--;	
		   }
		   
		   
		   if(ClassifyActor(0) & ACTOR_ALIVE)
		  {
            PlaySound(0,"RECHARG",CHAN_7,1.0,FALSE);
		  }
		   
		   while (CheckInventory("Armor") < GetCVar("shot_shieldtypeiiimax") && shielddelay[PlayerNumber()] == 0 && ClassifyActor(0) & ACTOR_ALIVE)
			{
			  GiveInventory("ShieldTypeIIIBonus",1);
			  Delay(1);
			  Delay(1);
			  Delay(1);
			  //Log(s:"Adding ShieldTypeIIIBonus");
			    if (CheckInventory("Armor") == GetCVar("shot_shieldtypeiiimax"))
				{
				  StopSound(0,CHAN_7);
				  PlaySound(0,"SH_FULL",CHAN_AUTO,1.0,FALSE);
				  break;
				}			  			  
			 }
			 	
		   
		  }
		  
		  if(CheckInventory("ShieldTierIV") == 1 && CheckInventory("Armor") < GetCVar("shot_shieldtypeivmax") && ClassifyActor(0) & ACTOR_ALIVE)
		 {
		   //Log(s:"Entered ShieldTierIV State");	
		   While(CheckInventory("Armor") < GetCVar("shot_shieldtypeivmax") && shielddelay[PlayerNumber()] != 0)
		   {
		     if(CheckInventory("Armor") < GetCVar("shot_shieldtypeivmax")/2)
			{
			  ACS_NamedExecute("ShieldDamageSound",0,0);
			}
			  delay(1);
			  shielddelay[PlayerNumber()]--;	
		   }
		   
		   
		   if(ClassifyActor(0) & ACTOR_ALIVE)
		  {
            PlaySound(0,"RECHARG",CHAN_7,1.0,FALSE);
		  }
		   
		   while (CheckInventory("Armor") < GetCVar("shot_shieldtypeivmax") && shielddelay[PlayerNumber()] == 0 && ClassifyActor(0) & ACTOR_ALIVE)
			{
			  GiveInventory("ShieldTypeIVBonus",1);
			  Delay(1);
			  Delay(1);
			  //Log(s:"Adding ShieldTypeIIIBonus");
			    if (CheckInventory("Armor") == GetCVar("shot_shieldtypeivmax"))
				{
				  StopSound(0,CHAN_7);
				  PlaySound(0,"SH_FULL",CHAN_AUTO,1.0,FALSE);
				  break;
				}			  			  
			 }
			 	
		   
		  }
		 

restart;
}
def timeToDeg(s):
   h=float(s.split(" ")[0]);
   m=float(s.split(" ")[1]);
   sec=float(s.split(" ")[2]);

   return (h+m/60+sec/3600)*360/24
def degToDeg(s):
   ss=s[1:];
   h=float(ss.split(" ")[0]);
   m=float(ss.split(" ")[1]);
   sec=float(ss.split(" ")[2]);

   t=h+m/60+sec/3600;
   if(s[0]=="-"):
      t=-t;
   return t;

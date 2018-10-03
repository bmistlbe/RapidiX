(* Created with the Wolfram Language for Students - Personal Use Only : www.wolfram.com *)
ALARM*\[Epsilon] + 
 ((nc*(336 - 1440*x1b + 2760*x1b^2 - 3112*x1b^3 + 2301*x1b^4 - 1160*x1b^5 + 
      389*x1b^6 - 78*x1b^7 + 7*x1b^8 - 1440*x2b + 6016*x1b*x2b - 
      11144*x1b^2*x2b + 12012*x1b^3*x2b - 8384*x1b^4*x2b + 3945*x1b^5*x2b - 
      1227*x1b^6*x2b + 228*x1b^7*x2b - 19*x1b^8*x2b + 2760*x2b^2 - 
      11144*x1b*x2b^2 + 19742*x1b^2*x2b^2 - 20104*x1b^3*x2b^2 + 
      13047*x1b^4*x2b^2 - 5611*x1b^5*x2b^2 + 1576*x1b^6*x2b^2 - 
      264*x1b^7*x2b^2 + 20*x1b^8*x2b^2 - 3112*x2b^3 + 12012*x1b*x2b^3 - 
      20104*x1b^2*x2b^3 + 19098*x1b^3*x2b^3 - 11342*x1b^4*x2b^3 + 
      4348*x1b^5*x2b^3 - 1060*x1b^6*x2b^3 + 152*x1b^7*x2b^3 - 
      10*x1b^8*x2b^3 + 2301*x2b^4 - 8384*x1b*x2b^4 + 13047*x1b^2*x2b^4 - 
      11342*x1b^3*x2b^4 + 6012*x1b^4*x2b^4 - 1977*x1b^5*x2b^4 + 
      390*x1b^6*x2b^4 - 42*x1b^7*x2b^4 + 2*x1b^8*x2b^4 - 1160*x2b^5 + 
      3945*x1b*x2b^5 - 5611*x1b^2*x2b^5 + 4348*x1b^3*x2b^5 - 
      1977*x1b^4*x2b^5 + 524*x1b^5*x2b^5 - 74*x1b^6*x2b^5 + 4*x1b^7*x2b^5 + 
      389*x2b^6 - 1227*x1b*x2b^6 + 1576*x1b^2*x2b^6 - 1060*x1b^3*x2b^6 + 
      390*x1b^4*x2b^6 - 74*x1b^5*x2b^6 + 6*x1b^6*x2b^6 - 78*x2b^7 + 
      228*x1b*x2b^7 - 264*x1b^2*x2b^7 + 152*x1b^3*x2b^7 - 42*x1b^4*x2b^7 + 
      4*x1b^5*x2b^7 + 7*x2b^8 - 19*x1b*x2b^8 + 20*x1b^2*x2b^8 - 
      10*x1b^3*x2b^8 + 2*x1b^4*x2b^8))/((-2 + x1b)*(-1 + x1b)*(-2 + x2b)*
     (-1 + x2b)*(-2 + x1b + x2b)^4) - 
   (nc*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*PlusD[x2b, 0])/(-1 + x1b) + 
   PlusD[x1b, 0]*(-((nc*(-1 + 3*x2b - 2*x2b^2 + x2b^3))/(-1 + x2b)) + 
     nc*PlusD[x2b, 0]) + 
   (-((nc*(Log[2] - 2*x1b*Log[2] + 3*x1b^2*Log[2] - 2*x1b^3*Log[2] + 
         x1b^4*Log[2] - x1b*Log[MH2/muf2] + 3*x1b^2*Log[MH2/muf2] - 
         2*x1b^3*Log[MH2/muf2] + x1b^4*Log[MH2/muf2] - Log[2 - x1b] + 
         2*x1b*Log[2 - x1b] - 3*x1b^2*Log[2 - x1b] + 2*x1b^3*Log[2 - x1b] - 
         x1b^4*Log[2 - x1b] - x1b*Log[x1b] + 3*x1b^2*Log[x1b] - 
         2*x1b^3*Log[x1b] + x1b^4*Log[x1b]))/((-1 + x1b)*x1b)) + 
     nc*Log[MH2/muf2]*PlusD[x1b, 0] + nc*PlusD[x1b, 1])*\[Delta][x2b] + 
   \[Delta][x1b]*(-((nc*(Log[2] - 2*x2b*Log[2] + 3*x2b^2*Log[2] - 
         2*x2b^3*Log[2] + x2b^4*Log[2] - x2b*Log[MH2/muf2] + 
         3*x2b^2*Log[MH2/muf2] - 2*x2b^3*Log[MH2/muf2] + 
         x2b^4*Log[MH2/muf2] - Log[2 - x2b] + 2*x2b*Log[2 - x2b] - 
         3*x2b^2*Log[2 - x2b] + 2*x2b^3*Log[2 - x2b] - x2b^4*Log[2 - x2b] - 
         x2b*Log[x2b] + 3*x2b^2*Log[x2b] - 2*x2b^3*Log[x2b] + 
         x2b^4*Log[x2b]))/((-1 + x2b)*x2b)) + nc*Log[MH2/muf2]*
      PlusD[x2b, 0] + nc*PlusD[x2b, 1] + (nc*Pi^2*\[Delta][x2b])/2))*
  \[Delta][y]

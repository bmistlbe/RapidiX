(* Created with the Wolfram Language : www.wolfram.com *)
{-((-131*nc^3 + 17*nc^2*nf - 6*nc^3*Pi^2 + 45*nc^3*x1b + 15*nf*x1b - 
      129*nc^2*nf*x1b + 18*nc^3*Pi^2*x1b + 86*nc^3*x1b^2 - 9*nf*x1b^2 + 
      106*nc^2*nf*x1b^2 - 12*nc^3*Pi^2*x1b^2 - 48*nc^3*x1b^3 - 12*nf*x1b^3 - 
      34*nc^2*nf*x1b^3 + 6*nc^3*Pi^2*x1b^3)*del[x2b]*G[0, x1b])/
   (72*nc*(-1 + x1b)) - ((-131*nc^3 + 17*nc^2*nf - 6*nc^3*Pi^2 + 
     45*nc^3*x2b + 15*nf*x2b - 129*nc^2*nf*x2b + 18*nc^3*Pi^2*x2b + 
     86*nc^3*x2b^2 - 9*nf*x2b^2 + 106*nc^2*nf*x2b^2 - 12*nc^3*Pi^2*x2b^2 - 
     48*nc^3*x2b^3 - 12*nf*x2b^3 - 34*nc^2*nf*x2b^3 + 6*nc^3*Pi^2*x2b^3)*
    del[x1b]*G[0, x2b])/(72*nc*(-1 + x2b)) - 
  ((-24*nc^3 + 24*nc^2*nf + 48*nc^3*Pi^2 + 254*nc^3*x1b + 588*nf*x1b - 
     934*nc^2*nf*x1b + 12*nf*Pi^2*x1b - 12*nc^2*nf*Pi^2*x1b - 
     1065*nc^3*x1b^2 - 1398*nf*x1b^2 + 2124*nc^2*nf*x1b^2 - 
     18*nf*Pi^2*x1b^2 + 18*nc^2*nf*Pi^2*x1b^2 + 1099*nc^3*x1b^3 + 
     1026*nf*x1b^3 - 1606*nc^2*nf*x1b^3 - 48*nc^3*Pi^2*x1b^3 + 
     6*nf*Pi^2*x1b^3 - 6*nc^2*nf*Pi^2*x1b^3 - 264*nc^3*x1b^4 - 216*nf*x1b^4 + 
     392*nc^2*nf*x1b^4 + 48*nc^3*Pi^2*x1b^4)*del[x2b]*G[1, x1b])/
   (144*nc*(-1 + x1b)*x1b) - 
  ((-24*nc^3 + 24*nc^2*nf + 48*nc^3*Pi^2 + 254*nc^3*x2b + 588*nf*x2b - 
     934*nc^2*nf*x2b + 12*nf*Pi^2*x2b - 12*nc^2*nf*Pi^2*x2b - 
     1065*nc^3*x2b^2 - 1398*nf*x2b^2 + 2124*nc^2*nf*x2b^2 - 
     18*nf*Pi^2*x2b^2 + 18*nc^2*nf*Pi^2*x2b^2 + 1099*nc^3*x2b^3 + 
     1026*nf*x2b^3 - 1606*nc^2*nf*x2b^3 - 48*nc^3*Pi^2*x2b^3 + 
     6*nf*Pi^2*x2b^3 - 6*nc^2*nf*Pi^2*x2b^3 - 264*nc^3*x2b^4 - 216*nf*x2b^4 + 
     392*nc^2*nf*x2b^4 + 48*nc^3*Pi^2*x2b^4)*del[x1b]*G[1, x2b])/
   (144*nc*(-1 + x2b)*x2b) + 
  ((122*nc^3 - 8*nc^2*nf + 30*nc^3*Pi^2 + 1730*nc^3*x1b + 330*nf*x1b - 
     474*nc^2*nf*x1b - 60*nc^3*Pi^2*x1b - 3075*nc^3*x1b^2 - 747*nf*x1b^2 + 
     1011*nc^2*nf*x1b^2 + 90*nc^3*Pi^2*x1b^2 + 2135*nc^3*x1b^3 + 
     531*nf*x1b^3 - 731*nc^2*nf*x1b^3 - 60*nc^3*Pi^2*x1b^3 - 448*nc^3*x1b^4 - 
     120*nf*x1b^4 + 162*nc^2*nf*x1b^4 + 30*nc^3*Pi^2*x1b^4)*del[x2b]*
    G[2, x1b])/(72*nc*(-1 + x1b)*x1b) + 
  ((122*nc^3 - 8*nc^2*nf + 30*nc^3*Pi^2 + 1730*nc^3*x2b + 330*nf*x2b - 
     474*nc^2*nf*x2b - 60*nc^3*Pi^2*x2b - 3075*nc^3*x2b^2 - 747*nf*x2b^2 + 
     1011*nc^2*nf*x2b^2 + 90*nc^3*Pi^2*x2b^2 + 2135*nc^3*x2b^3 + 
     531*nf*x2b^3 - 731*nc^2*nf*x2b^3 - 60*nc^3*Pi^2*x2b^3 - 448*nc^3*x2b^4 - 
     120*nf*x2b^4 + 162*nc^2*nf*x2b^4 + 30*nc^3*Pi^2*x2b^4)*del[x1b]*
    G[2, x2b])/(72*nc*(-1 + x2b)*x2b) + 
  ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x1b + 15*nf*x1b - 27*nc^2*nf*x1b - 
     236*nc^3*x1b^2 - 15*nf*x1b^2 + 23*nc^2*nf*x1b^2 + 110*nc^3*x1b^3 + 
     4*nf*x1b^3 - 8*nc^2*nf*x1b^3)*del[x2b]*G[0, 0, x1b])/
   (24*nc*(-1 + x1b)) + ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x2b + 15*nf*x2b - 
     27*nc^2*nf*x2b - 236*nc^3*x2b^2 - 15*nf*x2b^2 + 23*nc^2*nf*x2b^2 + 
     110*nc^3*x2b^3 + 4*nf*x2b^3 - 8*nc^2*nf*x2b^3)*del[x1b]*G[0, 0, x2b])/
   (24*nc*(-1 + x2b)) - ((22*nc^3 - 4*nc^2*nf - 44*nc^3*x1b + 8*nc^2*nf*x1b + 
     258*nc^3*x1b^2 + 15*nf*x1b^2 - 27*nc^2*nf*x1b^2 - 236*nc^3*x1b^3 - 
     15*nf*x1b^3 + 23*nc^2*nf*x1b^3 + 110*nc^3*x1b^4 + 4*nf*x1b^4 - 
     8*nc^2*nf*x1b^4)*del[x2b]*G[0, 1, x1b])/(24*nc*(-1 + x1b)*x1b) - 
  ((22*nc^3 - 4*nc^2*nf - 44*nc^3*x2b + 8*nc^2*nf*x2b + 258*nc^3*x2b^2 + 
     15*nf*x2b^2 - 27*nc^2*nf*x2b^2 - 236*nc^3*x2b^3 - 15*nf*x2b^3 + 
     23*nc^2*nf*x2b^3 + 110*nc^3*x2b^4 + 4*nf*x2b^4 - 8*nc^2*nf*x2b^4)*
    del[x1b]*G[0, 1, x2b])/(24*nc*(-1 + x2b)*x2b) - 
  ((372*nc^3 + 38*nf - 30*nc^2*nf - 426*nc^3*x1b - 55*nf*x1b + 
     51*nc^2*nf*x1b + 200*nc^3*x1b^2 + 20*nf*x1b^2 - 20*nc^2*nf*x1b^2)*
    del[x2b]*G[1, 0, x1b])/(24*nc) - 
  ((372*nc^3 + 38*nf - 30*nc^2*nf - 426*nc^3*x2b - 55*nf*x2b + 
     51*nc^2*nf*x2b + 200*nc^3*x2b^2 + 20*nf*x2b^2 - 20*nc^2*nf*x2b^2)*
    del[x1b]*G[1, 0, x2b])/(24*nc) + 
  ((628*nc^3 + 100*nf - 92*nc^2*nf - 698*nc^3*x1b - 125*nf*x1b + 
     121*nc^2*nf*x1b + 312*nc^3*x1b^2 + 40*nf*x1b^2 - 40*nc^2*nf*x1b^2)*
    del[x2b]*G[1, 1, x1b])/(48*nc) + 
  ((628*nc^3 + 100*nf - 92*nc^2*nf - 698*nc^3*x2b - 125*nf*x2b + 
     121*nc^2*nf*x2b + 312*nc^3*x2b^2 + 40*nf*x2b^2 - 40*nc^2*nf*x2b^2)*
    del[x1b]*G[1, 1, x2b])/(48*nc) + 
  ((140*nc^3 - 12*nf + 20*nc^2*nf - 154*nc^3*x1b + 9*nf*x1b - 
     13*nc^2*nf*x1b + 88*nc^3*x1b^2)*del[x2b]*G[1, 2, x1b])/(24*nc) + 
  ((140*nc^3 - 12*nf + 20*nc^2*nf - 154*nc^3*x2b + 9*nf*x2b - 
     13*nc^2*nf*x2b + 88*nc^3*x2b^2)*del[x1b]*G[1, 2, x2b])/(24*nc) + 
  ((-22*nc^3 + 4*nc^2*nf + 44*nc^3*x1b - 50*nf*x1b + 42*nc^2*nf*x1b + 
     30*nc^3*x1b^2 + 99*nf*x1b^2 - 87*nc^2*nf*x1b^2 - 52*nc^3*x1b^3 - 
     69*nf*x1b^3 + 61*nc^2*nf*x1b^3 + 2*nc^3*x1b^4 + 16*nf*x1b^4 - 
     12*nc^2*nf*x1b^4)*del[x2b]*G[2, 0, x1b])/(24*nc*(-1 + x1b)*x1b) + 
  ((-22*nc^3 + 4*nc^2*nf + 44*nc^3*x2b - 50*nf*x2b + 42*nc^2*nf*x2b + 
     30*nc^3*x2b^2 + 99*nf*x2b^2 - 87*nc^2*nf*x2b^2 - 52*nc^3*x2b^3 - 
     69*nf*x2b^3 + 61*nc^2*nf*x2b^3 + 2*nc^3*x2b^4 + 16*nf*x2b^4 - 
     12*nc^2*nf*x2b^4)*del[x1b]*G[2, 0, x2b])/(24*nc*(-1 + x2b)*x2b) + 
  ((22*nc^3 - 4*nc^2*nf - 276*nc^3*x1b + 50*nf*x1b - 42*nc^2*nf*x1b + 
     270*nc^3*x1b^2 - 99*nf*x1b^2 + 87*nc^2*nf*x1b^2 - 128*nc^3*x1b^3 + 
     69*nf*x1b^3 - 61*nc^2*nf*x1b^3 + 42*nc^3*x1b^4 - 16*nf*x1b^4 + 
     12*nc^2*nf*x1b^4)*del[x2b]*G[2, 1, x1b])/(24*nc*(-1 + x1b)*x1b) + 
  ((22*nc^3 - 4*nc^2*nf - 276*nc^3*x2b + 50*nf*x2b - 42*nc^2*nf*x2b + 
     270*nc^3*x2b^2 - 99*nf*x2b^2 + 87*nc^2*nf*x2b^2 - 128*nc^3*x2b^3 + 
     69*nf*x2b^3 - 61*nc^2*nf*x2b^3 + 42*nc^3*x2b^4 - 16*nf*x2b^4 + 
     12*nc^2*nf*x2b^4)*del[x1b]*G[2, 1, x2b])/(24*nc*(-1 + x2b)*x2b) - 
  (3*nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*del[x2b]*G[0, 0, 0, x1b])/
   (-1 + x1b) - (3*nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*del[x1b]*
    G[0, 0, 0, x2b])/(-1 + x2b) + (5*nc^2*(1 - x1b + x1b^2)^2*del[x2b]*
    G[0, 0, 1, x1b])/(2*(-1 + x1b)*x1b) + 
  (5*nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 0, 1, x2b])/(2*(-1 + x2b)*x2b) + 
  (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 0, 2, x1b])/(2*(-1 + x1b)*x1b) + 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 0, 2, x2b])/(2*(-1 + x2b)*x2b) + 
  (5*nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 1, 0, x1b])/(2*(-1 + x1b)*x1b) + 
  (5*nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 1, 0, x2b])/(2*(-1 + x2b)*x2b) - 
  (3*nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 1, 1, x1b])/(2*(-1 + x1b)*x1b) - 
  (3*nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 1, 1, x2b])/(2*(-1 + x2b)*x2b) - 
  (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 1, 2, x1b])/((-1 + x1b)*x1b) - 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 1, 2, x2b])/((-1 + x2b)*x2b) + 
  (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 2, 0, x1b])/((-1 + x1b)*x1b) + 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 2, 0, x2b])/((-1 + x2b)*x2b) - 
  (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 2, 1, x1b])/((-1 + x1b)*x1b) - 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 2, 1, x2b])/((-1 + x2b)*x2b) + 
  ((10*nc^3 - 4*nc^3*x1b + 2*nf*x1b - 2*nc^2*nf*x1b + 6*nc^3*x1b^2 - 
     3*nf*x1b^2 + 3*nc^2*nf*x1b^2 - 12*nc^3*x1b^3 + nf*x1b^3 - 
     nc^2*nf*x1b^3 + 10*nc^3*x1b^4)*del[x2b]*G[1, 0, 0, x1b])/
   (4*nc*(-1 + x1b)*x1b) + 
  ((10*nc^3 - 4*nc^3*x2b + 2*nf*x2b - 2*nc^2*nf*x2b + 6*nc^3*x2b^2 - 
     3*nf*x2b^2 + 3*nc^2*nf*x2b^2 - 12*nc^3*x2b^3 + nf*x2b^3 - 
     nc^2*nf*x2b^3 + 10*nc^3*x2b^4)*del[x1b]*G[1, 0, 0, x2b])/
   (4*nc*(-1 + x2b)*x2b) - ((8*nc^3 + 2*nf*x1b - 2*nc^2*nf*x1b - 3*nf*x1b^2 + 
     3*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 
     8*nc^3*x1b^4)*del[x2b]*G[1, 0, 1, x1b])/(4*nc*(-1 + x1b)*x1b) - 
  ((8*nc^3 + 2*nf*x2b - 2*nc^2*nf*x2b - 3*nf*x2b^2 + 3*nc^2*nf*x2b^2 - 
     8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 8*nc^3*x2b^4)*del[x1b]*
    G[1, 0, 1, x2b])/(4*nc*(-1 + x2b)*x2b) + 
  (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[1, 0, 2, x1b])/(2*(-1 + x1b)*x1b) + 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[1, 0, 2, x2b])/(2*(-1 + x2b)*x2b) - 
  ((4*nc^3 + 8*nc^3*x1b + 4*nf*x1b - 4*nc^2*nf*x1b - 4*nc^3*x1b^2 - 
     4*nf*x1b^2 + 4*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 
     4*nc^3*x1b^4)*del[x2b]*G[1, 1, 0, x1b])/(4*nc*(-2 + x1b)*x1b) - 
  ((4*nc^3 + 8*nc^3*x2b + 4*nf*x2b - 4*nc^2*nf*x2b - 4*nc^3*x2b^2 - 
     4*nf*x2b^2 + 4*nc^2*nf*x2b^2 - 8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 
     4*nc^3*x2b^4)*del[x1b]*G[1, 1, 0, x2b])/(4*nc*(-2 + x2b)*x2b) + 
  ((4*nc^3 + 8*nc^3*x1b + 4*nf*x1b - 4*nc^2*nf*x1b - 4*nc^3*x1b^2 - 
     4*nf*x1b^2 + 4*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 
     4*nc^3*x1b^4)*del[x2b]*G[1, 1, 1, x1b])/(8*nc*(-2 + x1b)*x1b) + 
  ((4*nc^3 + 8*nc^3*x2b + 4*nf*x2b - 4*nc^2*nf*x2b - 4*nc^3*x2b^2 - 
     4*nf*x2b^2 + 4*nc^2*nf*x2b^2 - 8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 
     4*nc^3*x2b^4)*del[x1b]*G[1, 1, 1, x2b])/(8*nc*(-2 + x2b)*x2b) + 
  ((4*nc^3 + 8*nc^3*x1b + 4*nf*x1b - 4*nc^2*nf*x1b - 4*nc^3*x1b^2 - 
     4*nf*x1b^2 + 4*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 
     4*nc^3*x1b^4)*del[x2b]*G[1, 1, 2, x1b])/(4*nc*(-2 + x1b)*x1b) + 
  ((4*nc^3 + 8*nc^3*x2b + 4*nf*x2b - 4*nc^2*nf*x2b - 4*nc^3*x2b^2 - 
     4*nf*x2b^2 + 4*nc^2*nf*x2b^2 - 8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 
     4*nc^3*x2b^4)*del[x1b]*G[1, 1, 2, x2b])/(4*nc*(-2 + x2b)*x2b) + 
  (nc^2*(3 - 3*x1b + x1b^2)^2*del[x2b]*G[1, 3/2, 1, x1b])/
   ((-2 + x1b)*(-1 + x1b)) + (nc^2*(3 - 3*x2b + x2b^2)^2*del[x1b]*
    G[1, 3/2, 1, x2b])/((-2 + x2b)*(-1 + x2b)) - 
  (nc^2*(3 - 3*x1b + x1b^2)^2*del[x2b]*G[1, 3/2, 2, x1b])/
   (2*(-2 + x1b)*(-1 + x1b)) - (nc^2*(3 - 3*x2b + x2b^2)^2*del[x1b]*
    G[1, 3/2, 2, x2b])/(2*(-2 + x2b)*(-1 + x2b)) - 
  ((8*nc^3 + 2*nf*x1b - 2*nc^2*nf*x1b - 3*nf*x1b^2 + 3*nc^2*nf*x1b^2 - 
     8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 8*nc^3*x1b^4)*del[x2b]*
    G[1, 2, 0, x1b])/(4*nc*(-1 + x1b)*x1b) - 
  ((8*nc^3 + 2*nf*x2b - 2*nc^2*nf*x2b - 3*nf*x2b^2 + 3*nc^2*nf*x2b^2 - 
     8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 8*nc^3*x2b^4)*del[x1b]*
    G[1, 2, 0, x2b])/(4*nc*(-1 + x2b)*x2b) + 
  ((-20*nc^3 - 36*nc^3*x1b - 4*nf*x1b + 4*nc^2*nf*x1b + 92*nc^3*x1b^2 + 
     8*nf*x1b^2 - 8*nc^2*nf*x1b^2 - 60*nc^3*x1b^3 - 5*nf*x1b^3 + 
     5*nc^2*nf*x1b^3 + 4*nc^3*x1b^4 + nf*x1b^4 - nc^2*nf*x1b^4 + 
     4*nc^3*x1b^5)*del[x2b]*G[1, 2, 1, x1b])/(4*nc*(-2 + x1b)*(-1 + x1b)*
    x1b) + ((-20*nc^3 - 36*nc^3*x2b - 4*nf*x2b + 4*nc^2*nf*x2b + 
     92*nc^3*x2b^2 + 8*nf*x2b^2 - 8*nc^2*nf*x2b^2 - 60*nc^3*x2b^3 - 
     5*nf*x2b^3 + 5*nc^2*nf*x2b^3 + 4*nc^3*x2b^4 + nf*x2b^4 - nc^2*nf*x2b^4 + 
     4*nc^3*x2b^5)*del[x1b]*G[1, 2, 1, x2b])/(4*nc*(-2 + x2b)*(-1 + x2b)*
    x2b) - (3*nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[1, 2, 2, x1b])/
   (2*(-1 + x1b)*x1b) - (3*nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[1, 2, 2, x2b])/
   (2*(-1 + x2b)*x2b) + (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[2, 0, 0, x1b])/
   ((-1 + x1b)*x1b) + (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[2, 0, 0, x2b])/
   ((-1 + x2b)*x2b) - (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[2, 0, 2, x1b])/
   (2*(-1 + x1b)*x1b) - (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[2, 0, 2, x2b])/
   (2*(-1 + x2b)*x2b) - (nc^2*(-4 + x1b + 2*x1b^2 - x1b^3 - 2*x1b^4 + x1b^5)*
    del[x2b]*G[2, 1, 0, x1b])/((-2 + x1b)*(-1 + x1b)*x1b) - 
  (nc^2*(-4 + x2b + 2*x2b^2 - x2b^3 - 2*x2b^4 + x2b^5)*del[x1b]*
    G[2, 1, 0, x2b])/((-2 + x2b)*(-1 + x2b)*x2b) + 
  (nc^2*(-4 + x1b + 2*x1b^2 - x1b^3 - 2*x1b^4 + x1b^5)*del[x2b]*
    G[2, 1, 1, x1b])/(2*(-2 + x1b)*(-1 + x1b)*x1b) + 
  (nc^2*(-4 + x2b + 2*x2b^2 - x2b^3 - 2*x2b^4 + x2b^5)*del[x1b]*
    G[2, 1, 1, x2b])/(2*(-2 + x2b)*(-1 + x2b)*x2b) - 
  (nc^2*(3 - 3*x1b + x1b^2)^2*del[x2b]*G[2, 1, 2, x1b])/
   ((-2 + x1b)*(-1 + x1b)) - (nc^2*(3 - 3*x2b + x2b^2)^2*del[x1b]*
    G[2, 1, 2, x2b])/((-2 + x2b)*(-1 + x2b)) - 
  (nc^2*(3 - 3*x1b + x1b^2)^2*del[x2b]*G[2, 3/2, 1, x1b])/
   ((-2 + x1b)*(-1 + x1b)) - (nc^2*(3 - 3*x2b + x2b^2)^2*del[x1b]*
    G[2, 3/2, 1, x2b])/((-2 + x2b)*(-1 + x2b)) + 
  (nc^2*(3 - 3*x1b + x1b^2)^2*del[x2b]*G[2, 3/2, 2, x1b])/
   (2*(-2 + x1b)*(-1 + x1b)) + (nc^2*(3 - 3*x2b + x2b^2)^2*del[x1b]*
    G[2, 3/2, 2, x2b])/(2*(-2 + x2b)*(-1 + x2b)) + 
  (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[2, 2, 0, x1b])/((-1 + x1b)*x1b) + 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[2, 2, 0, x2b])/((-1 + x2b)*x2b) - 
  (nc^2*(-4 + x1b + 2*x1b^2 - x1b^3 - 2*x1b^4 + x1b^5)*del[x2b]*
    G[2, 2, 1, x1b])/((-2 + x1b)*(-1 + x1b)*x1b) - 
  (nc^2*(-4 + x2b + 2*x2b^2 - x2b^3 - 2*x2b^4 + x2b^5)*del[x1b]*
    G[2, 2, 1, x2b])/((-2 + x2b)*(-1 + x2b)*x2b) - 
  ((-134*nc^3 + 20*nc^2*nf - 6*nc^3*Pi^2 + 51*nc^3*x2b + 15*nf*x2b - 
     135*nc^2*nf*x2b + 18*nc^3*Pi^2*x2b + 83*nc^3*x2b^2 - 9*nf*x2b^2 + 
     109*nc^2*nf*x2b^2 - 12*nc^3*Pi^2*x2b^2 - 48*nc^3*x2b^3 - 12*nf*x2b^3 - 
     34*nc^2*nf*x2b^3 + 6*nc^3*Pi^2*x2b^3)*del[x1b]*Log[MH2/muf2])/
   (72*nc*(-1 + x2b)) - ((-134*nc^3 + 20*nc^2*nf - 6*nc^3*Pi^2 + 
     51*nc^3*x1b + 15*nf*x1b - 135*nc^2*nf*x1b + 18*nc^3*Pi^2*x1b + 
     83*nc^3*x1b^2 - 9*nf*x1b^2 + 109*nc^2*nf*x1b^2 - 12*nc^3*Pi^2*x1b^2 - 
     48*nc^3*x1b^3 - 12*nf*x1b^3 - 34*nc^2*nf*x1b^3 + 6*nc^3*Pi^2*x1b^3)*
    del[x2b]*Log[MH2/muf2])/(72*nc*(-1 + x1b)) + 
  ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x1b + 15*nf*x1b - 27*nc^2*nf*x1b - 
     236*nc^3*x1b^2 - 15*nf*x1b^2 + 23*nc^2*nf*x1b^2 + 110*nc^3*x1b^3 + 
     4*nf*x1b^3 - 8*nc^2*nf*x1b^3)*del[x2b]*G[0, x1b]*Log[MH2/muf2])/
   (24*nc*(-1 + x1b)) + ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x2b + 15*nf*x2b - 
     27*nc^2*nf*x2b - 236*nc^3*x2b^2 - 15*nf*x2b^2 + 23*nc^2*nf*x2b^2 + 
     110*nc^3*x2b^3 + 4*nf*x2b^3 - 8*nc^2*nf*x2b^3)*del[x1b]*G[0, x2b]*
    Log[MH2/muf2])/(24*nc*(-1 + x2b)) - 
  ((372*nc^3 + 38*nf - 30*nc^2*nf - 426*nc^3*x1b - 55*nf*x1b + 
     51*nc^2*nf*x1b + 200*nc^3*x1b^2 + 20*nf*x1b^2 - 20*nc^2*nf*x1b^2)*
    del[x2b]*G[1, x1b]*Log[MH2/muf2])/(24*nc) - 
  ((372*nc^3 + 38*nf - 30*nc^2*nf - 426*nc^3*x2b - 55*nf*x2b + 
     51*nc^2*nf*x2b + 200*nc^3*x2b^2 + 20*nf*x2b^2 - 20*nc^2*nf*x2b^2)*
    del[x1b]*G[1, x2b]*Log[MH2/muf2])/(24*nc) + 
  ((-22*nc^3 + 4*nc^2*nf + 44*nc^3*x1b - 50*nf*x1b + 42*nc^2*nf*x1b + 
     30*nc^3*x1b^2 + 99*nf*x1b^2 - 87*nc^2*nf*x1b^2 - 52*nc^3*x1b^3 - 
     69*nf*x1b^3 + 61*nc^2*nf*x1b^3 + 2*nc^3*x1b^4 + 16*nf*x1b^4 - 
     12*nc^2*nf*x1b^4)*del[x2b]*G[2, x1b]*Log[MH2/muf2])/
   (24*nc*(-1 + x1b)*x1b) + 
  ((-22*nc^3 + 4*nc^2*nf + 44*nc^3*x2b - 50*nf*x2b + 42*nc^2*nf*x2b + 
     30*nc^3*x2b^2 + 99*nf*x2b^2 - 87*nc^2*nf*x2b^2 - 52*nc^3*x2b^3 - 
     69*nf*x2b^3 + 61*nc^2*nf*x2b^3 + 2*nc^3*x2b^4 + 16*nf*x2b^4 - 
     12*nc^2*nf*x2b^4)*del[x1b]*G[2, x2b]*Log[MH2/muf2])/
   (24*nc*(-1 + x2b)*x2b) - (3*nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*del[x2b]*
    G[0, 0, x1b]*Log[MH2/muf2])/(-1 + x1b) - 
  (3*nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*del[x1b]*G[0, 0, x2b]*Log[MH2/muf2])/
   (-1 + x2b) + (2*nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 1, x1b]*
    Log[MH2/muf2])/((-1 + x1b)*x1b) + 
  (2*nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 1, x2b]*Log[MH2/muf2])/
   ((-1 + x2b)*x2b) + (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[0, 2, x1b]*
    Log[MH2/muf2])/((-1 + x1b)*x1b) + 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[0, 2, x2b]*Log[MH2/muf2])/
   ((-1 + x2b)*x2b) + ((8*nc^3 + 2*nf*x1b - 2*nc^2*nf*x1b - 3*nf*x1b^2 + 
     3*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 
     8*nc^3*x1b^4)*del[x2b]*G[1, 0, x1b]*Log[MH2/muf2])/
   (4*nc*(-1 + x1b)*x1b) + ((8*nc^3 + 2*nf*x2b - 2*nc^2*nf*x2b - 3*nf*x2b^2 + 
     3*nc^2*nf*x2b^2 - 8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 
     8*nc^3*x2b^4)*del[x1b]*G[1, 0, x2b]*Log[MH2/muf2])/
   (4*nc*(-1 + x2b)*x2b) - ((4*nc^3 + 8*nc^3*x1b + 4*nf*x1b - 4*nc^2*nf*x1b - 
     4*nc^3*x1b^2 - 4*nf*x1b^2 + 4*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - 
     nc^2*nf*x1b^3 + 4*nc^3*x1b^4)*del[x2b]*G[1, 1, x1b]*Log[MH2/muf2])/
   (4*nc*(-2 + x1b)*x1b) - ((4*nc^3 + 8*nc^3*x2b + 4*nf*x2b - 4*nc^2*nf*x2b - 
     4*nc^3*x2b^2 - 4*nf*x2b^2 + 4*nc^2*nf*x2b^2 - 8*nc^3*x2b^3 + nf*x2b^3 - 
     nc^2*nf*x2b^3 + 4*nc^3*x2b^4)*del[x1b]*G[1, 1, x2b]*Log[MH2/muf2])/
   (4*nc*(-2 + x2b)*x2b) - ((4*nc^3 + 8*nc^3*x1b + 2*nf*x1b - 2*nc^2*nf*x1b - 
     12*nc^3*x1b^2 - 3*nf*x1b^2 + 3*nc^2*nf*x1b^2 + nf*x1b^3 - 
     nc^2*nf*x1b^3 + 4*nc^3*x1b^4)*del[x2b]*G[1, 2, x1b]*Log[MH2/muf2])/
   (4*nc*(-1 + x1b)*x1b) - ((4*nc^3 + 8*nc^3*x2b + 2*nf*x2b - 2*nc^2*nf*x2b - 
     12*nc^3*x2b^2 - 3*nf*x2b^2 + 3*nc^2*nf*x2b^2 + nf*x2b^3 - 
     nc^2*nf*x2b^3 + 4*nc^3*x2b^4)*del[x1b]*G[1, 2, x2b]*Log[MH2/muf2])/
   (4*nc*(-1 + x2b)*x2b) + (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[2, 0, x1b]*
    Log[MH2/muf2])/((-1 + x1b)*x1b) + 
  (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[2, 0, x2b]*Log[MH2/muf2])/
   ((-1 + x2b)*x2b) - (2*nc^2*(-1 - 2*x1b + 5*x1b^2 - 4*x1b^3 + x1b^4)*
    del[x2b]*G[2, 1, x1b]*Log[MH2/muf2])/((-2 + x1b)*(-1 + x1b)*x1b) - 
  (2*nc^2*(-1 - 2*x2b + 5*x2b^2 - 4*x2b^3 + x2b^4)*del[x1b]*G[2, 1, x2b]*
    Log[MH2/muf2])/((-2 + x2b)*(-1 + x2b)*x2b) + 
  (nc^2*(1 - x1b + x1b^2)^2*del[x2b]*G[2, 2, x1b]*Log[MH2/muf2])/
   ((-1 + x1b)*x1b) + (nc^2*(1 - x2b + x2b^2)^2*del[x1b]*G[2, 2, x2b]*
    Log[MH2/muf2])/((-1 + x2b)*x2b) + 
  ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x2b + 15*nf*x2b - 27*nc^2*nf*x2b - 
     236*nc^3*x2b^2 - 15*nf*x2b^2 + 23*nc^2*nf*x2b^2 + 110*nc^3*x2b^3 + 
     4*nf*x2b^3 - 8*nc^2*nf*x2b^3)*del[x1b]*Log[MH2/muf2]^2)/
   (48*nc*(-1 + x2b)) + ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x1b + 15*nf*x1b - 
     27*nc^2*nf*x1b - 236*nc^3*x1b^2 - 15*nf*x1b^2 + 23*nc^2*nf*x1b^2 + 
     110*nc^3*x1b^3 + 4*nf*x1b^3 - 8*nc^2*nf*x1b^3)*del[x2b]*Log[MH2/muf2]^2)/
   (48*nc*(-1 + x1b)) - (nc^2*Pi^2*del[x1b]*del[x2b]*Log[MH2/muf2]^2)/6 - 
  (nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*del[x2b]*G[0, x1b]*Log[MH2/muf2]^2)/
   (-1 + x1b) - (nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*del[x1b]*G[0, x2b]*
    Log[MH2/muf2]^2)/(-1 + x2b) + 
  ((4*nc^3 + 8*nc^3*x1b + 2*nf*x1b - 2*nc^2*nf*x1b - 12*nc^3*x1b^2 - 
     3*nf*x1b^2 + 3*nc^2*nf*x1b^2 + nf*x1b^3 - nc^2*nf*x1b^3 + 4*nc^3*x1b^4)*
    del[x2b]*G[1, x1b]*Log[MH2/muf2]^2)/(8*nc*(-1 + x1b)*x1b) + 
  ((4*nc^3 + 8*nc^3*x2b + 2*nf*x2b - 2*nc^2*nf*x2b - 12*nc^3*x2b^2 - 
     3*nf*x2b^2 + 3*nc^2*nf*x2b^2 + nf*x2b^3 - nc^2*nf*x2b^3 + 4*nc^3*x2b^4)*
    del[x1b]*G[1, x2b]*Log[MH2/muf2]^2)/(8*nc*(-1 + x2b)*x2b) - 
  ((-134*nc^3 + 20*nc^2*nf - 6*nc^3*Pi^2 + 51*nc^3*x2b + 15*nf*x2b - 
     135*nc^2*nf*x2b + 18*nc^3*Pi^2*x2b + 83*nc^3*x2b^2 - 9*nf*x2b^2 + 
     109*nc^2*nf*x2b^2 - 12*nc^3*Pi^2*x2b^2 - 48*nc^3*x2b^3 - 12*nf*x2b^3 - 
     34*nc^2*nf*x2b^3 + 6*nc^3*Pi^2*x2b^3)*PlusD[x1b, 0])/
   (72*nc*(-1 + x2b)) + ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x2b + 15*nf*x2b - 
     27*nc^2*nf*x2b - 236*nc^3*x2b^2 - 15*nf*x2b^2 + 23*nc^2*nf*x2b^2 + 
     110*nc^3*x2b^3 + 4*nf*x2b^3 - 8*nc^2*nf*x2b^3)*G[0, x2b]*PlusD[x1b, 0])/
   (24*nc*(-1 + x2b)) - ((372*nc^3 + 38*nf - 30*nc^2*nf - 426*nc^3*x2b - 
     55*nf*x2b + 51*nc^2*nf*x2b + 200*nc^3*x2b^2 + 20*nf*x2b^2 - 
     20*nc^2*nf*x2b^2)*G[1, x2b]*PlusD[x1b, 0])/(24*nc) + 
  ((-22*nc^3 + 4*nc^2*nf + 44*nc^3*x2b - 50*nf*x2b + 42*nc^2*nf*x2b + 
     30*nc^3*x2b^2 + 99*nf*x2b^2 - 87*nc^2*nf*x2b^2 - 52*nc^3*x2b^3 - 
     69*nf*x2b^3 + 61*nc^2*nf*x2b^3 + 2*nc^3*x2b^4 + 16*nf*x2b^4 - 
     12*nc^2*nf*x2b^4)*G[2, x2b]*PlusD[x1b, 0])/(24*nc*(-1 + x2b)*x2b) - 
  (3*nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*G[0, 0, x2b]*PlusD[x1b, 0])/
   (-1 + x2b) + (2*nc^2*(1 - x2b + x2b^2)^2*G[0, 1, x2b]*PlusD[x1b, 0])/
   ((-1 + x2b)*x2b) + (nc^2*(1 - x2b + x2b^2)^2*G[0, 2, x2b]*PlusD[x1b, 0])/
   ((-1 + x2b)*x2b) + ((8*nc^3 + 2*nf*x2b - 2*nc^2*nf*x2b - 3*nf*x2b^2 + 
     3*nc^2*nf*x2b^2 - 8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 
     8*nc^3*x2b^4)*G[1, 0, x2b]*PlusD[x1b, 0])/(4*nc*(-1 + x2b)*x2b) - 
  ((4*nc^3 + 8*nc^3*x2b + 4*nf*x2b - 4*nc^2*nf*x2b - 4*nc^3*x2b^2 - 
     4*nf*x2b^2 + 4*nc^2*nf*x2b^2 - 8*nc^3*x2b^3 + nf*x2b^3 - nc^2*nf*x2b^3 + 
     4*nc^3*x2b^4)*G[1, 1, x2b]*PlusD[x1b, 0])/(4*nc*(-2 + x2b)*x2b) - 
  ((4*nc^3 + 8*nc^3*x2b + 2*nf*x2b - 2*nc^2*nf*x2b - 12*nc^3*x2b^2 - 
     3*nf*x2b^2 + 3*nc^2*nf*x2b^2 + nf*x2b^3 - nc^2*nf*x2b^3 + 4*nc^3*x2b^4)*
    G[1, 2, x2b]*PlusD[x1b, 0])/(4*nc*(-1 + x2b)*x2b) + 
  (nc^2*(1 - x2b + x2b^2)^2*G[2, 0, x2b]*PlusD[x1b, 0])/((-1 + x2b)*x2b) - 
  (2*nc^2*(-1 - 2*x2b + 5*x2b^2 - 4*x2b^3 + x2b^4)*G[2, 1, x2b]*
    PlusD[x1b, 0])/((-2 + x2b)*(-1 + x2b)*x2b) + 
  (nc^2*(1 - x2b + x2b^2)^2*G[2, 2, x2b]*PlusD[x1b, 0])/((-1 + x2b)*x2b) + 
  ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x2b + 15*nf*x2b - 27*nc^2*nf*x2b - 
     236*nc^3*x2b^2 - 15*nf*x2b^2 + 23*nc^2*nf*x2b^2 + 110*nc^3*x2b^3 + 
     4*nf*x2b^3 - 8*nc^2*nf*x2b^3)*Log[MH2/muf2]*PlusD[x1b, 0])/
   (24*nc*(-1 + x2b)) + (nc*(67*nc - 10*nf + 3*nc*Pi^2)*del[x2b]*
    Log[MH2/muf2]*PlusD[x1b, 0])/36 - 
  (3*nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*G[0, x2b]*Log[MH2/muf2]*
    PlusD[x1b, 0])/(-1 + x2b) + 
  ((4*nc^3 + 8*nc^3*x2b + 2*nf*x2b - 2*nc^2*nf*x2b - 12*nc^3*x2b^2 - 
     3*nf*x2b^2 + 3*nc^2*nf*x2b^2 + nf*x2b^3 - nc^2*nf*x2b^3 + 4*nc^3*x2b^4)*
    G[1, x2b]*Log[MH2/muf2]*PlusD[x1b, 0])/(4*nc*(-1 + x2b)*x2b) + 
  (nc^2*(1 - x2b + x2b^2)^2*G[2, x2b]*Log[MH2/muf2]*PlusD[x1b, 0])/
   ((-1 + x2b)*x2b) - (nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*Log[MH2/muf2]^2*
    PlusD[x1b, 0])/(-1 + x2b) - (nc*(11*nc - 2*nf)*del[x2b]*Log[MH2/muf2]^2*
    PlusD[x1b, 0])/24 + ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x2b + 15*nf*x2b - 
     27*nc^2*nf*x2b - 236*nc^3*x2b^2 - 15*nf*x2b^2 + 23*nc^2*nf*x2b^2 + 
     110*nc^3*x2b^3 + 4*nf*x2b^3 - 8*nc^2*nf*x2b^3)*PlusD[x1b, 1])/
   (24*nc*(-1 + x2b)) + (nc*(67*nc - 10*nf + 3*nc*Pi^2)*del[x2b]*
    PlusD[x1b, 1])/36 - (3*nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*G[0, x2b]*
    PlusD[x1b, 1])/(-1 + x2b) + 
  ((4*nc^3 + 8*nc^3*x2b + 2*nf*x2b - 2*nc^2*nf*x2b - 12*nc^3*x2b^2 - 
     3*nf*x2b^2 + 3*nc^2*nf*x2b^2 + nf*x2b^3 - nc^2*nf*x2b^3 + 4*nc^3*x2b^4)*
    G[1, x2b]*PlusD[x1b, 1])/(4*nc*(-1 + x2b)*x2b) + 
  (nc^2*(1 - x2b + x2b^2)^2*G[2, x2b]*PlusD[x1b, 1])/((-1 + x2b)*x2b) - 
  (3*nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*Log[MH2/muf2]*PlusD[x1b, 1])/
   (-1 + x2b) - (nc*(11*nc - 2*nf)*del[x2b]*Log[MH2/muf2]*PlusD[x1b, 1])/12 + 
  nc^2*del[x2b]*Log[MH2/muf2]^2*PlusD[x1b, 1] - 
  (3*nc^2*(-1 + 3*x2b - 2*x2b^2 + x2b^3)*PlusD[x1b, 2])/(2*(-1 + x2b)) - 
  (nc*(11*nc - 2*nf)*del[x2b]*PlusD[x1b, 2])/24 + 
  (3*nc^2*del[x2b]*Log[MH2/muf2]*PlusD[x1b, 2])/2 + 
  (nc^2*del[x2b]*PlusD[x1b, 3])/2 - 
  ((-134*nc^3 + 20*nc^2*nf - 6*nc^3*Pi^2 + 51*nc^3*x1b + 15*nf*x1b - 
     135*nc^2*nf*x1b + 18*nc^3*Pi^2*x1b + 83*nc^3*x1b^2 - 9*nf*x1b^2 + 
     109*nc^2*nf*x1b^2 - 12*nc^3*Pi^2*x1b^2 - 48*nc^3*x1b^3 - 12*nf*x1b^3 - 
     34*nc^2*nf*x1b^3 + 6*nc^3*Pi^2*x1b^3)*PlusD[x2b, 0])/
   (72*nc*(-1 + x1b)) + ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x1b + 15*nf*x1b - 
     27*nc^2*nf*x1b - 236*nc^3*x1b^2 - 15*nf*x1b^2 + 23*nc^2*nf*x1b^2 + 
     110*nc^3*x1b^3 + 4*nf*x1b^3 - 8*nc^2*nf*x1b^3)*G[0, x1b]*PlusD[x2b, 0])/
   (24*nc*(-1 + x1b)) - ((372*nc^3 + 38*nf - 30*nc^2*nf - 426*nc^3*x1b - 
     55*nf*x1b + 51*nc^2*nf*x1b + 200*nc^3*x1b^2 + 20*nf*x1b^2 - 
     20*nc^2*nf*x1b^2)*G[1, x1b]*PlusD[x2b, 0])/(24*nc) + 
  ((-22*nc^3 + 4*nc^2*nf + 44*nc^3*x1b - 50*nf*x1b + 42*nc^2*nf*x1b + 
     30*nc^3*x1b^2 + 99*nf*x1b^2 - 87*nc^2*nf*x1b^2 - 52*nc^3*x1b^3 - 
     69*nf*x1b^3 + 61*nc^2*nf*x1b^3 + 2*nc^3*x1b^4 + 16*nf*x1b^4 - 
     12*nc^2*nf*x1b^4)*G[2, x1b]*PlusD[x2b, 0])/(24*nc*(-1 + x1b)*x1b) - 
  (3*nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*G[0, 0, x1b]*PlusD[x2b, 0])/
   (-1 + x1b) + (2*nc^2*(1 - x1b + x1b^2)^2*G[0, 1, x1b]*PlusD[x2b, 0])/
   ((-1 + x1b)*x1b) + (nc^2*(1 - x1b + x1b^2)^2*G[0, 2, x1b]*PlusD[x2b, 0])/
   ((-1 + x1b)*x1b) + ((8*nc^3 + 2*nf*x1b - 2*nc^2*nf*x1b - 3*nf*x1b^2 + 
     3*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 
     8*nc^3*x1b^4)*G[1, 0, x1b]*PlusD[x2b, 0])/(4*nc*(-1 + x1b)*x1b) - 
  ((4*nc^3 + 8*nc^3*x1b + 4*nf*x1b - 4*nc^2*nf*x1b - 4*nc^3*x1b^2 - 
     4*nf*x1b^2 + 4*nc^2*nf*x1b^2 - 8*nc^3*x1b^3 + nf*x1b^3 - nc^2*nf*x1b^3 + 
     4*nc^3*x1b^4)*G[1, 1, x1b]*PlusD[x2b, 0])/(4*nc*(-2 + x1b)*x1b) - 
  ((4*nc^3 + 8*nc^3*x1b + 2*nf*x1b - 2*nc^2*nf*x1b - 12*nc^3*x1b^2 - 
     3*nf*x1b^2 + 3*nc^2*nf*x1b^2 + nf*x1b^3 - nc^2*nf*x1b^3 + 4*nc^3*x1b^4)*
    G[1, 2, x1b]*PlusD[x2b, 0])/(4*nc*(-1 + x1b)*x1b) + 
  (nc^2*(1 - x1b + x1b^2)^2*G[2, 0, x1b]*PlusD[x2b, 0])/((-1 + x1b)*x1b) - 
  (2*nc^2*(-1 - 2*x1b + 5*x1b^2 - 4*x1b^3 + x1b^4)*G[2, 1, x1b]*
    PlusD[x2b, 0])/((-2 + x1b)*(-1 + x1b)*x1b) + 
  (nc^2*(1 - x1b + x1b^2)^2*G[2, 2, x1b]*PlusD[x2b, 0])/((-1 + x1b)*x1b) + 
  ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x1b + 15*nf*x1b - 27*nc^2*nf*x1b - 
     236*nc^3*x1b^2 - 15*nf*x1b^2 + 23*nc^2*nf*x1b^2 + 110*nc^3*x1b^3 + 
     4*nf*x1b^3 - 8*nc^2*nf*x1b^3)*Log[MH2/muf2]*PlusD[x2b, 0])/
   (24*nc*(-1 + x1b)) + (nc*(67*nc - 10*nf + 3*nc*Pi^2)*del[x1b]*
    Log[MH2/muf2]*PlusD[x2b, 0])/36 - 
  (3*nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*G[0, x1b]*Log[MH2/muf2]*
    PlusD[x2b, 0])/(-1 + x1b) + 
  ((4*nc^3 + 8*nc^3*x1b + 2*nf*x1b - 2*nc^2*nf*x1b - 12*nc^3*x1b^2 - 
     3*nf*x1b^2 + 3*nc^2*nf*x1b^2 + nf*x1b^3 - nc^2*nf*x1b^3 + 4*nc^3*x1b^4)*
    G[1, x1b]*Log[MH2/muf2]*PlusD[x2b, 0])/(4*nc*(-1 + x1b)*x1b) + 
  (nc^2*(1 - x1b + x1b^2)^2*G[2, x1b]*Log[MH2/muf2]*PlusD[x2b, 0])/
   ((-1 + x1b)*x1b) - (nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*Log[MH2/muf2]^2*
    PlusD[x2b, 0])/(-1 + x1b) - (nc*(11*nc - 2*nf)*del[x1b]*Log[MH2/muf2]^2*
    PlusD[x2b, 0])/24 + (nc*(67*nc - 10*nf + 3*nc*Pi^2)*PlusD[x1b, 0]*
    PlusD[x2b, 0])/36 - (nc*(11*nc - 2*nf)*Log[MH2/muf2]*PlusD[x1b, 0]*
    PlusD[x2b, 0])/12 + nc^2*Log[MH2/muf2]^2*PlusD[x1b, 0]*PlusD[x2b, 0] - 
  (nc*(11*nc - 2*nf)*PlusD[x1b, 1]*PlusD[x2b, 0])/12 + 
  3*nc^2*Log[MH2/muf2]*PlusD[x1b, 1]*PlusD[x2b, 0] + 
  (3*nc^2*PlusD[x1b, 2]*PlusD[x2b, 0])/2 + 
  ((-22*nc^3 + 4*nc^2*nf + 258*nc^3*x1b + 15*nf*x1b - 27*nc^2*nf*x1b - 
     236*nc^3*x1b^2 - 15*nf*x1b^2 + 23*nc^2*nf*x1b^2 + 110*nc^3*x1b^3 + 
     4*nf*x1b^3 - 8*nc^2*nf*x1b^3)*PlusD[x2b, 1])/(24*nc*(-1 + x1b)) + 
  (nc*(67*nc - 10*nf + 3*nc*Pi^2)*del[x1b]*PlusD[x2b, 1])/36 - 
  (3*nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*G[0, x1b]*PlusD[x2b, 1])/
   (-1 + x1b) + ((4*nc^3 + 8*nc^3*x1b + 2*nf*x1b - 2*nc^2*nf*x1b - 
     12*nc^3*x1b^2 - 3*nf*x1b^2 + 3*nc^2*nf*x1b^2 + nf*x1b^3 - 
     nc^2*nf*x1b^3 + 4*nc^3*x1b^4)*G[1, x1b]*PlusD[x2b, 1])/
   (4*nc*(-1 + x1b)*x1b) + (nc^2*(1 - x1b + x1b^2)^2*G[2, x1b]*PlusD[x2b, 1])/
   ((-1 + x1b)*x1b) - (3*nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*Log[MH2/muf2]*
    PlusD[x2b, 1])/(-1 + x1b) - (nc*(11*nc - 2*nf)*del[x1b]*Log[MH2/muf2]*
    PlusD[x2b, 1])/12 + nc^2*del[x1b]*Log[MH2/muf2]^2*PlusD[x2b, 1] - 
  (nc*(11*nc - 2*nf)*PlusD[x1b, 0]*PlusD[x2b, 1])/12 + 
  3*nc^2*Log[MH2/muf2]*PlusD[x1b, 0]*PlusD[x2b, 1] + 
  3*nc^2*PlusD[x1b, 1]*PlusD[x2b, 1] - 
  (3*nc^2*(-1 + 3*x1b - 2*x1b^2 + x1b^3)*PlusD[x2b, 2])/(2*(-1 + x1b)) - 
  (nc*(11*nc - 2*nf)*del[x1b]*PlusD[x2b, 2])/24 + 
  (3*nc^2*del[x1b]*Log[MH2/muf2]*PlusD[x2b, 2])/2 + 
  (3*nc^2*PlusD[x1b, 0]*PlusD[x2b, 2])/2 + (nc^2*del[x1b]*PlusD[x2b, 3])/2 + 
  (nc*del[x2b]*PlusD[x1b, 0]*(-404*nc + 56*nf + 33*nc*Pi^2 - 6*nf*Pi^2 + 
     810*nc*Zeta[3]))/216 + (nc*del[x1b]*PlusD[x2b, 0]*
    (-404*nc + 56*nf + 33*nc*Pi^2 - 6*nf*Pi^2 + 810*nc*Zeta[3]))/216 - 
  (del[x1b]*del[x2b]*Log[MH2/muf2]*(36*nc^3 + 3*nf - 15*nc^2*nf + 
     11*nc^3*Pi^2 - 2*nc^2*nf*Pi^2 - 84*nc^3*Zeta[3]))/(24*nc) + 
  (del[x1b]*del[x2b]*(8370*nc^3 + 1005*nf - 3405*nc^2*nf + 1340*nc^3*Pi^2 - 
     200*nc^2*nf*Pi^2 + 126*nc^3*Pi^4 - 3960*nc^3*Zeta[3] - 720*nf*Zeta[3]))/
   (1440*nc) - (del[x2b]*(772*nc^3 - 76*nc^2*nf - 66*nc^3*Pi^2 + 
     12*nc^2*nf*Pi^2 - 6540*nc^3*x1b + 630*nf*x1b - 240*nc^2*nf*x1b + 
     774*nc^3*Pi^2*x1b + 45*nf*Pi^2*x1b - 81*nc^2*nf*Pi^2*x1b + 
     4724*nc^3*x1b^2 - 1206*nf*x1b^2 + 1024*nc^2*nf*x1b^2 - 
     708*nc^3*Pi^2*x1b^2 - 45*nf*Pi^2*x1b^2 + 69*nc^2*nf*Pi^2*x1b^2 - 
     2308*nc^3*x1b^3 + 594*nf*x1b^3 - 484*nc^2*nf*x1b^3 + 
     330*nc^3*Pi^2*x1b^3 + 12*nf*Pi^2*x1b^3 - 24*nc^2*nf*Pi^2*x1b^3 - 
     1620*nc^3*Zeta[3] + 4860*nc^3*x1b*Zeta[3] - 3240*nc^3*x1b^2*Zeta[3] + 
     1620*nc^3*x1b^3*Zeta[3]))/(432*nc*(-1 + x1b)) - 
  (del[x1b]*(772*nc^3 - 76*nc^2*nf - 66*nc^3*Pi^2 + 12*nc^2*nf*Pi^2 - 
     6540*nc^3*x2b + 630*nf*x2b - 240*nc^2*nf*x2b + 774*nc^3*Pi^2*x2b + 
     45*nf*Pi^2*x2b - 81*nc^2*nf*Pi^2*x2b + 4724*nc^3*x2b^2 - 1206*nf*x2b^2 + 
     1024*nc^2*nf*x2b^2 - 708*nc^3*Pi^2*x2b^2 - 45*nf*Pi^2*x2b^2 + 
     69*nc^2*nf*Pi^2*x2b^2 - 2308*nc^3*x2b^3 + 594*nf*x2b^3 - 
     484*nc^2*nf*x2b^3 + 330*nc^3*Pi^2*x2b^3 + 12*nf*Pi^2*x2b^3 - 
     24*nc^2*nf*Pi^2*x2b^3 - 1620*nc^3*Zeta[3] + 4860*nc^3*x2b*Zeta[3] - 
     3240*nc^3*x2b^2*Zeta[3] + 1620*nc^3*x2b^3*Zeta[3]))/(432*nc*(-1 + x2b)), 
 ((-1 + nc)*(1 + nc)*(-36 - 182*nc^2 + 32*nc*nf - 6*Pi^2 - 12*nc^2*Pi^2 + 
     225*x1b + 807*nc^2*x1b - 24*nc*nf*x1b - 45*x1b^2 - 581*nc^2*x1b^2 + 
     32*nc*nf*x1b^2 - 6*Pi^2*x1b^2 - 12*nc^2*Pi^2*x1b^2 + 176*nc^2*x1b^3)*
    del[x2b]*G[0, x1b])/(288*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-198 - 1510*nc^2 + 6*Pi^2 + 162*nc^2*Pi^2 + 27*x1b + 
     2313*nc^2*x1b - 144*nc^2*Pi^2*x1b + 171*x1b^2 - 1155*nc^2*x1b^2 - 
     6*Pi^2*x1b^2 + 78*nc^2*Pi^2*x1b^2 + 352*nc^2*x1b^3)*del[x2b]*G[1, x1b])/
   (576*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(9 - 1889*nc^2 + 40*nc*nf - 
     6*Pi^2 - 36*nc^2*Pi^2 + 189*x1b + 1815*nc^2*x1b - 198*x1b^2 - 
     1066*nc^2*x1b^2 + 40*nc*nf*x1b^2 - 6*Pi^2*x1b^2 - 36*nc^2*Pi^2*x1b^2 + 
     176*nc^2*x1b^3)*del[x2b]*G[2, x1b])/(288*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(-12 - 17*nc^2 + 2*nc*nf + 3*x1b + 117*nc^2*x1b - 
     18*x1b^2 - 41*nc^2*x1b^2 + 2*nc*nf*x1b^2 + 8*nc^2*x1b^3)*del[x2b]*
    G[0, 0, x1b])/(48*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-9 - 3*nc^2 - 6*x1b + 198*nc^2*x1b - 21*x1b^2 - 
     51*nc^2*x1b^2 + 16*nc^2*x1b^3)*del[x2b]*G[0, 1, x1b])/
   (96*nc^2*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(-1 + x1b)*del[x2b]*
    G[0, 2, x1b])/4 - ((-1 + nc)*(1 + nc)*(27 + 365*nc^2 - 39*x1b - 
     145*nc^2*x1b + 32*nc^2*x1b^2)*del[x2b]*G[1, 0, x1b])/(96*nc^2) + 
  ((-1 + nc)*(1 + nc)*(21 + 479*nc^2 - 57*x1b - 139*nc^2*x1b + 32*nc^2*x1b^2)*
    del[x2b]*G[1, 1, x1b])/(192*nc^2) + 
  ((-1 + nc)*(1 + nc)*(39 + 245*nc^2 - 15*x1b - 109*nc^2*x1b + 32*nc^2*x1b^2)*
    del[x2b]*G[1, 2, x1b])/(96*nc^2) - 
  ((-1 + nc)*(1 + nc)*(-21 - 203*nc^2 - 18*x1b + 186*nc^2*x1b + 3*x1b^2 - 
     63*nc^2*x1b^2 + 16*nc^2*x1b^3)*del[x2b]*G[2, 0, x1b])/
   (96*nc^2*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(-21 - 535*nc^2 - 18*x1b + 
     450*nc^2*x1b + 3*x1b^2 - 147*nc^2*x1b^2 + 32*nc^2*x1b^3)*del[x2b]*
    G[2, 1, x1b])/(96*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(9 + 13*nc^2 - 4*nc*nf)*(1 + x1b^2)*del[x2b]*
    G[2, 2, x1b])/(48*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 11*nc^2)*(1 + x1b^2)*del[x2b]*G[0, 0, 0, x1b])/
   (16*nc^2*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(-1 + 2*nc)*(1 + 2*nc)*
    (1 + x1b^2)*del[x2b]*G[0, 0, 1, x1b])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*G[0, 0, 2, x1b])/(8*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(-1 + 2*nc)*(1 + 2*nc)*(1 + x1b^2)*del[x2b]*
    G[0, 1, 0, x1b])/(8*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 2*nc^2)*(1 + x1b^2)*del[x2b]*G[0, 1, 1, x1b])/
   (8*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*
    G[0, 1, 2, x1b])/(4*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*G[0, 2, 0, x1b])/(4*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*G[0, 2, 1, x1b])/(4*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 29*nc^2 - 24*nc^2*x1b - x1b^2 + 15*nc^2*x1b^2)*
    del[x2b]*G[1, 0, 0, x1b])/(16*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x1b - x1b^2 + 13*nc^2*x1b^2)*
    del[x2b]*G[1, 0, 1, x1b])/(16*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*G[1, 0, 2, x1b])/(8*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x1b + 5*nc^2*x1b)*del[x2b]*
    G[1, 1, 0, x1b])/(16*nc^2) + 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x1b + 5*nc^2*x1b)*del[x2b]*
    G[1, 1, 1, x1b])/(32*nc^2) + 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x1b + 5*nc^2*x1b)*del[x2b]*
    G[1, 1, 2, x1b])/(16*nc^2) - ((-1 + nc)*(1 + nc)*(5 - 4*x1b + x1b^2)*
    del[x2b]*G[1, 3/2, 1, x1b])/(4*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(5 - 4*x1b + x1b^2)*del[x2b]*G[1, 3/2, 2, x1b])/
   (8*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x1b - x1b^2 + 
     13*nc^2*x1b^2)*del[x2b]*G[1, 2, 0, x1b])/(16*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 59*nc^2 - 48*nc^2*x1b - x1b^2 + 21*nc^2*x1b^2)*
    del[x2b]*G[1, 2, 1, x1b])/(16*nc^2*(-1 + x1b)) - 
  (3*(-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*G[1, 2, 2, x1b])/
   (8*(-1 + x1b)) + ((-1 + nc)^2*(1 + nc)^2*(1 + x1b^2)*del[x2b]*
    G[2, 0, 0, x1b])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + nc^2)*(1 + x1b^2)*del[x2b]*G[2, 0, 1, x1b])/
   (8*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*
    G[2, 0, 2, x1b])/(8*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 13*nc^2 - 8*nc^2*x1b - x1b^2 + 5*nc^2*x1b^2)*
    del[x2b]*G[2, 1, 0, x1b])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(-1 + 6*nc^2 - 4*nc^2*x1b - x1b^2 + 2*nc^2*x1b^2)*
    del[x2b]*G[2, 1, 1, x1b])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(5 - 4*x1b + x1b^2)*del[x2b]*G[2, 1, 2, x1b])/
   (4*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(5 - 4*x1b + x1b^2)*del[x2b]*
    G[2, 3/2, 1, x1b])/(4*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(5 - 4*x1b + x1b^2)*del[x2b]*G[2, 3/2, 2, x1b])/
   (8*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*G[2, 2, 0, x1b])/
   (4*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(7 - 4*x1b + 3*x1b^2)*del[x2b]*
    G[2, 2, 1, x1b])/(4*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + nc^2)*(1 + x1b^2)*del[x2b]*G[2, 2, 2, x1b])/
   (8*nc^2*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(-81 - 223*nc^2 + 40*nc*nf - 
     6*Pi^2 - 12*nc^2*Pi^2 + 171*x1b + 729*nc^2*x1b - 90*x1b^2 - 
     622*nc^2*x1b^2 + 40*nc*nf*x1b^2 - 6*Pi^2*x1b^2 - 12*nc^2*Pi^2*x1b^2 + 
     176*nc^2*x1b^3)*del[x2b]*Log[MH2/muf2])/(288*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(-9 - 15*nc^2 - 6*x1b + 222*nc^2*x1b - 21*x1b^2 - 
     63*nc^2*x1b^2 + 16*nc^2*x1b^3)*del[x2b]*G[0, x1b]*Log[MH2/muf2])/
   (96*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(27 + 353*nc^2 - 39*x1b - 
     133*nc^2*x1b + 32*nc^2*x1b^2)*del[x2b]*G[1, x1b]*Log[MH2/muf2])/
   (96*nc^2) - ((-1 + nc)*(1 + nc)*(-3 - 177*nc^2 - 8*nc*nf - 18*x1b + 
     186*nc^2*x1b + 21*x1b^2 - 37*nc^2*x1b^2 - 8*nc*nf*x1b^2 + 16*nc^2*x1b^3)*
    del[x2b]*G[2, x1b]*Log[MH2/muf2])/(96*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x1b^2)*del[x2b]*G[0, 0, x1b]*
    Log[MH2/muf2])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(-1 + 3*nc^2)*(1 + x1b^2)*del[x2b]*G[0, 1, x1b]*
    Log[MH2/muf2])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*del[x2b]*G[0, 2, x1b]*Log[MH2/muf2])/
   (4*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x1b - x1b^2 + 
     13*nc^2*x1b^2)*del[x2b]*G[1, 0, x1b]*Log[MH2/muf2])/
   (16*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x1b + 
     5*nc^2*x1b)*del[x2b]*G[1, 1, x1b]*Log[MH2/muf2])/(16*nc^2) - 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x1b - x1b^2 + 9*nc^2*x1b^2)*
    del[x2b]*G[1, 2, x1b]*Log[MH2/muf2])/(16*nc^2*(-1 + x1b)) + 
  ((-1 + nc)^2*(1 + nc)^2*(1 + x1b^2)*del[x2b]*G[2, 0, x1b]*Log[MH2/muf2])/
   (8*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(-1 + 11*nc^2 - 8*nc^2*x1b - 
     x1b^2 + 3*nc^2*x1b^2)*del[x2b]*G[2, 1, x1b]*Log[MH2/muf2])/
   (8*nc^2*(-1 + x1b)) + ((-1 + nc)^2*(1 + nc)^2*(1 + x1b^2)*del[x2b]*
    G[2, 2, x1b]*Log[MH2/muf2])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(9 + 35*nc^2 - 8*nc*nf - 6*x1b + 174*nc^2*x1b - 
     3*x1b^2 - 13*nc^2*x1b^2 - 8*nc*nf*x1b^2 + 16*nc^2*x1b^3)*del[x2b]*
    Log[MH2/muf2]^2)/(192*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 3*nc^2)*(1 + x1b^2)*del[x2b]*G[0, x1b]*
    Log[MH2/muf2]^2)/(16*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x1b - x1b^2 + 9*nc^2*x1b^2)*
    del[x2b]*G[1, x1b]*Log[MH2/muf2]^2)/(32*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(-81 - 223*nc^2 + 40*nc*nf - 6*Pi^2 - 12*nc^2*Pi^2 + 
     171*x1b + 729*nc^2*x1b - 90*x1b^2 - 622*nc^2*x1b^2 + 40*nc*nf*x1b^2 - 
     6*Pi^2*x1b^2 - 12*nc^2*Pi^2*x1b^2 + 176*nc^2*x1b^3)*PlusD[x2b, 0])/
   (288*nc^2*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(-9 - 15*nc^2 - 6*x1b + 
     222*nc^2*x1b - 21*x1b^2 - 63*nc^2*x1b^2 + 16*nc^2*x1b^3)*G[0, x1b]*
    PlusD[x2b, 0])/(96*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(27 + 353*nc^2 - 39*x1b - 133*nc^2*x1b + 32*nc^2*x1b^2)*
    G[1, x1b]*PlusD[x2b, 0])/(96*nc^2) - 
  ((-1 + nc)*(1 + nc)*(-3 - 177*nc^2 - 8*nc*nf - 18*x1b + 186*nc^2*x1b + 
     21*x1b^2 - 37*nc^2*x1b^2 - 8*nc*nf*x1b^2 + 16*nc^2*x1b^3)*G[2, x1b]*
    PlusD[x2b, 0])/(96*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x1b^2)*G[0, 0, x1b]*PlusD[x2b, 0])/
   (8*nc^2*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(-1 + 3*nc^2)*(1 + x1b^2)*
    G[0, 1, x1b]*PlusD[x2b, 0])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*G[0, 2, x1b]*PlusD[x2b, 0])/
   (4*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x1b - x1b^2 + 
     13*nc^2*x1b^2)*G[1, 0, x1b]*PlusD[x2b, 0])/(16*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x1b + 5*nc^2*x1b)*G[1, 1, x1b]*
    PlusD[x2b, 0])/(16*nc^2) - 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x1b - x1b^2 + 9*nc^2*x1b^2)*
    G[1, 2, x1b]*PlusD[x2b, 0])/(16*nc^2*(-1 + x1b)) + 
  ((-1 + nc)^2*(1 + nc)^2*(1 + x1b^2)*G[2, 0, x1b]*PlusD[x2b, 0])/
   (8*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(-1 + 11*nc^2 - 8*nc^2*x1b - 
     x1b^2 + 3*nc^2*x1b^2)*G[2, 1, x1b]*PlusD[x2b, 0])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)^2*(1 + nc)^2*(1 + x1b^2)*G[2, 2, x1b]*PlusD[x2b, 0])/
   (8*nc^2*(-1 + x1b)) + ((-1 + nc)*(1 + nc)*(9 + 11*nc^2 - 8*nc*nf - 6*x1b + 
     222*nc^2*x1b - 3*x1b^2 - 37*nc^2*x1b^2 - 8*nc*nf*x1b^2 + 16*nc^2*x1b^3)*
    Log[MH2/muf2]*PlusD[x2b, 0])/(96*nc^2*(-1 + x1b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x1b^2)*G[0, x1b]*Log[MH2/muf2]*
    PlusD[x2b, 0])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x1b - x1b^2 + 9*nc^2*x1b^2)*
    G[1, x1b]*Log[MH2/muf2]*PlusD[x2b, 0])/(16*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*G[2, x1b]*Log[MH2/muf2]*PlusD[x2b, 0])/
   (4*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(1 + x1b^2)*Log[MH2/muf2]^2*
    PlusD[x2b, 0])/(4*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(9 + 11*nc^2 - 8*nc*nf - 6*x1b + 222*nc^2*x1b - 
     3*x1b^2 - 37*nc^2*x1b^2 - 8*nc*nf*x1b^2 + 16*nc^2*x1b^3)*PlusD[x2b, 1])/
   (96*nc^2*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x1b^2)*
    G[0, x1b]*PlusD[x2b, 1])/(8*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x1b - x1b^2 + 9*nc^2*x1b^2)*
    G[1, x1b]*PlusD[x2b, 1])/(16*nc^2*(-1 + x1b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x1b^2)*G[2, x1b]*PlusD[x2b, 1])/(4*(-1 + x1b)) - 
  (3*(-1 + nc)*(1 + nc)*(1 + x1b^2)*Log[MH2/muf2]*PlusD[x2b, 1])/
   (4*(-1 + x1b)) - (3*(-1 + nc)*(1 + nc)*(1 + x1b^2)*PlusD[x2b, 2])/
   (8*(-1 + x1b)) - ((-1 + nc)*(1 + nc)*del[x2b]*
    (-243 - 677*nc^2 + 104*nc*nf - 27*Pi^2 + 225*nc^2*Pi^2 + 648*x1b - 
     6816*nc^2*x1b + 240*nc*nf*x1b - 18*Pi^2*x1b + 126*nc^2*Pi^2*x1b - 
     405*x1b^2 + 2005*nc^2*x1b^2 + 104*nc*nf*x1b^2 - 63*Pi^2*x1b^2 + 
     81*nc^2*Pi^2*x1b^2 - 1216*nc^2*x1b^3 + 48*nc^2*Pi^2*x1b^3 + 
     1620*nc^2*Zeta[3] + 1620*nc^2*x1b^2*Zeta[3]))/(1728*nc^2*(-1 + x1b)), 
 ((-1 + nc)*(1 + nc)*(-36 - 182*nc^2 + 32*nc*nf - 6*Pi^2 - 12*nc^2*Pi^2 + 
     225*x2b + 807*nc^2*x2b - 24*nc*nf*x2b - 45*x2b^2 - 581*nc^2*x2b^2 + 
     32*nc*nf*x2b^2 - 6*Pi^2*x2b^2 - 12*nc^2*Pi^2*x2b^2 + 176*nc^2*x2b^3)*
    del[x1b]*G[0, x2b])/(288*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-198 - 1510*nc^2 + 6*Pi^2 + 162*nc^2*Pi^2 + 27*x2b + 
     2313*nc^2*x2b - 144*nc^2*Pi^2*x2b + 171*x2b^2 - 1155*nc^2*x2b^2 - 
     6*Pi^2*x2b^2 + 78*nc^2*Pi^2*x2b^2 + 352*nc^2*x2b^3)*del[x1b]*G[1, x2b])/
   (576*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(9 - 1889*nc^2 + 40*nc*nf - 
     6*Pi^2 - 36*nc^2*Pi^2 + 189*x2b + 1815*nc^2*x2b - 198*x2b^2 - 
     1066*nc^2*x2b^2 + 40*nc*nf*x2b^2 - 6*Pi^2*x2b^2 - 36*nc^2*Pi^2*x2b^2 + 
     176*nc^2*x2b^3)*del[x1b]*G[2, x2b])/(288*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(-12 - 17*nc^2 + 2*nc*nf + 3*x2b + 117*nc^2*x2b - 
     18*x2b^2 - 41*nc^2*x2b^2 + 2*nc*nf*x2b^2 + 8*nc^2*x2b^3)*del[x1b]*
    G[0, 0, x2b])/(48*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-9 - 3*nc^2 - 6*x2b + 198*nc^2*x2b - 21*x2b^2 - 
     51*nc^2*x2b^2 + 16*nc^2*x2b^3)*del[x1b]*G[0, 1, x2b])/
   (96*nc^2*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(-1 + x2b)*del[x1b]*
    G[0, 2, x2b])/4 - ((-1 + nc)*(1 + nc)*(27 + 365*nc^2 - 39*x2b - 
     145*nc^2*x2b + 32*nc^2*x2b^2)*del[x1b]*G[1, 0, x2b])/(96*nc^2) + 
  ((-1 + nc)*(1 + nc)*(21 + 479*nc^2 - 57*x2b - 139*nc^2*x2b + 32*nc^2*x2b^2)*
    del[x1b]*G[1, 1, x2b])/(192*nc^2) + 
  ((-1 + nc)*(1 + nc)*(39 + 245*nc^2 - 15*x2b - 109*nc^2*x2b + 32*nc^2*x2b^2)*
    del[x1b]*G[1, 2, x2b])/(96*nc^2) - 
  ((-1 + nc)*(1 + nc)*(-21 - 203*nc^2 - 18*x2b + 186*nc^2*x2b + 3*x2b^2 - 
     63*nc^2*x2b^2 + 16*nc^2*x2b^3)*del[x1b]*G[2, 0, x2b])/
   (96*nc^2*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(-21 - 535*nc^2 - 18*x2b + 
     450*nc^2*x2b + 3*x2b^2 - 147*nc^2*x2b^2 + 32*nc^2*x2b^3)*del[x1b]*
    G[2, 1, x2b])/(96*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(9 + 13*nc^2 - 4*nc*nf)*(1 + x2b^2)*del[x1b]*
    G[2, 2, x2b])/(48*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 11*nc^2)*(1 + x2b^2)*del[x1b]*G[0, 0, 0, x2b])/
   (16*nc^2*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(-1 + 2*nc)*(1 + 2*nc)*
    (1 + x2b^2)*del[x1b]*G[0, 0, 1, x2b])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*G[0, 0, 2, x2b])/(8*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(-1 + 2*nc)*(1 + 2*nc)*(1 + x2b^2)*del[x1b]*
    G[0, 1, 0, x2b])/(8*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 2*nc^2)*(1 + x2b^2)*del[x1b]*G[0, 1, 1, x2b])/
   (8*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*
    G[0, 1, 2, x2b])/(4*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*G[0, 2, 0, x2b])/(4*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*G[0, 2, 1, x2b])/(4*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 29*nc^2 - 24*nc^2*x2b - x2b^2 + 15*nc^2*x2b^2)*
    del[x1b]*G[1, 0, 0, x2b])/(16*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x2b - x2b^2 + 13*nc^2*x2b^2)*
    del[x1b]*G[1, 0, 1, x2b])/(16*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*G[1, 0, 2, x2b])/(8*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x2b + 5*nc^2*x2b)*del[x1b]*
    G[1, 1, 0, x2b])/(16*nc^2) + 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x2b + 5*nc^2*x2b)*del[x1b]*
    G[1, 1, 1, x2b])/(32*nc^2) + 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x2b + 5*nc^2*x2b)*del[x1b]*
    G[1, 1, 2, x2b])/(16*nc^2) - ((-1 + nc)*(1 + nc)*(5 - 4*x2b + x2b^2)*
    del[x1b]*G[1, 3/2, 1, x2b])/(4*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(5 - 4*x2b + x2b^2)*del[x1b]*G[1, 3/2, 2, x2b])/
   (8*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x2b - x2b^2 + 
     13*nc^2*x2b^2)*del[x1b]*G[1, 2, 0, x2b])/(16*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 59*nc^2 - 48*nc^2*x2b - x2b^2 + 21*nc^2*x2b^2)*
    del[x1b]*G[1, 2, 1, x2b])/(16*nc^2*(-1 + x2b)) - 
  (3*(-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*G[1, 2, 2, x2b])/
   (8*(-1 + x2b)) + ((-1 + nc)^2*(1 + nc)^2*(1 + x2b^2)*del[x1b]*
    G[2, 0, 0, x2b])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + nc^2)*(1 + x2b^2)*del[x1b]*G[2, 0, 1, x2b])/
   (8*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*
    G[2, 0, 2, x2b])/(8*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 13*nc^2 - 8*nc^2*x2b - x2b^2 + 5*nc^2*x2b^2)*
    del[x1b]*G[2, 1, 0, x2b])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(-1 + 6*nc^2 - 4*nc^2*x2b - x2b^2 + 2*nc^2*x2b^2)*
    del[x1b]*G[2, 1, 1, x2b])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(5 - 4*x2b + x2b^2)*del[x1b]*G[2, 1, 2, x2b])/
   (4*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(5 - 4*x2b + x2b^2)*del[x1b]*
    G[2, 3/2, 1, x2b])/(4*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(5 - 4*x2b + x2b^2)*del[x1b]*G[2, 3/2, 2, x2b])/
   (8*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*G[2, 2, 0, x2b])/
   (4*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(7 - 4*x2b + 3*x2b^2)*del[x1b]*
    G[2, 2, 1, x2b])/(4*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + nc^2)*(1 + x2b^2)*del[x1b]*G[2, 2, 2, x2b])/
   (8*nc^2*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(-81 - 223*nc^2 + 40*nc*nf - 
     6*Pi^2 - 12*nc^2*Pi^2 + 171*x2b + 729*nc^2*x2b - 90*x2b^2 - 
     622*nc^2*x2b^2 + 40*nc*nf*x2b^2 - 6*Pi^2*x2b^2 - 12*nc^2*Pi^2*x2b^2 + 
     176*nc^2*x2b^3)*del[x1b]*Log[MH2/muf2])/(288*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(-9 - 15*nc^2 - 6*x2b + 222*nc^2*x2b - 21*x2b^2 - 
     63*nc^2*x2b^2 + 16*nc^2*x2b^3)*del[x1b]*G[0, x2b]*Log[MH2/muf2])/
   (96*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(27 + 353*nc^2 - 39*x2b - 
     133*nc^2*x2b + 32*nc^2*x2b^2)*del[x1b]*G[1, x2b]*Log[MH2/muf2])/
   (96*nc^2) - ((-1 + nc)*(1 + nc)*(-3 - 177*nc^2 - 8*nc*nf - 18*x2b + 
     186*nc^2*x2b + 21*x2b^2 - 37*nc^2*x2b^2 - 8*nc*nf*x2b^2 + 16*nc^2*x2b^3)*
    del[x1b]*G[2, x2b]*Log[MH2/muf2])/(96*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x2b^2)*del[x1b]*G[0, 0, x2b]*
    Log[MH2/muf2])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(-1 + 3*nc^2)*(1 + x2b^2)*del[x1b]*G[0, 1, x2b]*
    Log[MH2/muf2])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*del[x1b]*G[0, 2, x2b]*Log[MH2/muf2])/
   (4*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x2b - x2b^2 + 
     13*nc^2*x2b^2)*del[x1b]*G[1, 0, x2b]*Log[MH2/muf2])/
   (16*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x2b + 
     5*nc^2*x2b)*del[x1b]*G[1, 1, x2b]*Log[MH2/muf2])/(16*nc^2) - 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x2b - x2b^2 + 9*nc^2*x2b^2)*
    del[x1b]*G[1, 2, x2b]*Log[MH2/muf2])/(16*nc^2*(-1 + x2b)) + 
  ((-1 + nc)^2*(1 + nc)^2*(1 + x2b^2)*del[x1b]*G[2, 0, x2b]*Log[MH2/muf2])/
   (8*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(-1 + 11*nc^2 - 8*nc^2*x2b - 
     x2b^2 + 3*nc^2*x2b^2)*del[x1b]*G[2, 1, x2b]*Log[MH2/muf2])/
   (8*nc^2*(-1 + x2b)) + ((-1 + nc)^2*(1 + nc)^2*(1 + x2b^2)*del[x1b]*
    G[2, 2, x2b]*Log[MH2/muf2])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(9 + 35*nc^2 - 8*nc*nf - 6*x2b + 174*nc^2*x2b - 
     3*x2b^2 - 13*nc^2*x2b^2 - 8*nc*nf*x2b^2 + 16*nc^2*x2b^3)*del[x1b]*
    Log[MH2/muf2]^2)/(192*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 3*nc^2)*(1 + x2b^2)*del[x1b]*G[0, x2b]*
    Log[MH2/muf2]^2)/(16*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x2b - x2b^2 + 9*nc^2*x2b^2)*
    del[x1b]*G[1, x2b]*Log[MH2/muf2]^2)/(32*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(-81 - 223*nc^2 + 40*nc*nf - 6*Pi^2 - 12*nc^2*Pi^2 + 
     171*x2b + 729*nc^2*x2b - 90*x2b^2 - 622*nc^2*x2b^2 + 40*nc*nf*x2b^2 - 
     6*Pi^2*x2b^2 - 12*nc^2*Pi^2*x2b^2 + 176*nc^2*x2b^3)*PlusD[x1b, 0])/
   (288*nc^2*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(-9 - 15*nc^2 - 6*x2b + 
     222*nc^2*x2b - 21*x2b^2 - 63*nc^2*x2b^2 + 16*nc^2*x2b^3)*G[0, x2b]*
    PlusD[x1b, 0])/(96*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(27 + 353*nc^2 - 39*x2b - 133*nc^2*x2b + 32*nc^2*x2b^2)*
    G[1, x2b]*PlusD[x1b, 0])/(96*nc^2) - 
  ((-1 + nc)*(1 + nc)*(-3 - 177*nc^2 - 8*nc*nf - 18*x2b + 186*nc^2*x2b + 
     21*x2b^2 - 37*nc^2*x2b^2 - 8*nc*nf*x2b^2 + 16*nc^2*x2b^3)*G[2, x2b]*
    PlusD[x1b, 0])/(96*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x2b^2)*G[0, 0, x2b]*PlusD[x1b, 0])/
   (8*nc^2*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(-1 + 3*nc^2)*(1 + x2b^2)*
    G[0, 1, x2b]*PlusD[x1b, 0])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*G[0, 2, x2b]*PlusD[x1b, 0])/
   (4*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(1 + 27*nc^2 - 24*nc^2*x2b - x2b^2 + 
     13*nc^2*x2b^2)*G[1, 0, x2b]*PlusD[x1b, 0])/(16*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 - 11*nc^2 - x2b + 5*nc^2*x2b)*G[1, 1, x2b]*
    PlusD[x1b, 0])/(16*nc^2) - 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x2b - x2b^2 + 9*nc^2*x2b^2)*
    G[1, 2, x2b]*PlusD[x1b, 0])/(16*nc^2*(-1 + x2b)) + 
  ((-1 + nc)^2*(1 + nc)^2*(1 + x2b^2)*G[2, 0, x2b]*PlusD[x1b, 0])/
   (8*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(-1 + 11*nc^2 - 8*nc^2*x2b - 
     x2b^2 + 3*nc^2*x2b^2)*G[2, 1, x2b]*PlusD[x1b, 0])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)^2*(1 + nc)^2*(1 + x2b^2)*G[2, 2, x2b]*PlusD[x1b, 0])/
   (8*nc^2*(-1 + x2b)) + ((-1 + nc)*(1 + nc)*(9 + 11*nc^2 - 8*nc*nf - 6*x2b + 
     222*nc^2*x2b - 3*x2b^2 - 37*nc^2*x2b^2 - 8*nc*nf*x2b^2 + 16*nc^2*x2b^3)*
    Log[MH2/muf2]*PlusD[x1b, 0])/(96*nc^2*(-1 + x2b)) - 
  ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x2b^2)*G[0, x2b]*Log[MH2/muf2]*
    PlusD[x1b, 0])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x2b - x2b^2 + 9*nc^2*x2b^2)*
    G[1, x2b]*Log[MH2/muf2]*PlusD[x1b, 0])/(16*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*G[2, x2b]*Log[MH2/muf2]*PlusD[x1b, 0])/
   (4*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(1 + x2b^2)*Log[MH2/muf2]^2*
    PlusD[x1b, 0])/(4*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(9 + 11*nc^2 - 8*nc*nf - 6*x2b + 222*nc^2*x2b - 
     3*x2b^2 - 37*nc^2*x2b^2 - 8*nc*nf*x2b^2 + 16*nc^2*x2b^3)*PlusD[x1b, 1])/
   (96*nc^2*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*(-1 + 5*nc^2)*(1 + x2b^2)*
    G[0, x2b]*PlusD[x1b, 1])/(8*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + 23*nc^2 - 24*nc^2*x2b - x2b^2 + 9*nc^2*x2b^2)*
    G[1, x2b]*PlusD[x1b, 1])/(16*nc^2*(-1 + x2b)) + 
  ((-1 + nc)*(1 + nc)*(1 + x2b^2)*G[2, x2b]*PlusD[x1b, 1])/(4*(-1 + x2b)) - 
  (3*(-1 + nc)*(1 + nc)*(1 + x2b^2)*Log[MH2/muf2]*PlusD[x1b, 1])/
   (4*(-1 + x2b)) - (3*(-1 + nc)*(1 + nc)*(1 + x2b^2)*PlusD[x1b, 2])/
   (8*(-1 + x2b)) - ((-1 + nc)*(1 + nc)*del[x1b]*
    (-243 - 677*nc^2 + 104*nc*nf - 27*Pi^2 + 225*nc^2*Pi^2 + 648*x2b - 
     6816*nc^2*x2b + 240*nc*nf*x2b - 18*Pi^2*x2b + 126*nc^2*Pi^2*x2b - 
     405*x2b^2 + 2005*nc^2*x2b^2 + 104*nc*nf*x2b^2 - 63*Pi^2*x2b^2 + 
     81*nc^2*Pi^2*x2b^2 - 1216*nc^2*x2b^3 + 48*nc^2*Pi^2*x2b^3 + 
     1620*nc^2*Zeta[3] + 1620*nc^2*x2b^2*Zeta[3]))/(1728*nc^2*(-1 + x2b)), 0, 
 0, 0}

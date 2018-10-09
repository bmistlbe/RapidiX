(* Created with the Wolfram Language : www.wolfram.com *)
{G[2, x1b] -> -Log[2] + Log[2 - x1b], G[2, x2b] -> -Log[2] + Log[2 - x2b], 
 G[2, zb] -> -Log[2] + Log[2 - zb], G[2 - x1b, x2b] -> 
  -Log[2 - x1b] + Log[2 - x1b - x2b], G[-((2 - x1b)/(-1 + x1b)), x2b] -> 
  -Log[2 - x1b] + Log[2 - x1b - x2b + x1b*x2b], 
 G[2 - x2b, x1b] -> -Log[2 - x2b] + Log[2 - x1b - x2b], 
 G[-((2 - x2b)/(-1 + x2b)), x1b] -> -Log[2 - x2b] + 
   Log[2 - x1b - x2b + x1b*x2b], G[2, 2, x1b] -> 
  Log[2]^2/2 - Log[2]*Log[2 - x1b] + Log[2 - x1b]^2/2, 
 G[2, 2, x2b] -> Log[2]^2/2 - Log[2]*Log[2 - x2b] + Log[2 - x2b]^2/2, 
 G[2, 2, zb] -> Log[2]^2/2 - Log[2]*Log[2 - zb] + Log[2 - zb]^2/2, 
 G[2 - x1b, 2 - x1b, x2b] -> Log[2 - x1b]^2/2 - 
   Log[2 - x1b]*Log[2 - x1b - x2b] + Log[2 - x1b - x2b]^2/2, 
 G[2 - x2b, 2 - x2b, x1b] -> Log[2 - x2b]^2/2 - 
   Log[2 - x2b]*Log[2 - x1b - x2b] + Log[2 - x1b - x2b]^2/2, 
 G[2, 2, 2, x1b] -> -Log[2]^3/6 + (Log[2]^2*Log[2 - x1b])/2 - 
   (Log[2]*Log[2 - x1b]^2)/2 + Log[2 - x1b]^3/6, 
 G[2, 2, 2, x2b] -> -Log[2]^3/6 + (Log[2]^2*Log[2 - x2b])/2 - 
   (Log[2]*Log[2 - x2b]^2)/2 + Log[2 - x2b]^3/6, 
 G[2, 2, 2, zb] -> -Log[2]^3/6 + (Log[2]^2*Log[2 - zb])/2 - 
   (Log[2]*Log[2 - zb]^2)/2 + Log[2 - zb]^3/6, 
 G[2, 2, 2, 2, x1b] -> Log[2]^4/24 - (Log[2]^3*Log[2 - x1b])/6 + 
   (Log[2]^2*Log[2 - x1b]^2)/4 - (Log[2]*Log[2 - x1b]^3)/6 + 
   Log[2 - x1b]^4/24, G[2, 2, 2, 2, x2b] -> 
  Log[2]^4/24 - (Log[2]^3*Log[2 - x2b])/6 + (Log[2]^2*Log[2 - x2b]^2)/4 - 
   (Log[2]*Log[2 - x2b]^3)/6 + Log[2 - x2b]^4/24, 
 G[2, 2, 2, 2, zb] -> Log[2]^4/24 - (Log[2]^3*Log[2 - zb])/6 + 
   (Log[2]^2*Log[2 - zb]^2)/4 - (Log[2]*Log[2 - zb]^3)/6 + Log[2 - zb]^4/24}

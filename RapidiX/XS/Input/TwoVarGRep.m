(* Created with the Wolfram Language : www.wolfram.com *)
{G[0, 2 - x1b, x2b] -> G[0, 2, x2b] - G[2, 2 - x2b, x1b] - Log[2]^2/2 + 
   Log[2 - x1b]^2/2 + Log[2]*Log[2 - x2b] - Log[2 - x1b]*Log[2 - x2b], 
 G[1, 2 - x1b, x2b] -> G[1, 2, x1b] + G[1, 2, x2b] - G[1, 2 - x2b, x1b] + 
   Log[2]*Log[1 - x1b] + Log[2]*Log[1 - x2b] + Log[1 - x1b]*Log[1 - x2b] - 
   Log[2 - x1b]*Log[1 - x2b] - Log[1 - x1b]*Log[2 - x2b], 
 G[2, 2 - x1b, x2b] -> G[0, 2, x1b] - G[0, 2 - x2b, x1b] - Log[2]^2/2 + 
   Log[2]*Log[2 - x1b] - Log[2 - x1b]*Log[2 - x2b] + Log[2 - x2b]^2/2, 
 G[2 - x1b, 1, x2b] -> -G[1, 2, x1b] + G[1, 2 - x2b, x1b] + G[2, 1, x2b] - 
   Log[2]*Log[1 - x1b] - Log[1 - x1b]*Log[1 - x2b] + 
   Log[1 - x1b]*Log[2 - x2b] - Log[1 - x2b]*Log[2 - x2b] + 
   Log[1 - x2b]*Log[2 - x1b - x2b], G[2 - x1b, 2, x2b] -> 
  -G[0, 2, x1b] + G[0, 2 - x2b, x1b] + Log[2]^2/2 - Log[2 - x2b]^2/2 - 
   Log[2]*Log[2 - x1b - x2b] + Log[2 - x2b]*Log[2 - x1b - x2b], 
 G[0, 2 - x2b, x1b] -> N3LOTwoVarG1, G[1, 2 - x2b, x1b] -> N3LOTwoVarG2, 
 G[2, 2 - x2b, x1b] -> N3LOTwoVarG3, G[2 - x2b, 1, x1b] -> N3LOTwoVarG4, 
 G[2 - x2b, 2, x1b] -> N3LOTwoVarG5}

library IEEE;
use IEEE.STD_LOGIC_1164.all;
 
entity mux_4to1 is
 port(
 
     A,B,C,D : in STD_LOGIC_vector(7 downto 0);
     S: in STD_LOGIC_vector(1 downto 0);
     Z: out STD_LOGIC_vector(7 downto 0)
  );
end mux_4to1;
 
architecture bhv of mux_4to1 is
begin
process (A,B,C,D,S) is
begin
  if (S = "00") then
      Z <= A;
  elsif (S = "01") then
      Z <= B;
  elsif (S = "10") then
      Z <= C;
  else
      Z <= D;
  end if;
 
end process;
end bhv;
----UNIVERSIDADE FEDERAL DE SANTA CATARINA - UFSC
--CENTRO TECNOLOGICO - CTC
--DEPARTAMENTO DE ENGENHARIA ELETRICA E ELETRONICA
--EEL7120 - INTRODUCAO A MICROELETRONICA
--SUM SUB INCREMENT DECREMENT
--GUSTAVO SIMAS E PEDRO PAULO SANTOS GOMES

library IEEE;
use IEEE.Std_Logic_1164.all;

entity usertop is
port(CLOCK_50: in std_logic;
CLK_500Hz:in std_logic;
RKEY: in std_logic_vector(3 downto 0);
KEY: in std_logic_vector(3 downto 0);
RSW: in std_logic_vector(17 downto 0);
SW: in std_logic_vector(17 downto 0);
LEDR: out std_logic_vector(17 downto 0);
HEX0,HEX1,HEX2,HEX3,HEX4,HEX5,HEX6,HEX7: out std_logic_vector(6 downto 0)
);
end usertop;

architecture usertop_arch of usertop is
signal R_sig: std_logic_vector(3 downto 0);
signal C_sig: std_logic_vector(3 downto 0);
signal Sum_sig: std_logic_vector(3 downto 0);

component fulladder is
port (A: in std_logic;
B: in std_logic;
Cin: in std_logic;
Sum: out std_logic;
Cout: out std_logic
);
end component;

component mode is
port (I0: in std_logic;
I1: in std_logic;
I2: in std_logic;
R: out std_logic
);
end component;

begin

MOD1: mode port map (SW(4),SW(8),SW(9),R_sig(0));
FA1: fulladder port map (SW(0),R_sig(0),SW(8),Sum_sig(0),C_sig(0));
LEDR(0) <= Sum_sig(0);

MOD2: mode port map (SW(5),SW(8),SW(9),R_sig(1));
FA2: fulladder port map (SW(1),R_sig(1),C_sig(0),Sum_sig(1),C_sig(1));
LEDR(1) <= Sum_sig(1);

MOD3: mode port map (SW(6),SW(8),SW(9),R_sig(2));
FA3: fulladder port map (SW(2),R_sig(2),C_sig(1),Sum_sig(2),C_sig(2));
LEDR(2) <= Sum_sig(2);

MOD4: mode port map (SW(7),SW(8),SW(9),R_sig(3));
FA4: fulladder port map (SW(3),R_sig(3),C_sig(2),Sum_sig(3),C_sig(3));
LEDR(3) <= Sum_sig(3);

LEDR(9) <= C_sig(2) XOR C_sig(3);

end usertop_arch;

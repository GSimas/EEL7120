----UNIVERSIDADE FEDERAL DE SANTA CATARINA - UFSC
--CENTRO TECNOLOGICO - CTC
--DEPARTAMENTO DE ENGENHARIA ELETRICA E ELETRONICA
--EEL7120 - INTRODUCAO A MICROELETRONICA
--SUM SUB INCREMENT DECREMENT
--GUSTAVO SIMAS E PEDRO PAULO SANTOS GOMES

library IEEE;
use IEEE.Std_Logic_1164.all;

entity Sum_Sub is
port (A: in std_logic_vector(3 downto 0);
B: in std_logic_vector(3 downto 0);
C: in std_logic_vector(1 downto 0);
S: out std_logic_vector(3 downto 0);
Overflow: out std_logic);
end Sum_Sub;

architecture Sum_Sub_arch of Sum_Sub is
signal R_sig: std_logic_vector(3 downto 0);
signal C_sig: std_logic_vector(3 downto 0);

component fulladder is
port (A: in std_logic;
B: in std_logic;
Cin: in std_logic;
Sum: out std_logic;
Cout: out std_logic);
end component;

component mode is
port (I0: in std_logic;
I1: in std_logic;
I2: in std_logic;
R: out std_logic
);
end component;

begin

MOD1: mode port map (B(0),C(0),C(1),R_sig(0));
FA1: fulladder port map (A(0),R_sig(0),C(0),S(0),C_sig(0));

MOD2: mode port map (B(1),C(0),C(1),R_sig(1));
FA2: fulladder port map (A(1),R_sig(1),C_sig(0),S(1),C_sig(1));

MOD3: mode port map (B(2),C(0),C(1),R_sig(2));
FA3: fulladder port map (A(2),R_sig(2),C_sig(1),S(2),C_sig(2));

MOD4: mode port map (B(3),C(0),C(1),R_sig(3));
FA4: fulladder port map (A(3),R_sig(3),C_sig(2),S(3),C_sig(3));

Overflow <= C_sig(2) XOR C_sig(3);

end Sum_Sub_arch;
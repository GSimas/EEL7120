--UNIVERSIDADE FEDERAL DE SANTA CATARINA - UFSC
--CENTRO TECNOLOGICO - CTC
--DEPARTAMENTO DE ENGENHARIA ELETRICA E ELETRONICA
--EEL7120 - INTRODUCAO A MICROELETRONICA

--PROJETO 5 APARTADO A

--GUSTAVO SIMAS E PEDRO PAULO SANTOS GOMES

library IEEE;
use IEEE.Std_Logic_1164.all;

entity ProjetoV5 is
port (A: in std_logic_vector(7 downto 0);
C: in std_logic_vector(1 downto 0);
F: out std_logic_vector(7 downto 0));
end ProjetoV5;

architecture ProjetoV5_arch of ProjetoV5 is
signal B_sig: std_logic_vector(7 downto 0);
signal Overflow_sig: std_logic;

component Sum_Sub is
port (A: in std_logic_vector(7 downto 0);
B: in std_logic_vector(7 downto 0);
C: in std_logic_vector(1 downto 0);
S: out std_logic_vector(7 downto 0);
Overflow: out std_logic);
end component;

component mux_4to1 is
 port(
     A,B,C,D : in STD_LOGIC_vector(7 downto 0);
     S: in STD_LOGIC_vector(1 downto 0);
     Z: out STD_LOGIC_vector(7 downto 0)
  );
end component;

begin

Multiplexer_4_1: mux_4to1 port map ("00010100", "10010110", "01011101", "11011111", C, B_Sig);

Somador: Sum_Sub port map (A, B_sig, "00", F, Overflow_sig);


end ProjetoV5_arch;
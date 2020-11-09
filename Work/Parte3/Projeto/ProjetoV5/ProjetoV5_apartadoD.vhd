--UNIVERSIDADE FEDERAL DE SANTA CATARINA - UFSC
--CENTRO TECNOLOGICO - CTC
--DEPARTAMENTO DE ENGENHARIA ELETRICA E ELETRONICA
--EEL7120 - INTRODUCAO A MICROELETRONICA

--PROJETO 5 APARTADO D

--GUSTAVO SIMAS E PEDRO PAULO SANTOS GOMES

library IEEE;
use IEEE.Std_Logic_1164.all;
use ieee.numeric_std.all; 

entity ProjetoV5_apartadoC is
port (A: in std_logic_vector(7 downto 0);
C: in std_logic_vector(1 downto 0);
F: out std_logic_vector(7 downto 0));
end ProjetoV5_apartadoC;

architecture ProjetoV5_apartadoC_arch of ProjetoV5_apartadoC is
signal B_sig: std_logic_vector(7 downto 0);
signal Overflow_sig: std_logic;

component SomadorArit2 is
port (A: in std_logic_vector(7 downto 0);
C: in std_logic_vector(1 downto 0);
S: out std_logic_vector(7 downto 0));
end component;

begin

Somador: SomadorArit2 port map (A, C, F);

end ProjetoV5_apartadoC_arch;
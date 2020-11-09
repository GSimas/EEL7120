--UNIVERSIDADE FEDERAL DE SANTA CATARINA - UFSC
--CENTRO TECNOLOGICO - CTC
--DEPARTAMENTO DE ENGENHARIA ELETRICA E ELETRONICA
--EEL7120 - INTRODUCAO A MICROELETRONICA
--SOMADOR +
--GUSTAVO SIMAS E PEDRO PAULO SANTOS GOMES

library IEEE;
use IEEE.Std_Logic_1164.all;
use IEEE.numeric_std.all; 
use IEEE.std_logic_signed.all;

entity SomadorArit is
port (A: in std_logic_vector(7 downto 0);
B: in std_logic_vector(7 downto 0);
S: out std_logic_vector(7 downto 0));
end SomadorArit;

architecture SomadorArit_arch of SomadorArit is

begin

S <= A + B;

end SomadorArit_arch;
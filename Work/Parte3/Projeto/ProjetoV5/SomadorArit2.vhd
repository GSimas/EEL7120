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

entity SomadorArit2 is
port (A: in std_logic_vector(7 downto 0);
C: in std_logic_vector(1 downto 0);
S: out std_logic_vector(7 downto 0));
end SomadorArit2;

architecture SomadorArit2_arch of SomadorArit2 is
signal B: std_logic_vector(7 downto 0);

begin

B <= C(0) & C(1) & "01" & C(1) & "1" & C(0) & C(1);

S <= A + B;

end SomadorArit2_arch;
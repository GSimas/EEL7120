----UNIVERSIDADE FEDERAL DE SANTA CATARINA - UFSC
--CENTRO TECNOLOGICO - CTC
--DEPARTAMENTO DE ENGENHARIA ELETRICA E ELETRONICA
--EEL7120 - INTRODUCAO A MICROELETRONICA
--MAJORITY DETECTOR
--GUSTAVO SIMAS E PEDRO PAULO SANTOS GOMES

library IEEE;
use IEEE.Std_Logic_1164.all;
entity majority is
port (A: in std_logic;
 B: in std_logic;
 C: in std_logic;
 Y: out std_logic
 );
end majority;
architecture circuito_logico of majority is
 signal D,E,F: std_logic;
begin
 Y <= D or E or F;
 D <= A and B;
 E <= A and C;
 F <= B and C;
end circuito_logico;
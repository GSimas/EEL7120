library IEEE;
use IEEE.Std_Logic_1164.all; 

entity mode is
port (I0: in std_logic;
I1: in std_logic;
I2: in std_logic;
R: out std_logic
);
end mode;

architecture mode_arch of mode is
BEGIN
	R <= (NOT(I1) AND I0) OR (NOT(I0) AND I2);
END mode_arch;
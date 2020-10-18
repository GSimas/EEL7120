library IEEE;
use IEEE.Std_Logic_1164.all; 

entity fulladder is
port (A: in std_logic;
B: in std_logic;
Cin: in std_logic;
Sum: out std_logic;
Cout: out std_logic
);
end fulladder;

architecture fulladder_arch of fulladder is
BEGIN
	Sum <= A XOR B XOR Cin;
	Cout <= (A AND B) OR (Cin AND A) OR (Cin AND B);
END fulladder_arch;
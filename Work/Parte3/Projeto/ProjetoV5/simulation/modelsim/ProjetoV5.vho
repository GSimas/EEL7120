-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 32-bit"
-- VERSION "Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"

-- DATE "11/09/2020 13:10:44"

-- 
-- Device: Altera EP4CGX15BF14C6 Package FBGA169
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIV;
LIBRARY IEEE;
USE CYCLONEIV.CYCLONEIV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	ProjetoV5_apartadoC IS
    PORT (
	A : IN std_logic_vector(7 DOWNTO 0);
	C : IN std_logic_vector(1 DOWNTO 0);
	F : OUT std_logic_vector(7 DOWNTO 0)
	);
END ProjetoV5_apartadoC;

-- Design Ports Information
-- F[0]	=>  Location: PIN_N9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[1]	=>  Location: PIN_M11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[2]	=>  Location: PIN_K13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[3]	=>  Location: PIN_H10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[4]	=>  Location: PIN_N11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[5]	=>  Location: PIN_K10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[6]	=>  Location: PIN_L11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[7]	=>  Location: PIN_K9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C[1]	=>  Location: PIN_F13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[0]	=>  Location: PIN_F12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C[0]	=>  Location: PIN_K12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[1]	=>  Location: PIN_N10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[2]	=>  Location: PIN_L9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[3]	=>  Location: PIN_L12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[4]	=>  Location: PIN_N12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[5]	=>  Location: PIN_L13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[6]	=>  Location: PIN_M9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A[7]	=>  Location: PIN_M13,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF ProjetoV5_apartadoC IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_A : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_C : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_F : std_logic_vector(7 DOWNTO 0);
SIGNAL \F[0]~output_o\ : std_logic;
SIGNAL \F[1]~output_o\ : std_logic;
SIGNAL \F[2]~output_o\ : std_logic;
SIGNAL \F[3]~output_o\ : std_logic;
SIGNAL \F[4]~output_o\ : std_logic;
SIGNAL \F[5]~output_o\ : std_logic;
SIGNAL \F[6]~output_o\ : std_logic;
SIGNAL \F[7]~output_o\ : std_logic;
SIGNAL \C[1]~input_o\ : std_logic;
SIGNAL \A[0]~input_o\ : std_logic;
SIGNAL \Somador|S[0]~0_combout\ : std_logic;
SIGNAL \A[1]~input_o\ : std_logic;
SIGNAL \C[0]~input_o\ : std_logic;
SIGNAL \Somador|S[0]~1\ : std_logic;
SIGNAL \Somador|S[1]~2_combout\ : std_logic;
SIGNAL \A[2]~input_o\ : std_logic;
SIGNAL \Somador|S[1]~3\ : std_logic;
SIGNAL \Somador|S[2]~4_combout\ : std_logic;
SIGNAL \A[3]~input_o\ : std_logic;
SIGNAL \Somador|S[2]~5\ : std_logic;
SIGNAL \Somador|S[3]~6_combout\ : std_logic;
SIGNAL \A[4]~input_o\ : std_logic;
SIGNAL \Somador|S[3]~7\ : std_logic;
SIGNAL \Somador|S[4]~8_combout\ : std_logic;
SIGNAL \A[5]~input_o\ : std_logic;
SIGNAL \Somador|S[4]~9\ : std_logic;
SIGNAL \Somador|S[5]~10_combout\ : std_logic;
SIGNAL \A[6]~input_o\ : std_logic;
SIGNAL \Somador|S[5]~11\ : std_logic;
SIGNAL \Somador|S[6]~12_combout\ : std_logic;
SIGNAL \A[7]~input_o\ : std_logic;
SIGNAL \Somador|S[6]~13\ : std_logic;
SIGNAL \Somador|S[7]~14_combout\ : std_logic;

BEGIN

ww_A <= A;
ww_C <= C;
F <= ww_F;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X20_Y0_N2
\F[0]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[0]~0_combout\,
	devoe => ww_devoe,
	o => \F[0]~output_o\);

-- Location: IOOBUF_X29_Y0_N9
\F[1]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[1]~2_combout\,
	devoe => ww_devoe,
	o => \F[1]~output_o\);

-- Location: IOOBUF_X33_Y15_N2
\F[2]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[2]~4_combout\,
	devoe => ww_devoe,
	o => \F[2]~output_o\);

-- Location: IOOBUF_X33_Y14_N2
\F[3]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[3]~6_combout\,
	devoe => ww_devoe,
	o => \F[3]~output_o\);

-- Location: IOOBUF_X26_Y0_N2
\F[4]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[4]~8_combout\,
	devoe => ww_devoe,
	o => \F[4]~output_o\);

-- Location: IOOBUF_X31_Y0_N9
\F[5]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[5]~10_combout\,
	devoe => ww_devoe,
	o => \F[5]~output_o\);

-- Location: IOOBUF_X31_Y0_N2
\F[6]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[6]~12_combout\,
	devoe => ww_devoe,
	o => \F[6]~output_o\);

-- Location: IOOBUF_X22_Y0_N2
\F[7]~output\ : cycloneiv_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Somador|S[7]~14_combout\,
	devoe => ww_devoe,
	o => \F[7]~output_o\);

-- Location: IOIBUF_X33_Y16_N8
\C[1]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_C(1),
	o => \C[1]~input_o\);

-- Location: IOIBUF_X33_Y16_N1
\A[0]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(0),
	o => \A[0]~input_o\);

-- Location: LCCOMB_X32_Y12_N0
\Somador|S[0]~0\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[0]~0_combout\ = (\C[1]~input_o\ & (\A[0]~input_o\ $ (VCC))) # (!\C[1]~input_o\ & (\A[0]~input_o\ & VCC))
-- \Somador|S[0]~1\ = CARRY((\C[1]~input_o\ & \A[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110011010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \C[1]~input_o\,
	datab => \A[0]~input_o\,
	datad => VCC,
	combout => \Somador|S[0]~0_combout\,
	cout => \Somador|S[0]~1\);

-- Location: IOIBUF_X26_Y0_N8
\A[1]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(1),
	o => \A[1]~input_o\);

-- Location: IOIBUF_X33_Y11_N8
\C[0]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_C(0),
	o => \C[0]~input_o\);

-- Location: LCCOMB_X32_Y12_N2
\Somador|S[1]~2\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[1]~2_combout\ = (\A[1]~input_o\ & ((\C[0]~input_o\ & (\Somador|S[0]~1\ & VCC)) # (!\C[0]~input_o\ & (!\Somador|S[0]~1\)))) # (!\A[1]~input_o\ & ((\C[0]~input_o\ & (!\Somador|S[0]~1\)) # (!\C[0]~input_o\ & ((\Somador|S[0]~1\) # (GND)))))
-- \Somador|S[1]~3\ = CARRY((\A[1]~input_o\ & (!\C[0]~input_o\ & !\Somador|S[0]~1\)) # (!\A[1]~input_o\ & ((!\Somador|S[0]~1\) # (!\C[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011000010111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A[1]~input_o\,
	datab => \C[0]~input_o\,
	datad => VCC,
	cin => \Somador|S[0]~1\,
	combout => \Somador|S[1]~2_combout\,
	cout => \Somador|S[1]~3\);

-- Location: IOIBUF_X24_Y0_N8
\A[2]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(2),
	o => \A[2]~input_o\);

-- Location: LCCOMB_X32_Y12_N4
\Somador|S[2]~4\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[2]~4_combout\ = (\A[2]~input_o\ & ((GND) # (!\Somador|S[1]~3\))) # (!\A[2]~input_o\ & (\Somador|S[1]~3\ $ (GND)))
-- \Somador|S[2]~5\ = CARRY((\A[2]~input_o\) # (!\Somador|S[1]~3\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101010101111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A[2]~input_o\,
	datad => VCC,
	cin => \Somador|S[1]~3\,
	combout => \Somador|S[2]~4_combout\,
	cout => \Somador|S[2]~5\);

-- Location: IOIBUF_X33_Y12_N1
\A[3]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(3),
	o => \A[3]~input_o\);

-- Location: LCCOMB_X32_Y12_N6
\Somador|S[3]~6\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[3]~6_combout\ = (\C[1]~input_o\ & ((\A[3]~input_o\ & (\Somador|S[2]~5\ & VCC)) # (!\A[3]~input_o\ & (!\Somador|S[2]~5\)))) # (!\C[1]~input_o\ & ((\A[3]~input_o\ & (!\Somador|S[2]~5\)) # (!\A[3]~input_o\ & ((\Somador|S[2]~5\) # (GND)))))
-- \Somador|S[3]~7\ = CARRY((\C[1]~input_o\ & (!\A[3]~input_o\ & !\Somador|S[2]~5\)) # (!\C[1]~input_o\ & ((!\Somador|S[2]~5\) # (!\A[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011000010111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \C[1]~input_o\,
	datab => \A[3]~input_o\,
	datad => VCC,
	cin => \Somador|S[2]~5\,
	combout => \Somador|S[3]~6_combout\,
	cout => \Somador|S[3]~7\);

-- Location: IOIBUF_X29_Y0_N1
\A[4]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(4),
	o => \A[4]~input_o\);

-- Location: LCCOMB_X32_Y12_N8
\Somador|S[4]~8\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[4]~8_combout\ = (\A[4]~input_o\ & ((GND) # (!\Somador|S[3]~7\))) # (!\A[4]~input_o\ & (\Somador|S[3]~7\ $ (GND)))
-- \Somador|S[4]~9\ = CARRY((\A[4]~input_o\) # (!\Somador|S[3]~7\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110011001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A[4]~input_o\,
	datad => VCC,
	cin => \Somador|S[3]~7\,
	combout => \Somador|S[4]~8_combout\,
	cout => \Somador|S[4]~9\);

-- Location: IOIBUF_X33_Y12_N8
\A[5]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(5),
	o => \A[5]~input_o\);

-- Location: LCCOMB_X32_Y12_N10
\Somador|S[5]~10\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[5]~10_combout\ = (\A[5]~input_o\ & (!\Somador|S[4]~9\)) # (!\A[5]~input_o\ & ((\Somador|S[4]~9\) # (GND)))
-- \Somador|S[5]~11\ = CARRY((!\Somador|S[4]~9\) # (!\A[5]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A[5]~input_o\,
	datad => VCC,
	cin => \Somador|S[4]~9\,
	combout => \Somador|S[5]~10_combout\,
	cout => \Somador|S[5]~11\);

-- Location: IOIBUF_X24_Y0_N1
\A[6]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(6),
	o => \A[6]~input_o\);

-- Location: LCCOMB_X32_Y12_N12
\Somador|S[6]~12\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[6]~12_combout\ = ((\C[1]~input_o\ $ (\A[6]~input_o\ $ (!\Somador|S[5]~11\)))) # (GND)
-- \Somador|S[6]~13\ = CARRY((\C[1]~input_o\ & ((\A[6]~input_o\) # (!\Somador|S[5]~11\))) # (!\C[1]~input_o\ & (\A[6]~input_o\ & !\Somador|S[5]~11\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100110001110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \C[1]~input_o\,
	datab => \A[6]~input_o\,
	datad => VCC,
	cin => \Somador|S[5]~11\,
	combout => \Somador|S[6]~12_combout\,
	cout => \Somador|S[6]~13\);

-- Location: IOIBUF_X33_Y10_N1
\A[7]~input\ : cycloneiv_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A(7),
	o => \A[7]~input_o\);

-- Location: LCCOMB_X32_Y12_N14
\Somador|S[7]~14\ : cycloneiv_lcell_comb
-- Equation(s):
-- \Somador|S[7]~14_combout\ = \A[7]~input_o\ $ (\C[0]~input_o\ $ (\Somador|S[6]~13\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011010010110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A[7]~input_o\,
	datab => \C[0]~input_o\,
	cin => \Somador|S[6]~13\,
	combout => \Somador|S[7]~14_combout\);

ww_F(0) <= \F[0]~output_o\;

ww_F(1) <= \F[1]~output_o\;

ww_F(2) <= \F[2]~output_o\;

ww_F(3) <= \F[3]~output_o\;

ww_F(4) <= \F[4]~output_o\;

ww_F(5) <= \F[5]~output_o\;

ww_F(6) <= \F[6]~output_o\;

ww_F(7) <= \F[7]~output_o\;
END structure;



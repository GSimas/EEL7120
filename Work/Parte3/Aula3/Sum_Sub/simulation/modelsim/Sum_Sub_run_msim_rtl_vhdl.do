transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {C:/Users/Gustavo Simas/Downloads/Sum_Sub-20201018T183530Z-001/Sum_Sub/Sum_Sub.vhd}
vcom -93 -work work {C:/Users/Gustavo Simas/Downloads/Sum_Sub-20201018T183530Z-001/Sum_Sub/fulladder.vhd}
vcom -93 -work work {C:/Users/Gustavo Simas/Downloads/Sum_Sub-20201018T183530Z-001/Sum_Sub/mode.vhd}


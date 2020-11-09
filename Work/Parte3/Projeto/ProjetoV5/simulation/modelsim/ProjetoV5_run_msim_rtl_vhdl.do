transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {/home/100000000820483/Documents/ProjetoV5/mux_4to1.vhd}
vcom -93 -work work {/home/100000000820483/Documents/ProjetoV5/SomadorArit.vhd}
vcom -93 -work work {/home/100000000820483/Documents/ProjetoV5/ProjetoV5_apartadoC.vhd}


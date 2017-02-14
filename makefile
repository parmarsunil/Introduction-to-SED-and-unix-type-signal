all: compile
compile:
	gcc myshell_16cs60r59.c
	gcc mypwd_16cs60r59.c -o mypwd
	gcc mymkdir_16cs60r59.c -o mymkdir
	gcc mycd_16cs60r59.c -o mycd
	gcc myrm_16cs60r59.c -o myrm
	gcc mymv_16cs60r59.c -o mymv
	gcc myps_16cs60r59.c -o myps
	gcc myls_16cs60r59.c -o myls
	gcc mytail_16cs60r59.c -o mytail
	gcc mygrep_16cs60r59.c -o mygrep
	gcc mypipe_16cs60r59.c -o mypipe
	gcc mysed_16cs60r59.c -o mysed

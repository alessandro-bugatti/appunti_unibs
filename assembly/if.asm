	INP R0, 2
	INP R1, 2
	/if (R0 > R1)
	CMP R0, R1
	BGT VERO
	ADD R0, R0, #1
	B FALSO
VERO:
	ADD R1, R1, #1
FALSO:
	HALT

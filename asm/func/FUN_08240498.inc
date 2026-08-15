	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _082404AC
	bl Script_GetValue
	bl sound_fadeout_08240440
_082404AC:
	pop {r0}
	bx r0

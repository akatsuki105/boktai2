	push {lr}
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _082404AC
	bl Script_GetValue
	bl sound_fadeout_08240440
_082404AC:
	pop {r0}
	bx r0

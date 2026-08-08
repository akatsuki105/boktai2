	push {r4, lr}
	ldr r0, _08224DC0 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08224DAC
	ldr r0, _08224DC4 @ =0x0000BB34
	movs r1, #0
	bl FUN_08229c6c
	adds r4, r0, #0
	cmp r4, #0
	beq _08224DBA
_08224DAC:
	movs r0, #0x72
	movs r1, #0
	bl FUN_0823174c
	ldr r2, _08224DC8 @ =0x00000F28
	adds r1, r4, r2
	strb r0, [r1]
_08224DBA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08224DC0: .4byte 0x03000248
_08224DC4: .4byte 0x0000BB34
_08224DC8: .4byte 0x00000F28

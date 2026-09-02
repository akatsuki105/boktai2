	push {r4, r5, lr}
	ldr r5, _08240AC4 @ =0x0000757B
	adds r0, r5, #0
	bl FUN_08230e70
	cmp r0, #0
	bne _08240ACC
	movs r0, #0xc
	bl Malloc
	adds r4, r0, #0
	movs r1, #0xc
	bl ClearMemory
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08230e30
	ldr r0, _08240AC8 @ =0x030016FC
	str r4, [r0]
	bl Entity08240a54_Create
	movs r0, #1
	b _08240ACE
	.align 2, 0
_08240AC4: .4byte 0x0000757B
_08240AC8: .4byte 0x030016FC
_08240ACC:
	movs r0, #0
_08240ACE:
	pop {r4, r5}
	pop {r1}
	bx r1

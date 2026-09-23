	push {lr}
	adds r2, r0, #0
	ldr r0, _08049E50 @ =0x030000C8
	ldr r1, [r0]
	cmp r1, #0
	beq _08049E54
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0804990c
	movs r0, #0
	b _08049E58
	.align 2, 0
_08049E50: .4byte 0x030000C8
_08049E54:
	movs r0, #1
	rsbs r0, r0, #0
_08049E58:
	pop {r1}
	bx r1

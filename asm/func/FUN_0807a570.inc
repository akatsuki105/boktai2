	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r0, _0807A598 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807A59C
	adds r0, r4, #0
	bl FUN_080d040c
	adds r0, r4, #0
	movs r1, #0x1c
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0
	b _0807A5D0
	.align 2, 0
_0807A598: .4byte 0x030047A4
_0807A59C:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _0807A5BC
	movs r5, #1
	subs r1, #0x94
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_0807bdc8
	b _0807A5CE
_0807A5BC:
	movs r5, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0807bdc8
_0807A5CE:
	adds r0, r5, #0
_0807A5D0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

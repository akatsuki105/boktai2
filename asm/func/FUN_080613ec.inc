	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0xca
	lsls r0, r0, #3
	adds r5, r4, r0
	cmp r2, #0
	beq _08061408
	ldr r2, _08061404 @ =0x0000067A
	adds r1, r4, r2
	movs r0, #0x48
	b _0806140E
	.align 2, 0
_08061404: .4byte 0x0000067A
_08061408:
	ldr r0, _0806144C @ =0x0000067A
	adds r1, r4, r0
	movs r0, #4
_0806140E:
	strb r0, [r1]
	ldr r1, _08061450 @ =0x0000064C
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0806144C @ =0x0000067A
	adds r0, r4, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08061454 @ =0x00000679
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806144C: .4byte 0x0000067A
_08061450: .4byte 0x0000064C
_08061454: .4byte 0x00000679

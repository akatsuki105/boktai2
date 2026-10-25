	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r7, r4, #0
	adds r7, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033BA6
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033B64
	ldr r1, _08033B60 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _08033B74
	movs r3, #0
	b _08033B74
	.align 2, 0
_08033B60: .4byte 0x00000824
_08033B64:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _08033B74
	movs r3, #5
_08033B74:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Boss_PlayAnimDir8
	movs r2, #0x10
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, r4, #0
	adds r2, #0xcc
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08033BA6:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08033BFC @ =0x0001000C
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033C56
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	cmp r6, #0x1f
	ble _08033C00
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08033C56
	.align 2, 0
_08033BFC: .4byte 0x0001000C
_08033C00:
	movs r1, #3
	bics r1, r6
	movs r0, #0x20
	subs r0, r0, r6
	adds r4, r7, #0
	adds r4, #0x10
	lsls r5, r1, #6
	lsls r6, r0, #3
	ldr r2, _08033C2C @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033C30
	asrs r3, r0, #0xc
	b _08033C36
	.align 2, 0
_08033C2C: .4byte gSineTable
_08033C30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08033C36:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033C4E
	asrs r0, r0, #0xc
	b _08033C54
_08033C4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08033C54:
	strh r0, [r4, #4]
_08033C56:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

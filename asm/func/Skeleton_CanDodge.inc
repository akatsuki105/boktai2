	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r4, [r0]
	cmp r4, #0
	beq _08103404
	movs r6, #0xeb
	lsls r6, r6, #3
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08103404
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08103404
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r1, r3, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r6, #2
	ldrsh r0, [r1, r6]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r2, r2, r0
	movs r6, #4
	ldrsh r0, [r1, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	cmn r2, r0
	bne _08103404
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r1, [r0]
	movs r0, #0x90
	lsls r0, r0, #0xa
	cmp r1, r0
	bhi _08103404
	ldrb r1, [r4, #5]
	ldrb r0, [r3, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081033D8
	ldr r6, _081033D4 @ =0xFFFFFF00
	adds r1, r1, r6
	b _081033E6
	.align 2, 0
_081033D4: .4byte 0xFFFFFF00
_081033D8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081033E6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081033E6:
	adds r0, r1, #0
	cmp r0, #0
	bge _081033EE
	rsbs r0, r0, #0
_081033EE:
	cmp r0, #0x3f
	ble _08103404
	ldr r1, _08103400 @ =0x00000724
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08103404
	movs r0, #1
	b _08103406
	.align 2, 0
_08103400: .4byte 0x00000724
_08103404:
	movs r0, #0
_08103406:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

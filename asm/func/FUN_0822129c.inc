	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r7
	bl FUN_08221ae0
	adds r0, r7, #0
	adds r0, #0x48
	bl FUN_0823b4b8
	adds r0, r7, #0
	bl FUN_0821c140
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r1, _08221380 @ =0xFF00FFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_082215e8
	movs r1, #0xff
	lsls r1, r1, #2
	adds r3, r7, r1
	ldr r0, [r3]
	cmp r0, #0
	ble _082212EC
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r3]
	subs r0, #1
	str r0, [r3]
_082212EC:
	adds r0, r7, #0
	bl FUN_0821c520
	adds r0, r7, #0
	bl FUN_08022e20
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r7, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0822134A
	ldr r2, _08221384 @ =0x0203B400
	mov r8, r2
	ldr r6, _08221388 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r4, _0822138C @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r5, #0xb7
	lsls r5, r5, #2
	adds r3, r7, r5
	ldrh r0, [r3]
	subs r0, #0x10
	movs r5, #0x20
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrh r0, [r2]
	subs r0, #0x10
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_0822134A:
	movs r1, #0xbc
	lsls r1, r1, #4
	adds r3, r7, r1
	ldrb r0, [r3]
	cmp r0, #0
	beq _082213E2
	subs r0, #1
	strb r0, [r3]
	ldr r2, _08221390 @ =0x085B0A08
	ldr r4, _08221394 @ =0x00000BC2
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrb r0, [r3]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _08221398
	asrs r3, r0, #0xc
	b _0822139E
	.align 2, 0
_08221380: .4byte 0xFF00FFFF
_08221384: .4byte 0x0203B400
_08221388: .4byte 0x030046B8
_0822138C: .4byte 0x000003FF
_08221390: .4byte 0x085B0A08
_08221394: .4byte 0x00000BC2
_08221398:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0822139E:
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _082213CC @ =0x00000BC2
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xbc
	lsls r4, r4, #4
	adds r0, r7, r4
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _082213D0
	asrs r2, r0, #0xc
	b _082213D6
	.align 2, 0
_082213CC: .4byte 0x00000BC2
_082213D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_082213D6:
	movs r5, #0xb8
	lsls r5, r5, #2
	adds r1, r7, r5
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_082213E2:
	adds r1, r7, #0
	adds r1, #0x50
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r2, [r0]
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r5, #4
	ldrsh r4, [r1, r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #4
	ldrsh r1, [r2, r5]
	subs r0, r0, r3
	subs r1, r1, r4
	bl FUN_0823785c
	mov r1, sb
	adds r1, #0x4d
	strb r0, [r1]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0822143E
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #8
	beq _0822143E
	cmp r0, #9
	beq _0822143E
	ldr r4, _0822144C @ =0x0000080C
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r5, #0x81
	lsls r5, r5, #4
	adds r1, r7, r5
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0822143E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822144C: .4byte 0x0000080C

	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081DAD1E
	bl VM_GetPC_Proxy
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DAD1E
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAE0E
_081DAD1E:
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r4, #0
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, _081DAE18 @ =0x000002A2
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl Entity7999_InitBG
	adds r0, r5, #0
	bl Entity7999_InitPanels
	adds r0, r5, #0
	bl Entity7999_InitSprites
	adds r0, r5, #0
	bl FUN_081da468
	adds r0, r5, #0
	bl Entity7999_SavePltt
	ldr r3, _081DAE1C @ =0x0000029B
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r2, _081DAE20 @ =0x00000299
	adds r1, r5, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	ldr r1, _081DAE24 @ =FUN_081da930
	subs r2, #0x2d
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081DADB8
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DAE28 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081DADB8:
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _081DAE2C @ =0x03002C68
	ldr r0, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r0, r3
	cmp r0, #0
	bne _081DADCE
	movs r2, #0
_081DADCE:
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r1, [r0]
	ldr r3, _081DAE30 @ =0x00000286
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x41
	ldrb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r1, [r0]
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_081d9e50
	adds r0, r5, #0
	bl FUN_081da814
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da218
	movs r0, #1
_081DAE0E:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DAE18: .4byte 0x000002A2
_081DAE1C: .4byte 0x0000029B
_081DAE20: .4byte 0x00000299
_081DAE24: .4byte FUN_081da930
_081DAE28: .4byte 0x0000FFFF
_081DAE2C: .4byte 0x03002C68
_081DAE30: .4byte 0x00000286

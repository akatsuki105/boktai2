	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x74
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, _0819A974 @ =0x00000CC5
	adds r1, r5, r2
	strb r0, [r1]
	ldr r2, _0819A978 @ =0x0000012D
	adds r0, r2, #0
	ldrb r1, [r1]
	adds r0, r0, r1
	ldr r2, _0819A97C @ =0x00000CC6
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _0819A980 @ =0x00000CC8
	adds r1, r5, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToNamedArg
	movs r4, #0
	ldr r2, _0819A984 @ =0x00000CDC
	adds r6, r5, r2
	b _0819A990
	.align 2, 0
_0819A974: .4byte 0x00000CC5
_0819A978: .4byte 0x0000012D
_0819A97C: .4byte 0x00000CC6
_0819A980: .4byte 0x00000CC8
_0819A984: .4byte 0x00000CDC
_0819A988:
	bl VM_GetValue
	stm r6!, {r0}
	adds r4, #1
_0819A990:
	cmp r4, #1
	bgt _0819A99C
	bl VM_GetPC
	cmp r0, #0
	bne _0819A988
_0819A99C:
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0819A9B0
	bl VM_GetValue
	ldr r2, _0819A9CC @ =0x00000CD8
	adds r1, r5, r2
	str r0, [r1]
_0819A9B0:
	movs r0, #0x58
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0819A9EA
	bl VM_GetPC
	cmp r0, #0
	beq _0819A9D0
	bl VM_GetValue
	adds r1, r0, #0
	b _0819A9D2
	.align 2, 0
_0819A9CC: .4byte 0x00000CD8
_0819A9D0:
	movs r1, #0
_0819A9D2:
	adds r0, r5, #0
	adds r0, #0x5c
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A9E6
	bl VM_GetValue
	b _0819A9E8
_0819A9E6:
	movs r0, #0
_0819A9E8:
	strh r0, [r5, #0x3e]
_0819A9EA:
	adds r0, r5, #0
	bl EneSword_InitSlaveSwords
	adds r0, r5, #0
	bl FUN_0819a0ac
	ldr r0, _0819AA04 @ =0x00000CEC
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0819AA04: .4byte 0x00000CEC

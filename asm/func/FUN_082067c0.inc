	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #8]
	cmp r0, #0
	beq _082067EC
	movs r1, #0
	strb r1, [r3, #8]
	strb r1, [r3, #7]
	adds r2, r3, #0
	adds r2, #0x20
	ldrb r0, [r2, #4]
	cmp r0, #1
	bne _082067E4
	movs r0, #0x11
	strb r0, [r3, #5]
	strb r1, [r2, #4]
	b _082067E8
_082067E4:
	movs r0, #0xf
	strb r0, [r3, #5]
_082067E8:
	movs r0, #0
	str r0, [r3, #0x14]
_082067EC:
	ldr r1, _0820685C @ =0x00000434
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08206848
	adds r4, r3, #0
	adds r4, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r3, r6
	ldr r5, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08206812
	rsbs r1, r1, #0
_08206812:
	cmp r1, r5
	bge _08206840
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08206826
	rsbs r1, r1, #0
_08206826:
	cmp r1, #0xff
	bgt _08206840
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _0820683A
	rsbs r0, r0, #0
_0820683A:
	movs r1, #1
	cmp r0, r5
	blt _08206842
_08206840:
	movs r1, #0
_08206842:
	movs r0, #1
	cmp r1, #0
	bne _0820684A
_08206848:
	movs r0, #0
_0820684A:
	cmp r0, #0
	beq _08206880
	ldrb r0, [r3, #6]
	cmp r0, #0x10
	beq _08206860
	movs r0, #0x10
	strb r0, [r3, #5]
	b _08206890
	.align 2, 0
_0820685C: .4byte 0x00000434
_08206860:
	ldrb r4, [r3, #7]
	cmp r4, #1
	bne _08206890
	ldrb r1, [r3, #4]
	ldr r6, _0820687C @ =0x00000227
	adds r0, r3, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r3, #4]
	str r2, [r3, #0x14]
	strb r4, [r3, #8]
	b _08206890
	.align 2, 0
_0820687C: .4byte 0x00000227
_08206880:
	ldrb r0, [r3, #6]
	cmp r0, #0x10
	bne _0820688A
	movs r0, #0xf
	strb r0, [r3, #5]
_0820688A:
	ldr r0, [r3, #0x14]
	adds r0, #1
	str r0, [r3, #0x14]
_08206890:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

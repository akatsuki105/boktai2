	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #8]
	cmp r0, #0
	beq _08043D0A
	movs r0, #0
	strb r0, [r3, #8]
	strb r0, [r3, #7]
	movs r0, #0xc
	strb r0, [r3, #5]
_08043D0A:
	ldr r1, _08043D84 @ =0x00000434
	adds r0, r2, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043D66
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
	bge _08043D30
	rsbs r1, r1, #0
_08043D30:
	cmp r1, r5
	bge _08043D5E
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043D44
	rsbs r1, r1, #0
_08043D44:
	cmp r1, #0xff
	bgt _08043D5E
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043D58
	rsbs r0, r0, #0
_08043D58:
	movs r2, #1
	cmp r0, r5
	blt _08043D60
_08043D5E:
	movs r2, #0
_08043D60:
	movs r1, #1
	cmp r2, #0
	bne _08043D68
_08043D66:
	movs r1, #0
_08043D68:
	cmp r1, #0
	beq _08043D8C
	ldrb r1, [r3, #4]
	ldr r6, _08043D88 @ =0x00000227
	adds r0, r3, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r3, #4]
	str r2, [r3, #0x14]
	movs r0, #1
	strb r0, [r3, #8]
	b _08043DA2
	.align 2, 0
_08043D84: .4byte 0x00000434
_08043D88: .4byte 0x00000227
_08043D8C:
	ldrb r0, [r3, #7]
	cmp r0, #0
	beq _08043D9C
	movs r0, #0xe
	strb r0, [r3, #4]
	str r1, [r3, #0x14]
	movs r0, #1
	strb r0, [r3, #8]
_08043D9C:
	ldr r0, [r3, #0x14]
	adds r0, #1
	str r0, [r3, #0x14]
_08043DA2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

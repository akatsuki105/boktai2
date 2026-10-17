	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _080B8978 @ =0x00001410
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080B8938
	b _080B8ABE
_080B8938:
	bl VM_GetValue
	ldr r2, _080B897C @ =0x00001411
	adds r6, r4, r2
	strb r0, [r6]
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080B894E
	b _080B8ABE
_080B894E:
	movs r5, #0
	ldrb r6, [r6]
	cmp r5, r6
	bge _080B896E
	ldr r0, _080B8980 @ =0x00001414
	adds r7, r4, r0
	ldr r1, _080B897C @ =0x00001411
	adds r6, r4, r1
_080B895E:
	bl VM_GetValue
	adds r1, r7, r5
	strb r0, [r1]
	adds r5, #1
	ldrb r2, [r6]
	cmp r5, r2
	blt _080B895E
_080B896E:
	movs r5, #0
	ldr r1, _080B897C @ =0x00001411
	adds r0, r4, r1
	b _080B8A84
	.align 2, 0
_080B8978: .4byte 0x00001410
_080B897C: .4byte 0x00001411
_080B8980: .4byte 0x00001414
_080B8984:
	ldr r2, _080B899C @ =0x00001414
	adds r0, r4, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _080B8992
	b _080B8ABE
_080B8992:
	lsls r0, r0, #2
	ldr r1, _080B89A0 @ =_080B89A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B899C: .4byte 0x00001414
_080B89A0: .4byte _080B89A4
_080B89A4: @ jump table
	.4byte _080B89B8 @ case 0
	.4byte _080B89E4 @ case 1
	.4byte _080B8A0C @ case 2
	.4byte _080B8A38 @ case 3
	.4byte _080B8A60 @ case 4
_080B89B8:
	ldr r1, _080B89D8 @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x50
	strb r1, [r0]
	ldr r2, _080B89DC @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	ldr r1, _080B89E0 @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x2c
	b _080B8A7C
	.align 2, 0
_080B89D8: .4byte 0x00001419
_080B89DC: .4byte 0x0000141E
_080B89E0: .4byte 0x00001423
_080B89E4:
	ldr r2, _080B8A04 @ =0x00001419
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x50
	strb r1, [r0]
	ldr r1, _080B8A08 @ =0x0000141E
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	adds r2, #0xa
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x2d
	b _080B8A7C
	.align 2, 0
_080B8A04: .4byte 0x00001419
_080B8A08: .4byte 0x0000141E
_080B8A0C:
	ldr r1, _080B8A2C @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x5a
	strb r1, [r0]
	ldr r2, _080B8A30 @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	ldr r1, _080B8A34 @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x2c
	b _080B8A7C
	.align 2, 0
_080B8A2C: .4byte 0x00001419
_080B8A30: .4byte 0x0000141E
_080B8A34: .4byte 0x00001423
_080B8A38:
	ldr r2, _080B8A58 @ =0x00001419
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x5a
	strb r1, [r0]
	ldr r1, _080B8A5C @ =0x0000141E
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	adds r2, #0xa
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x2d
	b _080B8A7C
	.align 2, 0
_080B8A58: .4byte 0x00001419
_080B8A5C: .4byte 0x0000141E
_080B8A60:
	ldr r1, _080B8AA4 @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x53
	strb r1, [r0]
	ldr r2, _080B8AA8 @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #7
	strb r1, [r0]
	ldr r1, _080B8AAC @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x10
_080B8A7C:
	strb r1, [r0]
	adds r5, #1
	ldr r2, _080B8AB0 @ =0x00001411
	adds r0, r4, r2
_080B8A84:
	ldrb r0, [r0]
	cmp r5, r0
	bge _080B8A8C
	b _080B8984
_080B8A8C:
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080B8AB8
	bl VM_GetValue
	ldr r2, _080B8AB4 @ =0x00001490
	adds r1, r4, r2
	str r0, [r1]
	b _080B8ABE
	.align 2, 0
_080B8AA4: .4byte 0x00001419
_080B8AA8: .4byte 0x0000141E
_080B8AAC: .4byte 0x00001423
_080B8AB0: .4byte 0x00001411
_080B8AB4: .4byte 0x00001490
_080B8AB8:
	ldr r2, _080B8AC4 @ =0x00001490
	adds r0, r4, r2
	str r1, [r0]
_080B8ABE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8AC4: .4byte 0x00001490

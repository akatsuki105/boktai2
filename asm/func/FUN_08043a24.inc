	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043A3E
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #8
	strb r0, [r4, #5]
_08043A3E:
	ldr r0, [r4, #0x14]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08043B2C
	ldr r1, _08043A9C @ =0x000001ED
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	beq _08043AD0
	bl FUN_080865c0
	adds r3, r0, #0
	movs r6, #0
	cmp r3, #0
	beq _08043A8E
	adds r1, r4, #0
	adds r1, #0x64
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r7, #0
	ldrsh r0, [r3, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r3, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08043AA0 @ =0x000270FF
	cmp r1, r0
	bgt _08043A8E
	movs r6, #1
_08043A8E:
	cmp r6, #0
	beq _08043AA8
	ldr r6, _08043AA4 @ =0x00000236
	adds r1, r4, r6
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08043AC4
	.align 2, 0
_08043A9C: .4byte 0x000001ED
_08043AA0: .4byte 0x000270FF
_08043AA4: .4byte 0x00000236
_08043AA8:
	mov r7, r8
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _08043AD0
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043AD0
	ldr r0, _08043ACC @ =0x00000236
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
_08043AC4:
	strh r0, [r1]
	movs r0, #0xc
	movs r1, #0
	b _08043BB0
	.align 2, 0
_08043ACC: .4byte 0x00000236
_08043AD0:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043B2C
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043B2C
	adds r2, r5, #0
	adds r2, #0x22
	ldr r6, _08043B28 @ =0x00000233
	adds r3, r4, r6
	ldrb r0, [r2]
	ldrb r7, [r3]
	cmp r0, r7
	bne _08043B06
	adds r0, r5, #0
	adds r0, #0x23
	adds r6, #1
	adds r1, r4, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043B22
_08043B06:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08043B2C
	adds r0, r5, #0
	adds r0, #0x23
	movs r7, #0x8d
	lsls r7, r7, #2
	adds r1, r4, r7
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08043B2C
_08043B22:
	movs r0, #0xd
	movs r1, #0
	b _08043BB0
	.align 2, 0
_08043B28: .4byte 0x00000233
_08043B2C:
	ldr r1, _08043BA0 @ =0x00000434
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043B88
	adds r3, r4, #0
	adds r3, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r4, r6
	ldr r5, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043B52
	rsbs r1, r1, #0
_08043B52:
	cmp r1, r5
	bge _08043B80
	movs r7, #2
	ldrsh r1, [r2, r7]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043B66
	rsbs r1, r1, #0
_08043B66:
	cmp r1, #0xff
	bgt _08043B80
	movs r7, #4
	ldrsh r1, [r2, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043B7A
	rsbs r0, r0, #0
_08043B7A:
	movs r2, #1
	cmp r0, r5
	blt _08043B82
_08043B80:
	movs r2, #0
_08043B82:
	movs r1, #1
	cmp r2, #0
	bne _08043B8A
_08043B88:
	movs r1, #0
_08043B8A:
	cmp r1, #0
	beq _08043BA8
	ldrb r1, [r4, #4]
	ldr r6, _08043BA4 @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
	b _08043BB4
	.align 2, 0
_08043BA0: .4byte 0x00000434
_08043BA4: .4byte 0x00000227
_08043BA8:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08043BBA
	movs r0, #7
_08043BB0:
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
_08043BB4:
	movs r0, #1
	strb r0, [r4, #8]
	b _08043BC0
_08043BBA:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043BC0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

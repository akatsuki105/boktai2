	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _08072AD8 @ =0x0000049C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x2c
	ldrsh r0, [r4, r3]
	subs r6, r1, r0
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0823785c
	mov r8, r0
	movs r7, #0xc
	movs r0, #0xc
	bl FUN_080670d4
	ldr r1, _08072ADC @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08072A88
	ldr r2, _08072AE0 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08072A88
	movs r1, #1
_08072A88:
	cmp r1, #0
	beq _08072A96
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	muls r0, r7, r0
	asrs r7, r0, #6
_08072A96:
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r0, r1
	adds r1, r7, #0
	muls r1, r7, r1
	cmp r0, r1
	bgt _08072B64
	ldr r3, _08072AD8 @ =0x0000049C
	adds r0, r4, r3
	ldrh r0, [r0]
	strh r0, [r4, #0x2c]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x30]
	ldr r2, _08072AE4 @ =0x000004A9
	adds r1, r4, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08072AE8
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0xff
	strb r0, [r1]
	b _08072B04
	.align 2, 0
_08072AD8: .4byte 0x0000049C
_08072ADC: .4byte 0x00000446
_08072AE0: .4byte 0x00000442
_08072AE4: .4byte 0x000004A9
_08072AE8:
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_08072B04:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r2, [r0]
	cmp r2, #4
	bls _08072B28
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08072B24 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08072B36
	.align 2, 0
_08072B24: .4byte 0x000002E6
_08072B28:
	ldr r1, _08072B5C @ =0x000002E6
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08072B60 @ =0x000002E7
	adds r0, r4, r2
	strb r1, [r0]
_08072B36:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
	b _08072D3A
	.align 2, 0
_08072B5C: .4byte 0x000002E6
_08072B60: .4byte 0x000002E7
_08072B64:
	ldr r2, _08072B80 @ =0x085B0A08
	mov r0, r8
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08072B84
	asrs r0, r0, #0xc
	b _08072B8A
	.align 2, 0
_08072B80: .4byte 0x085B0A08
_08072B84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08072B8A:
	strh r0, [r4, #0x34]
	movs r0, #0xff
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08072BA4
	asrs r0, r0, #0xc
	b _08072BAA
_08072BA4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08072BAA:
	strh r0, [r4, #0x38]
	ldr r2, _08072BCC @ =0x000001C7
	adds r3, r4, r2
	ldrb r3, [r3]
	cmp r3, #1
	bne _08072BEA
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08072BD0
	movs r3, #0x38
	ldrsh r1, [r4, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08072BDC
	b _08072BE0
	.align 2, 0
_08072BCC: .4byte 0x000001C7
_08072BD0:
	movs r0, #0x38
	ldrsh r1, [r4, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08072BE0
_08072BDC:
	asrs r0, r0, #6
	b _08072BE6
_08072BE0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08072BE6:
	strh r0, [r4, #0x38]
	b _08072C1C
_08072BEA:
	cmp r3, #2
	bne _08072C1C
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _08072C04
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08072C10
	b _08072C14
_08072C04:
	movs r3, #0x34
	ldrsh r1, [r4, r3]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08072C14
_08072C10:
	asrs r0, r0, #6
	b _08072C1A
_08072C14:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08072C1A:
	strh r0, [r4, #0x34]
_08072C1C:
	mov r0, r8
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #4
	bls _08072C54
	movs r0, #8
	subs r0, r0, r1
	ldr r3, _08072C4C @ =0x000002E6
	adds r1, r4, r3
	strb r0, [r1]
	ldr r0, _08072C50 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _08072C60
	.align 2, 0
_08072C4C: .4byte 0x000002E6
_08072C50: .4byte 0x000002E7
_08072C54:
	ldr r2, _08072CC0 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _08072CC4 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_08072C60:
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x9c
	ldrh r1, [r2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08072D22
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08072D22
	ldr r1, _08072CC8 @ =0x00000446
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r5, #0
	adds r3, r0, #0
	cmp r1, #0
	beq _08072C94
	ldr r1, _08072CCC @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08072C94
	movs r5, #1
_08072C94:
	cmp r5, #0
	bne _08072D22
	ldrh r0, [r3]
	movs r1, #0
	cmp r0, #0
	beq _08072CAC
	ldr r3, _08072CCC @ =0x00000442
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _08072CAC
	movs r1, #1
_08072CAC:
	cmp r1, #0
	beq _08072CD8
	ldrh r0, [r2]
	cmp r0, #0
	bne _08072CD0
	movs r0, #0xc8
	bl PlaySound_082406e0
	b _08072D22
	.align 2, 0
_08072CC0: .4byte 0x000002E6
_08072CC4: .4byte 0x000002E7
_08072CC8: .4byte 0x00000446
_08072CCC: .4byte 0x00000442
_08072CD0:
	movs r0, #0xc7
	bl PlaySound_082406e0
	b _08072D22
_08072CD8:
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08072CEE
	ldr r3, _08072CFC @ =0x000001C7
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08072D08
_08072CEE:
	ldrh r0, [r2]
	cmp r0, #0
	bne _08072D00
	movs r0, #0xca
	bl PlaySound_082406e0
	b _08072D22
	.align 2, 0
_08072CFC: .4byte 0x000001C7
_08072D00:
	movs r0, #0xc9
	bl PlaySound_082406e0
	b _08072D22
_08072D08:
	ldrh r0, [r2]
	cmp r0, #0
	bne _08072D1C
	ldr r0, _08072D18 @ =0x0000028E
	bl PlaySound_082406e0
	b _08072D22
	.align 2, 0
_08072D18: .4byte 0x0000028E
_08072D1C:
	ldr r0, _08072D44 @ =0x0000028D
	bl PlaySound_082406e0
_08072D22:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
_08072D3A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08072D44: .4byte 0x0000028D

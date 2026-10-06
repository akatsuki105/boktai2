	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r0, _0809E3E0 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	bne _0809E3B2
	b _0809E53E
_0809E3B2:
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0xf
	bls _0809E3C0
	b _0809E53E
_0809E3C0:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E3E4
	bl VM_GetValue
	mov r1, r8
	ldrb r2, [r1]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E3F2
	.align 2, 0
_0809E3E0: .4byte 0x03000140
_0809E3E4:
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E3F2:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809E438
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809E430 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0809E434 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0809E442
	.align 2, 0
_0809E430: .4byte 0xFFFF0000
_0809E434: .4byte 0x0000FFFF
_0809E438:
	ldr r1, _0809E470 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0809E442:
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0809E46A
	cmp r1, #0
	blt _0809E46A
	ldr r0, _0809E474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0809E46A
	ldr r0, _0809E478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0809E47C
_0809E46A:
	movs r4, #0
	b _0809E48A
	.align 2, 0
_0809E470: .4byte 0xFFFF0000
_0809E474: .4byte 0x030046A8
_0809E478: .4byte 0x030046AC
_0809E47C:
	ldr r0, _0809E49C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0809E48A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0809E4A0
	adds r0, #4
	b _0809E4AC
	.align 2, 0
_0809E49C: .4byte 0x030046A4
_0809E4A0:
	ldr r0, _0809E4C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0809E4AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0809E4C4
	cmp r2, #2
	beq _0809E4C8
	b _0809E4CC
	.align 2, 0
_0809E4C0: .4byte 0x030046A4
_0809E4C4:
	ldrb r0, [r5, #4]
	b _0809E4CA
_0809E4C8:
	ldrb r0, [r5]
_0809E4CA:
	subs r1, r1, r0
_0809E4CC:
	add r0, sp, #4
	strh r1, [r0, #2]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809E4E2
	bl VM_GetValue
	adds r7, r0, #0
	b _0809E4E4
_0809E4E2:
	movs r7, #0
_0809E4E4:
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0809E4F6
	bl VM_GetValue
	adds r3, r0, #0
	b _0809E4F8
_0809E4F6:
	movs r3, #0
_0809E4F8:
	mov r4, r8
	ldrb r0, [r4]
	movs r5, #0xa8
	muls r0, r5, r0
	adds r0, #0x2c
	adds r0, r6, r0
	ldrh r1, [r6, #0x24]
	str r1, [sp]
	adds r1, r7, #0
	add r2, sp, #4
	bl FUN_0809e22c
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r2, #1
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E536
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r1, r6, #0
	adds r1, #0x34
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0809E536:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0809E53E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

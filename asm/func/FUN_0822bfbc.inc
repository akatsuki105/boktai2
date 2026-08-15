	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x40
	adds r7, r0, #0
	adds r5, r2, #0
	ldr r3, [sp, #0x58]
	ldr r4, [sp, #0x5c]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #4
	ldr r2, _0822C024 @ =0x03003ED0
	adds r6, r0, r2
	movs r0, #0
	strh r1, [r6]
	strh r7, [r6, #2]
	strh r0, [r6, #0x20]
	strh r0, [r6, #0x22]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r6, #0x10]
	strh r0, [r6, #0x12]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x14
	mov r8, r3
	lsls r4, r4, #0x10
	asrs r4, r4, #0x14
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0x40
	bl memcpy
	ldr r0, [sp, #0x1c]
	adds r0, r0, r5
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x24]
	adds r0, r0, r5
	str r0, [sp, #0x24]
	ldr r0, [sp, #0xc]
	adds r0, r0, r5
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	adds r0, r0, r5
	str r0, [sp, #0x14]
	movs r5, #0
	cmp r7, #1
	beq _0822C03C
	cmp r7, #1
	bgt _0822C028
	cmp r7, #0
	beq _0822C032
	b _0822C06C
	.align 2, 0
_0822C024: .4byte 0x03003ED0
_0822C028:
	cmp r7, #2
	beq _0822C04A
	cmp r7, #3
	beq _0822C058
	b _0822C06C
_0822C032:
	movs r5, #0x80
	lsls r5, r5, #8
	movs r0, #0x80
	lsls r0, r0, #1
	b _0822C064
_0822C03C:
	mov r0, sp
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	lsls r5, r0, #5
	movs r0, #0x80
	lsls r0, r0, #2
	b _0822C064
_0822C04A:
	mov r0, sp
	movs r2, #0x12
	ldrsh r0, [r0, r2]
	lsls r5, r0, #5
	movs r0, #0x80
	lsls r0, r0, #3
	b _0822C064
_0822C058:
	mov r0, sp
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	lsls r5, r0, #5
	movs r0, #0x80
	lsls r0, r0, #4
_0822C064:
	ldr r2, _0822C0B4 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0822C06C:
	ldr r1, [sp, #0x14]
	mov r0, sp
	movs r2, #0x10
	ldrsh r3, [r0, r2]
	adds r0, r7, #0
	adds r2, r5, #0
	bl FUN_0822b9d4
	adds r0, r7, #0
	ldr r1, [sp, #0x60]
	bl SetBGPrioDirect
	mov r0, r8
	strh r0, [r6, #0x14]
	strh r4, [r6, #0x16]
	ldr r0, [sp, #0x38]
	strh r0, [r6, #0x18]
	ldr r0, [sp, #0x3c]
	strh r0, [r6, #0x1a]
	ldr r0, [sp, #0x1c]
	str r0, [r6, #0x24]
	ldr r0, [sp, #0x24]
	str r0, [r6, #0x28]
	ldr r0, [sp, #0x64]
	str r0, [r6, #0x2c]
	cmp r7, #0
	bne _0822C0A6
	bl FUN_0822e8b4
_0822C0A6:
	add sp, #0x40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822C0B4: .4byte 0x03003E78

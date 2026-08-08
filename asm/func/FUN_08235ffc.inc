	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	adds r3, r1, #0
	mov sl, r2
	ldrh r1, [r3, #4]
	lsls r1, r1, #2
	adds r0, #4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp]
	adds r7, r1, r0
	ldr r0, [r7, #8]
	adds r0, r0, r7
	mov r8, r0
	ldrh r2, [r3, #6]
	mov r1, sl
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	bne _0823611E
	ldr r0, [r7, #0xc]
	adds r0, r7, r0
	str r0, [sp, #4]
	ldrh r0, [r3, #6]
	lsls r0, r0, #4
	add r0, r8
	str r0, [sp, #8]
	movs r6, #0
	adds r1, r0, #0
	adds r1, #4
	ldrb r0, [r0, #4]
	cmp r0, #0xff
	beq _082360A2
_0823604C:
	adds r0, r1, r6
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, [sp, #4]
	adds r2, r2, r0
	mov sb, r2
	movs r4, #0
_0823605E:
	mov r0, sb
	adds r0, #6
	adds r5, r0, r4
	ldrb r0, [r5]
	cmp r0, #0xff
	beq _08236088
	adds r2, r0, #0
	ldrh r0, [r3, #6]
	cmp r2, r0
	beq _0823608A
	mov r0, r8
	mov r1, sl
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	beq _0823608A
	ldrb r0, [r5]
	strh r0, [r3, #6]
	b _0823611E
_08236088:
	movs r4, #6
_0823608A:
	adds r4, #1
	cmp r4, #5
	ble _0823605E
	adds r6, #1
	cmp r6, #0xb
	bgt _082360A2
	ldr r1, [sp, #8]
	adds r1, #4
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0823604C
_082360A2:
	movs r6, #0
	ldrh r1, [r7]
	cmp r6, r1
	bge _082360CE
_082360AA:
	ldrh r2, [r3, #6]
	cmp r6, r2
	beq _082360C6
	mov r0, r8
	mov r1, sl
	adds r2, r6, #0
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	beq _082360C6
	strh r6, [r3, #6]
	b _0823611E
_082360C6:
	adds r6, #1
	ldrh r0, [r7]
	cmp r6, r0
	blt _082360AA
_082360CE:
	movs r6, #0
	b _08236116
_082360D2:
	ldrh r2, [r3, #4]
	cmp r6, r2
	beq _08236114
	lsls r1, r6, #2
	ldr r0, [sp]
	adds r0, #4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp]
	adds r7, r1, r0
	ldr r0, [r7, #8]
	adds r0, r0, r7
	mov r8, r0
	movs r4, #0
	ldrh r2, [r7]
	cmp r4, r2
	bge _08236114
_082360F4:
	mov r0, r8
	mov r1, sl
	adds r2, r4, #0
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	beq _0823610C
	strh r6, [r3, #4]
	strh r4, [r3, #6]
	b _0823611E
_0823610C:
	adds r4, #1
	ldrh r0, [r7]
	cmp r4, r0
	blt _082360F4
_08236114:
	adds r6, #1
_08236116:
	ldr r1, [sp]
	ldrh r1, [r1]
	cmp r6, r1
	blt _082360D2
_0823611E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

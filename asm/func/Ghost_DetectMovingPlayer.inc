	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816D6C6
	b _0816D84A
_0816D6C6:
	movs r1, #0x20
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816D6D8
	b _0816D84A
_0816D6D8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov ip, r0
	ldr r2, _0816D728 @ =0x03002BE0
	mov r8, r2
	mov r7, sp
	movs r2, #0x89
	lsls r2, r2, #4
	add r2, ip
	mov r4, r8
	ldr r3, [r4]
	adds r4, r3, #0
	adds r4, #0x2c
	ldrh r0, [r3, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0816D72C @ =0x0000083E
	add r1, ip
	ldrb r0, [r1]
	mov r4, r8
	cmp r0, #0
	beq _0816D730
	subs r0, #1
	b _0816D848
	.align 2, 0
_0816D728: .4byte 0x03002BE0
_0816D72C: .4byte 0x0000083E
_0816D730:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0816D73E
	b _0816D84A
_0816D73E:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0816D752
	movs r2, #4
	ldrsh r0, [r7, r2]
	cmp r0, #0
	bne _0816D752
	b _0816D84A
_0816D752:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816D84A
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #0xa
	ldrsh r1, [r6, r0]
	ldr r0, [r4]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0816D77C
	rsbs r1, r1, #0
_0816D77C:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _0816D84A
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0816D84A
	movs r2, #0x10
	ldr r1, _0816D7AC @ =0x000007DC
	add r1, ip
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0816D7B0
	movs r0, #1
	b _0816D7B2
	.align 2, 0
_0816D7AC: .4byte 0x000007DC
_0816D7B0:
	movs r0, #0
_0816D7B2:
	adds r3, r0, #0
	cmp r3, #0
	beq _0816D808
	ldr r0, [r4]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0816D84A
	movs r2, #4
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0816D7FC @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _0816D800 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrh r1, [r0]
	ldr r2, _0816D804 @ =0x0000024E
	adds r0, r6, r2
	strh r1, [r0]
	b _0816D84A
	.align 2, 0
_0816D7FC: .4byte 0x00000469
_0816D800: .4byte 0x00000484
_0816D804: .4byte 0x0000024E
_0816D808:
	movs r1, #0x10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #2
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #1
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _0816D858 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r6, r4
	str r3, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _0816D85C @ =0x0000024E
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0816D860 @ =0x0000083E
	add r1, ip
	movs r0, #0xa
_0816D848:
	strb r0, [r1]
_0816D84A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816D858: .4byte 0x0000046A
_0816D85C: .4byte 0x0000024E
_0816D860: .4byte 0x0000083E

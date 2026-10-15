	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	mov r1, sp
	bl FUN_08059b7c
	adds r7, r0, #0
	cmp r7, #0
	bne _0805A384
	movs r0, #1
	rsbs r0, r0, #0
	b _0805A42E
_0805A384:
	str r4, [r7, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	adds r2, r7, #0
	adds r2, #0xbc
	movs r1, #0
	strb r6, [r7]
	ldrb r0, [r7]
	cmp r0, #1
	beq _0805A3BE
	cmp r0, #1
	bgt _0805A3B8
	cmp r0, #0
	beq _0805A3C2
	b _0805A3CA
_0805A3B8:
	cmp r0, #2
	beq _0805A3C2
	b _0805A3CA
_0805A3BE:
	strb r1, [r7, #2]
	b _0805A3C6
_0805A3C2:
	strb r1, [r7, #2]
	movs r0, #1
_0805A3C6:
	strb r0, [r7, #1]
	strh r1, [r7, #8]
_0805A3CA:
	strb r3, [r7, #0xc]
	strb r3, [r7, #0xd]
	movs r0, #0
	mov r8, r0
	ldr r0, [sp, #0x20]
	strh r0, [r7, #0xe]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r7, #0xd]
	adds r0, #0x60
	rsbs r0, r0, #0
	strb r0, [r2, #6]
	ldr r0, [r2]
	movs r5, #1
	orrs r0, r5
	str r0, [r2]
	strb r5, [r2, #9]
	adds r0, r7, #0
	adds r0, #0x1c
	adds r6, r7, #0
	adds r6, #0xd8
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r4, r7, #0
	adds r4, #0x6c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r4, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	strb r1, [r7, #3]
	strb r1, [r7, #4]
	ldr r0, [sp, #0x24]
	strh r0, [r7, #0xa]
	ldr r0, [sp]
	lsls r5, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r5
	str r0, [r2, #0x18]
	movs r0, #0
_0805A42E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

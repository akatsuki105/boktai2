	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r4, r0
	bge _0801FCFC
	ldr r1, _0801FD08 @ =0x0000042C
	adds r6, r5, r1
	movs r3, #2
	mov sb, r3
	ldr r0, _0801FD0C @ =FUN_08020734
	mov r8, r0
_0801FCAA:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _0801FCF4
	movs r1, #0x37
	adds r1, r1, r2
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801FCCA
	cmp r0, #3
	bne _0801FCF4
_0801FCCA:
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _0801FCF4
	adds r0, r2, #0
	adds r0, #0x41
	strb r3, [r0]
	mov r0, sb
	mov r3, ip
	strb r0, [r3]
	mov r3, r8
	str r3, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0801FCF4:
	adds r4, #1
	ldrh r0, [r5, #0x1a]
	cmp r4, r0
	blt _0801FCAA
_0801FCFC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD08: .4byte 0x0000042C
_0801FD0C: .4byte FUN_08020734

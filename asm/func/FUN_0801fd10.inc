	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FD72
	ldr r1, _0801FD80 @ =0x0000042C
	adds r5, r4, r1
	movs r2, #3
	mov sb, r2
	mov r8, r3
	movs r0, #2
	mov ip, r0
	ldr r7, _0801FD84 @ =FUN_080206b8
_0801FD36:
	movs r0, #0x8c
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r0, [r1, #0x34]
	cmp r0, r6
	bne _0801FD6A
	adds r2, r1, #0
	adds r2, #0x37
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801FD6A
	mov r0, sb
	strb r0, [r2]
	str r7, [r1, #0x30]
	adds r0, r1, #0
	adds r0, #0x39
	mov r2, ip
	strb r2, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
_0801FD6A:
	adds r3, #1
	ldrh r2, [r4, #0x1a]
	cmp r3, r2
	blt _0801FD36
_0801FD72:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD80: .4byte 0x0000042C
_0801FD84: .4byte FUN_080206b8

	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D479E
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	add r3, sp, #8
	adds r5, r7, #0
	adds r5, #0xfc
	mov r0, sp
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r6, r1, r0
	strh r6, [r3, #4]
	ldr r4, _081D47AC @ =0x085AE0D0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r2, r0
	bgt _081D479E
	movs r2, #0
	ldrsh r1, [r3, r2]
	cmn r1, r0
	blt _081D479E
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bgt _081D479E
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmn r1, r0
	blt _081D479E
	adds r0, r5, #0
	bl FUN_08086a4c
	ldr r4, _081D47B0 @ =0x000012B2
	add r4, r8
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r1, r7, #0
	adds r1, #0xd4
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r1, [r1]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	adds r2, r7, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D479E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D47AC: .4byte 0x085AE0D0
_081D47B0: .4byte 0x000012B2

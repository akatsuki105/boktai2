	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	adds r0, r5, #0
	adds r0, #0x58
	mov r1, sp
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #2]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	add r6, sp, #8
	adds r3, r5, #0
	adds r3, #0xfc
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r1, r0
	strh r1, [r6]
	ldrh r2, [r4, #2]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	mov ip, r2
	mov r2, ip
	strh r2, [r6, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r3, #4]
	subs r2, r2, r0
	strh r2, [r6, #4]
	ldr r0, _081D4394 @ =0x03000194
	ldr r4, [r0]
	ldr r3, _081D4398 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bgt _081D43A0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r7, #2
	ldrsh r1, [r3, r7]
	cmp r0, r1
	bgt _081D43A0
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r7, #2
	ldrsh r0, [r3, r7]
	cmn r1, r0
	blt _081D43A0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r2, #4
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bgt _081D43A0
	movs r7, #4
	ldrsh r1, [r6, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmn r1, r0
	blt _081D43A0
	ldr r7, _081D439C @ =0x000012B2
	adds r4, r4, r7
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	adds r0, r5, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_081d407c
	movs r0, #0x10
	adds r2, r5, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	b _081D43C6
	.align 2, 0
_081D4394: .4byte 0x03000194
_081D4398: .4byte 0x085AE0D0
_081D439C: .4byte 0x000012B2
_081D43A0:
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r1, _081D43D0 @ =0x000012B2
	adds r4, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	bne _081D43C8
	movs r0, #0
	strh r0, [r4]
	movs r0, #7
	bl FUN_080869f8
	adds r2, r5, #0
	adds r2, #0xb4
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
_081D43C6:
	strh r0, [r2]
_081D43C8:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D43D0: .4byte 0x000012B2

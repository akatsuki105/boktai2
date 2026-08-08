	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	beq _0807B7DA
	ldr r1, _0807B878 @ =0x00000992
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	ldr r6, _0807B87C @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	adds r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
_0807B7DA:
	movs r0, #2
	str r0, [r5, #0x1c]
	ldr r1, _0807B880 @ =0x000004AA
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r2, #1
	strb r2, [r0]
	subs r1, #0xb4
	adds r0, r5, r1
	strh r4, [r0]
	subs r6, #0xb0
	adds r0, r5, r6
	strh r4, [r0]
	ldr r7, _0807B884 @ =0x03002BA8
	ldr r1, [r7]
	cmp r1, #0
	beq _0807B824
	ldr r6, _0807B888 @ =0x03002BF4
	ldrh r0, [r6]
	cmp r0, #0
	beq _0807B824
	ldr r0, [r1, #4]
	ands r0, r2
	cmp r0, #0
	bne _0807B820
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #1
	movs r2, #0x3c
	bl _call_via_r3
_0807B820:
	str r4, [r7]
	strh r4, [r6]
_0807B824:
	adds r0, r5, #0
	bl FUN_08060c60
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	strh r2, [r0]
	movs r6, #0xb9
	lsls r6, r6, #1
	adds r3, r5, r6
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r6, _0807B88C @ =0x000003CE
	adds r0, r5, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0807B85C
	adds r0, r5, #0
	bl FUN_08066d10
_0807B85C:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807B878: .4byte 0x00000992
_0807B87C: .4byte 0x0000098C
_0807B880: .4byte 0x000004AA
_0807B884: .4byte 0x03002BA8
_0807B888: .4byte 0x03002BF4
_0807B88C: .4byte 0x000003CE

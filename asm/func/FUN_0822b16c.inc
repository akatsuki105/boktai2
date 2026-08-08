	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _0822B1BC @ =0x030035A0
	ldr r3, [r0]
	adds r7, r0, #0
	cmp r3, #0
	beq _0822B1B6
	ldr r0, [r3, #0xc]
	adds r0, r0, r3
	mov r8, r0
	ldr r0, [r3, #0x10]
	adds r0, r0, r3
	mov ip, r0
	movs r6, #0
	adds r4, r3, #0
	adds r4, #0x18
	movs r2, #0
	ldr r0, [r3, #4]
	cmp r6, r0
	bge _0822B1B2
	ldrh r0, [r3, #0x18]
	cmp r0, r1
	beq _0822B1C0
_0822B19E:
	adds r4, #0xc
	adds r2, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	cmp r2, r0
	bge _0822B1B2
	ldrh r0, [r4]
	cmp r0, r1
	bne _0822B19E
	movs r6, #1
_0822B1B2:
	cmp r6, #0
	bne _0822B1C0
_0822B1B6:
	movs r0, #0
	b _0822B1FE
	.align 2, 0
_0822B1BC: .4byte 0x030035A0
_0822B1C0:
	ldr r2, [r4, #8]
	add r2, ip
	ldrb r0, [r4, #2]
	movs r1, #0
	strb r0, [r5]
	strb r1, [r5, #1]
	strh r1, [r5, #2]
	ldrb r0, [r4, #4]
	strb r0, [r5, #8]
	ldrb r0, [r4, #5]
	strb r0, [r5, #9]
	ldrb r0, [r4, #6]
	strb r0, [r5, #0xa]
	ldrb r0, [r4, #7]
	strb r0, [r5, #0xb]
	strh r1, [r5, #4]
	ldrh r0, [r2, #2]
	strh r0, [r5, #6]
	ldr r0, _0822B208 @ =0x03003584
	ldrh r1, [r5, #6]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r5, #0xc]
	ldr r0, [r2, #4]
	add r0, r8
	str r0, [r5, #0x10]
	ldr r0, [r4, #8]
	add r0, ip
	str r0, [r5, #0x14]
	movs r0, #1
_0822B1FE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0822B208: .4byte 0x03003584

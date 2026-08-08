	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r1, [r4, #0x1c]
	cmp r1, #1
	bne _0807E7F4
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r2, [r6, #6]
	ands r0, r2
	cmp r0, #0
	beq _0807E7B4
	movs r0, #0x46
	adds r0, r0, r5
	mov ip, r0
	ldrb r3, [r0]
	ands r1, r3
	cmp r1, #0
	beq _0807E7F4
	movs r0, #0xfe
	ands r0, r3
	mov r1, ip
	strb r0, [r1]
_0807E7B4:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r2, r0
	cmp r2, #0
	beq _0807E7D2
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807E7F4
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
_0807E7D2:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_0807e3b0
	movs r1, #0x80
	lsls r1, r1, #0xb
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807E7F4
	adds r0, r4, #0
	bl FUN_0807e2cc
_0807E7F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

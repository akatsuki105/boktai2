	push {r4, r5, r6, lr}
	sub sp, #0x50
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r3, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _0807E848
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r3, r4, r0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bgt _0807E848
	mov r1, sp
	movs r0, #0x80
	lsls r0, r0, #6
	strh r0, [r1, #6]
	mov r0, sp
	strh r5, [r0, #0x3c]
	add r0, sp, #0x40
	strh r2, [r0]
	adds r0, #2
	strb r6, [r0]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x38]
	add r1, sp, #0x44
	ldr r0, [sp, #0x60]
	strh r0, [r1]
	adds r0, r4, #0
	mov r1, sp
	adds r2, r3, #0
	bl FUN_0807e3b0
	b _0807E84A
_0807E848:
	movs r0, #0
_0807E84A:
	add sp, #0x50
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

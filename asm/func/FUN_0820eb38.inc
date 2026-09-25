	push {r4, r5, r6, r7, lr}
	movs r4, #0
	movs r6, #1
	ldr r1, _0820EB7C @ =0x000005B4
	adds r1, r1, r0
	mov ip, r1
	ldr r1, _0820EB80 @ =0x00000854
	adds r7, r0, r1
_0820EB48:
	lsls r1, r4, #1
	adds r5, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #6
	adds r2, r0, r7
	movs r3, #1
_0820EB54:
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820EB54
	adds r1, r1, r4
	lsls r1, r1, #5
	add r1, ip
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r4, r5, #0
	cmp r4, #6
	ble _0820EB48
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820EB7C: .4byte 0x000005B4
_0820EB80: .4byte 0x00000854

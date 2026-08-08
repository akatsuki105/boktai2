	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r5, [sp, #0x10]
	ldr r6, [sp, #0x14]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #0xec
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xf1
	lsls r0, r0, #1
	add r0, ip
	strh r3, [r0]
	movs r4, #0x80
	lsls r4, r4, #2
	add r4, ip
	strh r5, [r4]
	movs r1, #0xf6
	lsls r1, r1, #1
	add r1, ip
	adds r0, r2, #0
	muls r0, r2, r0
	str r0, [r1]
	movs r1, #0xf8
	lsls r1, r1, #1
	add r1, ip
	adds r0, r3, #0
	muls r0, r3, r0
	str r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	str r0, [r1]
	ldr r0, _080E3AF8 @ =0x000001FD
	add r0, ip
	strb r6, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E3AF8: .4byte 0x000001FD

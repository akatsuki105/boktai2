	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	ldr r0, _0823BD58 @ =gCamera
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	beq _0823BD90
	ldr r0, _0823BD5C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823BD90
	cmp r3, #0
	bne _0823BD60
	cmp r5, #1
	bne _0823BD60
	adds r0, r2, #0
	adds r0, #0x84
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, #0x85
	strb r3, [r0]
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x86
	strh r3, [r1]
	adds r0, #0x88
	strh r3, [r0]
	b _0823BD8A
	.align 2, 0
_0823BD58: .4byte gCamera
_0823BD5C: .4byte 0x030047A4
_0823BD60:
	ldr r0, [r4]
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	mov ip, r0
	mov r1, ip
	adds r1, #0x88
	strh r6, [r1]
	adds r0, #0x8a
	strh r3, [r0]
	lsls r0, r3, #0x10
	cmp r0, #0
	bne _0823BD84
	ldrh r1, [r1]
	mov r0, ip
	adds r0, #0x86
	strh r1, [r0]
_0823BD84:
	ldr r0, [r4]
	adds r0, #0x85
	strb r5, [r0]
_0823BD8A:
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BD90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

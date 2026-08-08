	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r0, _0807E2C4 @ =0x00000994
	adds r4, r6, r0
	ldrh r0, [r6, #0x24]
	movs r2, #0
	movs r3, #0
	strh r0, [r4]
	movs r0, #2
	strb r0, [r4, #2]
	strb r2, [r4, #3]
	strh r3, [r4, #4]
	strb r1, [r4, #6]
	strb r5, [r4, #7]
	cmp r7, #0
	beq _0807E2B6
	cmp r5, #0
	ble _0807E2B6
	adds r3, r7, #0
	ldr r0, _0807E2C8 @ =0x0000099C
	adds r1, r6, r0
	adds r2, r5, #0
_0807E2A8:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0807E2A8
_0807E2B6:
	adds r0, r4, #0
	bl FUN_080224f0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E2C4: .4byte 0x00000994
_0807E2C8: .4byte 0x0000099C

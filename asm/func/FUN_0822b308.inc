	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0822B374 @ =0x03003594
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #5
	ldr r3, _0822B378 @ =0x06010000
	adds r4, r1, r3
	ldr r5, _0822B37C @ =0x03000288
	ldr r1, _0822B380 @ =0x03003590
	ldrh r2, [r1]
	mov r8, r0
	adds r7, r1, #0
	ldr r0, _0822B384 @ =0x03003578
	mov ip, r0
	cmp r2, #0
	beq _0822B352
	ldr r3, _0822B388 @ =0x040000D4
	movs r6, #0x84
	lsls r6, r6, #0x18
	adds r1, r2, #0
_0822B334:
	ldrh r0, [r5]
	lsls r2, r0, #5
	ldr r0, [r5, #4]
	str r0, [r3]
	str r4, [r3, #4]
	adds r0, r2, #0
	asrs r0, r0, #2
	orrs r0, r6
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r4, r4, r2
	adds r5, #8
	subs r1, #1
	cmp r1, #0
	bne _0822B334
_0822B352:
	movs r0, #0
	strh r0, [r7]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r3, ip
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r0, r0, r1
	bl FUN_0822b38c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822B374: .4byte 0x03003594
_0822B378: .4byte 0x06010000
_0822B37C: .4byte 0x03000288
_0822B380: .4byte 0x03003590
_0822B384: .4byte 0x03003578
_0822B388: .4byte 0x040000D4

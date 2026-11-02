	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08147440 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08147444
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08147446
	.align 2, 0
_08147440: .4byte 0x0000046D
_08147444:
	movs r0, #0
_08147446:
	cmp r0, #0
	beq _08147466
	ldrb r0, [r5, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080efb60
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08147466:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081474CE
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _081474D4 @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	movs r4, #0
	strh r0, [r2]
	ldr r3, _081474D8 @ =0x000005A4
	adds r0, r5, r3
	ldr r2, [r0]
	ldr r6, _081474DC @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0x25
	adds r0, r5, r6
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081474E0 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081474E4 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	strb r3, [r0]
_081474CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081474D4: .4byte 0x0000FFFB
_081474D8: .4byte 0x000005A4
_081474DC: .4byte 0x0000046D
_081474E0: .4byte 0x00000469
_081474E4: .4byte 0x00000484

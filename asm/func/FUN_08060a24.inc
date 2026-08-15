	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r2, #0
	movs r3, #0
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, r1
	bne _08060A3C
	movs r3, #1
_08060A3C:
	strh r1, [r2]
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _08060A74 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, r1, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08060A78 @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08060A7C
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _08060A88
	.align 2, 0
_08060A74: .4byte 0x000002E6
_08060A78: .4byte 0x000002E7
_08060A7C:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08060A88:
	str r1, [r0]
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

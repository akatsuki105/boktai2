	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r0, _081F6CEC @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F6CBA
	ldr r2, _081F6CF0 @ =0x000006DC
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F6CF4 @ =0x05000002
	bl CpuSet
	movs r3, #0xdd
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_081f6458
	movs r0, #0xd1
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081F6CBA:
	adds r0, r5, #0
	bl FUN_081f69a0
	ldr r2, _081F6CF8 @ =0x00006D60
	adds r0, r5, #0
	movs r1, #8
	bl Entity081f73ec_FollowHead
	adds r0, r5, #0
	bl Entity081f73ec_UpdateBuried
	adds r0, r5, #0
	bl Entity081f73ec_UpdateFlash
	movs r3, #0xdd
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x1d
	bgt _081F6CFC
	adds r0, r2, #1
	strh r0, [r1]
	b _081F6D08
	.align 2, 0
_081F6CEC: .4byte 0x000006EA
_081F6CF0: .4byte 0x000006DC
_081F6CF4: .4byte 0x05000002
_081F6CF8: .4byte 0x00006D60
_081F6CFC:
	ldr r1, _081F6D10 @ =0x000006E6
	adds r0, r5, r1
	movs r1, #5
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
_081F6D08:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F6D10: .4byte 0x000006E6

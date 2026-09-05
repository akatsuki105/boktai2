	push {r4, r5, lr}
	sub sp, #8
	ldr r1, _080B2588 @ =0x03002BE0
	ldr r4, [r1]
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r2, r0, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r1, r1, r2
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r5, _080B258C @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r5
	orrs r3, r1
	str r3, [sp]
	ldrh r2, [r4, #0x2e]
	adds r2, #0x96
	lsls r2, r2, #0x10
	ldr r1, _080B2590 @ =0x0000FFFF
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	ldr r3, _080B2594 @ =0x00000504
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_0823b8ac
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2588: .4byte 0x03002BE0
_080B258C: .4byte 0xFFFF0000
_080B2590: .4byte 0x0000FFFF
_080B2594: .4byte 0x00000504

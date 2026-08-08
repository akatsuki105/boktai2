	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0807C678 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x96
	muls r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _0807C67C
	asrs r1, r0, #0xc
	b _0807C682
	.align 2, 0
_0807C678: .4byte 0x085B0A08
_0807C67C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807C682:
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0807C6B8 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _0807C6BC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r0, r3, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _0807C6C0
	asrs r2, r0, #0xc
	b _0807C6C6
	.align 2, 0
_0807C6B8: .4byte 0xFFFF0000
_0807C6BC: .4byte 0x0000FFFF
_0807C6C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0807C6C6:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807C6F0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807C6F8
	ldr r0, _0807C6F4 @ =0x00000203
	bl PlaySound_082406e0
	movs r1, #0x32
	b _0807C700
	.align 2, 0
_0807C6F0: .4byte 0xFFFF0000
_0807C6F4: .4byte 0x00000203
_0807C6F8:
	movs r0, #0xcd
	bl PlaySound_082406e0
	movs r1, #0x2c
_0807C700:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0xc
	movs r2, #0
	bl FUN_080c0fa0
	movs r5, #0x96
	lsls r5, r5, #3
	adds r0, r4, r5
	str r7, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C744 @ =FUN_08074350
	str r0, [r1]
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C744: .4byte FUN_08074350

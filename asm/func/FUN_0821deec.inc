	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r1, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0xa
	orrs r1, r0
	str r1, [r5]
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r2, [r0]
	cmp r2, #0
	bne _0821DF58
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5]
	movs r3, #0xed
	lsls r3, r3, #2
	adds r1, r4, r3
	adds r0, r4, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	movs r0, #1
	str r0, [sp]
	str r2, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_0821c400
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, _0821DF60 @ =0x00000804
	adds r0, r4, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r2]
	cmp r0, r1
	blt _0821DF58
	movs r1, #0x10
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0821DF58:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821DF60: .4byte 0x00000804

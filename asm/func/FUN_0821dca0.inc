	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _0821DCF4 @ =0x00000B54
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r2, r4, #0
	adds r2, #0x50
	ldr r1, _0821DCF8 @ =0x00000BB4
	adds r4, r4, r1
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r0, _0821DCFC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x32
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x32
	bl FUN_0807ac74
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0821DCF4: .4byte 0x00000B54
_0821DCF8: .4byte 0x00000BB4
_0821DCFC: .4byte 0x03002BE0

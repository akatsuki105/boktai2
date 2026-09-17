	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	cmp r6, #0
	beq _081EB1EC
	ldr r0, _081EB1E8 @ =0x030001C4
	ldr r5, [r0]
	cmp r5, #0
	bne _081EB196
	bl Entity081eb2f0_Create
	adds r5, r0, #0
	cmp r5, #0
	beq _081EB1EC
_081EB196:
	adds r0, r5, #0
	bl FUN_081eb12c
	adds r4, r0, #0
	cmp r4, #0
	beq _081EB1EC
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	ldr r1, [r5, #0x1c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x28
	ldr r1, [r5, #0x18]
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	strb r7, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	movs r0, #0
	b _081EB1F0
	.align 2, 0
_081EB1E8: .4byte 0x030001C4
_081EB1EC:
	movs r0, #1
	rsbs r0, r0, #0
_081EB1F0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

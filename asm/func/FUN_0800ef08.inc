	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EF40
	movs r2, #0
	strb r2, [r4, #3]
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EF60 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0800EF3A
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0800EF3A:
	adds r0, r4, #0
	bl FUN_0800e530
_0800EF40:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _0800EF56
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _0800EF52
	adds r0, r4, #0
	bl FUN_0800eebc
_0800EF52:
	movs r0, #1
	strb r0, [r4, #0xd]
_0800EF56:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800EF60: .4byte 0x03002B3C

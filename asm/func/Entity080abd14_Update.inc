	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	bne _080ABC30
	movs r0, #1
	strb r0, [r4, #0x1b]
	movs r0, #0
	b _080ABC7A
_080ABC30:
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _080ABC42
	ldr r0, _080ABC80 @ =0x03002BF0
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	movs r0, #0
	strb r0, [r4, #0x19]
_080ABC42:
	adds r0, r4, #0
	bl FUN_080ab898
	adds r0, r4, #0
	bl FUN_080abac8
	adds r0, r4, #0
	bl FUN_080ab67c
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _080ABC7A
	adds r1, r4, #0
	adds r1, #0xb0
	ldrb r1, [r1]
	cmp r1, #0
	bne _080ABC7A
	adds r2, #0xe
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _080ABC7A
	adds r0, r4, #0
	bl KillEntity
_080ABC7A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080ABC80: .4byte 0x03002BF0

	push {r4, lr}
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08130498
	ldr r0, _081304A0 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _081304A4 @ =0x000003FF
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08130498
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_08130498:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081304A0: .4byte 0x03002BE0
_081304A4: .4byte 0x000003FF

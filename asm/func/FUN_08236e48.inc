	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xca
	ldrh r0, [r6]
	cmp r0, #0
	beq _08236E8A
	ldr r0, _08236E68 @ =0x030044BC
	ldr r5, [r0]
	cmp r5, #0
	beq _08236E6C
	movs r1, #0
	strh r1, [r6]
	ldr r0, [r4, #0x1c]
	str r1, [r0]
	b _08236E88
	.align 2, 0
_08236E68: .4byte 0x030044BC
_08236E6C:
	adds r1, r4, #0
	adds r1, #0xc8
	ldrh r0, [r1]
	cmp r0, #0
	beq _08236E82
	ldrh r0, [r6]
	ldrh r1, [r1]
	ldr r2, [r4, #0x1c]
	ldr r3, [r4, #0x18]
	bl FUN_08236d70
_08236E82:
	strh r5, [r6]
	ldr r0, [r4, #0x1c]
	str r5, [r0]
_08236E88:
	str r0, [r4, #0x24]
_08236E8A:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

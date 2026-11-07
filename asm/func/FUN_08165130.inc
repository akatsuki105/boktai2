	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #0x10
	ldr r2, _0816514C @ =0x0000068E
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08165150
	movs r0, #1
	b _08165152
	.align 2, 0
_0816514C: .4byte 0x0000068E
_08165150:
	movs r0, #0
_08165152:
	cmp r0, #0
	beq _0816516A
	ldr r0, _08165170 @ =0x000003C2
	bl PlaySound_082406e0
	ldr r0, _08165174 @ =0x0000068E
	adds r2, r4, r0
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0816516A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08165170: .4byte 0x000003C2
_08165174: .4byte 0x0000068E

	push {lr}
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0806513C
	ldr r0, _08065138 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _0806515E
	.align 2, 0
_08065138: .4byte 0x030046A0
_0806513C:
	ldr r1, _08065154 @ =0x03002BB0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08065158 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5e
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0806515C
	movs r0, #9
	b _0806515E
	.align 2, 0
_08065154: .4byte 0x03002BB0
_08065158: .4byte 0x030046A0
_0806515C:
	movs r0, #8
_0806515E:
	pop {r1}
	bx r1
	.align 2, 0

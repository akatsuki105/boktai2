	push {lr}
	adds r1, r0, #0
	ldr r2, _08192068 @ =0x00000544
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0819207C
	cmp r0, #0x3b
	bhi _08192070
	ldr r0, _0819206C @ =0x00000482
	adds r1, r1, r0
	movs r0, #2
	b _08192082
	.align 2, 0
_08192068: .4byte 0x00000544
_0819206C: .4byte 0x00000482
_08192070:
	ldr r2, _08192078 @ =0x00000482
	adds r1, r1, r2
	movs r0, #3
	b _08192082
	.align 2, 0
_08192078: .4byte 0x00000482
_0819207C:
	ldr r0, _08192088 @ =0x00000482
	adds r1, r1, r0
	movs r0, #1
_08192082:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08192088: .4byte 0x00000482

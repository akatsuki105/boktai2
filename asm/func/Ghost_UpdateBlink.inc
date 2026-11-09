	push {r4, r5, lr}
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816DE12
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	movs r1, #0x60
	ldr r2, _0816DD68 @ =0x000007DC
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816DD6C
	movs r0, #1
	b _0816DD6E
	.align 2, 0
_0816DD68: .4byte 0x000007DC
_0816DD6C:
	movs r0, #0
_0816DD6E:
	cmp r0, #0
	beq _0816DE12
	ldr r0, _0816DD98 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	ldr r1, _0816DD9C @ =0x00000836
	adds r0, r5, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x13
	bhi _0816DDA0
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0816DDAE
	b _0816DDBC
	.align 2, 0
_0816DD98: .4byte 0x030047A4
_0816DD9C: .4byte 0x00000836
_0816DDA0:
	cmp r1, #0x1d
	bhi _0816DDC8
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0816DDBC
_0816DDAE:
	ldr r0, [r4, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0816DE08
_0816DDBC:
	ldr r0, [r4, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0816DE08
_0816DDC8:
	movs r2, #0x20
	ldr r0, _0816DDDC @ =0x000007DC
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0816DDE0
	movs r0, #1
	b _0816DDE2
	.align 2, 0
_0816DDDC: .4byte 0x000007DC
_0816DDE0:
	movs r0, #0
_0816DDE2:
	cmp r0, #0
	beq _0816DDF6
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	subs r1, #0x1f
	b _0816DE02
_0816DDF6:
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	subs r1, #0x42
_0816DE02:
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
_0816DE08:
	ldr r2, _0816DE18 @ =0x00000836
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0816DE12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816DE18: .4byte 0x00000836

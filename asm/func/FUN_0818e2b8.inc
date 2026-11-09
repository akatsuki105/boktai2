	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818E302
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _0818E2E4 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818E2E8
	movs r0, #1
	b _0818E2EA
	.align 2, 0
_0818E2E4: .4byte 0x00000F2C
_0818E2E8:
	movs r0, #0
_0818E2EA:
	cmp r0, #0
	bne _0818E302
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0818E308 @ =0x00000ED8
	adds r1, r1, r2
	ldrh r0, [r5]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0818E302:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0818E308: .4byte 0x00000ED8

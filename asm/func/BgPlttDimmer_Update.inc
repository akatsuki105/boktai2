	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	cmp r0, #1
	beq _0801B234
	cmp r0, #1
	blo _0801B220
	cmp r0, #2
	beq _0801B24A
	b _0801B268
_0801B220:
	ldr r2, [r4, #0x24]
	ldr r1, [r4, #0x1c]
	cmp r2, r1
	bls _0801B22E
	subs r0, r2, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B22E:
	str r1, [r4, #0x24]
	adds r0, #1
	b _0801B242
_0801B234:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x20]
	cmp r0, r1
	blo _0801B268
	movs r0, #2
_0801B242:
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	b _0801B268
_0801B24A:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3f
	bhi _0801B256
	adds r0, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B256:
	movs r0, #0x40
	str r0, [r4, #0x24]
	movs r0, #3
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl KillEntity
_0801B268:
	ldr r0, _0801B294 @ =0x03004460
	ldr r3, [r4, #0x24]
	str r3, [r0]
	ldr r1, _0801B298 @ =0x03004454
	ldr r2, _0801B29C @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2A0 @ =0x03004494
	ldr r1, _0801B2A4 @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2A8 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2AC @ =0x03004490
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _0801B2B0 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B294: .4byte 0x03004460
_0801B298: .4byte 0x03004454
_0801B29C: .4byte 0x00001FFF
_0801B2A0: .4byte 0x03004494
_0801B2A4: .4byte 0x00001084
_0801B2A8: .4byte 0x0300445C
_0801B2AC: .4byte 0x03004490
_0801B2B0: .4byte 0x03004464

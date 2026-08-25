	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x44]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08219F7C
	ldr r0, [r2, #0x58]
	adds r0, #1
	str r0, [r2, #0x58]
_08219F7C:
	ldr r0, [r2, #0x44]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08219F8C
	ldr r0, [r2, #0x60]
	adds r0, #1
	str r0, [r2, #0x60]
_08219F8C:
	ldr r1, _08219FA0 @ =0x00001FE8
	adds r0, r2, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08219FA0: .4byte 0x00001FE8

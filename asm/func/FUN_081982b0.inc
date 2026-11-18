	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	adds r0, #0x45
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081982D4
	ldr r0, _081982D8 @ =0x085ADDA8
	adds r1, r2, #0
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_081982D4:
	pop {r0}
	bx r0
	.align 2, 0
_081982D8: .4byte 0x085ADDA8

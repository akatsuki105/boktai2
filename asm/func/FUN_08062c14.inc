	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x18]
	cmp r0, #0
	bne _08062C2C
	ldr r0, _08062C28 @ =0x0000094A
	adds r1, r1, r0
	movs r0, #0x1d
	b _08062C32
	.align 2, 0
_08062C28: .4byte 0x0000094A
_08062C2C:
	ldr r0, _08062C38 @ =0x0000094A
	adds r1, r1, r0
	movs r0, #0x28
_08062C32:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08062C38: .4byte 0x0000094A

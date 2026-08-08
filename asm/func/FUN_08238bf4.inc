	push {lr}
	ldr r0, _08238C04 @ =0x030046CC
	ldr r0, [r0]
	cmp r0, #0
	bne _08238C08
	bl FUN_0823869c
	b _08238C0C
	.align 2, 0
_08238C04: .4byte 0x030046CC
_08238C08:
	bl FUN_0823869c
_08238C0C:
	ldr r1, _08238C20 @ =0x030046C4
	ldr r0, [r1]
	cmp r0, #1
	bne _08238C18
	movs r0, #0
	str r0, [r1]
_08238C18:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08238C20: .4byte 0x030046C4

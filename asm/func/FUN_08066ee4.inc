	push {lr}
	cmp r0, #0
	bne _08066EF4
	ldr r0, _08066EF0 @ =0x085ABB2C
	b _08066F0A
	.align 2, 0
_08066EF0: .4byte 0x085ABB2C
_08066EF4:
	cmp r0, #1
	bne _08066F00
	ldr r0, _08066EFC @ =0x085ABB9E
	b _08066F0A
	.align 2, 0
_08066EFC: .4byte 0x085ABB9E
_08066F00:
	cmp r0, #5
	beq _08066F08
	movs r0, #0
	b _08066F10
_08066F08:
	ldr r0, _08066F14 @ =0x085ABC10
_08066F0A:
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
_08066F10:
	pop {r1}
	bx r1
	.align 2, 0
_08066F14: .4byte 0x085ABC10

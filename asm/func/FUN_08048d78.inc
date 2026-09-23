	push {lr}
	ldr r0, _08048D98 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08048D9C
	cmp r0, #1
	bgt _08048D9C
	cmp r0, #0
	bne _08048D9C
	movs r0, #0x1b
	b _08048D9E
	.align 2, 0
_08048D98: .4byte 0x030046A0
_08048D9C:
	movs r0, #0x1c
_08048D9E:
	pop {r1}
	bx r1
	.align 2, 0

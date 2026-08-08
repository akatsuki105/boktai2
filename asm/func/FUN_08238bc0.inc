	push {lr}
	bl FUN_08238aac
	ldr r0, _08238BE0 @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _08238BEE
	ldr r0, _08238BE4 @ =0x030046CC
	ldr r0, [r0]
	cmp r0, #0
	beq _08238BE8
	bl FUN_08238634
	movs r0, #1
	b _08238BEE
	.align 2, 0
_08238BE0: .4byte 0x030046D4
_08238BE4: .4byte 0x030046CC
_08238BE8:
	bl FUN_08238634
	movs r0, #0
_08238BEE:
	pop {r1}
	bx r1
	.align 2, 0

	push {r4, lr}
	ldr r0, [r0, #0x1c]
	cmp r0, #0
	beq _08016628
_0801661C:
	ldr r4, [r0, #0x7c]
	bl FUN_080160cc
	adds r0, r4, #0
	cmp r0, #0
	bne _0801661C
_08016628:
	ldr r1, _08016634 @ =0x03002B44
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016634: .4byte 0x03002B44

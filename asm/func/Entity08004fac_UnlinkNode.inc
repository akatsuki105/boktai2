	push {lr}
	ldr r2, [r0, #0x1c]
	ldr r1, [r0, #0x20]
	cmp r2, #0
	beq _08004CB6
	str r1, [r2, #0x20]
	b _08004CBC
_08004CB6:
	ldr r0, _08004CC8 @ =0x03000024
	ldr r0, [r0]
	str r1, [r0, #0x18]
_08004CBC:
	cmp r1, #0
	beq _08004CC2
	str r2, [r1, #0x1c]
_08004CC2:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08004CC8: .4byte 0x03000024

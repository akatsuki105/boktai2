	push {lr}
	ldr r0, _08241724 @ =PTR_03001708
	ldr r0, [r0]
	cmp r0, #0
	beq _0824171E
	ldrb r0, [r0, #0x19]
	cmp r0, #0
	beq _08241718
	bl FUN_082477b4
_08241718:
	ldr r1, _08241728 @ =0x0300486C
	movs r0, #1
	strh r0, [r1]
_0824171E:
	pop {r0}
	bx r0
	.align 2, 0
_08241724: .4byte PTR_03001708
_08241728: .4byte 0x0300486C

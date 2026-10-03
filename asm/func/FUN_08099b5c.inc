	push {lr}
	ldr r0, _08099B70 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne _08099B74
	movs r0, #2
	b _08099B7E
	.align 2, 0
_08099B70: .4byte 0x030046A0
_08099B74:
	cmp r0, #2
	beq _08099B7C
	movs r0, #0
	b _08099B7E
_08099B7C:
	movs r0, #1
_08099B7E:
	pop {r1}
	bx r1
	.align 2, 0

	push {lr}
	cmp r1, #0
	bne _08231B84
	ldr r1, _08231B94 @ =0x085B01C8
_08231B84:
	bl FUN_08231ad0
	cmp r0, #1
	beq _08231B9C
	ldr r1, _08231B98 @ =gVM
	movs r0, #0
	str r0, [r1, #4]
	b _08231BA0
	.align 2, 0
_08231B94: .4byte 0x085B01C8
_08231B98: .4byte gVM
_08231B9C:
	ldr r0, _08231BA4 @ =gVM
	ldr r0, [r0, #4]
_08231BA0:
	pop {r1}
	bx r1
	.align 2, 0
_08231BA4: .4byte gVM

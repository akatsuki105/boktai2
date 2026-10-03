	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080BCA40
	bl VM_GetValue
	ldr r2, _080BCA3C @ =0x00001534
	adds r1, r4, r2
	str r0, [r1]
	b _080BCA46
	.align 2, 0
_080BCA3C: .4byte 0x00001534
_080BCA40:
	ldr r2, _080BCA4C @ =0x00001534
	adds r0, r4, r2
	str r1, [r0]
_080BCA46:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCA4C: .4byte 0x00001534

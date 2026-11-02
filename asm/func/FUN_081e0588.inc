	push {r4, lr}
	adds r4, r0, #0
	bl Save_SwitchSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E05A0
	ldr r1, _081E059C @ =Entity501B_StateSaveDone
	movs r2, #7
	b _081E05A4
	.align 2, 0
_081E059C: .4byte Entity501B_StateSaveDone
_081E05A0:
	ldr r1, _081E05C4 @ =Entity501B_StateSaveFailed
	movs r2, #8
_081E05A4:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081E05C8 @ =0x000003E9
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E05C4: .4byte Entity501B_StateSaveFailed
_081E05C8: .4byte 0x000003E9

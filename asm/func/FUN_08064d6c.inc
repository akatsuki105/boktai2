	push {lr}
	adds r2, r1, #0
	ldr r1, _08064D9C @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _08064DA0 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bgt _08064DA8
	ldr r3, _08064DA4 @ =0x00000942
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	blt _08064DA8
	movs r0, #1
	b _08064DAA
	.align 2, 0
_08064D9C: .4byte 0x0000038E
_08064DA0: .4byte 0x030046A0
_08064DA4: .4byte 0x00000942
_08064DA8:
	movs r0, #0
_08064DAA:
	pop {r1}
	bx r1
	.align 2, 0

	push {r4, lr}
	adds r4, r0, #0
	bl Credits_TakeStepChanged
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804A6D0
	ldr r1, _0804A6F4 @ =0x03004040
	movs r0, #0x40
	str r0, [r1]
_0804A6D0:
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A6EC
	adds r0, r4, #0
	movs r1, #2
	bl Credits_SetStep
_0804A6EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A6F4: .4byte 0x03004040

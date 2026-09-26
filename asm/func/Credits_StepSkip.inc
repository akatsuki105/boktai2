	push {r4, r5, lr}
	adds r5, r0, #0
	bl Credits_TakeStepChanged
	ldrh r0, [r5, #0x32]
	cmp r0, #0
	beq _0804A7B8
	ldr r0, [r5, #0x20]
	cmp r0, #0xf
	bls _0804A7A8
	ldr r0, _0804A7A4 @ =0x03004040
	movs r4, #0
	str r4, [r0]
	ldrh r0, [r5, #0x32]
	movs r1, #0
	bl VM_ExecByID
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl KillEntity
	b _0804A7B8
	.align 2, 0
_0804A7A4: .4byte 0x03004040
_0804A7A8:
	ldr r4, _0804A7C0 @ =0x03004040
	lsls r0, r0, #6
	movs r1, #0x10
	bl Div
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [r4]
_0804A7B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804A7C0: .4byte 0x03004040
